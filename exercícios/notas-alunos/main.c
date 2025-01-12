#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *file;

    file = fopen("pessoas.txt", "r");

    if(file == NULL) {
        printf("ocorreu um erro");
        return 0;
    }

    char nome[20], line[100];
    float n1, n2, n3;

    fgets(line, sizeof(line), file);

    while(fscanf(file, "%20s %f %f %f", nome, &n1, &n2, &n3) != EOF) {
            printf("%s teve media %.2f\n", nome, (n1+n2+n3)/3);
        }

    return 0;
}
