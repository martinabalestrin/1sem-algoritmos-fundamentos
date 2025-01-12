#include <stdio.h>
#include <stdlib.h>

/*
Dado o vetor de números inteiros [33, 5, 54, 41, 3, 16, 19, 8, 87, 93] faça um
algoritmo que identifique e mostre os itens abaixo. Cada item deve ser desenvolvido em uma
função individual, que recebe como parâmetro o vetor e retorna o número correspondente.
a) (1,0) O menor valor armazenado nos índices pares;
b) (1,0) O maior valor armazenado nos índices ímpares;
c) (2,0) A multiplicação dos valores pares dividido pelo somatório dos valores ímpares;
*/

// 6912 / 281 =

void menor_pares(int vetor[]) {

    int aux = vetor[1];;

    for(int i = 0; i < 10; i++) {
        if(vetor[i] < aux && i%2 == 0) {
            aux = vetor[i];
        }
    }

    printf("\nResultado: %d\n\n", aux);
}

void maior_impares(int vetor[]) {

    int aux = vetor[1];;

    for(int i = 1; i < 10; i++) {
        if(vetor[i] > aux && i%2 == 1) {
            aux = vetor[i];
        }
    }

    printf("\nResultado: %d\n\n", aux);

}

void calculo_03(int vetor[]) {

    float multi_par = 1;

    for(int i = 0; i < 10; i++) {
        if(vetor[i]%2 == 0) {
            multi_par *= vetor[i];
        }
    }

    printf("\n%d", multi_par);

    float soma_impar = 0;

    for(int j = 0; j < 10; j++) {
        if(vetor[j]%2 == 1) {
            soma_impar += vetor[j];
        }
    }

    float resultado = (multi_par / soma_impar);

    printf("\nResultado: %.2f\n\n", resultado);

}

int main()
{

    int vet[10] = {33, 5, 54, 41, 3, 16, 19, 8, 87, 93};
    int escolha;

    do {

        printf("----- MENU -----\n");
        printf("1 - Menor valor armazenado nos indices pares\n");
        printf("2 - Maior valor armazenado nos indices impares\n");
        printf("3 - Multiplicacao dos valores pares dividido pelo somatorio dos valores impares\n");
        printf("4 - Sair\n");
        printf("\nEscolha um dos numeros: ");
        scanf("%d", &escolha);

        switch(escolha) {

            case 1:
                menor_pares(vet);
                break;

            case 2:
                maior_impares(vet);
                break;

            case 3:
                calculo_03(vet);
                break;

            default:
                break;
        }

    } while(escolha != 4);

    return 0;
}
