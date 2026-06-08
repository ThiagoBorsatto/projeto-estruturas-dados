#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

NoArvore* arvore_inserir(NoArvore *raiz, Atendimento a) {
    if (raiz == NULL) {
        NoArvore *novo = (NoArvore*)malloc(sizeof(NoArvore));
        if (!novo) { printf("  Erro: memoria insuficiente.\n"); return raiz; }
        novo->dado     = a;
        novo->esquerda = NULL;
        novo->direita  = NULL;
        return novo;
    }
    if (a.id < raiz->dado.id)
        raiz->esquerda = arvore_inserir(raiz->esquerda, a);
    else if (a.id > raiz->dado.id)
        raiz->direita = arvore_inserir(raiz->direita, a);
    // ID duplicado: ignora
    return raiz;
}

NoArvore* arvore_buscar(NoArvore *raiz, int id) {
    if (raiz == NULL || raiz->dado.id == id) return raiz;
    if (id < raiz->dado.id) return arvore_buscar(raiz->esquerda, id);
    return arvore_buscar(raiz->direita, id);
}

// Encontra o menor no da subarvore (usado na remocao)
static NoArvore* menor_no(NoArvore *no) {
    while (no->esquerda != NULL) no = no->esquerda;
    return no;
}

NoArvore* arvore_remover(NoArvore *raiz, int id) {
    if (raiz == NULL) return NULL;

    if (id < raiz->dado.id) {
        raiz->esquerda = arvore_remover(raiz->esquerda, id);
    } else if (id > raiz->dado.id) {
        raiz->direita = arvore_remover(raiz->direita, id);
    } else {
        // No encontrado - 3 casos
        if (raiz->esquerda == NULL) {
            NoArvore *temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            NoArvore *temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        // Dois filhos: substitui pelo sucessor (menor da direita)
        NoArvore *suc  = menor_no(raiz->direita);
        raiz->dado     = suc->dado;
        raiz->direita  = arvore_remover(raiz->direita, suc->dado.id);
    }
    return raiz;
}

void arvore_liberar(NoArvore *raiz) {
    if (raiz == NULL) return;
    arvore_liberar(raiz->esquerda);
    arvore_liberar(raiz->direita);
    free(raiz);
}
