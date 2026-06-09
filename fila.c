#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void fila_inicializar(Fila *f) {
    f->inicio  = NULL;
    f->fim     = NULL;
    f->tamanho = 0;
}

int fila_vazia(Fila *f) {
    return f->inicio == NULL;
}

void fila_enfileirar(Fila *f, Atendimento a) {
    NoFila *novo = (NoFila*)malloc(sizeof(NoFila));
    if (!novo) {
        printf("  Erro: memoria insuficiente.\n");
        return;
    }
    novo->dado    = a;
    novo->proximo = NULL;

    if (fila_vazia(f)) {
        f->inicio = novo;
        f->fim    = novo;
    } else {
        f->fim->proximo = novo;
        f->fim          = novo;
    }
    f->tamanho++;
}

// Retorna 1 se ok, 0 se fila vazia
int fila_desenfileirar(Fila *f, Atendimento *destino) {
    if (fila_vazia(f)) return 0;

    NoFila *remover = f->inicio;
    *destino        = remover->dado;
    f->inicio       = remover->proximo;

    if (f->inicio == NULL) f->fim = NULL;

    free(remover);
    f->tamanho--;
    return 1;
}

void fila_listar(Fila *f) {
    if (fila_vazia(f)) {
        printf("  Fila de espera vazia.\n");
        return;
    }
    printf("  Total na fila: %d\n\n", f->tamanho);
    NoFila *atual = f->inicio;
    int pos = 1;
    while (atual != NULL) {
        printf("  [Posicao %d]\n", pos++);
        exibir_atendimento(&atual->dado);
        atual = atual->proximo;
    }
}

void fila_liberar(Fila *f) {
    Atendimento temp;
    while (!fila_vazia(f))
        fila_desenfileirar(f, &temp);
}
