#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void lista_inicializar(Lista *l) {
    l->cabeca   = NULL;
    l->tamanho  = 0;
}

int lista_vazia(Lista *l) {
    return l->cabeca == NULL;
}

void lista_inserir(Lista *l, Atendimento a) {
    NoLista *novo = (NoLista*)malloc(sizeof(NoLista));
    if (!novo) {
        printf("  Erro: memoria insuficiente.\n");
        return;
    }
    novo->dado    = a;
    novo->proximo = l->cabeca;  // insere no inicio (mais rapido)
    l->cabeca     = novo;
    l->tamanho++;
}

void lista_listar(Lista *l) {
    if (lista_vazia(l)) {
        printf("  Historico vazio.\n");
        return;
    }
    printf("  Total no historico: %d\n\n", l->tamanho);
    NoLista *atual = l->cabeca;
    while (atual != NULL) {
        exibir_atendimento(&atual->dado);
        atual = atual->proximo;
    }
}

// Busca sequencial por nome (primeira ocorrencia)
NoLista* lista_buscar_por_nome(Lista *l, const char *nome) {
    NoLista *atual = l->cabeca;
    while (atual != NULL) {
        if (strcmp(atual->dado.cliente, nome) == 0)
            return atual;
        atual = atual->proximo;
    }
    return NULL;
}

// Lista todos com a prioridade informada
void lista_buscar_por_prioridade(Lista *l, int prioridade) {
    int encontrou = 0;
    NoLista *atual = l->cabeca;
    while (atual != NULL) {
        if (atual->dado.prioridade == prioridade) {
            exibir_atendimento(&atual->dado);
            encontrou = 1;
        }
        atual = atual->proximo;
    }
    if (!encontrou)
        printf("  Nenhum atendimento com prioridade %d encontrado.\n", prioridade);
}

int lista_atualizar_status(Lista *l, int id, const char *novo_status) {
    NoLista *atual = l->cabeca;
    while (atual != NULL) {
        if (atual->dado.id == id) {
            strcpy(atual->dado.status, novo_status);
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

NoLista* lista_buscar_por_id(Lista *l, int id) {
    NoLista *atual = l->cabeca;
    while (atual != NULL) {
        if (atual->dado.id == id) return atual;
        atual = atual->proximo;
    }
    return NULL;
}

void lista_liberar(Lista *l) {
    NoLista *atual = l->cabeca;
    while (atual != NULL) {
        NoLista *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    l->cabeca  = NULL;
    l->tamanho = 0;
}
