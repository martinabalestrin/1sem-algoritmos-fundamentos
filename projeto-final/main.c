#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/tabela.h"


int main() {
    //variavel do menu
    char opcao;

    int qntProduto = 0; //Variavel para armazenar a quantidade de produtos
    int qntCompras = 0; //Variavel para armazenar a quantidade de compras

    char descricao[50]; //Variavel para armazenar a descrição do novo produto
    int estoque; //Variavel para armezenar a quantidade do novo produto
    float valor; // Variavel para armazenar o valor do novo produto
    produto P; //Variavel para informar as categorias da structs
    produto produtos[20]; //Vetor para armazenar ate 20 produtos
    compra compras[100]; //Considerando um maximo de 100 compras

    inicializarProdutos(produtos, &qntProduto); //inicializa os produtos já conhecidos

    do {
        fflush(stdin);
        printf("---------- Menu ----------\n\n");
        printf("1. Registrar venda\n");
        printf("2. Repor estoque\n");
        printf("3. Mostrar estoque\n");
        printf("4. Mostrar compras\n");
        printf("5. Maior compra\n");
        printf("6. Adicionar mais produtos\n");
        printf("7. Sair\n");
        printf("\nEscolha uma opcao: ");

        scanf("%s", &opcao);

        switch (opcao) {
            case '1':
                system("cls"); // apaga o que já foi escrito

                char nomeCliente[50]; // define a variavel do nome do cliente


                printf("Nome do cliente: ");
                fflush(stdin);
                scanf("%50[^\n]s", nomeCliente); // pergunta e armazena o nome do cliente (com espaços)

                RegistraVenda(produtos, qntProduto, nomeCliente, compras, &qntCompras);

                printf("\n");
                break;
            case '2':
                system("cls"); // apaga o que já foi escrito

                int id; //variavel que ira armazenar o id do produto que a pessoa quer repor

                printf("Qual o id do produto que deseja repor? "); // pergunta o id do produto
                scanf("%d", &id);

                reporEstoque(produtos, qntProduto, id);

                printf("\n");
                break;
            case  '3':
                system("cls"); // apaga o que já foi escrito
                mostrarEstoque(produtos, qntProduto);
                printf("\n");
                break;
            case '4':
                system("cls"); // apaga o que ja foi escrito
                printf("\n");
                mostrarCompras(compras, qntCompras, produtos, qntProduto);
                printf("\n");
                break;
            case '5':
                printf("\n"); // apaga o que ja foi escrito
                system("cls");
                maiorVenda(compras, qntCompras, produtos, qntProduto);
                printf("\n");
                break;
            case '6':
                system("cls"); // apaga o que já foi escrito

                printf("Qual o nome do novo produto? ");
                fflush(stdin);
                scanf("%50[^\n]s", descricao);

                printf("Qual a quantidade em estoque? ");
                scanf("%d", &estoque);

                printf("Qual o valor do novo produto? ");
                scanf("%f", &valor);

                adicionarProduto(&P, &qntProduto, descricao, estoque, valor);
                produtos[qntProduto-1] = P;

                printf("\nProduto adicionado com sucesso!\n");
                break;
            case '7':
                printf("\n");
                printf("Saindo...");
                printf("\n");
                break;
            default:
                printf("\n");
                printf("Opcao invalida!\n");
                printf("\n");
                break;
        }
    } while (opcao != '7');

    return 0;
}
