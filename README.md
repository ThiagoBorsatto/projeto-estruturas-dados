Contexto do Projeto
Uma empresa precisa controlar os atendimentos técnicos recebidos ao longo do dia. Esses atendimentos devem ser cadastrados, organizados em uma fila de espera, consultados posteriormente e analisados conforme diferentes critérios.

O objetivo do projeto é desenvolver, em linguagem C, um sistema de terminal que aplique estruturas de dados para resolver esse problema. A equipe deverá implementar suas próprias estruturas, organizar o código em módulos e justificar tecnicamente as escolhas realizadas.

Estrutura do Atendimento
Cada atendimento deve conter, no mínimo, os seguintes dados:

typedef struct {
    int id;
    char cliente[50];
    char categoria[30];
    int prioridade;      
    int tempo_estimado;   
    char status[20];      
} Atendimento;

Menu do sistema:

===== SISTEMA DE ATENDIMENTOS =====

1  - Cadastrar atendimento
2  - Atender próximo da fila
3  - Cancelar atendimento
4  - Listar fila de espera
5  - Listar histórico
6  - Buscar por nome do cliente
7  - Buscar por prioridade
8  - Buscar por ID usando árvore
9  - Buscar por categoria usando hash
10 - Ordenar histórico por prioridade
11 - Ordenar histórico por tempo estimado
12 - Exibir estatísticas
0  - Sair
