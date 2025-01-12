#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int tam;

    printf("quantidade de elementos na array: ");
    scanf("%d", &tam);

    int array, *p;
    int soma = 0;

    array = malloc(sizeof(int)*(tam));

    for(int i = 0; i < tam; i++) {
        printf("indice %d: ", i);
        scanf("%d", &array[i]);
    }

    for(int i = 0; i < tam; i++) {
        p = *array[i];
        printf("\n%d", p);
        soma += *(p);
    }

    printf("soma: ", soma);

    free(array);

    return 0;
}
