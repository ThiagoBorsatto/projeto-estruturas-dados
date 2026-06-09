#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

// Funcao hash simples: soma dos caracteres % tamanho
static int hash_funcao(const char *categoria) {
    int soma = 0;
    for (int i = 0; categoria[i] != '\0'; i++)
        soma += (unsigned char)categoria[i];
    return soma % HASH_TAMANHO;
}

void hash_inicializar(TabelaHash *t) {
    for (int i = 0; i < HASH_TAMANHO; i++)
        t->buckets[i] = NULL;
}

void hash_inserir(TabelaHash *t, Atendimento a) {
    int indice = hash_funcao(a.categoria);

    NoBucket *novo = (NoBucket*)malloc(sizeof(NoBucket));
    if (!novo) { printf("  Erro: memoria insuficiente.\n"); return; }

    novo->dado    = a;
    novo->proximo = t->buckets[indice];  // encadeamento
    t->buckets[indice] = novo;
}

void hash_buscar_por_categoria(TabelaHash *t, const char *categoria) {
    int indice = hash_funcao(categoria);
    NoBucket *atual = t->buckets[indice];
    int encontrou = 0;

    while (atual != NULL) {
        if (strcmp(atual->dado.categoria, categoria) == 0) {
            exibir_atendimento(&atual->dado);
            encontrou = 1;
        }
        atual = atual->proximo;
    }
    if (!encontrou)
        printf("  Nenhum atendimento encontrado para categoria: %s\n", categoria);
}

void hash_liberar(TabelaHash *t) {
    for (int i = 0; i < HASH_TAMANHO; i++) {
        NoBucket *atual = t->buckets[i];
        while (atual != NULL) {
            NoBucket *prox = atual->proximo;
            free(atual);
            atual = prox;
        }
        t->buckets[i] = NULL;
    }
}
