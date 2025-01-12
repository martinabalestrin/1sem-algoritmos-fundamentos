#include <stdio.h>

int main()
{

    int comp = 1;

    // entrada do n�mero de competidores
    printf("Informe o numero de competidores:\n");
    scanf("%d", &comp);

    // la�o de repeti��o
    while(comp != 0) {

        // vari�vel da ordem de largada
        int largada[comp];
        // vari�vel da ordem de chegada
        int chegada[comp];

        // entrada da ordem de largada
        printf("Informe a ordem do grid de largada:\n");

        for(int i = 0; i < comp; i++) {
            scanf("%d", &largada[i]);
        }

        // entrada da ordem de chegada
        printf("Informe a ordem do grid de chegada:\n");

        for(int j = 0; j < comp; j++) {
            scanf("%d", &chegada[j]);
        }

        // variavel de ultrapassagens
        int ultrapassagens = 0;

        // sistema para verificar as ultrapassagens
        for(int k = 0; k < comp; k++) {
            for(int p = 0; p< comp; p++) {
                if(largada[k] == chegada[p]) {
                    if(k < p ) {
                        ultrapassagens++;
                    }
                }
            }
        }

        // impress�o dos resultados
        printf("Houveram %d ultrapassagens!", ultrapassagens);

        // valida��o do la�o de repeti��o
        printf("\nInforme o numero de competidores:\n");
        scanf("%d", &comp);

    }
}
