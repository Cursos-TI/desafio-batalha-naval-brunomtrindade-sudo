#include <stdio.h>

#define TABULEIRO 10
#define TAMANHOHABILIDADE 5
#define TAMANHONAVIO 3
#define NAVIO 3
#define HABILIDADE 5
#define AGUA 0

int main() {

    // Parâmetros do tabuleiro:
    int tabuleiro[TABULEIRO][TABULEIRO];

    for (int i = 0; i < TABULEIRO; i++) {
        for (int j = 0; j < TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Navio horizontal:
    int linhaH = 1;
    int colunaH = 3;

    for (int i = 0; i < TAMANHONAVIO; i++) {

        if (colunaH + i < TABULEIRO) {

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
    int colunaD1 = 1;

    for (int i = 0; i < TAMANHONAVIO; i++) {

        if ((linhaD1 + i < TABULEIRO) &&
            (colunaD1 + i < TABULEIRO)) {

            if (tabuleiro[linhaD1 + i][colunaD1 + i] == AGUA) {
                tabuleiro[linhaD1 + i][colunaD1 + i] = NAVIO;
            }
        }
    }

    // Navio diagonal 2:
    int linhaD2 = 6;
    int colunaD2 = 8;

    for (int i = 0; i < TAMANHONAVIO; i++) {

        if ((linhaD2 + i < TABULEIRO) &&
            (colunaD2 - i >= 0)) {

            if (tabuleiro[linhaD2 + i][colunaD2 - i] == AGUA) {
                tabuleiro[linhaD2 + i][colunaD2 - i] = NAVIO;
            }
        }
    }

    //Matrizes de habilidades:

    int cone[TAMANHOHABILIDADE][TAMANHOHABILIDADE];
    int cruz[TAMANHOHABILIDADE][TAMANHOHABILIDADE];
    int octaedro[TAMANHOHABILIDADE][TAMANHOHABILIDADE];

    for (int i = 0; i < TAMANHOHABILIDADE; i++) {
        for (int j = 0; j < TAMANHOHABILIDADE; j++) {

            cone[i][j] = 0;
            cruz[i][j] = 0;
            octaedro[i][j] = 0;
        }
    }

    //Habilidade de cone:

    for (int i = 0; i < TAMANHOHABILIDADE; i++) {

        for (int j = 0; j < TAMANHOHABILIDADE; j++) {
            if (j >= 2 - i && j <= 2 + i) {

                if (i <= 2) {
                    cone[i][j] = 1;
                }
            }
        }
    }

    //Habilidade de cruz:
    for (int i = 0; i < TAMANHOHABILIDADE; i++) {

        for (int j = 0; j < TAMANHOHABILIDADE; j++) {

            // Linha central e coluna central
            if (i == 2 || j == 2) {
                cruz[i][j] = 1;
            }
        }
    }

    //Habilidade de octaedro:
    for (int i = 0; i < TAMANHOHABILIDADE; i++) {

        for (int j = 0; j < TAMANHOHABILIDADE; j++) {

            // Distância do centro
            if ((i - 2 >= 0 ? i - 2 : 2 - i) +
                (j - 2 >= 0 ? j - 2 : 2 - j) <= 2) {

                octaedro[i][j] = 1;
            }
        }
    }

    // Posições de origem das habilidades:

    int origemConeLinha = 2;
    int origemConeColuna = 7;

    int origemCruzLinha = 7;
    int origemCruzColuna = 2;

    int origemOctaedroLinha = 7;
    int origemOctaedroColuna = 7;

    // Sobreposição cone:

    for (int i = 0; i < TAMANHOHABILIDADE; i++) {

        for (int j = 0; j < TAMANHOHABILIDADE; j++) {

            int linhaTabuleiro = origemConeLinha + i - 2;
            int colunaTabuleiro = origemConeColuna + j - 2;

            if (linhaTabuleiro >= 0 &&
                linhaTabuleiro < TABULEIRO &&
                colunaTabuleiro >= 0 &&
                colunaTabuleiro < TABULEIRO) {

                if (cone[i][j] == 1 &&
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] == AGUA) {

                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = HABILIDADE;
                }
            }
        }
    }

    // Sobreposição cruz:

    for (int i = 0; i < TAMANHOHABILIDADE; i++) {

        for (int j = 0; j < TAMANHOHABILIDADE; j++) {

            int linhaTabuleiro = origemCruzLinha + i - 2;
            int colunaTabuleiro = origemCruzColuna + j - 2;

            if (linhaTabuleiro >= 0 &&
                linhaTabuleiro < TABULEIRO &&
                colunaTabuleiro >= 0 &&
                colunaTabuleiro < TABULEIRO) {

                if (cruz[i][j] == 1 &&
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] == AGUA) {

                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = HABILIDADE;
                }
            }
        }
    }

    // Sobreposição octaedro:

    for (int i = 0; i < TAMANHOHABILIDADE; i++) {
        for (int j = 0; j < TAMANHOHABILIDADE; j++) {

            int linhaTabuleiro = origemOctaedroLinha + i - 2;
            int colunaTabuleiro = origemOctaedroColuna + j - 2;

            if (linhaTabuleiro >= 0 &&
                linhaTabuleiro < TABULEIRO &&
                colunaTabuleiro >= 0 &&
                colunaTabuleiro < TABULEIRO) {

                if (octaedro[i][j] == 1 &&
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] == AGUA) {

                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = HABILIDADE;
                }
            }
        }
    }

    // Exibição do tabuleiro:
    printf("TABULEIRO BATALHA NAVAL\n\n");

    for (int i = 0; i < TABULEIRO; i++) {

        for (int j = 0; j < TABULEIRO; j++) {

            if (tabuleiro[i][j] == AGUA) {
                printf("0 ");
            }

            else if (tabuleiro[i][j] == NAVIO) {
                printf("3 ");
            }

            else if (tabuleiro[i][j] == HABILIDADE) {
                printf("5 ");
            }
        }

        printf("\n");
    }

    return 0;
}
