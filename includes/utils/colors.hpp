#ifndef COLORS_HPP
# define COLORS_HPP

// Cores
# define RST	"\033[0m"					/* Reset to default color */
# define RED	"\033[1;31m"				/* Bold Red */
# define G		"\033[1;32m"				/* Bold Green */
# define Y		"\033[1;33m"				/* Bold Yellow */
# define B		"\033[1;34m"				/* Bold Blue */
# define M		"\033[1;35m"				/* Bold Magenta */
# define C		"\033[1;36m"				/* Bold Cyan */
# define W		"\033[1;37m"				/* Bold White */
# define O		"\001\033[38;5;208m\002"	/* Orange */

// Cores em negrito
#define BRED	"\033[1;31m"				// Vermelho em negrito
#define BGRN	"\033[1;32m"				// Verde em negrito
#define BYEL	"\033[1;33m"				// Amarelo em negrito
#define BBLU	"\033[1;34m"				// Azul em negrito
#define BMAG	"\033[1;35m"				// Magenta em negrito
#define BCYN	"\033[1;36m"				// Ciano em negrito
#define BWHT	"\033[1;37m"				// Branco em negrito

// Fundo colorido
#define BGBLK	"\033[40m"					// Fundo Preto
#define BGRED	"\033[41m"					// Fundo Vermelho
#define BGGRN	"\033[42m"					// Fundo Verde
#define BGYEL	"\033[43m"					// Fundo Amarelo
#define BGBLU	"\033[44m"					// Fundo Azul
#define BGMAG	"\033[45m"					// Fundo Magenta
#define BGCYN	"\033[46m"					// Fundo Ciano
#define BGWHT	"\033[47m"					// Fundo Branco

// Fundo brilhante (claro)
#define BGBRED	"\033[101m"					// Fundo Vermelho Claro
#define BGBGRN	"\033[102m"					// Fundo Verde Claro
#define BGBYEL	"\033[103m"					// Fundo Amarelo Claro
#define BGBBLU	"\033[104m"					// Fundo Azul Claro
#define BGBMAG	"\033[105m"					// Fundo Magenta Claro
#define BGBCYN	"\033[106m"					// Fundo Ciano Claro
#define BGBWHT	"\033[107m"					// Fundo Branco Claro

// Estilos adicionais
#define BOLD	"\033[1m"					// Negrito
#define UNDL	"\033[4m"					// Sublinhado
#define BLNK	"\033[5m"					// Piscando
#define REV		"\033[7m"					// Invertido (fundo e texto)
#define HIDDEN	"\033[8m"					// Texto oculto

// Emojis comuns
#define GRINNING	"\U0001F600"				// 😀 - Rosto sorridente
#define SMILING		"\U0001F642"				// 🙂 - Sorriso leve
#define LAUGHING	"\U0001F606"				// 😆 - Rindo muito
#define WINK		"\U0001F609"				// 😉 - Piscando
#define COOL		"\U0001F60E"				// 😎 - Com óculos escuros
#define THINKING	"\U0001F914"				// 🤔 - Pensando
#define SLEEPING	"\U0001F634"				// 😴 - Emoji de rosto dormindo
#define WAVE		"\U0001F44B"				// 👋 - Emoji de mão acenando (dando tchau)
#define CLAP		"\U0001F44F"				// 👏 - Aplausos
#define OK_HAND		"\U0001F44C"				// 👌 - Mão "OK"
#define CRYING		"\U0001F622"				// 😢 - Chorando
#define ANGRY		"\U0001F620"				// 😠 - Com raiva

// Emojis de animais
#define CAT_FACE	"\U0001F431"			// 🐱 - Rosto de gato
#define DOG_FACE	"\U0001F436"			// 🐶 - Rosto de cachorro
#define MOUSE_FACE	"\U0001F42D"			// 🐭 - Rosto de rato
#define PANDA_FACE	"\U0001F43C"			// 🐼 - Rosto de panda
#define KOALA		"\U0001F428"			// 🐨 - Koala
#define MONKEY_FACE	"\U0001F435"			// 🐵 - Rosto de macaco
#define TIGER_FACE	"\U0001F42F"			// 🐯 - Rosto de tigre
#define ROSE		"\U0001F339"			// 🌹 - Rosa
#define SUNFLOWER	"\U0001F33B"			// 🌻 - Girassol
#define CACTUS		"\U0001F335"			// 🌵 - Cacto

// Emojis de comida e bebida
#define PIZZA		"\U0001F355"			// 🍕 - Pizza
#define BURGER		"\U0001F354"			// 🍔 - Hambúrguer
#define TACO		"\U0001F32E"			// 🌮 - Taco
#define ICE_CREAM	"\U0001F368"			// 🍨 - Sorvete
#define CAKE		"\U0001F370"			// 🍰 - Bolo
#define COFFEE		"\U00002615"			// ☕ - Café
#define BEER		"\U0001F37A"			// 🍺 - Cerveja
#define WINE		"\U0001F377"			// 🍷 - Taça de vinho
#define APPLE		"\U0001F34E"			// 🍎 - Maçã
#define BANANA		"\U0001F34C"			// 🍌 - Banana

// Emojis de esportes
#define SOCCER		"\U000026BD"			// ⚽ - Bola de futebol
#define BASKETBALL	"\U0001F3C0"			// 🏀 - Bola de basquete
#define BASEBALL	"\U000026BE"			// ⚾ - Bola de beisebol
#define TENNIS		"\U0001F3BE"			// 🎾 - Bola de tênis
#define TROPHY		"\U0001F3C6"			// 🏆 - Troféu
#define MEDAL		"\U0001F3C5"			// 🏅 - Medalha
#define RUNNER		"\U0001F3C3"			// 🏃 - Corredor
#define SWIMMER		"\U0001F3CA"			// 🏊 - Nadador
#define DANCER		"\U0001F483"			// 💃 - Dançarina
#define GUITAR		"\U0001F3B8"			// 🎸 - Guitarra

#endif // ! COLORS_HPP