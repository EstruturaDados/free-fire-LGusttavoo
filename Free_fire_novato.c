#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10

// Criando uma Struct que representa um item no inventário

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

Item mochila[MAX_ITENS];   // Um vetor de structs(mochila)
int totalItens = 0; 

// Função que insere um item na Mochila!
void inserirItem() {
    if (totalItens >= MAX_ITENS) {
        printf("\n ATENÇÃO!, A mochila está cheia! Remova algo antes.\n");
        return;
    }

    Item novo;

    printf("\nDigite o nome do item: ");
    scanf("%s", novo.nome);

    printf("Digite o tipo do item (arma, municao, cura...): ");
    scanf("%s", novo.tipo);

    printf("Digite a quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[totalItens] = novo;
    totalItens++;

    printf("\nItem cadastrado com sucesso!\n");
}

// Função que Busca item pelo nome (busca sequencial)

int buscarItem(char nomeBuscado[]) {
    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeBuscado) == 0) {
            return i;
        }
    }
    return -1;
}

// Função que remove item pelo NOME.

void removerItem() {
    if (totalItens == 0) {
        printf("\nA mochila está vazia.\n");
        return;
    }

    char nome[30];
    printf("\nDigite o nome do item que deseja remover: ");
    scanf("%s", nome);

    int index = buscarItem(nome);

    if (index == -1) {
        printf("\n Item não encontrado.\n");
        return;
    }

    // Remover deslocando elementos à esquerda

    for (int i = index; i < totalItens - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    totalItens--;
    printf("\n  Item removido com sucesso!\n");
}
// Função que Lista todos os itens da Mochila

void listarItens() {
    if (totalItens == 0) {
        printf("\nA mochila está vazia.\n");
        return;
    }

    printf("\n======= ITENS NA MOCHILA =======\n");
    for (int i = 0; i < totalItens; i++) {
        printf("[%d] Nome: %s | Tipo: %s | Quantidade: %d\n",
               i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
    printf("================================\n");
}

// Função que Busca item pelo nome e exibe os dados 
void mostrarBusca() {
    char nome[30];
    printf("\nDigite o nome do item que deseja buscar: ");
    scanf("%s", nome);

    int index = buscarItem(nome);

    if (index == -1) {
        printf("\n Item nao encontrado.\n");
    } else {
        Item item = mochila[index];
        printf("\nItem encontrado!\n");
        printf("Nome: %s\n", item.nome);
        printf("Tipo: %s\n", item.tipo);
        printf("Quantidade: %d\n", item.quantidade);
    }
}

// FunçÃO Main (função principal)

int main() {

    int opcao;

    do {
        printf("\n=====================================\n");
        printf(" MOCHILA DE SOBREVIVÊNCIA - INVENTÁRIO\n");
        printf("=====================================\n");
        printf("Itens na mochila: %d/%d\n", totalItens, MAX_ITENS);
        printf("\n1. Cadastrar item");
        printf("\n2. Remover item");
        printf("\n3. Listar itens");
        printf("\n4. Buscar item");
        printf("\n0. Sair");
        printf("\n-------------------------------------\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirItem();
                listarItens();
                break;
            case 2:
                removerItem();
                listarItens();
                break;
            case 3:
                listarItens();
                break;
            case 4:
                mostrarBusca();
                break;
            case 0:
                printf("\nSaindo... Boa sorte na sobrevivência!\n");
                break;
            default:
                printf("\n❌ Opção inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}

