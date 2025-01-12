#include <string.h>
#include "tabela.h"

void adicionarProduto(produto *P, int *id, char descricao[], int estoque, float valor){

    (*id)++; //soma 1 ao valor do ponteiro de id do produto
    (*P).id = *id; //Atribuiu o valor do ponteiro no novo produto
    strcpy((*P).descricao, descricao); //copia a informação da descrição
    (*P).estoque = estoque; // atribuiu a quantidade em estoque para o novo produto
    (*P).valor = valor; // atribuiu o valor do novo produto

}

void inicializarProdutos(produto produtos[], int *qntProduto) {

    produto P;

    // adicionando os produtos ja cadastrados da tabela
    adicionarProduto(&P, qntProduto, "Calca", 20, 112.0);
    produtos[*qntProduto-1] = P;

    adicionarProduto(&P, qntProduto, "Camisa", 18, 95.0);
    produtos[*qntProduto-1] = P;

    adicionarProduto(&P, qntProduto, "Bermuda", 23, 49.9);
    produtos[*qntProduto-1] = P;

    adicionarProduto(&P, qntProduto, "Saia", 12, 169.0);
    produtos[*qntProduto-1] = P;

    adicionarProduto(&P, qntProduto, "Blusa", 9, 120.0);
    produtos[*qntProduto-1] = P;

    adicionarProduto(&P, qntProduto, "Moletom", 4, 125.0);
    produtos[*qntProduto-1] = P;

    adicionarProduto(&P, qntProduto, "Meia", 17, 12.99);
    produtos[*qntProduto-1] = P;

    adicionarProduto(&P, qntProduto, "Tenis", 8, 183.0);
    produtos[*qntProduto-1] = P;

    adicionarProduto(&P, qntProduto, "Bota", 3, 219.9);
    produtos[*qntProduto-1] = P;
}

int mostrarEstoque(produto produtos[], int qntProduto) {

    if(qntProduto < 1) {
        printf("nNao ha nenhum produto no estoque.\n");
    }

    else {
        printf("\n----- ESTOQUE -----\n\n");
        printf("%-8s %-20s %-12s %-10s\n\n", "ID", "Descricao", "Estoque", "Valor"); //Poem o cabeçalho

        for (int i = 0; i < qntProduto; i++) {
            if (produtos[i].estoque > 0) {
                printf("%-8d %-20s %-12d %-10.2f\n", produtos[i].id, produtos[i].descricao, produtos[i].estoque, produtos[i].valor); // printa os itens
            }
        }
    }
}

void RegistraVenda(produto produtos[], int qntProduto, char nome[],compra compras[], int *qntCompras) {
    int id = 0, quantidade = 0;
    float totalCompra = 0;

    do {
        printf("Codigo do produto (0 para terminar): "); //Pergunta o id do produto
        scanf("%d", &id);


        if (id > 0 && id <= qntProduto) { //verifica se o id informado bate com o de algum produto
            printf("Quantidade desejada: "); // pergunta a quantidade de itens comprados
            scanf("%d", &quantidade);

            if (quantidade <= produtos[id-1].estoque) { // verifica se a quantidade de itens é menor ou igual a quantidade em estoque
                float valorItem = produtos[id-1].valor * quantidade; // calcula o valor total da quantidade de itens desejados
                printf("Total da compra: %.2f\n", valorItem); // Mostra o total da compra

                char confirmacao;

                do{
                    printf("Confirmar compra (s/n)? "); // pede para confirmar a compra
                    scanf(" %c", &confirmacao);

                    if (confirmacao == 's') {
                        printf("\nCompra confirmada.\n\n");

                        produtos[id-1].estoque -= quantidade; // se a compra for confirmada diminui a quantidade do estoque
                        totalCompra += valorItem;

                        // Registro da compra no vetor de compras
                        strcpy(compras[*qntCompras].nomeCliente, nome);
                        compras[*qntCompras].idProduto = id;
                        compras[*qntCompras].quantidade = quantidade;
                        compras[*qntCompras].valorTotal = valorItem;
                        (*qntCompras)++; // Incrementa o contador de compras realizadas
                    }else if(confirmacao == 'n'){
                        printf("\nCompra nao confirmada.\n\n");
                    }else{
                        printf("\nOpcao invalida.\n\n");
                    }

                }while(confirmacao != 's' && confirmacao != 'n');

            } else {
                printf("Quantidade insuficiente em estoque.\n"); // mostra essa mensagem se a quantidade de itens desejados for maior do que disponivel no estoque
            }
        } else if(id < 0 || id > qntProduto) {
            printf("Produto nao encontrado.\n"); // mostra essa mensagem se o id informado não bater com algum produto
        }
    }while(id != 0); // repete o codigo acima ate o valor da variavel id ser 0

    printf("Total da compra de %s eh: %.2f\n", nome, totalCompra); // mostra o nome da pessoa que comprou e o total da compra
}

void mostrarCompras(compra compras[], int qntCompras, produto produtos[], int qntProdutos) {
    if (qntCompras == 0) {// Verifica se alguma compra foi realizada
        printf("Nenhuma compra registrada.\n");// se nenhuma compra for realizada
        return;
    }
    //Cabeçalho de compras realizadas
    printf("\n----- COMPRAS REALIZADAS -----\n\n");
    printf("%-20s %-20s %-12s %-12s %-12s\n", "Nome do Cliente", "Descricao Produto", "Quantidade", "Valor Unitario", "Valor Total");

    float totalGeral = 0;//VAriavel para armazenar o total geral das compras

    //loop para percorrree as compras registradas
    for (int i = 0; i < qntCompras; i++) {
        int idProduto = compras[i].idProduto;
        printf("%-20s %-20s %-12d %-12.2f %-12.2f\n",
        compras[i].nomeCliente,//nome cliente
        produtos[idProduto - 1].descricao,//descrisao do produto
        compras[i].quantidade,//quantidade comprada
        produtos[idProduto - 1].valor,//valor unitario da compra
        compras[i].valorTotal);//valor total da compra
        totalGeral += compras[i].valorTotal;// Soma o valor total da compra atual ao total geral
    }

    // Imprime o total geral de todas as compras
    printf("\nTotal Geral das Compras: %.2f\n", totalGeral);
}


int reporEstoque(produto produtos[], int qntProduto, int id) {
    int quantidade; //variavel para armazenar a quantidade que sera adicionada ao estoque

    if (id > 0 && id <= qntProduto) { //verifica se o id informado bate com o de algum produto
        printf("Qual a quantidade que sera reposta: "); // pergunta a quantidade que sera adicionada ao estoque
        scanf("%d", &quantidade);

        produtos[id-1].estoque += quantidade; // soma a quanridade informada com a quantidade já existente
        printf("Quantidade de %s atualizada para: %d\n", produtos[id-1].descricao, produtos[id-1].estoque); // mostra qual produto foi adicionado os novos itens e qual o total de itens finais
    } else {
        printf("Produto nao encontrado.\n"); // mostra essa mensagem se o id informado não bater com algum produto
    }
    return 0;
}


