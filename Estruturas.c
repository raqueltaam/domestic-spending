typedef struct {
    int dia, mes, ano;
} tp_data;

typedef struct
{
    int id;
    char nome[50];
    float valor;
} ContaExtraordinaria;

typedef struct
{
    int id;
    char nome[50];
    float valor;
    int parcelas;
    tp_data vencimento;
} ContaRecorrente;

typedef struct
{
    int id;
    char nome[50];
    float valor;
    tp_data vencimento;
} ContaPeriodica;
