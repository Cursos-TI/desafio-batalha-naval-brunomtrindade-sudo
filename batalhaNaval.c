#include <stdio.h>
    int main() {
        //Casas do tabuleiro com apenas 2 navios em uma matriz 10x10, representados pelo número 3
        //O restante do tabuleiro é representado por 0, indicando água:
        int index;
        char * tabuleiro[10][10] = {
         {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
         {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
         {"0", "0", "3", "3", "3", "0", "0", "0", "0", "0"},
         {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
         {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
         {"0", "3", "0", "0", "0", "0", "0", "0", "0", "0"},
         {"0", "3", "0", "0", "0", "0", "0", "0", "0", "0"},
         {"0", "3", "0", "0", "0", "0", "0", "0", "0", "0"},
         {"0", "3", "0", "0", "0", "0", "0", "0", "0", "0"},
         {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"}
        };
           
            printf("Aqui está o tabuleiro inicial:\n");
            for (index = 0; index < 10; index++) {
                for (int j = 0; j < 10; j++) {
                    printf("%s ", tabuleiro[index][j]);
                 }
                printf("\n");
            }


        return 0;
    }
