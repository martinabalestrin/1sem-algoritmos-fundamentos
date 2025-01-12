#include <stdio.h>
#include <stdlib.h>

/* Crie uma matriz de caracteres com dimensões definidas pelo usuário em tempo de execução. Cada elemento da
matriz deve ser inicializado com um espaço em branco. O programa deve garantir que as dimensões informadas
sejam números inteiros entre 3 e 9, e não deve prosseguir enquanto não forem informados valores válidos. Em
seguida, atualize a(s) linha(s) e coluna(s) central(is) da matriz com caracteres “x”, e imprima a matriz na tela utilizando
o caractere “pipe” (barra) para delimitar as colunas. */

void imprimirMatriz(int dim) {

    int asterisco = (dim/2);

    for(int i = 0; i < dim; i++) {

        for(int j = 0; j < dim; j++) {

            if(asterisco == j || asterisco == i) {
                printf("x|");
            }
            else {
                printf(" |");
            }
        }

        printf("\n");
    }
}

int main() {

    int dimensao = 1;

    while(dimensao %2 == 0 || dimensao < 3 || dimensao > 9) {
        printf("Tamanho da matriz: ");
        scanf("%d", &dimensao);

        if(dimensao %2 == 0 || dimensao < 3 || dimensao > 9) {
            printf("Informe um valor valido.\n");
        }
    }

    imprimirMatriz(dimensao);

    return 0;
}
