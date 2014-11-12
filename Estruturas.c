typedef struct {
    int dia, mes, ano;
} tp_data;

typedef struct
{
    int id;
    char nome[50];
    float valor[10];
} ContaExtraordinaria;

typedef struct
{
    int id;
    char nome[50];
    float valor[10];
    int parcelas;
    tp_data vencimento;
} ContaRecorrente;

typedef struct
{
    int id;
    char nome[50];
    float valor[10];
    tp_data vencimento;
} ContaPeriodica;
