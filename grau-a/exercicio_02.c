#include <stdio.h>
#include <stdlib.h>

/*
Crie uma função denominada “soma_inversa(n)”, que recebe como parâmetro um
número “n”, calcula e retorna a seguinte soma: 1/1 + 1/2 + 1/3 + … + 1/(n-1) + 1/n. O valor de “n”
deve ser lido como uma entrada do usuário da seguinte forma: Dentro de uma estrutura de
repetição, solicite ao usuário um número “n” inteiro entre 1 e 9. Somente saia da estrutura de
repetição quando o usuário digitar -1 para encerrar o programa. Ainda dentro de laço de
repetição, chame a função “soma_inversa(n)” e imprima o valor retornado.
*/

void soma_inversa(int n) {

    float resultado = 0;

    for(float i = 1; i <= n; i++) {
        resultado += (1/i);
    }

    printf("Resultado da soma: %.2f\n\n", resultado);
}

int main() {

    int n = 0;

    while(n != -1) {

        printf("Informe um numero de 1 a 9: ");
        scanf("%d", &n);

        if(n > 0 && n < 10) {

            soma_inversa(n);
        }
    }

    return 0;
}
