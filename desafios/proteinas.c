#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void comparaVetores(char dna[], char proteina[], int A, int B);

int main()
{
    // variável do tamanho do DNA
    int N = 0;
    // variável do tamanho da proteína
    int M = 0;
    // variável da quantidade de comparações
    int Q = 0;

    // leitura do tamanho do DNA e da proteína
    printf("Informe o tamanho da fita de DNA:\n");
    scanf("%d", &N);
    printf("Informe o tamanho da sequencia de proteina:\n");
    scanf("%d", &M);

    // alocação de memória dinãmica para as strings
    char *dna[N+1];
    char *proteina[M+1];

    *dna = (char*)malloc(sizeof(char)*(N+1));
    *proteina = (char*)malloc(sizeof(char)*(M+1));

    // leitura da fita de dna e sequência de proteína
    printf("Informe a fita de DNA:\n");
    fflush(stdin);
    fgets(dna, sizeof(char)*(N+1), stdin);

    printf("Informe a sequencia da proteina:\n");
    fflush(stdin);
    fgets(proteina, sizeof(char)*(M+1), stdin);

    // leitura da quantidade de consultas
    printf("Informe quantas comparacoes serao feitas:\n");
    scanf("%d", &Q);

    // variáveis delimitadoras da substring
    int A = 0;
    int B = 0;

    // comparar o dna e substring da proteína
    for(int i = 0; i < Q; i++) {
        printf("Informe a posicao inicial:\n");
        scanf("%d", &A);
        printf("Informe a posicao final:\n");
        scanf("%d", &B);

        comparaVetores(dna, proteina, A, B);
    }

    // libera a memória dinâmica
    free(dna);
    free(proteina);

    return 0;
}

// função para comparar as strings/substrings
void comparaVetores(char dna[], char proteina[], int A, int B)
{
    int tam_subs = (B-A)+1;
    int tam_dna = strlen(dna);
    char sub_proteina[tam_subs];
    char sub_dna[tam_subs];
    int repeticoes = 0;

    // alimenta a substring da proteína selecionada
    for(int i = 0; i < tam_subs; i++) {
        sub_proteina[i] = proteina[A-1+i];
    }

    sub_proteina[tam_subs] = '\0';

    // cria substrings do dna e compara com a substring da proteína
    for(int i = 0; i < tam_dna; i++) {

        strncpy(sub_dna, &dna[i], tam_subs);
        sub_dna[tam_subs] = '\0';

        if(strcmp(sub_dna, sub_proteina) == 0) {
            repeticoes++;
        }
    }

    // imprime quantas vezes a proteína aparece na fita de DNA
    printf("A proteina aparece %d vezes na fita de DNA.\n\n", repeticoes);
}
