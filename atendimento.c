#include <stdio.h>
#include <string.h>
#include "atendimento.h"

// Contador global de IDs
static int contador_id = 1;

int proximo_id() {
    return contador_id++;
}

const char* prioridade_texto(int p) {
    if (p == 1) return "Baixa";
    if (p == 2) return "Media";
    if (p == 3) return "Alta";
    return "Desconhecida";
}

void exibir_atendimento(Atendimento *a) {
    printf("  ID: %d | Cliente: %s | Categoria: %s\n", a->id, a->cliente, a->categoria);
    printf("  Prioridade: %s | Tempo: %d min | Status: %s\n",
           prioridade_texto(a->prioridade), a->tempo_estimado, a->status);
    printf("  ----------------------------------------\n");
}

Atendimento cadastrar_atendimento() {
    Atendimento a;
    a.id = proximo_id();

    printf("  Cliente: ");
    scanf(" %49[^\n]", a.cliente);

    printf("  Categoria (ex: Hardware, Software, Rede): ");
    scanf(" %29[^\n]", a.categoria);

    printf("  Prioridade (1=Baixa, 2=Media, 3=Alta): ");
    do {
        scanf("%d", &a.prioridade);
        if (a.prioridade < 1 || a.prioridade > 3)
            printf("  Valor invalido. Digite 1, 2 ou 3: ");
    } while (a.prioridade < 1 || a.prioridade > 3);

    printf("  Tempo estimado (minutos): ");
    do {
        scanf("%d", &a.tempo_estimado);
        if (a.tempo_estimado <= 0)
            printf("  Valor invalido. Digite um numero positivo: ");
    } while (a.tempo_estimado <= 0);

    strcpy(a.status, "aberto");
    return a;
}

Atendimento gerar_atendimento_teste(int i) {
    Atendimento a;
    a.id = proximo_id();

    const char *nomes[]     = {"Ana", "Bruno", "Carlos", "Diana", "Eduardo"};
    const char *categorias[] = {"Hardware", "Software", "Rede", "Impressora", "Email"};

    snprintf(a.cliente, 50, "%s_%d", nomes[i % 5], i);
    snprintf(a.categoria, 30, "%s", categorias[i % 5]);
    a.prioridade     = (i % 3) + 1;
    a.tempo_estimado = (i % 5 + 1) * 10;
    strcpy(a.status, "aberto");
    return a;
}
