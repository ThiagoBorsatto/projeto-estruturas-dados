#ifndef FILA_H
#define FILA_H

#include "atendimento.h"

// =============================================
// Fila dinamica (FIFO) para ordem de atendimento
// Cada no aponta para o proximo
// =============================================
typedef struct NoFila {
    Atendimento dado;
    struct NoFila *proximo;
} NoFila;

typedef struct {
    NoFila *inicio;
    NoFila *fim;
    int tamanho;
} Fila;

void fila_inicializar(Fila *f);
int  fila_vazia(Fila *f);
void fila_enfileirar(Fila *f, Atendimento a);
int  fila_desenfileirar(Fila *f, Atendimento *destino);
void fila_listar(Fila *f);
void fila_liberar(Fila *f);

#endif
