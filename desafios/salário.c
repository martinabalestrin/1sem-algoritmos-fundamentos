#include <stdio.h>
#include <stdlib.h>

/*
Desenvolva um programa que pergunte ao usu�rio quanto ele ganha por hora (op��o 1
no menu) e o n�mero de horas trabalhadas no m�s (op��o 2 no menu). Calcule e
mostre o detalhamento do seu contracheque no referido m�s, conforme o seguinte
menu:
� Sal�rio bruto (op��o 3);
� Quanto pagou ao INSS (op��o 4) (11%);
� Quanto pagou ao sindicato (op��o 5) (2%);
� O sal�rio l�quido (op��o 6);
� Sair (op��o 7);
� Caso n�o tenha sido informado o valor recebido por hora ou a quantidade de horas
trabalhadas, deve gerar uma mensagem avisando que n�o h� dados suficientes;
*/

float valorHora() {

    float valor = 0;

    // leitura do valor por hora
    printf("\nValor por hora: ");
    scanf("%f", &valor);

    return valor;
}

float horasTrabalhadas() {

    float horas = 0;

    // leitura das horas trabalhadas no m�s
    printf("\nHoras trabalhadas no m�s: ");
    scanf("%f", &horas);

    return horas;
}

void dadosInsuficientes() {

    // imprime mensagem que os dados s�o insuficientes
    printf("\nDados insuficientes. Certifique-se de preencher o valor por hora e horas trabalhadas.\n");
}

float salarioBruto(float valor, float horas) {

    // verifica se os valores das vari�veis foram inclu�dos
    if(valor > 0 && horas > 0) {

        // declara vari�vel do sal�rio
        float salario = 0;

        // c�lculo do sal�rio
        salario = valor * horas;

        // imprime o sal�rio bruto
        printf("\nSal�rio Bruto: %f\n", salario);

        return salario;
    }

    else {

        dadosInsuficientes();

        return 0;
    }
}

float valorINSS(float valor, float horas) {

    // verifica se os valores das vari�veis foram inclu�dos
    if(valor > 0 && horas > 0) {

        // declara vari�vel da taxa do inss
        float taxa = 0;

        // calcula o valor da taxa
        taxa = (valor * horas) * 0.11;

        // imprime a taxa
        printf("\nTaxa do INSS: %f\n", taxa);

        return taxa;
    }

    else {

        dadosInsuficientes();

        return 0;
    }
}

float valorSindicato(float valor, float horas) {

    // verifica se os valores das vari�veis foram inclu�dos
    if(valor > 0 && horas > 0) {

        // declara vari�vel da taxa do sindicato
        float taxa = 0;

        // calcula o valor da taxa
        taxa = (valor * horas) * 0.02;

        // imprime a taxa
        printf("\nTaxa do Sindicato: %f\n", taxa);

        return taxa;
    }

    else {

        dadosInsuficientes();

        return 0;
    }
}

float salarioLiquido(float valor, float horas) {

    // verifica se os valores das vari�veis foram inclu�dos
    if(valor > 0 && horas > 0) {

        // declara vari�vel do sal�rio bruto
        float bruto = valor * horas;
        // declara vari�vel de taxas
        float taxas = 0.13;
        // declara vari�vel do sal�rio l�quido
        float liquido = bruto - (bruto * taxas);

        // imprime o sal�rio l�quido
        printf("\nSal�rio L�quido: %f\n", liquido);

        return liquido;
    }

    else {

        dadosInsuficientes();

        return 0;
    }
}

int main() {

    // declara a vari�vel do menu
    int menu = 0;
    // declara a vari�vel de valor
    float valor = 0;
    // declara a vari�vel de horas
    float horas = 0;
    // declara a var�avel de sal�rio bruto
    float s_bruto = 0;
    // declara a var�avel de taxa paga ao INSS
    float taxa_inss = 0;
    // declara a var�avel de taxa paga ao sindicato
    float taxa_sindicato = 0;
    // declara a var�avel de sal�rio l�quido
    float s_liquido = 0;

    // repete at� que o usu�rio insira 7
    while(menu != 7) {

        // imprime o menu
        printf("\n----- MENU -----\n\n");
        printf("1 - Inserir valor por hora\n");
        printf("2 - Inserir horas trabalhadas\n");
        printf("3 - Sal�rio bruto\n");
        printf("4 - Valor pago ao INSS\n");
        printf("5 - Valor pago ao sindicato\n");
        printf("6 - Sal�rio l�quido\n");
        printf("7 - Sair\n");

        // leitura da vari�vel menu
        printf("\nSelecione uma op��o: ");
        scanf("%d", &menu);

        // limpa o console
        system("cls");

        // executar comandos de acordo com a op��o selecionada
        switch(menu) {

            case 1:
                // fun��o de leitura do valor por hora
                valor = valorHora();
                break;

            case 2:
                // fun��o de leitura de horas trabalhadas no m�s
                horas = horasTrabalhadas();
                break;

            case 3:
                // fun��o de c�lculo do sal�rio bruto
                s_bruto = salarioBruto(valor, horas);
                break;

            case 4:
                // fun��o de c�lculo da taxa do INSS
                taxa_inss = valorINSS(valor, horas);
                break;

            case 5:
                // fun��o de c�lculo da taxa do Sindicato
                taxa_sindicato = valorSindicato(valor, horas);
                break;

            case 6:
                // fun��o de c�lculo do sal�rio l�quido
                s_liquido = salarioLiquido(valor, horas);
                break;

            case 7:
                // termina a execu��o do c�digo
                printf("\nSaindo...");

            default:
                // imprime a mensagem
                printf("\nEscolha uma das op��es do menu.\n");
                break;
        }
    }

    return 0;
}
