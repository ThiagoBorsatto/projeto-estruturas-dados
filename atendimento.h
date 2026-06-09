#ifndef ATENDIMENTO_H
#define ATENDIMENTO_H
 
// =============================================
// Estrutura principal de um atendimento
// =============================================
typedef struct Atendimento{
    int id;
    char cliente[50];
    char categoria[30];
    int prioridade;       // 1 = baixa, 2 = media, 3 = alta
    int tempo_estimado;   // em minutos
    char status[20];      // aberto, atendido ou cancelado
} Atendimento;
 
// Retorna proximo ID unico
int proximo_id();
 
// Exibe os dados de um atendimento na tela
void exibir_atendimento(Atendimento *a);
 
// Preenche um atendimento com dados do usuario
Atendimento cadastrar_atendimento();
 
// Gera atendimento automatico para testes
Atendimento gerar_atendimento_teste(int i);
 
// Converte prioridade numerica para texto
const char* prioridade_texto(int p);
 
#endif
