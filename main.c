#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 26

typedef struct no {
    struct no* filhos[MAX];
    int fim;
}No;

No* criaNo() {
    No* novo = (No*)malloc(sizeof(No));
    if (novo) {
        novo->fim = 0;
        for (int i = 0; i < MAX; i++) {
            novo->filhos[i] = NULL;
        }
    }
    return novo;
}

No* iniciarNo() {
    return(criaNo());
}

int mapearIndice(char c) {
    return((int)c - (int)'a');
}

void inserir(No* r) {
    int nivel;
    int i;
    char buffer[20];

    printf("Digite a palavra que deseja adicionar: ");
    scanf(" %[^\n]", buffer);
    int len = strlen(buffer);

    No* aux = r;
    for (nivel = 0; nivel < len; nivel++) {
        i = mapearIndice(buffer[nivel]);
        if (!aux->filhos[i]) aux->filhos[i] = criaNo();
        aux = aux->filhos[i];
    }
    aux->fim = 1;
    printf("Palavra inserida com sucesso!\n\n");
}

int busca(No* r) {
    int nivel;
    char buffer[20];
    int i;

    printf("Digite a palavra que deseja buscar: ");
    scanf(" %[^\n]", buffer);
    int len = strlen(buffer);

    No* aux = r;
    for (nivel = 0; nivel < len; nivel++) {
        i = mapearIndice(buffer[nivel]);
        if (!aux->filhos[i]) {
            printf("Palavra nao encontrada!\n\n");
            return 0;
        }
        aux = aux->filhos[i];
    }

    if (aux->fim) {
        printf("Palavra encontrada!\n\n");
    }
    else {
        printf("Palavra nao encontrada!\n\n");
    }
    return aux->fim;
}

int main() {
    int op = 9;
    No* r = iniciarNo();

    while (op != 0) {
        printf("===== DICIONARIO =====\n");
        printf("1. Adicionar palavra\n2. Buscar palavra\n0. Sair\n");
        printf("Digite uma opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                inserir(r);
                break;
            case 2:
                busca(r);
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }

    return 0;
}