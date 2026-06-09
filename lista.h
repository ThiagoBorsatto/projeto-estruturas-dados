#ifndef LISTA_H
#define LISTA_H

#include "atendimento.h"

// =============================================
// Lista encadeada simples para historico
// Mantem todos os atendimentos cadastrados
// =============================================
typedef struct NoLista {
    Atendimento dado;
    struct NoLista *proximo;
} NoLista;

typedef struct {
    NoLista *cabeca;
    int tamanho;
} Lista;

void lista_inicializar(Lista *l);
int  lista_vazia(Lista *l);
void lista_inserir(Lista *l, Atendimento a);
void lista_listar(Lista *l);
void lista_liberar(Lista *l);

// Busca sequencial
NoLista* lista_buscar_por_nome(Lista *l, const char *nome);
void     lista_buscar_por_prioridade(Lista *l, int prioridade);

// Atualiza status de um atendimento pelo ID
int lista_atualizar_status(Lista *l, int id, const char *novo_status);

// Retorna ponteiro para o no com o ID informado
NoLista* lista_buscar_por_id(Lista *l, int id);

#endif
