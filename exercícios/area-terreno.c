#include <stdio.h>
#include <stdlib.h>

/*
A imobiliária Imóbilis vende apenas terrenos retangulares. Faça um algoritmo para ler as
dimensões de um terreno e depois exibir a área do terreno.
*/

int main()
{
    // declara variável dimensões
    float a = 0;
    float b = 0;

    // entrada do valor do lado do terreno
    printf("Informe um dos lados do terreno: ");
    scanf("%f", &a);

    printf("Informe o outro lado do terreno: ");
    scanf("%f", &b);

    // declara variável da área
    float area = 0;

    // se o terreno for retangular
    if(a != b) {
        // calculo da área
        area = a * b;
        // imprime o valor da área
        printf("Área: %.2f", area);
    }

    // se o terreno não for retangular
    else {
        printf("A Imobiliária Imóbilis vende apenas terrenos retangulares. Este terreno é quadrado.");
    }

    return 0;
}
