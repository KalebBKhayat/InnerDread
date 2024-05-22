#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

// Protótipos das funções
void jogo();
void historia();
void menu();
void tutorial();
void movimento();
void abrirPorta(int y, int x);
void pegarChave();
int checarVitoria(int y, int x);
void desenharMapa();
void moverInimigo();
void segundaFase();
void desenharMapaFase2();
void apertarBotao();
void lerNota();

int contadorNotas;
int contadorFase = 0;
int vida = 3;
int chave1 = 0; // Variável para indicar se o jogador possui a chave 1
int chave2 = 0; // Variável para indicar se o jogador possui a chave 2
int chave3 = 0; // Variável para indicar se o jogador possui a chave 3
int contadorChaves = 0;
char move;
int posicaox = 7;
int posicaoy = 2;
int inimigo_posx = 3; // Posição inicial do inimigo
int inimigo_posy = 7;
int inimigo2_posx; // Posição inicial do inimigo 2 (fora do mapa)
int inimigo2_posy;
int botao;

char mapa3[40][40] = {
	{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', 'D', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '#', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
	{'*', ' ', ' ', '@', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '#', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '#', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*', 'H', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', 'O', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', 'D', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '>', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
	{'*', '#', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '@', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', 'O', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', '*', '*', '*', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', '*'},
	{'*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '*'},
	{'*', '@', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', '*', '*', ' ', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', '*', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', '*', ' ', ' ', '*', ' ', '*', '*', '*', '*', '*', ' ', '*'},
	{'*', ' ', ' ', 'N', ' ', '*', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', '*', ' ', ' ', 'O', ' ', ' ', ' ', '#', ' ', ' ', ' ', '*', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '*', '*', ' ', ' ', '*', ' ', '*', '*', '*', '*', '*', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', '*', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', 'D', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '*'},
	{'*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '#', '#', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', '*', '>', '*', ' ', '*'},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', '*', '*', '*', ' ', '*'},
	{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
};
char mapa2[20][20] = {
	{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
	{'*', 'N', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', '*'},
	{'*', ' ', ' ', '*', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@', '*', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', '*', 'D', '*', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', '*', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', '*', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', '*', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', '*', '*', '*', '*', ' ', '*', '*', ' ', '*', ' ', '*'},
	{'*', ' ', ' ', '*', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', '*', ' ', '*', '*', ' ', '*', ' ', '*'},
	{'*', ' ', ' ', '*', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', '*'},
	{'*', ' ', ' ', '*', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', ' ', '*'},
	{'*', ' ', ' ', '*', ' ', ' ', ' ', ' ', '#', ' ', '@', ' ', 'D', ' ', ' ', ' ', ' ', '*', 'O', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', '@', ' ', '*', '#', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', '*', '#', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'D'},
	{'*', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
	{'*', '*', '*', '*', '*', '*', '*', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}
};

char mapa1[10][10] = {
	{'*', '*', '*', '*', 'D', '*', '*', '*', '*', '*'},
	{'*', ' ', ' ', '*', ' ', '*', ' ', ' ', 'N', '*'},
	{'*', '@', ' ', 'D', ' ', ' ', ' ', ' ', ' ', '*'},
	{'*', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', '*'},
	{'*', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', '*'},
	{'*', '*', '*', '*', ' ', '*', '*', '*', '*', '*'},
	{'*', ' ', ' ', '*', ' ', 'D', ' ', ' ', ' ', '*'},
	{'*', '@', ' ', ' ', ' ', '*', ' ', '@', ' ', '*'},
	{'*', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', '*'},
	{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}
};

int chave1_posy = 7;
int chave1_posx = 1;
int chave2_posy = 2;
int chave2_posx = 1;
int chave3_posy = 7;
int chave3_posx = 7;

void clear() {

}

void movimento() {
	while (1) {
		if (_kbhit()) {
			move = _getch();
			break;
		}
	}
	int portalEntradaY;
	int portalEntradaX;
	int oldPosicaoy = posicaoy;
	int oldPosicaox = posicaox;
	if(contadorFase==0) {
		switch (move) {
			case ('w'):
				if (mapa1[posicaoy - 1][posicaox] == ' ' || mapa1[posicaoy - 1][posicaox] == '=' || mapa1[posicaoy - 1][posicaox] == '@'|| mapa1[posicaoy - 1][posicaox] == 'N') {
					posicaoy--;
				}
				break;

			case ('s'):
				if (mapa1[posicaoy + 1][posicaox] == ' ' || mapa1[posicaoy + 1][posicaox] == '=' || mapa1[posicaoy + 1][posicaox] == '@'|| mapa1[posicaoy + 1][posicaox] == 'N') {
					posicaoy++;
				}
				break;

			case ('a'):
				if (mapa1[posicaoy][posicaox - 1] == ' ' || mapa1[posicaoy][posicaox - 1] == '=' || mapa1[posicaoy][posicaox - 1] == '@'|| mapa1[posicaoy][posicaox - 1] == 'N') {
					posicaox--;
				}
				break;

			case ('d'):
				if (mapa1[posicaoy][posicaox + 1] == ' ' || mapa1[posicaoy][posicaox + 1] == '=' || mapa1[posicaoy][posicaox + 1] == '@'|| mapa1[posicaoy][posicaox + 1] == 'N') {
					posicaox++;
				}
				break;

			case ('i'):
				lerNota();
				apertarBotao();
				pegarChave(); // Chama a função para pegar a chave
				abrirPorta(posicaoy - 1, posicaox); // Tentar abrir a porta acima
				abrirPorta(posicaoy + 1, posicaox); // Tentar abrir a porta abaixo
				abrirPorta(posicaoy, posicaox - 1); // Tentar abrir a porta à esquerda
				abrirPorta(posicaoy, posicaox + 1); // Tentar abrir a porta à direita
				break;
		}

		// Verificar se o jogador alcançou a porta final (linha 0, coluna 4)
		if (checarVitoria(posicaoy, posicaox)) {
			contadorFase++;

		}
	} else if(contadorFase==1) {
		switch (move) {
			case ('w'):
				if (mapa2[posicaoy - 1][posicaox] == ' ' || mapa2[posicaoy - 1][posicaox] == '=' || mapa2[posicaoy - 1][posicaox] == '@'|| mapa2[posicaoy - 1][posicaox] == '#'|| mapa2[posicaoy - 1][posicaox] == 'O'|| mapa2[posicaoy - 1][posicaox] == 'N') {
					posicaoy--;
				}
				break;

			case ('s'):
				if (mapa2[posicaoy + 1][posicaox] == ' ' || mapa2[posicaoy + 1][posicaox] == '=' || mapa2[posicaoy + 1][posicaox] == '@'|| mapa2[posicaoy + 1][posicaox] == '#'|| mapa2[posicaoy + 1][posicaox] == 'O'|| mapa2[posicaoy + 1][posicaox] == 'N') {
					posicaoy++;
				}
				break;

			case ('a'):
				if (mapa2[posicaoy][posicaox - 1] == ' ' || mapa2[posicaoy][posicaox - 1] == '=' || mapa2[posicaoy][posicaox - 1] == '@'|| mapa2[posicaoy][posicaox - 1] == '#'|| mapa2[posicaoy][posicaox - 1] == 'O'|| mapa2[posicaoy][posicaox - 1] == 'N') {
					posicaox--;
				}
				break;

			case ('d'):
				if (mapa2[posicaoy][posicaox + 1] == ' ' || mapa2[posicaoy][posicaox + 1] == '=' || mapa2[posicaoy][posicaox + 1] == '@'|| mapa2[posicaoy][posicaox + 1] == '#'|| mapa2[posicaoy][posicaox + 1] == 'O'|| mapa2[posicaoy][posicaox + 1] == 'N') {
					posicaox++;
				}
				break;

			case ('i'):
				lerNota();
				apertarBotao();
				pegarChave(); // Chama a função para pegar a chave
				abrirPorta(posicaoy - 1, posicaox); // Tentar abrir a porta acima
				abrirPorta(posicaoy + 1, posicaox); // Tentar abrir a porta abaixo
				abrirPorta(posicaoy, posicaox - 1); // Tentar abrir a porta à esquerda
				abrirPorta(posicaoy, posicaox + 1); // Tentar abrir a porta à direita
				break;
		}
		if (mapa2[posicaoy][posicaox] == '#') {
			vida--; // Reduzir o número de vidas
			printf("Voce pisou em uma armadilha...\n");

			if (vida == 0) {
				system("cls");
				printf("Morte...\n");
				system("pause");
				menu();

			} else {
				posicaox = 7;
				posicaoy = 19;
			}
		}
		// Verificar se o jogador alcançou a porta final (linha 0, coluna 4)
		if (checarVitoria(posicaoy, posicaox)) {


		}

		// Move o inimigo 2 em direção ao jogador

		if (posicaox < inimigo2_posx) {
			if(mapa2[inimigo2_posy][inimigo2_posx - 1] == ' ' || mapa2[inimigo2_posy][inimigo2_posx - 1] == '=' || mapa2[inimigo2_posy][inimigo2_posx - 1] == 'O') {
				inimigo2_posx--;
			}

		} else if (posicaox > inimigo2_posx) {
			if(mapa2[inimigo2_posy][inimigo2_posx + 1] == ' ' || mapa2[inimigo2_posy][inimigo2_posx + 1] == '=' || mapa2[inimigo2_posy][inimigo2_posx + 1] == 'O') {
				inimigo2_posx++;
			}

		} else if (posicaoy < inimigo2_posy) {
			if(mapa2[inimigo2_posy - 1][inimigo2_posx] == ' ' || mapa2[inimigo2_posy - 1][inimigo2_posx] == '=' || mapa2[inimigo2_posy - 1][inimigo2_posx] == 'O') {
				inimigo2_posy--;
			}

		} else if (posicaoy > inimigo2_posy) {
			if(mapa2[inimigo2_posy + 1][inimigo2_posx] == ' ' || mapa2[inimigo2_posy + 1][inimigo2_posx] == '=' || mapa2[inimigo2_posy + 1][inimigo2_posx] == 'O') {
				inimigo2_posy++;
			}

		}

	} else if(contadorFase==2) {
		switch (move) {
			case ('w'):
				if (mapa3[posicaoy - 1][posicaox] == ' ' || mapa3[posicaoy - 1][posicaox] == '=' || mapa3[posicaoy - 1][posicaox] == '@'|| mapa3[posicaoy - 1][posicaox] == '#'|| mapa3[posicaoy - 1][posicaox] == 'O'|| mapa3[posicaoy - 1][posicaox] == 'N'|| mapa3[posicaoy - 1][posicaox] == '>'|| mapa3[posicaoy - 1][posicaox] == 'H') {
					posicaoy--;
				}
				break;

			case ('s'):
				if (mapa3[posicaoy + 1][posicaox] == ' ' || mapa3[posicaoy + 1][posicaox] == '=' || mapa3[posicaoy + 1][posicaox] == '@'|| mapa3[posicaoy + 1][posicaox] == '#'|| mapa3[posicaoy + 1][posicaox] == 'O'|| mapa3[posicaoy + 1][posicaox] == 'N'|| mapa3[posicaoy + 1][posicaox] == '>'|| mapa3[posicaoy + 1][posicaox] == 'H') {
					posicaoy++;
				}
				break;

			case ('a'):
				if (mapa3[posicaoy][posicaox - 1] == ' ' || mapa3[posicaoy][posicaox - 1] == '=' || mapa3[posicaoy][posicaox - 1] == '@'|| mapa3[posicaoy][posicaox - 1] == '#'|| mapa3[posicaoy][posicaox - 1] == 'O'|| mapa3[posicaoy][posicaox - 1] == 'N'|| mapa3[posicaoy][posicaox - 1] == '>'|| mapa3[posicaoy][posicaox - 1] == 'H') {
					posicaox--;
				}
				break;

			case ('d'):
				if (mapa3[posicaoy][posicaox + 1] == ' ' || mapa3[posicaoy][posicaox + 1] == '=' || mapa3[posicaoy][posicaox + 1] == '@'|| mapa3[posicaoy][posicaox + 1] == '#'|| mapa3[posicaoy][posicaox + 1] == 'O'|| mapa3[posicaoy][posicaox + 1] == 'N'|| mapa3[posicaoy][posicaox + 1] == '>'|| mapa3[posicaoy][posicaox + 1] == 'H') {
					posicaox++;
				}
				break;

			case ('i'):

				finalSecreto();
				lerNota();
				apertarBotao();
				pegarChave(); // Chama a função para pegar a chave
				abrirPorta(posicaoy - 1, posicaox); // Tentar abrir a porta acima
				abrirPorta(posicaoy + 1, posicaox); // Tentar abrir a porta abaixo
				abrirPorta(posicaoy, posicaox - 1); // Tentar abrir a porta à esquerda
				abrirPorta(posicaoy, posicaox + 1); // Tentar abrir a porta à direita
				break;
		}

		if (mapa3[posicaoy][posicaox] == '>') {
			// Determinar a posição do portal de saída com base na posição atual do jogador
			int portalSaidaY, portalSaidaX;
			if (posicaox == 36 && posicaoy == 37) {
				portalSaidaY = 9;
				portalSaidaX = 17;
			} else if (posicaox == 17 && posicaoy == 10) {
				portalSaidaY = 36;
				portalSaidaX = 36;
			}

			// Teleportar instantaneamente o jogador para a posição do portal de saída
			posicaoy = portalSaidaY;
			posicaox = portalSaidaX;
		}

		if (mapa3[posicaoy][posicaox] == '#') {
			vida--; // Reduzir o número de vidas
			printf("Voce pisou em uma armadilha...\n");

			if (vida == 0) {
				system("cls");
				printf("Morte...\n");
				system("pause");
				menu();
			} else {
				posicaox = 7;
				posicaoy = 19;
			}
		}

		if (checarVitoria(posicaoy, posicaox)) {


		}

		// Move o inimigo 2 em direção ao jogador

		if (posicaox < inimigo2_posx) {
			if(mapa3[inimigo2_posy][inimigo2_posx - 1] == ' ' || mapa3[inimigo2_posy][inimigo2_posx - 1] == '=' || mapa3[inimigo2_posy][inimigo2_posx - 1] == 'O') {
				inimigo2_posx--;
			}

		} else if (posicaox > inimigo2_posx) {
			if(mapa3[inimigo2_posy][inimigo2_posx + 1] == ' ' || mapa3[inimigo2_posy][inimigo2_posx + 1] == '=' || mapa3[inimigo2_posy][inimigo2_posx + 1] == 'O') {
				inimigo2_posx++;
			}

		} else if (posicaoy < inimigo2_posy) {
			if(mapa3[inimigo2_posy - 1][inimigo2_posx] == ' ' || mapa3[inimigo2_posy - 1][inimigo2_posx] == '=' || mapa3[inimigo2_posy - 1][inimigo2_posx] == 'O') {
				inimigo2_posy--;
			}

		} else if (posicaoy > inimigo2_posy) {
			if(mapa3[inimigo2_posy + 1][inimigo2_posx] == ' ' || mapa3[inimigo2_posy + 1][inimigo2_posx] == '=' || mapa3[inimigo2_posy + 1][inimigo2_posx] == 'O') {
				inimigo2_posy++;
			}

		}

	}
	if (posicaoy == inimigo2_posy && posicaox == inimigo2_posx) {
		vida--; // Decrementar a vida
		printf("Você foi pego pelo SeekerCrowl...\n");
		if (vida == 0) {
			system("cls");
			printf("Morte...\n");
			system("pause");
			menu();
		} else if(contadorFase==0) {
			posicaox = 7; // Reinicia o jogador na posição inicial
			posicaoy = 2;
		} else if(contadorFase==1) {
			posicaox = 7;
			posicaoy = 19;
		} else if(contadorFase ==2) {
			posicaox = 0;
			posicaoy = 38;
		}
	}
	// Verificar se o jogador foi pego pelo inimigo
	if (posicaoy == inimigo_posy && posicaox == inimigo_posx) {
		vida--; // Decrementar a vida
		printf("Você foi pego pelo BlindCrowl...\n");
		if (vida == 0) {
			system("cls");
			printf("Morte...\n");
			system("pause");
			menu();
		} else if(contadorFase==0) {
			posicaox = 7; // Reinicia o jogador na posição inicial
			posicaoy = 2;
		} else if(contadorFase==1) {
			posicaox = 7;
			posicaoy = 19;
		} else if(contadorFase==2) {
			posicaox = 0;
			posicaoy = 38;
		}
	}
}

void apertarBotao() {
	if(contadorFase==1) {
		if(mapa2[posicaoy][posicaox] == 'O') {
			if(mapa2[13][18] == '#' && mapa2[12][8] == '#' && mapa2[15][10] == '#') {
				mapa2[13][18] = ' ';
				mapa2[12][8] = ' ';
				mapa2[15][10] =' ';
			}
			botao++;
		}
	} else if(contadorFase==2) {
		if(mapa3[posicaoy][posicaox] == 'O') {
			if(posicaoy == 28 && posicaox == 19) {
				mapa3[37][19] = ' ';
				mapa3[37][20] = ' ';
				mapa3[20][31] =' ';
				mapa3[3][17] = ' ';
				mapa3[28][23] = ' ';
				mapa3[29][23] = ' ';
			} else if(posicaoy == 20 && posicaox == 38) {
				mapa3[1][7] = ' ';
				mapa3[13][1] = ' ';
				mapa3[4][17] = ' ';
			} else if(posicaoy == 7 && posicaox == 17) {
				mapa3[17][17] = ' ';
				mapa3[17][18] = ' ';
				mapa3[17][19] = ' ';
				mapa3[18][17] = ' ';
				mapa3[19][17] = ' ';
				mapa3[19][18] = ' ';
				mapa3[19][19] = ' ';
				mapa3[18][19] = ' ';
				mapa3[5][17] = ' ';
			}
			botao++;

		}

	}

}
void finalSecreto() {
	int esc;
	if(contadorNotas >=3) {
		if(mapa3[posicaoy][posicaox]=='H') {
			system("cls");
			printf("As paredes do hospital pareciam respirar, sussurrando segredos antigos e terriveis. E, no fim, a \npercepcao se arrastou para fora das profundezas do meu ser, uma revelacao que me consumiu \ncompletamente. A identidade que busquei estava la, sempre presente, um fragmento da minha \npropria existencia.\n\nO silencio apos o grito de agonia era absoluto. Eu estava sozinho, mas nunca realmente separado de \nmim mesmo, e no fim, eu era apenas um espectro de uma verdade que sempre existiu, esperando para \nser descoberta.");
			system("pause");
			system("cls");
			printf("Voce descobriu a verdade.\nO que fazer?\n1)Voltar para seu sono e aceitar o destino.\n2)Continuar.\nEscolha:");
			scanf("%d", &esc);
			switch(esc) {
				case 1:
					system("cls");
					printf("No fim, quando a verdade foi desenterrada das profundezas da sua mente fragmentada, Beth \nNo fim, quando a verdade foi desenterrada das profundezas da sua mente fragmentada, Beth \namaldiçoado, ele optou por se isolar, abraçando as sombras e a solidao, ao inves de deixar a praga se \nespalhar para alem das paredes sombrias que o aprisionavam.\n\nNaquele hospital amaldiçoado, Beth La'Dack permaneceu, uma figura solitaria e tragica, sabendo \nque sua existencia era a unica barreira entre a humanidade e o horror indescritivel. Uma escolha feita\nna penumbra, onde o misterio e a escuridao se entrelacavam, e a verdade se tornava um segredo \neterno, protegido por um homem que ja nao era apenas ele mesmo.\n ");
					system("pause");
					printf("\nFinal 2\n");
					system("pause");
					menu();

				case 2:
					system("cls");

			}
		}
	}
}
void lerNota() {
	if(contadorFase==0) {
		if(mapa1[posicaoy][posicaox] == 'N') {

			contadorNotas++;
			system("cls");
			printf("""Encontrei evidencias de uma mutacao singular no paciente numero 27. As caracteristicas observadas\ndivergem significativamente dos padroes conhecidos ate entao. As feridas exsudam um liquido \nviscoso, denso como alcatrao, e apresentam uma estranha semelhanca com penas em decomposicao.\n\nO paciente exibe uma agitacao incomum, acompanhada por acessos de violencia que desafiam\nqualquer explicacao racional. Sua pele adquiriu uma tonalidade acinzentada, os olhos brilhando com\numa intensidade perturbadora.\n\nE imperativo restringir o acesso ao paciente e tomar todas as precaucoes necessarias para evitar \na propagacao de qualquer agente infeccioso que possa estar associado a essa anomalia genetica.\n\nContinuarei monitorando de perto os desenvolvimentos desta condicao incomum, na esperanca de \nobter insights que possam lancar luz sobre sua origem e natureza.\n\n-Ethel\n""");

			system("pause");
			system("cls");
		}
	} else if(contadorFase==1) {
		if(mapa2[posicaoy][posicaox] == 'N') {

			contadorNotas++;
			system("cls");
			printf("""Os sintomas de insanidade entre os pacientes continuam a se manifestar de forma alarmante.\n Observo um declinio gradual em sua sanidade mental, conforme sao assolados por visoes grotescas e irracionais.\n\nAlguns apresentam surtos de violencia inexplicavel, enquanto outros sucumbem a uma apatia profunda\n, perdendo todo contato com a realidade. Os corredores do hospital ecoam com gritos de agonia e desespero, uma cacofonia de almas atormentadas.\n\nNo entanto, uma descoberta intrigante surgiu em minhas observacoes. Ha indicios de que uma unica entidade pode estar conectada a essas perturbacoes.\n Uma sombra que paira nas margens da percepcao, uma presenca sinistra que desafia a compreensao.\n\nSeja qual for sua natureza, parece ter escolhido seus hospedeiros com cuidado, deixando sua marca\n indelével em cada mente fragmentada.\n\nA resposta para este enigma reside nas entranhas deste hospital abandonado, \naguardando aqueles que ousarem buscar a verdade.\n\n-Ethel""");

			system("pause");
			system("cls");
		}
	} else if(contadorFase==2) {
		if(mapa3[posicaoy][posicaox] == 'N') {

			contadorNotas++;
			system("cls");
			printf("Nota de Ethel Dab\n\nOs sintomas se agravam. As alucinacoes sao mais intensas, a dor mais profunda. Os outros ja nao \nsao mais confiaveis, seus olhos denunciam a loucura crescente. Sei que preciso me proteger e \nproteger o trabalho que realizamos.\n\nHoje, tomei a decisao inevitavel. Preciso me internar, nao ha outra escolha. Espero que, ao me isolar, \neu consiga conter a mutacao dentro de mim.\n\nBeth, se voce encontrar esta nota, lembre-se: tudo que fiz foi para nos proteger. Se eu nao conseguir \nvoltar, saiba que a verdade esta no coracao das nossas pesquisas.\n");
			system("pause");
			system("cls");
		}
	}

}

void abrirPorta(int y, int x) {
	if(contadorFase==0) {
		if (mapa1[y][x] == 'D') {
			if ((y == 2 && x == 3 && chave1) || (y == 6 && x == 5 && chave2) || (y == 0 && x == 4 && chave3)) {
				mapa1[y][x] = '='; // Abre a porta
			}
		}
	} else if(contadorFase==1) {
		if (mapa2[y][x] == 'D') {
			if ((y == 5 && x == 7 && chave1) || (y == 12 && x == 12 && chave2) || (y == 17 && x == 19 && chave3)) {
				mapa2[y][x] = '='; // Abre a porta
			}
		}

	} else if(contadorFase==2) {
		if (mapa3[y][x] == 'D') {
			if ((y == 33 && x == 19 && chave1) || (y == 7 && x == 37 && chave2) || (y == 0 && x == 17 && chave3)) {
				mapa3[y][x] = '='; // Abre a porta
			}
		}

	}

}

void pegarChave() {
	if (posicaoy == chave1_posy && posicaox == chave1_posx && chave1 == 0) {
		chave1 = 1;
		contadorChaves++;
	} else if (posicaoy == chave2_posy && posicaox == chave2_posx && chave2 == 0) {
		chave2 = 1;
		contadorChaves++;
	} else if (posicaoy == chave3_posy && posicaox == chave3_posx && chave3 == 0) {
		chave3 = 1;
		contadorChaves++;

	}
}

int checarVitoria(int y, int x) {
	if(contadorFase==0) {
		return (y == 0 && x == 4); // Retorna verdadeiro se o jogador alcançou a porta final
	}

}

void desenharMapa() {
	int i = 0;
	int j = 0;

	for ( i = 0; i < 10; i++) {
		for ( j = 0; j < 10; j++) {
			if(mapa1[i][j]== '=' && chave1==0) {
				mapa1[i][j]= 'D';
			}
			if (i == posicaoy && j == posicaox) {
				printf(" & ");
			} else if (i == inimigo_posy && j == inimigo_posx) {
				printf(" X ");
			} else if (i == chave1_posy && j == chave1_posx && chave1) {
				printf("   "); // Chave coletada, não imprime nada
			} else if (i == chave2_posy && j == chave2_posx && chave2) {
				printf("   "); // Chave coletada, não imprime nada
			} else if (i == chave3_posy && j == chave3_posx && chave3) {
				printf("   "); // Chave coletada, não imprime nada
			} else {
				printf(" %c ", mapa1[i][j]);

			}
		}
		printf("\n");
	}
}

void desenharMapaFase2() {
	int i;
	int j;

	for ( i = 0; i < 20; i++) {
		for ( j = 0; j < 20; j++) {
			if(mapa2[i][j]== '=' && chave1==0) {
				mapa2[i][j]= 'D';
			}
			if(mapa2[13][18] == ' ' && mapa2[12][8] == ' ' && mapa2[15][10] == ' ' && botao==0) {
				mapa2[13][18] = '#' ;
				mapa2[12][8] = '#' ;
				mapa2[15][10] = '#';
			}
			if (i == posicaoy && j == posicaox) {
				printf(" & ");
			} else if (i == inimigo_posy && j == inimigo_posx) {
				printf(" X ");
			} else if(i == inimigo2_posy && j == inimigo2_posx) {
				printf(" V ");
			} else if (i == chave1_posy && j == chave1_posx && chave1) {
				printf("   "); // Chave coletada, não imprime nada
			} else if (i == chave2_posy && j == chave2_posx && chave2) {
				printf("   "); // Chave coletada, não imprime nada
			} else if (i == chave3_posy && j == chave3_posx && chave3) {
				printf("   "); // Chave coletada, não imprime nada
			} else {
				printf(" %c ", mapa2[i][j]);
			}
		}
		printf("\n");
	}
}

void desenharMapaFase3() {
	int i;
	int j;

	for ( i = 0; i < 40; i++) {
		for ( j = 0; j < 40; j++) {
			if(mapa3[i][j]== '='  && chave1==0) {
				mapa3[i][j]= 'D';
			}
			if (i == posicaoy && j == posicaox) {
				printf(" & ");
			} else if (i == inimigo_posy && j == inimigo_posx) {
				printf(" X ");
			} else if(i == inimigo2_posy && j == inimigo2_posx) {
				printf(" V ");
			} else if (i == chave1_posy && j == chave1_posx && chave1 == 1) {
				printf("   "); // Chave coletada, não imprime nada
			} else if (i == chave2_posy && j == chave2_posx && chave2 == 1) {
				printf("   "); // Chave coletada, não imprime nada
			} else if (i == chave3_posy && j == chave3_posx && chave3 == 1) {
				printf("   "); // Chave coletada, não imprime nada
			} else if (i == chave1_posy && j == chave1_posx && chave1 == 0) {
				printf(" @ ");
			} else if (i == chave2_posy && j == chave2_posx && chave2 == 0) {
				printf(" @ ");
			} else if (i == chave3_posy && j == chave3_posx && chave3 == 0) {
				printf(" @ ");
			} else {
				printf(" %c ", mapa3[i][j]);
			}
		}
		printf("\n");
	}
}



void moverInimigo() {
	// Movimento aleatório do inimigo
	srand(time(NULL));
	int movimento = rand() % 4;
	if(contadorFase==0) {
		switch (movimento) {
			case 0: // Movimento para cima
				if (mapa1[inimigo_posy - 1][inimigo_posx] == ' ') {
					inimigo_posy--;
				}
				break;

			case 1: // Movimento para baixo
				if (mapa1[inimigo_posy + 1][inimigo_posx] == ' ') {
					inimigo_posy++;
				}
				break;

			case 2: // Movimento para esquerda
				if (mapa1[inimigo_posy][inimigo_posx - 1] == ' ') {
					inimigo_posx--;
				}
				break;

			case 3: // Movimento para direita
				if (mapa1[inimigo_posy][inimigo_posx + 1] == ' ') {
					inimigo_posx++;
				}
				break;
		}
	} else if(contadorFase==1) {
		switch (movimento) {
			case 0: // Movimento para cima
				if (mapa2[inimigo_posy - 1][inimigo_posx] == ' ') {
					inimigo_posy--;
				}
				break;

			case 1: // Movimento para baixo
				if (mapa2[inimigo_posy + 1][inimigo_posx] == ' ') {
					inimigo_posy++;
				}
				break;

			case 2: // Movimento para esquerda
				if (mapa2[inimigo_posy][inimigo_posx - 1] == ' ') {
					inimigo_posx--;
				}
				break;

			case 3: // Movimento para direita
				if (mapa2[inimigo_posy][inimigo_posx + 1] == ' ') {
					inimigo_posx++;
				}
				break;
		}
	} else if (contadorFase ==2) {
		switch (movimento) {
			case 0: // Movimento para cima
				if (mapa3[inimigo_posy - 1][inimigo_posx] == ' ') {
					inimigo_posy--;
				}
				break;

			case 1: // Movimento para baixo
				if (mapa3[inimigo_posy + 1][inimigo_posx] == ' ') {
					inimigo_posy++;
				}
				break;

			case 2: // Movimento para esquerda
				if (mapa3[inimigo_posy][inimigo_posx - 1] == ' ') {
					inimigo_posx--;
				}
				break;

			case 3: // Movimento para direita
				if (mapa3[inimigo_posy][inimigo_posx + 1] == ' ') {
					inimigo_posx++;
				}
				break;
		}
	}
}

void jogo() {
	system("cls");
	printf("Um grito dilacerante corta o ar, penetrando minha mente como uma adaga de gelo.\n");
	system("pause");
	system("cls");
	printf("Meu corpo tenso se contrai em resposta, os musculos retesados como cordas de violino prestes a se romper.\n");
	system("pause");
	system("cls");
	printf("""O que e isso?""\n");
	system("pause");
	system("cls");
	int chave1 = 0; // Variável para indicar se o jogador possui a chave 1
	int chave2 = 0; // Variável para indicar se o jogador possui a chave 2
	int chave3 = 0; // Variável para indicar se o jogador possui a chave 3
	char move;
	int posicaox = 7;
	int posicaoy = 2;
	int inimigo_posx = 3; // Posição inicial do inimigo
	int inimigo_posy = 7;
	while (vida != 0) {
		while (contadorFase==0) {

			system("cls");
			desenharMapa();

			printf("Chaves coletadas: %d\n", contadorChaves);
			printf("Vidas restantes: %d\n", vida);
			printf("Fase Atual: Escritorio do Diretor (%d)", contadorFase + 1);

			movimento();
			moverInimigo(); // Movimentar o inimigo

			if (posicaoy == 0 && posicaox == 4) {
				contadorFase++;

			}

		}
		if (contadorFase==1) {
			system("cls");
			printf("Entrando na Ala medica...\n");
			system("pause");
			system("cls");
			printf("Tudo trancado...\n");
			system("pause");
			system("cls");
			printf("Lembro de um botao que usavamos para destrancar...\n");
			system("pause");
			system("cls");
			while(contadorFase==1) {
				system("cls");
				segundaFase();
			}
		}

	}
}

void segundaFase() {
	chave1_posy = 12;
	chave1_posx = 10;
	chave2_posy = 4;
	chave2_posx = 16;
	chave3_posy = 13;
	chave3_posx = 15;
	contadorChaves = 0;
	posicaox = 7;
	posicaoy = 19;
	inimigo_posx = 10; // Posição inicial do inimigo
	inimigo_posy = 10;
	inimigo2_posx = 18;
	inimigo2_posy = 14;
	chave1 = 0; // Variável para indicar se o jogador possui a chave 1
	chave2 = 0; // Variável para indicar se o jogador possui a chave 2
	chave3 = 0;
	while (contadorFase== 1) {
		system("cls");
		desenharMapaFase2(mapa2, 20, 20, posicaoy, posicaox, vida); // Desenha o mapa da segunda fase com o personagem e a contagem de vidas
		printf("Chaves coletadas: %d\n", contadorChaves);
		printf("Vidas restantes: %d\n", vida);
		printf("Fase Atual: Ala medica (%d)", contadorFase + 1);
		movimento();
		moverInimigo(); // Movimento do inimigo
		if (posicaoy == 17 && posicaox == 19) {

			contadorFase++;
		}

	}
	if(contadorFase==2) {
		system("cls");
		printf("Entrando nas salas de cirurgia...\n");
		system("pause");
		system("cls");
		printf("Por aqui deve ser a saida...\n");
		system("pause");
		system("cls");
		printf("Sei de uma passagem construida na planta do hospital...\n");
		system("pause");
		system("cls");
		terceiraFase();
	}
}

void terceiraFase() {
	inimigo2_posy == 38;
	inimigo2_posx == 19;
	chave1_posy = 24;
	chave1_posx = 1;
	chave2_posy = 4;
	chave2_posx = 3;
	chave3_posy = 18;
	chave3_posx = 18;
	contadorChaves = 0;
	posicaox = 0;
	posicaoy = 38;
	inimigo_posx = 1; // Posição inicial do inimigo
	inimigo_posy = 35;
	inimigo2_posx = 19;
	inimigo2_posy = 38;
	chave1 = 0; // Variável para indicar se o jogador possui a chave 1
	chave2 = 0; // Variável para indicar se o jogador possui a chave 2
	chave3 = 0;
	while (contadorFase== 2) {
		system("cls");
		desenharMapaFase3(mapa3, 40, 40, posicaoy, posicaox, vida); // Desenha o mapa da segunda fase com o personagem e a contagem de vidas
		printf("Chaves coletadas: %d\n", contadorChaves);
		printf("Vidas restantes: %d\n", vida);
		printf("Fase Atual: Ala medica (%d)", contadorFase + 1);
		movimento();
		moverInimigo(); // Movimento do inimigo
		if (posicaoy == 0 && posicaox == 17) {
			contadorFase++;
		}
	}
	if(contadorFase==3) {

		system("cls");
		printf("Ele saiu da sua prisao...\n");
		system("pause");
		system("cls");
		printf("Justo quando todos pensavam que tinha acabado...\n");
		system("pause");
		system("cls");
		printf("A praga se propaga mais uma vez.\n");
		system("pause");
		system("cls");
		printf("Final 1.\n");
		system("pause");
		system("cls");
		menu();
	}
}


void historia() {
	system("cls");
	printf("No silencio noturno, onde as estrelas se escondem e as trevas se agitam como um manto tetrico, \nergue-se um hospicio, uma sentinela solitaria no coracao da escuridao. E um lugar esquecido pelo\ntempo, onde as paredes sao manchadas com os lamentos dos perdidos e os corredores ecoam com \nsuspiros sussurrantes dos condenados.\n\nNos confins deste hospital macabro, onde as sombras se enroscam como serpentes famintas, desperta \nBeth La'Dack, um nome que ecoa na escuridao como um sussurro de tempestade. Perdido em um \nlabirinto de pesadelos, Beth busca desesperadamente por seu parceiro, Ethal Dab, um pesquisador \ncujos motivos sinistros o levaram a esse lugar de tortura e desespero. No entanto, as intencoes de Ethal \nDab permanecem envoltas em misterio, ocultas nas sombras que dancam ao redor de Beth como \nespectros ameacadores.\n\nAo redor, os corredores retorcidos se estendem como veias negras, pulsando com uma vida sinistra \nque se esconde nas profundezas. E o reino dos ""Rottencrowls"", criaturas sombrias e grotescas que se\ncontorcem nas sombras, suas feridas exsudando uma substancia viscosa que se assemelha a penas \nnegras. Seus olhos vazios brilham com a fome insaciavel da escuridao, suas vozes sussurram segredos \nantigos que fazem o sangue gelar nas veias dos vivos.\n\nCada passo de Beth e um mergulho mais profundo na escuridao, cada sombra uma promessa de perigo\ne misterio. Ele busca respostas nos recantos mais sombrios do hospicio, onde os segredos do passado\nse escondem atras de portas trancadas e corredores sem fim.\n");
	system("pause");
	tutorial();
}

void menu() {
	chave1_posy = 7;
	chave1_posx = 1;
	chave2_posy = 2;
	chave2_posx = 1;
	chave3_posy = 7;
	chave3_posx = 7;
	vida = 3;
	contadorFase = 0;
	contadorChaves = 0;
	chave1 = chave2 = chave3 = 0;
	posicaox = 7;
	posicaoy = 2;
	inimigo_posx = 3;
	inimigo_posy = 7;
	inimigo2_posx = inimigo2_posy = -1;
	system("cls");
	int escolha;
	printf("Inner Dread\n1) Iniciar\n2) Documentos(Tutorial/Historia)\n3) Sair\nEscolha: ");
	scanf("%d", &escolha);

	switch (escolha) {
		case 1:
			system("cls");
			jogo();
			break;

		case 2:
			system("cls");
			tutorial();
			break;

		case 3:
			printf("Saindo do jogo...\n");
			exit(0);
			break;

		default:
			printf("Opcao invalida!\n");
			menu();
	}
}

void tutorial() {
	system("cls");
	int escolha;
	printf("1)Regras da instituicao (Tutorial)\n2)Memorias(Historia) \n3) Voltar\nEscolha: ");
	scanf("%d", &escolha);

	switch (escolha) {
		case 1:
			system("cls");
			printf("Introducao:\nBem-vindo ao Sanatorio de Whisperwyck. Nesta Instituicao voce devera seguir algumas regras(caso queira sobreviver), voce aprendera como se portar e se familiarizara com a rotina e objetivos dos exames.\n\nControles:\nUse as teclas W, A, S e D para mover o personagem para cima, esquerda, baixo e direita, respectivamente.\nPressione a tecla I para interagir com objetos, como chaves e botoes.\n\nElementos do Jogo:\nPersonagem (&): Voce. Se controle pelas salas do Sanatorio em busca da saida ou algo parecido.\nRottenCrowls (X) e (V): Eles patrulham o Sanatorio.Sombras do que um dia ja foram. Evite-os para nao perder sua vida.\nPortas (D): Alguns caminhos estarao bloqueados por portas. Para abri-las, voce precisa ter a chave correspondente.\nChaves(@): Sao essenciais para abrir as portas. Colete-as ao longo do caminho.\nBotoes (O): Alguns botoes podem abrir portas especiais, mas voce precisa descobri-los primeiro.\nNotas (N): Documentos deixados para tras...podem conter pistas do seu passado\n");
			system("pause");
			tutorial();
			break;

		case 2:
			system("cls");
			historia();
			break;

		case 3:
			system("cls");
			menu();
			break;

		default:
			printf("Opcao invalida!\n");
			tutorial();
	}
}
int main() {
	menu();
	return 0;
}
