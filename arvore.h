#ifndef ARVORE_H
#define ARVORE_H

#include "atendimento.h"

// =============================================
// Arvore Binaria de Busca (BST) por ID
// Busca em O(log n) no caso medio
// Mais eficiente que lista para grandes volumes
// =============================================
typedef struct NoArvore {
    Atendimento dado;
    struct NoArvore *esquerda;
    struct NoArvore *direita;
} NoArvore;

NoArvore* arvore_inserir(NoArvore *raiz, Atendimento a);
NoArvore* arvore_buscar(NoArvore *raiz, int id);
NoArvore* arvore_remover(NoArvore *raiz, int id);
void      arvore_liberar(NoArvore *raiz);

#endif
