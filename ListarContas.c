#include <stdio.h>
#define ERRO_ABERTURA NULL

const int fim = 0;
enum contas {contasExtraordinarias = 1, contasRecorrentes, contasPeriodicas};
//enum tipo {atvivo = 1};
//estou mostrando todas as contas extraordinarias
void mostrarContasExtraordinarias (FILE *arq)
{
    ContaExtraordinaria conta;
    rewind(arq); //colocando o ponteiro do arquivo no inicio do arquivo

    while (fread(&conta, sizeof(ContaExtraordinaria), 1, arq) != fim) //lendo aruivo e printando na tela 
    {
        if (conta.ativo == 0) //estou mostrando as contas que não foram pagas
        {
            printf("\nConta Extraordinaria");
            printf("\nID: %d", conta.id);
            printf("\nTitulo: %s", conta.nome);
            printf("\nValor da conta: %.2f\n", conta.valor);
            printf("\nData de Lançamento: %d/%d/%d\n", conta.lancamento.dia, conta.lancamento.mes, conta.lancamento.ano);
        }
    }
}

//estou mostrando todas as contas recorrentes
void mostrarContasRecorrentes (FILE *arq)
{
    ContaRecorrente conta;
    rewind(arq);

    while (fread(&conta, sizeof(ContaRecorrente), 1, arq) != fim)
    {
        if (conta.ativo == 0)
        {
            printf("\nConta Recorrente");
            printf("\nID: %d", conta.id);
            printf("\nTitulo: %s", conta.nome);
            printf("\nValor da conta: %.2f", conta.valor);
            printf("\nNumero de parcelas: %d", conta.parcelas);
            printf("\nDia de vencimento: %d", conta.diaVencomento);
            printf("\nData de Lançamento: %d/%d/%d\n", conta.lancamento.dia, conta.lancamento.mes, conta.lancamento.ano);   
        }
    }
}

//estou mostrando todas as contas periodicas
void mostrarContasPeriodicas(FILE *arq)
{
    ContaPeriodica conta;
    rewind(arq);

    while (fread(&conta, sizeof(ContaPeriodica), 1, arq) != fim)
    {
        if (conta.ativo == 0)
        {
            printf("\nConta Periodica");
            printf("\nID: %d", conta.id);
            printf("\nTitulo: %s", conta.nome);
            printf("\nValor da conta: %.2f", conta.valor);
            printf("\nData de vencimento: %d/%d/%d\n", conta.lancamento.dia, conta.lancamento.mes, conta.lancamento.ano);
        }
    }
}

void listarContasExtraordinarias()
{
    FILE *arquivo;
    char nomearq[] = "ContasExtraordinarias.dat";

    arquivo = fopen(nomearq, "rb"); //abrindo o arquivo
    if (arquivo != ERRO_ABERTURA) //verificando se ele abriu 
    {
        mostrarContasExtraordinarias(arquivo); //mostro as contas
    fclose(arquivo); //fecho o arquivo
    }
    else
        printf("\nErro na abertura do arquivo\n");
}

void listarContasRecorrentes()
{
    FILE *arquivo;
    char nomearq[] = "ContasRecorrentes.dat";

    arquivo = fopen(nomearq, "rb");
    if (arquivo != ERRO_ABERTURA)
    {
        mostrarContasRecorrentes(arquivo);
    fclose(arquivo);
    }
    else
        printf("\nErro na abertura do arquivo\n");
}

void listarContasPeriodicas()
{
    FILE *arquivo;
    char nomearq[] = "ContasPeriodicas.dat";

    arquivo = fopen(nomearq, "rb");
    if (arquivo != ERRO_ABERTURA)
    {
        mostrarContasPeriodicas(arquivo);
    fclose(arquivo);
    }
    else
        printf("\nErro na abertura do arquivo\n");
}

void selecionarTipoConta (int menu)
{
        switch(menu)
        {
            case contasExtraordinarias: listarContasExtraordinarias(); break;
            case contasRecorrentes: listarContasRecorrentes(); break;
            case contasPeriodicas: listarContasPeriodicas(); break;
        }
}

void listarContas()
{
    int menu;

    system("cls");

    do
    {
        printf("Listar Contas\n\n");
        printf("\t1 - Listar Conta Extraordinaria\n");
        printf("\t2 - Listar Conta Recorrente\n");
        printf("\t3 - Listar Conta Periodica\n");
        printf("\t0 - Retornar ao menu aterior\n");
        printf("\nDigite a opcao: ");
        scanf("%d", &menu);
        if (menu != fim)
            if ((menu >= contasExtraordinarias) && (menu <= contasPeriodicas)) //verificando se o usuario digito a opção valida
                selecionarTipoConta(menu);
            else
                printf("\n\nOpcao Invalida!\n\n");
    } while (menu != fim)
    mostrarMenu(); //voltando para o menu inicial 
}
