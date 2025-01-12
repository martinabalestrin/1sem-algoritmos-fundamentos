#include <stdio.h>
#include <stdlib.h>

/* Crie uma matriz de caracteres com dimens�es definidas pelo usu�rio em tempo de execu��o. Cada elemento da
matriz deve ser inicializado com um espa�o em branco. O programa deve garantir que as dimens�es informadas
sejam n�meros inteiros entre 3 e 9, e n�o deve prosseguir enquanto n�o forem informados valores v�lidos. Em
seguida, atualize a(s) linha(s) e coluna(s) central(is) da matriz com caracteres �x�, e imprima a matriz na tela utilizando
o caractere �pipe� (barra) para delimitar as colunas. */

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
