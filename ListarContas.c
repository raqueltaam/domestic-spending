#include <stdio.h>

enum contas {contasExtraordinarias = 1, contasRecorrentes, contasPeriodicas};
//estou mostrando todas as contas extraordinarias
void mostrarContasExtraordinarias (FILE *arq)
{
    ContaExtraordinaria conta;
    rewind(arq); //colocando o ponteiro do arquivo no inicio do arquivo

    while (fread(&conta, sizeof(ContaExtraordinaria), 1, arq) != 0) //lendo aruivo e printando na tela 
    {
        printf("\nConta Extraordinaria");
        printf("\nID: %d", conta.id);
        printf("\nTitulo: %s", conta.nome);
        printf("\nValor da conta: %.2f\n", conta.valor);
    }
}

//estou mostrando todas as contas recorrentes
void mostrarContasRecorrentes (FILE *arq)
{
    ContaRecorrente conta;
    rewind(arq);

    while (fread(&conta, sizeof(ContaRecorrente), 1, arq) != 0)
    {
        printf("\nConta Recorrente");
        printf("\nID: %d", conta.id);
        printf("\nTitulo: %s", conta.nome);
        printf("\nValor da conta: %.2f", conta.valor);
        printf("\nNumero de parcelas: %d", conta.parcelas);
        printf("\nData de vencimento: %d/%d/%d\n", conta.vencimento.dia, conta.vencimento.mes, conta.vencimento.ano)
    }
}

//estou mostrando todas as contas recorrentes
void listarContasPeriodicas(FILE *arq)
{
    ContaPeriodica conta;
    rewind(arq);

    while (fread(&conta, sizeof(ContaPeriodica), 1, arq) != 0)
    {
        printf("\nConta Periodica");
        printf("\nID: %d", conta.id);
        printf("\nTitulo: %s", conta.nome);
        printf("\nValor da conta: %.2f", conta.valor);
        printf("\nData de vencimento: %d/%d/%d\n", conta.vencimento.dia, conta.vencimento.mes, conta.vencimento.ano)
    }
}

void listarContasExtraordinarias()
{
    FILE *arquivo;
    char nomearq[] = "ContasExtraordinarias.dat";

    arquivo = fopen(nomearq, "r"); //abrindo o arquivo
    if (arquivo != NULL) //verificando se ele abriu 
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

    arquivo = fopen(nomearq, "r");
    if (arquivo != NULL)
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

    arquivo = fopen(nomearq, "r");
    if (arquivo != NULL)
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
        if (menu != 0)
            if ((menu >= contasExtraordinarias) && (menu <= contasPeriodicas)) //verificando se o usuario digito a opção valida
                selecionarTipoConta(menu);
            else
                printf("\n\nOpcao Invalida!\n\n");
    } while (menu != 0)
    mostrarMenu(); //voltando para o menu inicial 
}

main ()
{
    listarContas();
}
