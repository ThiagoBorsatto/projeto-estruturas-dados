#include <stdio.h>
#include "ordenacao.h"

// Troca os DADOS de dois nos (nao os ponteiros)
static void trocar(NoLista *a, NoLista *b) {
    Atendimento temp = a->dado;
    a->dado = b->dado;
    b->dado = temp;
}

// Bubble sort decrescente por prioridade (3=Alta primeiro)
void ordenar_por_prioridade(Lista *l) {
    if (lista_vazia(l)) return;

    int trocou;
    do {
        trocou = 0;
        NoLista *atual = l->cabeca;
        while (atual->proximo != NULL) {
            if (atual->dado.prioridade < atual->proximo->dado.prioridade) {
                trocar(atual, atual->proximo);
                trocou = 1;
            }
            atual = atual->proximo;
        }
    } while (trocou);

    printf("  Historico ordenado por prioridade (Alta -> Baixa).\n");
}

// Bubble sort crescente por tempo estimado (menor primeiro)
void ordenar_por_tempo(Lista *l) {
    if (lista_vazia(l)) return;

    int trocou;
    do {
        trocou = 0;
        NoLista *atual = l->cabeca;
        while (atual->proximo != NULL) {
            if (atual->dado.tempo_estimado > atual->proximo->dado.tempo_estimado) {
                trocar(atual, atual->proximo);
                trocou = 1;
            }
            atual = atual->proximo;
        }
    } while (trocou);

    printf("  Historico ordenado por tempo estimado (menor -> maior).\n");
}
