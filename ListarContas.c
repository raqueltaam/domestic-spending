#include <stdio.h>

void listarContasExtraordinarias()
{
    ContaExtraordinaria conta
    FILE *arquivo;
    char nomearq[] = "ContasExtraordinarias.dat";

    arquivo = fopen(nomearq, "r");
    if (arquivo != NULL)
    {
        rewind(arquivo); //colocando o ponteiro do arquivo no inicio do arquivo

        while (fread(&conta, sizeof(ContaExtraordinaria), 1, arquivo) != 0)
        {
            printf("\nConta Extraordinaria");
            printf("\nID: %d", conta.id);
            printf("\nTitulo: %s", conta.nome);
            printf("\nValor da conta: %.2f\n", conta.valor);
        }
    fclose(arquivo);
    }
    else
        printf("\nErro na abertura do arquivo\n");
}

void listarContasRecorrentes(c)
{
    ContaRecorrente conta
    FILE *arquivo;
    char nomearq[] = "ContasRecorrentes.dat";

    arquivo = fopen(nomearq, "r");
    if (arquivo != NULL)
    {
        rewind(arquivo);

        while (fread(&conta, sizeof(ContaRecorrente), 1, arquivo) != 0)
        {
            printf("\nConta Recorrente");
            printf("\nID: %d", conta.id);
            printf("\nTitulo: %s", conta.nome);
            printf("\nValor da conta: %.2f", conta.valor);
            printf("\nNumero de parcelas: %d", conta.parcelas);
            printf("\nData de vencimento: %d/%d/%d\n", conta.vencimento.dia, conta.vencimento.mes, conta.vencimento.ano)
        }
    fclose(arquivo);
    }
    else
        printf("Erro na abertura do arquivo\n");
}

void listarContasPeriodicas(c)
{
    ContaPeriodica conta
    FILE *arquivo;
    char nomearq[] = "ContasRecorrentes.dat";

    arquivo = fopen(nomearq, "r");
    if (arquivo != NULL)
    {
        rewind(arquivo);

        while (fread(&conta, sizeof(ContaPeriodica), 1, arquivo) != 0)
        {
            printf("\nConta Periodica");
            printf("\nID: %d", conta.id);
            printf("\nTitulo: %s", conta.nome);
            printf("\nValor da conta: %.2f", conta.valor);
            printf("\nData de vencimento: %d/%d/%d\n", conta.vencimento.dia, conta.vencimento.mes, conta.vencimento.ano)
        }
    fclose(arquivo);
    }
    else
        printf("\nErro na abertura do arquivo\n");
}

void voltarMenuAnterior() 
{ 
     mostrarMenu(); 
} 

void selecionarTipoConta (int menu)
{
        switch(menu)
        {
            case 1: listarContasExtraordinarias(); break;
            case 2: listarContasRecorrentes(); break;
            case 3: listarContasPeriodicas(); break;
            case 0: retornarMenuAnterior(); break;
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
            if ((menu > 0) && (menu < 4))
                selecionarTipoConta(menu);
            else
                printf("\n\nOpcao Invalida!\n\n");
    } while (menu !=0)
}

main ()
{

    listarContas();

}
