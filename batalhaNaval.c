#include <stdio.h>
#include <stdlib.h>  // Para abs()

#define TAMANHO_TABULEIRO 10
#define TAM_HAB 5

// Desenha o cone 
void desenharCone(int matriz[TAM_HAB][TAM_HAB]) {
  
    int centro = TAM_HAB / 2;

    for(int i=0; i<TAM_HAB; i++) {
        for(int j=0; j<TAM_HAB; j++) {
    
            if(j >= centro - i && j <= centro + i && i <= centro + 1) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Desenha o octaedro com valores 2
void desenharOctaedro(int matriz[TAM_HAB][TAM_HAB]) {
    // Octaedro: losango com valores 2
    int centro = TAM_HAB / 2;

    for(int i=0; i<TAM_HAB; i++) {
        int distancia = abs(centro - i);
        for(int j=0; j<TAM_HAB; j++) {
            // Preenche '2' formando o losango central
            if(j >= distancia && j < TAM_HAB - distancia) {
                matriz[i][j] = 2;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Desenha a cruz com valores 3 no formato cruz
void desenharCruz(int matriz[TAM_HAB][TAM_HAB]) {
    
    int centro = TAM_HAB / 2;

    for(int i=0; i<TAM_HAB; i++) {
        for(int j=0; j<TAM_HAB; j++) {
            if(i == centro || j == centro) {
                matriz[i][j] = 3;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// aplica a "habilidade" no tabuleiro na posição (centro_linha, centro_coluna)
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAM_HAB][TAM_HAB], int centro_linha, int centro_coluna) {
    int offset = TAM_HAB / 2;

    for(int i=0; i<TAM_HAB; i++) {
        for(int j=0; j<TAM_HAB; j++) {
            int linha_tab = centro_linha - offset + i;
            int coluna_tab = centro_coluna - offset + j;

            if(linha_tab >= 0 && linha_tab < TAMANHO_TABULEIRO &&
               coluna_tab >= 0 && coluna_tab < TAMANHO_TABULEIRO &&
               habilidade[i][j] != 0) {
                tabuleiro[linha_tab][coluna_tab] = habilidade[i][j];
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};
    int cone[TAM_HAB][TAM_HAB], cruz[TAM_HAB][TAM_HAB], octaedro[TAM_HAB][TAM_HAB];

    // define a matriz colunas
    char linha[10] = {'A','B','C','D','E','F','G','H','I','J'};

    // Desenha as "habilidades"
    desenharCone(cone);
    desenharCruz(cruz);
    desenharOctaedro(octaedro);

    // Aplica habilidadess
    aplicarHabilidade(tabuleiro, cruz, 2, 3);     
    aplicarHabilidade(tabuleiro, cone, 6, 2);      
    aplicarHabilidade(tabuleiro, octaedro, 4, 7);  

    // Imprime as colunas
    printf("   ");
    for(int i=0; i<TAMANHO_TABULEIRO; i++) {
        printf("%c ", linha[i]);
    }
    printf("\n");

    // Imprime o tabuleiro 
    for(int i=0; i<TAMANHO_TABULEIRO; i++) {
        printf("%d  ", i);
        for(int j=0; j<TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}