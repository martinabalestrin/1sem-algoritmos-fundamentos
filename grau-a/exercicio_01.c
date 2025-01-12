#include <stdio.h>
#include <stdlib.h>

/*
Crie um algoritmo onde o usuário deve informar três números inteiros positivos,
“ini”, “fim” e “qt”. Em seguida, gere e mostre na tela uma sequência de “qt” números fracionários
partindo de “ini” até atingir “fim”, com intervalos regulares. A sequência pode ser tanto crescente
quanto decrescente.
Ex 1: ini = 3, fim = 12, qt = 5. Sequência: 3,00 5,25 7,50 9,75 12,00
Ex 2: ini = 35, fim = 18, qt = 6. Sequência: 35,00 31,60 28,20 24,80 21,40 18,00
*/

int main()
{
    float ini = 0;
    float fim = 0;
    float qt = 0;

    printf("Informe o valor inicial: ");
    scanf("%f", &ini);

    printf("Informe o valor final: ");
    scanf("%f", &fim);

    printf("Informe a quantidade de numeros da sequencia: ");
    scanf("%f", &qt);

    // fim = ini + ((qt-1) * r)

    float r = (fim - ini) / (qt-1);
    float a = ini;

    printf("%.2f, ", ini);

    for(int i = 0; i < qt-2; i++) {
        a = a + r;
        printf("%.2f, ", a);
    }

    printf("%.2f", fim);

    return 0;
}
