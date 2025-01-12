#include <stdio.h>
#include <stdlib.h>

#define MAX_ALUNOS 3
#define TAM_NOME 50

// declarar a struct
typedef struct {

    char nome[TAM_NOME];
    int idade;
    float nota;
} Aluno;

int main()
{
    Aluno alunos[MAX_ALUNOS];

    for(int i = 0; i < MAX_ALUNOS; i++) {

        printf("Nome do aluno %d: ", i+1);
        fgets(alunos[i].nome, sizeof(TAM_NOME), stdin);

        fflush(stdin);

        printf("Idade do aluno %d: ", i+1);
        scanf("%d", &alunos[i].idade);

        printf("Nota do aluno %d: ", i+1);
        scanf("%f", &alunos[i].nota);
        printf("\n");

        while(getchar() != '\n');
    }

    for(int i = 0; i < MAX_ALUNOS; i++) {

        printf("-- ALUNO %d --\n\n", i+1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Idade: %d\n", alunos[i].idade);
        printf("Nota: %.2f\n\n", alunos[i].nota);
    }

    return 0;
}
