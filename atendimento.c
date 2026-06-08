#include <stdio.h>
#include <stdlib.h>
#include "atendimento.h"

int geradorDeIDConstentes() {
    static int idAtual = 0;

    idAtual++;
    return idAtual;
}

Atendimento* criarAtendimento(Atendimento* paciente){
    int id = geradorDeIDConstentes();
    char cliente[50];
    char categoria[30];
    int prioridade;      // 1 = baixa, 2 = média, 3 = alta
    int tempo_estimado;   // em minutos
    char status[20];

    printf("===== Cadastro do Paciente =====\n");
    printf("Nome do paciente: ");
    scanf("%c", cliente);
    printf("Categoria do atendimento: ");
    scanf("%c", categoria);
    printf("Prioridade: ");
    scanf("%d", prioridade);
    
    paciente->id = id;
}