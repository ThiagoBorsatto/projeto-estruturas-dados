#include <stdio.h>
#include <stdlib.h>

int main() {
    int iniciarMenu = 1;
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

        switch (opcaoDeMenu)
        {
        case 0:
            printf("SAINDO\n");
            iniciarMenu = 0;
            break;
        case 1:
            printf("TESTE\n");
            break;
        case 2:
            printf("TESTE\n");
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