#include <stdio.h>
#include <stdlib.h>

/*
Desenvolva um programa que pergunte ao usuário quanto ele ganha por hora (opção 1
no menu) e o número de horas trabalhadas no mês (opção 2 no menu). Calcule e
mostre o detalhamento do seu contracheque no referido mês, conforme o seguinte
menu:
• Salário bruto (opção 3);
• Quanto pagou ao INSS (opção 4) (11%);
• Quanto pagou ao sindicato (opção 5) (2%);
• O salário líquido (opção 6);
• Sair (opção 7);
• Caso não tenha sido informado o valor recebido por hora ou a quantidade de horas
trabalhadas, deve gerar uma mensagem avisando que não há dados suficientes;
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

    // leitura das horas trabalhadas no mês
    printf("\nHoras trabalhadas no mês: ");
    scanf("%f", &horas);

    return horas;
}

void dadosInsuficientes() {

    // imprime mensagem que os dados são insuficientes
    printf("\nDados insuficientes. Certifique-se de preencher o valor por hora e horas trabalhadas.\n");
}

float salarioBruto(float valor, float horas) {

    // verifica se os valores das variáveis foram incluídos
    if(valor > 0 && horas > 0) {

        // declara variável do salário
        float salario = 0;

        // cálculo do salário
        salario = valor * horas;

        // imprime o salário bruto
        printf("\nSalário Bruto: %f\n", salario);

        return salario;
    }

    else {

        dadosInsuficientes();

        return 0;
    }
}

float valorINSS(float valor, float horas) {

    // verifica se os valores das variáveis foram incluídos
    if(valor > 0 && horas > 0) {

        // declara variável da taxa do inss
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

    // verifica se os valores das variáveis foram incluídos
    if(valor > 0 && horas > 0) {

        // declara variável da taxa do sindicato
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

    // verifica se os valores das variáveis foram incluídos
    if(valor > 0 && horas > 0) {

        // declara variável do salário bruto
        float bruto = valor * horas;
        // declara variável de taxas
        float taxas = 0.13;
        // declara variável do salário líquido
        float liquido = bruto - (bruto * taxas);

        // imprime o salário líquido
        printf("\nSalário Líquido: %f\n", liquido);

        return liquido;
    }

    else {

        dadosInsuficientes();

        return 0;
    }
}

int main() {

    // declara a variável do menu
    int menu = 0;
    // declara a variável de valor
    float valor = 0;
    // declara a variável de horas
    float horas = 0;
    // declara a varíavel de salário bruto
    float s_bruto = 0;
    // declara a varíavel de taxa paga ao INSS
    float taxa_inss = 0;
    // declara a varíavel de taxa paga ao sindicato
    float taxa_sindicato = 0;
    // declara a varíavel de salário líquido
    float s_liquido = 0;

    // repete até que o usuário insira 7
    while(menu != 7) {

        // imprime o menu
        printf("\n----- MENU -----\n\n");
        printf("1 - Inserir valor por hora\n");
        printf("2 - Inserir horas trabalhadas\n");
        printf("3 - Salário bruto\n");
        printf("4 - Valor pago ao INSS\n");
        printf("5 - Valor pago ao sindicato\n");
        printf("6 - Salário líquido\n");
        printf("7 - Sair\n");

        // leitura da variável menu
        printf("\nSelecione uma opção: ");
        scanf("%d", &menu);

        // limpa o console
        system("cls");

        // executar comandos de acordo com a opção selecionada
        switch(menu) {

            case 1:
                // função de leitura do valor por hora
                valor = valorHora();
                break;

            case 2:
                // função de leitura de horas trabalhadas no mês
                horas = horasTrabalhadas();
                break;

            case 3:
                // função de cálculo do salário bruto
                s_bruto = salarioBruto(valor, horas);
                break;

            case 4:
                // função de cálculo da taxa do INSS
                taxa_inss = valorINSS(valor, horas);
                break;

            case 5:
                // função de cálculo da taxa do Sindicato
                taxa_sindicato = valorSindicato(valor, horas);
                break;

            case 6:
                // função de cálculo do salário líquido
                s_liquido = salarioLiquido(valor, horas);
                break;

            case 7:
                // termina a execução do código
                printf("\nSaindo...");

            default:
                // imprime a mensagem
                printf("\nEscolha uma das opções do menu.\n");
                break;
        }
    }

    return 0;
}
