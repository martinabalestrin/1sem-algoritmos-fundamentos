#include <stdio.h>
#include <stdlib.h>

/*
A imobili�ria Im�bilis vende apenas terrenos retangulares. Fa�a um algoritmo para ler as
dimens�es de um terreno e depois exibir a �rea do terreno.
*/

int main()
{
    // declara vari�vel dimens�es
    float a = 0;
    float b = 0;

    // entrada do valor do lado do terreno
    printf("Informe um dos lados do terreno: ");
    scanf("%f", &a);

    printf("Informe o outro lado do terreno: ");
    scanf("%f", &b);

    // declara vari�vel da �rea
    float area = 0;

    // se o terreno for retangular
    if(a != b) {
        // calculo da �rea
        area = a * b;
        // imprime o valor da �rea
        printf("�rea: %.2f", area);
    }

    // se o terreno n�o for retangular
    else {
        printf("A Imobili�ria Im�bilis vende apenas terrenos retangulares. Este terreno � quadrado.");
    }

    return 0;
}
