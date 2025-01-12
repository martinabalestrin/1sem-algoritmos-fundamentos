#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Dado o arquivo �municipios.txt� descrito abaixo , contendo as colunas Munic�pio, Popula��o e PIB em Milh�es R$,
fa�a um programa que leia o arquivo e retorne:
a) Na tela, somente o nome dos munic�pios que n�o possuem nome composto;
b) Na tela, a popula��o e o nome dos munic�pios que possuem menos que 22000 ou mais que 41000 habitantes;
c) Calcular o PIB per capita de cada munic�pio pela f�rmula: PIB per capita = PIB Milh�es R$ / Popula��o * 106
, e mostrar na tela o PIB per capita com 2 casas decimais e o nome do munic�pio, somente para os munic�pios com
PIB per capita entre R$40.000 e R$50.000. */

typedef struct {

        char cidade[50];
        int populacao;
        float pib;

    } Municipio;

int verificaNumero(char line[]);

int testeNumero(char line);

void escreveTabela(Municipio m);

int main() {

    FILE *file;
    file = fopen("municipios.txt", "r");

    if(file == NULL) {
        printf("Ocorreu um erro.\n");
        return 0;
    }

    Municipio municipios[30];
    char line[100];
    int cont = 0;

    fgets(line, sizeof(line), file);

    while(!feof(file)) {

        fgets(line, sizeof(line), file);

        int tam = verificaNumero(line);

        if(tam != 0) {
            strncpy(municipios[cont].cidade, line, tam);
        }
    }

    escreveTabela(&municipios);

    fclose(file);

    return 0;
}

int verificaNumero(char line[]) {

    int tam = strlen(line);

    for(int i = 0; i < tam; i++) {

        if(testeNumero(line[i]) == 1) {
            return i;
        }
    }

    return 0;
}

int testeNumero(char line) {

    if(line == 1 || line == 2 || line == 3 || line == 4|| line == 5 ||
       line == 6 || line == 7 || line == 8 || line == 9 || line == 0) {

        return 1;
    }

    else {
        return 0;
    }
}

char escreveTabela(Municipio *m) {

    for(int i = 0; i < 30; i++) {

        printf("%s\n", m[i].cidade);
    }
}
