#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Crie a fun��o �separa_palavras(texto)�, que recebe como par�metro um texto contendo diversas palavras unidas, e
devolve um texto com as mesmas palavras separadas por espa�os. No texto de entrada, cada palavra inicia com letra
mai�scula e possui as demais letras min�sculas. Para testar a fun��o, solicite ao usu�rio que digite um texto, execute
a fun��o, e imprima na tela o texto retornado.
Exemplo: a frase: �VouPassarEmFundamentosDeProgramacao� deve ser convertida para
�Vou Passar Em Fundamentos De Programacao�. */

char separa_palavras(char frase[100], char palavras[120]);

int main() {

    char frase[100];
    char palavras[120];

    printf("Insira a frase:\n");
    fflush(stdin);
    fgets(frase, sizeof(frase), stdin);

    palavras[120] = separa_palavras(frase, palavras);

    printf("Frase com espacos:\n");
    printf("%s", palavras);

    return 0;
}

char separa_palavras(char frase[100], char palavras[120]) {

    int j = 0;

    for(int i = 0; i < strlen(frase); i++) {

        if(isupper(frase[i]) != 0 && i != 0) {

            palavras[j] = ' ';
            j++;
            palavras[j] = frase[i];
        }

        else {
            palavras[j] = frase[i];
        }

        j++;
    }

    return palavras;
}
