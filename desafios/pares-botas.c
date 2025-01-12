#include <stdio.h>
#include <stdlib.h>

int main() {

    // variável do número de botas
    int n = 0;
    // variável do tamanho das botas
    int tamanho[n];
    // variável do pé das botas
    char pe[n];
    // variável de looping
    char continuar = 'S';

    while(continuar == 'S') {

        // entrada da quantidade de botas -- enquanto não forem pares, não continua
        do {
            printf("Informe o numero de botas: ");
            scanf("%d", &n);
        } while (n%2 != 0);

        // entrada do tamanho e pé das botas
        for(int i = 0; i < n; i++)
        {
            printf("Informe o tamanho e pe:\n");
            scanf("%d %c", &tamanho[i], &pe[i]);
        }

        // imprimir dados de entrada
        for(int i = 0; i < n; i++)
        {
            printf("%d %c\n", tamanho[i], pe[i]);
        }

        // variável da quantidade de pares de botas
        int pares = 0;

        // confirmação de pares de botas
        for(int j = 0; j < n; j++)
        {
            for(int k = (j+1); k < n; k++)
            {
                if((tamanho[j] == tamanho[k]) && (pe[j] != pe[k]))
                {
                    pares++;
                }
            }
        }

        // imprime a quantidade de pares completos
        printf("Pares: %d\n", pares);

        // validação da continuação
        printf("Deseja continuar? S/N\n");
        scanf(" %c", &continuar);
    }

    return 0;
}
