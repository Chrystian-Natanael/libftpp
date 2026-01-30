/* tools/linter.cpp */
#include <iostream>
#include <filesystem>
#include <fstream>
#include <regex>
#include <string>
#include <vector>
#include <set>

namespace fs = std::filesystem;
bool g_has_errors = false;

//-- CORES 
const std::string RED = "\033[91m";
const std::string GREEN = "\033[92m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string RESET = "\033[0m";

//-- REGEX GERAIS
const std::regex FILE_SNAKE_CASE("^[a-z0-9_]+\\.(cpp|hpp|h|tpp)$"); // Adicionado .tpp
const std::regex CLASS_PASCAL_CASE("^[A-Z][a-zA-Z0-9]*$");
const std::regex METHOD_CAMEL_CASE("^[a-z][a-zA-Z0-9]*$");

const std::regex CLASS_DEF_PATTERN(R"(^\s*(?:class|struct)\s+([a-zA-Z0-9_]+))");
const std::regex METHOD_DEF_PATTERN(R"(\b([a-zA-Z0-9_]+)\s*\()");

const std::regex FORBIDDEN_FUNCS(R"(\b(printf|malloc|free|calloc|realloc|puts)\b)");
const std::regex FORBIDDEN_LIBS(R"(#include\s*<boost/)");
const std::regex HEADER_IMPL_PATTERN(R"(\)\s*(const)?\s*\{)");

//-- Palavras ignoradas na checagem de camelCase
const std::set<std::string> IGNORED_KEYWORDS = {
    "if", "while", "for", "switch", "catch", "sizeof", "main", "return", "typeid", "dynamic_cast"
};

//-- Função para reportar erros
void report_error(const std::string& file, int line, const std::string& message) {
    std::cout << RED << "[ERRO] " << RESET << file;
    if (line > 0) std::cout << ":" << line;
    std::cout << " -> " << message << "\n";
    g_has_errors = true;
}

//-- Verifica funções proibidas e bibliotecas externas
void check_forbidden(const std::string& line, const std::string& filename, int line_num) {
    std::smatch match;
    if (std::regex_search(line, match, FORBIDDEN_FUNCS)) {
        report_error(filename, line_num, "Função proibida encontrada: '" + match.str(1) + "' (Use iostream/new/delete).");
    }
    if (std::regex_search(line, match, FORBIDDEN_LIBS)) {
        report_error(filename, line_num, "Biblioteca proibida encontrada: Boost.");
    }
}

//-- Verifica se headers possuem Include Guards
void check_include_guards(const fs::path& path) {
    std::ifstream file(path);
    std::string line;
    bool has_ifndef = false;
    bool has_define = false;

    while (std::getline(file, line)) {
        if (line.find("#ifndef") != std::string::npos) has_ifndef = true;
        if (line.find("# define") != std::string::npos) has_define = true;
        if (has_ifndef && has_define) return;
    }
    
    report_error(path.string(), 0, "Include Guards (#ifndef / #define) ausentes ou incorretos.");
}

//-- Checa o conteúdo do arquivo linha por linha
void check_content(const fs::path& path) {
    std::ifstream file(path);
    std::string line;
    int line_num = 0;
    std::smatch match;
    bool is_header = (path.extension() == ".hpp" || path.extension() == ".h");

    if (is_header) {
        check_include_guards(path);
    }

    while (std::getline(file, line)) {
        line_num++;

        check_forbidden(line, path.string(), line_num);

        if (is_header) {
            if (std::regex_search(line, match, HEADER_IMPL_PATTERN)) {
                if (line.find("template") == std::string::npos && 
                    line.find("class") == std::string::npos && 
                    line.find("struct") == std::string::npos) {
                        report_error(path.string(), line_num, 
                        "[AVISO] Possível implementação no .hpp sem ser Template (Mova para .cpp).");
                }
            }
        }

        if (std::regex_search(line, match, CLASS_DEF_PATTERN)) {
            std::string class_name = match[1];
            if (!std::regex_match(class_name, CLASS_PASCAL_CASE)) {
                report_error(path.string(), line_num, 
                    "Classe '" + class_name + "' deveria ser PascalCase (ex: BrickWall).");
            }
        }

        auto begin = std::sregex_iterator(line.begin(), line.end(), METHOD_DEF_PATTERN);
        auto end = std::sregex_iterator();
        for (std::sregex_iterator i = begin; i != end; ++i) {
            std::smatch m = *i;
            std::string func_name = m[1];
            if (IGNORED_KEYWORDS.find(func_name) == IGNORED_KEYWORDS.end()) {
                if (std::islower(func_name[0])) { 
                     if (!std::regex_match(func_name, METHOD_CAMEL_CASE)) {
                        report_error(path.string(), line_num, 
                            "Método '" + func_name + "' deveria ser camelCase (ex: buildWall).");
                    }
                }
            }
        }
    }
}

//-- Verifica se o nome do arquivo segue snake_case
void check_filename(const fs::path& path) {
    std::string filename = path.filename().string();
    if (!std::regex_match(filename, FILE_SNAKE_CASE)) {
        report_error(path.string(), 0, 
            "Nome do arquivo deve ser snake_case (ex: brick_wall.hpp).");
    }
}

int main(int argc, char* argv[]) {
    std::cout << BLUE << "=== INICIANDO LINTER DE QUALIDADE DE CÓDIGO ===" << RESET << "\n";

    if (argc < 2) {
        std::cerr << "Uso: ./linter <diretorio1> [diretorio2] ...\n";
        return 1;
    }

    //-- REQUISITO DE ENTREGA FINAL 
    bool unified_header_found = false;
    for (int i = 1; i < argc; ++i) {
        fs::path p(argv[i]);
        if (fs::exists(p / "libftpp.hpp") || fs::exists(p / "includes/libftpp.hpp")) {
            unified_header_found = true;
        }
    }
    
    if (!unified_header_found && fs::exists("includes/libftpp.hpp")) {
        unified_header_found = true;
    }

    if (!unified_header_found) {
        std::cout << YELLOW << "[AVISO] Header unificado 'libftpp.hpp' não encontrado em includes/. (Necessário para entrega final)" << RESET << "\n";
    }

    // --- EXECUÇÃO DAS CHECAGENS ---
    for (int i = 1; i < argc; ++i) {
        if (!fs::exists(argv[i])) continue;

        for (const auto& entry : fs::recursive_directory_iterator(argv[i])) {
            if (entry.is_regular_file()) {
                std::string ext = entry.path().extension().string();
                if (ext == ".cpp" || ext == ".hpp" || ext == ".h" || ext == ".tpp") {
                    check_filename(entry.path());
                    check_content(entry.path());
                }
            }
        }
    }

    std::cout << "-----------------------------------------------" << "\n";
    if (!g_has_errors) {
        std::cout << GREEN << "✅ SUCESSO! O código segue as diretrizes do projeto." << RESET << "\n";
        return 0;
    } else {
        std::cout << RED << "❌ FALHA! Corrija os erros listados acima antes de entregar." << RESET << "\n";
        return 1;
    }
}