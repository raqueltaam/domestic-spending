#ifndef ESTRUTURAS
#define ESTRUTURAS

typedef struct {
    int dia, mes, ano;
} tp_data;

typedef struct
{
    int pago;
    int ativo;
    int id;
    char nome[50];
    float valor;
    tp_data lancamento;
} ContaExtraordinaria;

typedef struct
{
    int pago;
    int ativo;
    int id;
    char nome[50];
    float valor;
    int parcelas;
    tp_data lancamento;
    int diaVencimento;
} ContaRecorrente;

typedef struct
{
    int pago;
    int ativo;
    int id;
    char nome[50];
    float valor;
    tp_data vencimento;
} ContaPeriodica;

#endif // ESTRUTURAS
