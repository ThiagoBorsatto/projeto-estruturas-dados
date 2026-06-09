#ifndef HASH_H
#define HASH_H

#include "atendimento.h"

// =============================================
// Tabela Hash para agrupamento por categoria
// Acesso O(1) no caso medio
// Colisoes resolvidas por encadeamento (lista)
// =============================================
#define HASH_TAMANHO 10

typedef struct NoBucket {
    Atendimento dado;
    struct NoBucket *proximo;
} NoBucket;

typedef struct {
    NoBucket *buckets[HASH_TAMANHO];
} TabelaHash;

void hash_inicializar(TabelaHash *t);
void hash_inserir(TabelaHash *t, Atendimento a);
void hash_buscar_por_categoria(TabelaHash *t, const char *categoria);
void hash_liberar(TabelaHash *t);

#endif
