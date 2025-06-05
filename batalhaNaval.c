#include <stdio.h>

int main() {
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10];

    // definindo todas as posições do tabuleiro com 0
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Imprime o cabeçalho das colunas
    printf("   "); // Espaço pro alinhamento das letras
    for (int j = 0; j < 10; j++) {
        printf("%d ", j);
    }
    printf("\n");

    // Imprime o tabuleiro com as letras das linhas
    for (int i = 0; i < 10; i++) {
        printf("%c  ", linha[i]); // Letra da linha 
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
