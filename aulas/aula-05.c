#include <stdio.h>
#include <stdlib.h>

int main() {

    ordem_vet();

    return 0;
}

void soma_vet() {

    float vet[5];
    float soma=0, media=0;

    for(int i = 0; i < 5; i++) {
        scanf("%f", &vet[i]);
    }

    for(int j = 0; j < 5; j++) {
        soma += vet[j];
    }

    media = soma / 5;

    printf("%f", media);
}

void ordem_vet() {

    float vet[10];
    float aux = 0;

    for(int i = 0; i < 10; i++) {
        scanf("%f", &vet[i]);
    }

    for(int j = 0; j < 10; j++) {
        for(int m = 0; m < 10; m++) {
            if (vet[j] < vet[m]) {
                aux = vet[j];
                vet[j] = vet[m];
                vet[m] = aux;
            }
        }
    }

    for(int p = 0; p < 10; p++) {
        printf("%f\n", vet[p]);
    }

}

void desafio() {

    int n = 0;
    int tamanho[n];
    char pe[n];

    do {
        printf("Informe o numero de botas: ");
        scanf("%d", &n);
    } while (n%2 != 0);

    for(int i = 0; i<n; i++) {
        printf("Informe o tamanho. Ex: 40\n");
        scanf("%d", &tamanho[n]);
    }

    //printf("foi");
    //fgets(variável, sizeof(2), stdin);
}
