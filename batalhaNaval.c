#include <stdio.h>

int main() {
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10];

    // Inicializa tabuleiro com zeros
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Declara navios e suas posições
    int navioH[3] = {3, 3, 3}; // Navio horizontal
    int navioV[3] = {3, 3, 3}; // Navio vertical

    // Coordenadas
    int linhaH = 1; // linha B
    int colunaH = 2; // começa na coluna 2

    int linhaV = 4; // linha E
    int colunaV = 5; // começa na coluna 5

    // Posiciona navio horizontal no tabuleiro
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = navioH[i];
    }

    // Posiciona navio vertical no tabuleiro
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = navioV[i];
    }

      // insere o navio 1 da diagonal

    int linhaD1 = 0; // começa na linha A
    int colunaD1 = 0; // começa na coluna 0

    // verifica se está dentro do tabuleiro e sem sobrepor outro antes de posicionar
    if (linhaD1 + 2 < 10 && colunaD1 + 2 < 10) {
        if (tabuleiro[linhaD1][colunaD1] == 0 &&
            tabuleiro[linhaD1 + 1][colunaD1 + 1] == 0 &&
            tabuleiro[linhaD1 + 2][colunaD1 + 2] == 0) {
            
            for (int i = 0; i < 3; i++) {
                tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
            }
        }
    }

    // insere o navio 2 da diagonal
    int linhaD2 = 0; // linha A
    int colunaD2 = 9; //  coluna 9

    // verifica se está dentro do tabuleiro e sem sobrepor antes de posicionar
    if (linhaD2 + 2 < 10 && colunaD2 - 2 >= 0) {
        if (tabuleiro[linhaD2][colunaD2] == 0 &&
            tabuleiro[linhaD2 + 1][colunaD2 - 1] == 0 &&
            tabuleiro[linhaD2 + 2][colunaD2 - 2] == 0) {
            
            for (int i = 0; i < 3; i++) {
                tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
            }
        }
    }

    // Imprime o cabeçalho das colunas
    printf("   ");
    for (int j = 0; j < 10; j++) {
        printf("%d ", j);
    }
    printf("\n");

    // Imprime o tabuleiro com letras das linhas
    for (int i = 0; i < 10; i++) {
        printf("%c  ", linha[i]);
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
