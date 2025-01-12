#include <stdio.h>
#include <stdlib.h>

void sequencia(int n) {

    printf("1");

    for(int i = 0; i <= n; i++) {

        for(int j = 2; j <= n-i; j++) {
            printf("%d", j);
        }

        //printf("\nPRIMEIRO\n");

        for(int k = n-(i+1); k > 0; k--) {
            printf("%d", k);
        }

        //printf("\nSEGUNDO\n");
    }
}

int main()
{
    int num = 0;

    printf("Informe um numero para a sequencia: ");
    scanf("%d", &num);

    sequencia(num);
}
