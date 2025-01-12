#ifndef TABELA_H_INCLUDED
#define TABELA_H_INCLUDED

//Definição da estrutura

typedef struct{
    int id;
    char descricao[50];
    int estoque;
    float valor;
}produto;

// Definição da estrutura de compra

typedef struct {
    char nomeCliente[50];
    int idProduto;
    int quantidade;
    float valorTotal;
} compra;

// Prototipo das funções

void RegistraVenda(produto produtos[], int qntProduto, char nome[],compra compras[], int *qntCompras); // Registrar venda

int reporEstoque(produto produtos[], int qntProduto, int id); // Repor estoque

int mostrarEstoque(produto produtos[], int qntProduto);//Mostrar estoque

void mostrarCompras(compra compras[], int qntCompras, produto produtos[],int qntProdutos); //Mostrar compras

int maiorCompra(); //maior compra

void adicionarProduto(produto *P, int *id, char descricao[], int estoque, float valor); //Adicionar mais produtos

void inicializarProdutos(produto produtos[], int *qntProduto); //inicias a tabela com os produtos ja existentes

#endif // TABELA_H_INCLUDED
