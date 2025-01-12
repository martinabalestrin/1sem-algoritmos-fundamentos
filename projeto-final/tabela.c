#include <string.h>
#include "../include/tabela.h"

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

void RegistraVenda(produto produtos[], int qntProduto, char nome[], compra compras[], int *qntCompras) {
    int id = 0, quantidade = 0;
    float totalCompra = 0;

    do {
        printf("Codigo do produto (0 para terminar): ");
        char codigo[10];
        scanf("%s", codigo);

        if (isdigit(codigo[0])){
            id = atoi(codigo);


            if (id > 0 && id <= qntProduto) { // verifica se o id informado existe

                do {

                    printf("Quantidade desejada: "); // pergunta a quantidade de itens do produto selecionado
                    char input[10];
                    scanf("%s", input);

                    if (isdigit(input[0])) { // verifica se o valor informado para quantidade é um numro
                        quantidade = atoi(input);
                        if (quantidade <= produtos[id - 1].estoque) { // verifica se quantidade informada esta dentro do estoque
                            float valorItem = produtos[id - 1].valor * quantidade; // calcula o valor da compra das n peças do produto
                            printf("Total da compra: %.2f\n", valorItem);

                            char confirmacao;

                            do {
                                printf("Confirmar compra (s/n)? "); // solicita a confirmação da compra
                                scanf(" %c", &confirmacao);

                                if (confirmacao == 's') {
                                    printf("\nCompra confirmada.\n\n");
                                    produtos[id - 1].estoque -= quantidade; // remove a quantidade de itens do estoque
                                    totalCompra += valorItem; // atualiza o valor total da compra

                                    // Registro da compra no vetor de compras
                                    strcpy(compras[*qntCompras].nomeCliente, nome);
                                    compras[*qntCompras].idProduto = id;
                                    compras[*qntCompras].quantidade = quantidade;
                                    compras[*qntCompras].valorTotal = valorItem;
                                    (*qntCompras)++;
                                } else if (confirmacao == 'n') {
                                    printf("\nCompra nao confirmada.\n\n"); // mostra se a compra for negada
                                } else {
                                    printf("\nOpcao invalida.\n\n"); // mostra essa mensagem se a compra não for confirmada ou negada
                                }

                            } while (confirmacao != 's' && confirmacao != 'n'); // repete a confirmação aété a pessoa confirmar ou negar

                        } else {
                            printf("Quantidade insuficiente em estoque.\n"); // mostra essa mensagem se for selecionada uma quantidade que não tem em estoque
                        }

                    } else {
                        printf("\nDigite um numero.\n\n"); // mostra essa mensagem se não for digitado um numero para a quantidade de produtos
                    }

                } while (quantidade > produtos[id - 1].estoque || quantidade <= 0); // Repete a pergunta da quantidade de produtos comprados ate informar um valor valido

        } else if (id < 0 || id > qntProduto) {
            printf("Produto nao encontrado.\n"); // mostra essa mensagem se o id informado não bater com algum produto
        }

        }else {
            printf("\nDigite um numero.\n\n"); // mostra essa mensagem se não for digitado um numero para a quantidade de produtos
        }

    } while (id != 0); // repete o codigo acima ate o valor da variavel id ser 0

    printf("Total da compra de %s eh: %.2f\n", nome, totalCompra); // mostra o nome da pessoa que comprou e o total da compra
}

void mostrarCompras(compra compras[], int qntCompras, produto produtos[], int qntProdutos) {
    if (qntCompras == 0) {//verifica se alguma compra foi registrada
        printf("Nenhuma compra registrada.\n");
        return;
    }

    //("%-25s", forma descoberta para deixar o print alinhado) mostra uma tabela
    printf("\n----- COMPRAS REALIZADAS -----\n\n");
    printf("%-25s %-30s %-15s %-15s %-15s\n", "Nome do Cliente", "Descricao Produto", "Quantidade", "Valor Unitario", "Valor Total");

    float totalGeral = 0; // Variável para armazenar o valor total de todas as compras
    char clientesProcessados[100][50]; // Vetor para armazenar nomes de clientes processados para controle de repetição
    int qntClientesProcessados = 0; // Contador para o número de clientes já processados

    // Itera sobre todas as compras registradas
    for (int i = 0; i < qntCompras; i++) {
        int idProduto = compras[i].idProduto;

        // Imprime os detalhes da compra (nome do cliente, descrição do produto, quantidade, valor unitário, valor total)
        printf("%-25s %-30s %-15d %-15.2f %-15.2f\n",
               compras[i].nomeCliente, // nome cliente
               produtos[idProduto - 1].descricao, // descricao do produto
               compras[i].quantidade, // quantidade comprada
               produtos[idProduto - 1].valor, // valor unitario da compra
               compras[i].valorTotal); // valor total da compra

        totalGeral += compras[i].valorTotal; // Soma o valor total da compra atual ao total geral

        int jaProcessado = 0; // Variável para verificar se o cliente já foi processado anteriormente

        // Verifica se o cliente já foi processado
        for (int j = 0; j < qntClientesProcessados; j++) {
            if (strcmp(compras[i].nomeCliente, clientesProcessados[j]) == 0) {
                jaProcessado = 1;
                break; // Se já foi processado, não precisa verificar mais
            }
        }

        if (jaProcessado == 0) { // Se o cliente não foi processado
            float totalPorCliente = 0; // Variável para armazenar o total de compras para o cliente atual

            // Calcula o total de compras para o cliente atual
            for (int j = 0; j < qntCompras; j++) {
                if (strcmp(compras[i].nomeCliente, compras[j].nomeCliente) == 0) {
                    totalPorCliente += compras[j].valorTotal;
                }
            }

            // Adiciona o cliente ao vetor de processados
            strcpy(clientesProcessados[qntClientesProcessados], compras[i].nomeCliente);
            qntClientesProcessados++;
        }
    }

    // Imprime o total geral de todas as compras
    printf("\nTotal Geral das Compras: %.2f\n", totalGeral);

    // Imprime o total de compras por cliente
    printf("\n----- TOTAL DE COMPRAS POR CLIENTE -----\n\n");
    for (int i = 0; i < qntClientesProcessados; i++) {
        float totalPorCliente = 0;

        // Calcula o total de compras para o cliente atual
        for (int j = 0; j < qntCompras; j++) {
            if (strcmp(clientesProcessados[i], compras[j].nomeCliente) == 0) {
                totalPorCliente += compras[j].valorTotal;
            }
        }

        printf("Cliente: %s - Gastou ao total: %.2f\n", clientesProcessados[i], totalPorCliente);
    }
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

int maiorVenda(compra compras[], int qntCompras, produto produtos[], int qntProdutos){

    if(qntCompras == 0){ //verifica se ocorreu alguma venda até o momento
        printf("Nenhuma compra foi realizada\n");
        return 0;
    }

    int indiceMaiorVenda = 0; //variável para armazenar o índice que está a maior venda
    for(int i = 0; i < qntCompras; i++){//itera todas as compras
        if(compras[i].valorTotal > compras[indiceMaiorVenda].valorTotal){ //confere se o valor da compra iterada é maior que o valor da compra armazenada no índice atualmente
            indiceMaiorVenda = i; //armazena o índice da maior venda
        }
    }

    compra maiorCompra = compras[indiceMaiorVenda]; // armazena os dados da maior venda encontrada
    char clienteMaiorVenda[50]; //variável para armazenar o nome do cliente da maior venda
    float valorTotalCompra = 0.0; //variável para armazenar o valor total da compra
    strcpy(clienteMaiorVenda, maiorCompra.nomeCliente); //copia o nome do cliente da maior venda para a variável clienteMaiorVenda

    //exibe as informacoes sobre a maior compra
    printf("Maior compra \n");
    printf("Cliente: %s\n", maiorCompra.nomeCliente);

    //cabeçalho da tabela de itens comprados
    printf("Itens comprados:\n");
    printf("%-20s %-12s %-12s %-12s\n", "Descricao Produto", "Quantidade", "Valor Unitario", "Valor Total");

    //loop para exibir os itens comprados na maior venda
    for (int i = 0; i < qntCompras; i++){
        //verifica se o item foi comprado pelo cliente da maior venda
        if (strcmp(compras[i].nomeCliente, maiorCompra.nomeCliente) == 0) {
            int idProduto = compras[i].idProduto; //armazena o id do produto
            float valorTotalProduto = compras[i].quantidade * produtos[idProduto - 1].valor; //calcula o valor total do produto
            //exibe os detalhes do produto
            printf("%-20s %-12d %-12.2f %-12.2f\n", produtos[idProduto - 1].descricao, compras[i].quantidade, produtos[idProduto - 1].valor, valorTotalProduto);
            valorTotalCompra += valorTotalProduto; //soma o valor  total do produto ao valor total da compra
        }
    }
    //exibe o valor total da compra do maior cliente
    printf("Valor total da compra: %.2f\n", valorTotalCompra);
}

