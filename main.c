#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "atendimento.h"
#include "lista.h"
#include "fila.h"
#include "arvore.h"
#include "hash.h"

int main() {
    int iniciarMenu = 1;
    
    Fila       fila;
    Lista      historico;
    NoArvore  *arvore = NULL;
    TabelaHash hash;

    fila_inicializar(&fila);
    lista_inicializar(&historico);
    hash_inicializar(&hash);

    int opcaoDeMenu = 0;

    while (iniciarMenu) {
        printf("===== SISTEMA DE ATENDIMENTOS =====\n");
        printf("1  - Cadastrar atendimento\n");
        printf("2  - Atender proximo da fila\n");
        printf("3  - Cancelar atendimento\n");
        printf("4  - Listar fila de espera\n");
        printf("5  - Listar historico\n");
        printf("6  - Buscar por nome do cliente\n");
        printf("7  - Buscar por prioridade\n");
        printf("8  - Buscar por ID usando arvore\n");
        printf("9  - Buscar por categoria usando hash\n");
        printf("10 - Ordenar historico por prioridade\n");
        printf("11 - Ordenar historico por tempo estimado\n");
        printf("12 - Exibir estatisticas\n");
        printf("0  - Sair\n");

        scanf("%d", &opcaoDeMenu);

        switch (opcaoDeMenu) {
        case 0:
            printf("Saindo do sistema...\n");
            iniciarMenu = 0;
            break;
        case 1:
            printf("\n  -- Cadastrar Atendimento --\n");
                Atendimento a = cadastrar_atendimento();
                fila_enfileirar(&fila, a);
                lista_inserir(&historico, a);
                arvore  = arvore_inserir(arvore, a);
                hash_inserir(&hash, a);
                printf("  Atendimento #%d cadastrado e adicionado a fila.\n", a.id);
                break;
        case 2:
            Atendimento a;
                if (fila_desenfileirar(&fila, &a)) {
                    lista_atualizar_status(&historico, a.id, "atendido");
                    NoArvore *no = arvore_buscar(arvore, a.id);
                    if (no) strcpy(no->dado.status, "atendido");
                    printf("  Atendimento #%d (%s) marcado como ATENDIDO.\n", a.id, a.cliente);
                } else {
                    printf("  Fila vazia. Nenhum atendimento pendente.\n");
                }
                break;
        case 3:
            printf("TESTE\n");
            break;
        case 4:
            printf("TESTE\n");
            break;
        case 5:
            printf("TESTE\n");
            break;
        case 6:
            printf("TESTE\n");
            break;
        case 7:
            printf("TESTE\n");
            break;
        case 8:
            printf("TESTE\n");
            break;
        case 9:
            printf("TESTE\n");
            break;
        case 10:
            printf("TESTE\n");
            break;
        case 11:
            printf("TESTE\n");
            break;
        case 12:
            printf("TESTE\n");
            break;
        
        default:
            break;
        }
    }
    
    return 0;
}