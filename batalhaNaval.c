#include <stdio.h>

#define TABULEIRO 10
#define TAMANHONAVIO 3
#define NAVIO 3
#define AGUA 0

int main() {

    // Parâmetros do tabuliero:
    int tabuleiro[TABULEIRO][TABULEIRO];

    for (int i = 0; i < TABULEIRO; i++) {
        for (int j = 0; j < TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Navios posicionados.

    // Navio horizontal:
    int linhaH = 1;
    int colunaH = 3;

    for (int i = 0; i < TAMANHONAVIO; i++) {

        // Verificação do limite do tabuleiro:
        if (colunaH + i < TABULEIRO) {

            // Verificação de sobreposição:
            if (tabuleiro[linhaH][colunaH + i] == AGUA) {
                tabuleiro[linhaH][colunaH + i] = NAVIO;
            }
        }
    }

    // Navio vertical:

    int linhaV = 5;
    int colunaV = 5;

    for (int i = 0; i < TAMANHONAVIO; i++) {

        if (linhaV + i < TABULEIRO) {

            if (tabuleiro[linhaV + i][colunaV] == AGUA) {
                tabuleiro[linhaV + i][colunaV] = NAVIO;
            }
        }
    }

    // Navio diagonal 1:
    int linhaD1 = 3;
    int colunaD1 = 5;

    for (int i = 0; i < TAMANHONAVIO; i++) {

        if ((linhaD1 + i < TABULEIRO) && (colunaD1 + i < TABULEIRO)) {

            if (tabuleiro[linhaD1 + i][colunaD1 + i] == AGUA) {
                tabuleiro[linhaD1 + i][colunaD1 + i] = NAVIO;
            }
        }
    }

    // Navio diagonal 2:
    int linhaD2 = 6;
    int colunaD2 = 3;

    for (int i = 0; i < TAMANHONAVIO; i++) {

        if ((linhaD2 + i < TABULEIRO) && (colunaD2 - i >= 0)) {

            if (tabuleiro[linhaD2 + i][colunaD2 - i] == AGUA) {
                tabuleiro[linhaD2 + i][colunaD2 - i] = NAVIO;
            }
        }
    }

    // Exibição do tabuleiro:
    printf("TABULEIRO BATALHA NAVAL\n\n");

    for (int i = 0; i < TABULEIRO; i++) {

        for (int j = 0; j < TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }

        printf("\n");
    }

    return 0;
}
