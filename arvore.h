#ifndef ARVORE_H
#define ARVORE_H

typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

No* criarNo(int valor);
No* inserirNaArvore(No *raiz, int valor); 
int buscarNaArvore(No *raiz, int valor, long long *comparacoes);
int calcularAltura(No *raiz);
void liberarArvore(No *raiz);

#endif