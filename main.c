#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "atendimento.h"
#include "fila.h"
#include "lista.h"
#include "arvore.h"
#include "hash.h"
#include "ordenacao.h"

// Limpa o buffer do teclado
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void exibir_menu() {
    printf("\n===== SISTEMA DE ATENDIMENTOS =====\n");
    printf("  1  - Cadastrar atendimento\n");
    printf("  2  - Atender proximo da fila\n");
    printf("  3  - Cancelar atendimento\n");
    printf("  4  - Listar fila de espera\n");
    printf("  5  - Listar historico\n");
    printf("  6  - Buscar por nome do cliente\n");
    printf("  7  - Buscar por prioridade\n");
    printf("  8  - Buscar por ID (arvore)\n");
    printf("  9  - Buscar por categoria (hash)\n");
    printf("  10 - Ordenar historico por prioridade\n");
    printf("  11 - Ordenar historico por tempo estimado\n");
    printf("  12 - Exibir estatisticas\n");
    printf("  13 - Gerar atendimentos de teste\n");
    printf("  0  - Sair\n");
    printf("===================================\n");
    printf("  Opcao: ");
}

void exibir_estatisticas(Lista *l) {
    if (lista_vazia(l)) { printf("  Sem dados.\n"); return; }

    int total = 0, atendidos = 0, cancelados = 0, abertos = 0;
    int baixa = 0, media = 0, alta = 0;

    NoLista *atual = l->cabeca;
    while (atual != NULL) {
        total++;
        if (strcmp(atual->dado.status, "atendido")  == 0) atendidos++;
        if (strcmp(atual->dado.status, "cancelado") == 0) cancelados++;
        if (strcmp(atual->dado.status, "aberto")    == 0) abertos++;
        if (atual->dado.prioridade == 1) baixa++;
        if (atual->dado.prioridade == 2) media++;
        if (atual->dado.prioridade == 3) alta++;
        atual = atual->proximo;
    }

    printf("\n  === ESTATISTICAS ===\n");
    printf("  Total de atendimentos : %d\n", total);
    printf("  Abertos               : %d\n", abertos);
    printf("  Atendidos             : %d\n", atendidos);
    printf("  Cancelados            : %d\n", cancelados);
    printf("  Prioridade Alta       : %d\n", alta);
    printf("  Prioridade Media      : %d\n", media);
    printf("  Prioridade Baixa      : %d\n", baixa);
}

int main() {
    Fila       fila;
    Lista      historico;
    NoArvore  *arvore = NULL;
    TabelaHash hash;

    fila_inicializar(&fila);
    lista_inicializar(&historico);
    hash_inicializar(&hash);

    int opcao;

    do {
        exibir_menu();
        if (scanf("%d", &opcao) != 1) { limpar_buffer(); continue; }
        limpar_buffer();

        switch (opcao) {

            // ---- 1. Cadastrar ----
            case 1: {
                printf("\n  -- Cadastrar Atendimento --\n");
                Atendimento a = cadastrar_atendimento();
                fila_enfileirar(&fila, a);
                lista_inserir(&historico, a);
                arvore  = arvore_inserir(arvore, a);
                hash_inserir(&hash, a);
                printf("  Atendimento #%d cadastrado e adicionado a fila.\n", a.id);
                break;
            }

            // ---- 2. Atender proximo ----
            case 2: {
                Atendimento a;
                if (fila_desenfileirar(&fila, &a)) {
                    lista_atualizar_status(&historico, a.id, "atendido");
                    // Atualiza na arvore tambem
                    NoArvore *no = arvore_buscar(arvore, a.id);
                    if (no) strcpy(no->dado.status, "atendido");
                    printf("  Atendimento #%d (%s) marcado como ATENDIDO.\n", a.id, a.cliente);
                } else {
                    printf("  Fila vazia. Nenhum atendimento pendente.\n");
                }
                break;
            }

            // ---- 3. Cancelar ----
            case 3: {
                printf("\n  ID do atendimento para cancelar: ");
                int id;
                scanf("%d", &id);
                limpar_buffer();
                if (lista_atualizar_status(&historico, id, "cancelado")) {
                    NoArvore *no = arvore_buscar(arvore, id);
                    if (no) strcpy(no->dado.status, "cancelado");
                    printf("  Atendimento #%d cancelado.\n", id);
                } else {
                    printf("  ID nao encontrado no historico.\n");
                }
                break;
            }

            // ---- 4. Listar fila ----
            case 4:
                printf("\n  -- Fila de Espera --\n");
                fila_listar(&fila);
                break;

            // ---- 5. Listar historico ----
            case 5:
                printf("\n  -- Historico de Atendimentos --\n");
                lista_listar(&historico);
                break;

            // ---- 6. Buscar por nome ----
            case 6: {
                printf("\n  Nome do cliente: ");
                char nome[50];
                scanf(" %49[^\n]", nome);
                NoLista *encontrado = lista_buscar_por_nome(&historico, nome);
                if (encontrado) {
                    printf("  Encontrado:\n");
                    exibir_atendimento(&encontrado->dado);
                } else {
                    printf("  Cliente '%s' nao encontrado.\n", nome);
                }
                break;
            }

            // ---- 7. Buscar por prioridade ----
            case 7: {
                printf("\n  Prioridade (1=Baixa, 2=Media, 3=Alta): ");
                int p;
                scanf("%d", &p);
                limpar_buffer();
                lista_buscar_por_prioridade(&historico, p);
                break;
            }

            // ---- 8. Buscar por ID na arvore ----
            case 8: {
                printf("\n  ID do atendimento: ");
                int id;
                scanf("%d", &id);
                limpar_buffer();
                NoArvore *no = arvore_buscar(arvore, id);
                if (no) {
                    printf("  Encontrado na arvore:\n");
                    exibir_atendimento(&no->dado);
                } else {
                    printf("  ID %d nao encontrado na arvore.\n", id);
                }
                break;
            }

            // ---- 9. Buscar por categoria na hash ----
            case 9: {
                printf("\n  Categoria: ");
                char cat[30];
                scanf(" %29[^\n]", cat);
                hash_buscar_por_categoria(&hash, cat);
                break;
            }

            // ---- 10. Ordenar por prioridade ----
            case 10:
                ordenar_por_prioridade(&historico);
                break;

            // ---- 11. Ordenar por tempo ----
            case 11:
                ordenar_por_tempo(&historico);
                break;

            // ---- 12. Estatisticas ----
            case 12:
                exibir_estatisticas(&historico);
                break;

            // ---- 13. Gerar testes ----
            case 13: {
                printf("\n  Quantos atendimentos gerar? ");
                int qtd;
                scanf("%d", &qtd);
                limpar_buffer();
                for (int i = 0; i < qtd; i++) {
                    Atendimento a = gerar_atendimento_teste(i);
                    fila_enfileirar(&fila, a);
                    lista_inserir(&historico, a);
                    arvore  = arvore_inserir(arvore, a);
                    hash_inserir(&hash, a);
                }
                printf("  %d atendimentos de teste gerados.\n", qtd);
                break;
            }

            case 0:
                printf("\n  Encerrando sistema...\n");
                break;

            default:
                printf("  Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    // Libera toda a memoria
    fila_liberar(&fila);
    lista_liberar(&historico);
    arvore_liberar(arvore);
    hash_liberar(&hash);

    return 0;
}
