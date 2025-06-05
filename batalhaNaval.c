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
