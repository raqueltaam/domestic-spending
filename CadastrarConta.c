#include <stdio.h>
#include "Estruturas.h"

//conta quantos registos existem no arquivo e gera uma nova id
//com o numero de registros + 1
int gerarIdExtraordinaria(FILE * arquivo)
{
    rewind(arquivo);
    int contador = 0;

    ContaExtraordinaria conta;

    while(fread(&conta, sizeof(ContaExtraordinaria), 1, arquivo) != 0)
    {
        contador++;
    }

    return ++contador;

}

int gerarIdRecorrente(FILE * arquivo)
{
    rewind(arquivo);
    int contador = 0;

    ContaRecorrente conta;

    while(fread(&conta, sizeof(ContaRecorrente), 1, arquivo) != 0)
    {
        contador++;
    }

    return ++contador;

}

int gerarIdPeriodica(FILE * arquivo)
{
    rewind(arquivo);
    int contador = 0;

    ContaPeriodica conta;

    while(fread(&conta, sizeof(ContaPeriodica), 1, arquivo) != 0)
    {
        contador++;
    }

    return ++contador;

}

//Le a estrutura da conta extraordinaria
void lerContaExtraordinaria(ContaExtraordinaria * c, FILE * arquivo)
{
    c->id = gerarIdExtraordinaria(arquivo);
    printf("Digite o titulo: ");
    fflush(stdin);
    gets(c->nome);
    printf("Digite o valor da conta: ");
    scanf("%f", &c->valor);
    printf("Digite o dia de lancamento(dia/mes/ano): ");
    scanf("%d/%d/%d", &c->lancamento.dia, &c->lancamento.mes, &c->lancamento.ano);

}

void lerContaRecorrente(ContaRecorrente * c, FILE * arquivo)
{
    c->id = gerarIdRecorrente(arquivo);
    printf("Digite o titulo: ");
    fflush(stdin);
    gets(c->nome);
    printf("Digite o valor da conta: ");
    scanf("%f", &c->valor);
    printf("Digite o numero de parcelas: ");
    scanf("%d", &c->parcelas);
    printf("Digite o dia de lancamento(dia/mes/ano): ");
    scanf("%d/%d/%d", &c->lancamento.dia, &c->lancamento.mes, &c->lancamento.ano);
    printf("Digite o dia em que a conta vence: ");
    scanf("%d", &c->diaVencimento);
}

void lerContaPeriodica(ContaPeriodica * c, FILE * arquivo)
{
    c->id = gerarIdPeriodica(arquivo);
    printf("Digite o titulo: ");
    fflush(stdin);
    gets(c->nome);
    printf("Digite o valor da conta: ");
    scanf("%f", &c->valor);
    printf("Digite o vencimento(dia/mes/ano): ");
    scanf("%d/%d/%d", &c->vencimento.dia, &c->vencimento.mes, &c->vencimento.ano);

}

void mostrarArquivoExtra(FILE * arquivo)
{
    rewind(arquivo);

    ContaExtraordinaria conta;

    while(fread(&conta, sizeof(ContaExtraordinaria), 1, arquivo) != 0)
    {
        printf("\nID: %d", conta.id);
        printf("\nNome: %s", conta.nome);
    }

}

void mostrarArquivoRec(FILE * arquivo)
{
    rewind(arquivo);

    ContaRecorrente conta;

    while(fread(&conta, sizeof(ContaRecorrente), 1, arquivo) != 0)
    {
        printf("\nID: %d", conta.id);
        printf("\nNome: %s", conta.nome);
    }

}

void mostrarArquivoPer(FILE * arquivo)
{
    rewind(arquivo);

    ContaPeriodica conta;

    while(fread(&conta, sizeof(ContaPeriodica), 1, arquivo) != 0)
    {
        printf("\nID: %d", conta.id);
        printf("\nNome: %s", conta.nome);
    }

}

//Cadastra uma nova conta extraordinaria no seu respectivo arquivo
//Retorna 1 caso tenha sucesso e 0 caso falhe
int cadastrarContaExtraordinaria()
{
    int retorno;
    ContaExtraordinaria conta;
    FILE * arquivo;
    arquivo = fopen("ContasExtraordinarias.dat", "a+b");

    if(arquivo != NULL)
    {

        lerContaExtraordinaria(&conta, arquivo);

        retorno = fwrite(&conta, sizeof(ContaExtraordinaria), 1, arquivo);
        if(retorno)
            return 1;
        else
            return 0;

        fclose(arquivo);
    }
}

//Cadastra uma nova conta recorrente no seu respectivo arquivo
//Retorna 1 caso tenha sucesso e 0 caso falhe
int cadastrarContaRecorrente()
{
    int retorno;
    ContaRecorrente conta;
    FILE * arquivo;
    arquivo = fopen("ContasRecorrentes.dat", "a+b");

    if(arquivo != NULL)
    {
        lerContaRecorrente(&conta, arquivo);

        retorno = fwrite(&conta, sizeof(ContaRecorrente), 1, arquivo);
        if(retorno)
            return 1;
        else
            return 0;

        fclose(arquivo);
    }
}

//Cadastra uma nova conta periodica no seu respectivo arquivo
//Retorna 1 caso tenha sucesso e 0 caso falhe
int cadastrarContaPeriodica()
{
    int retorno;
    ContaPeriodica conta;
    FILE * arquivo;
    arquivo = fopen("ContasPeriodicas.dat", "a+b");

    if(arquivo != NULL)
    {
        lerContaPeriodica(&conta, arquivo);

        retorno = fwrite(&conta, sizeof(ContaExtraordinaria), 1, arquivo);
        if(retorno)
            return 1;
        else
            return 0;

        flcose(arquivo);
    }


}

//Mostra o menu na tela e retorna a opcao digitada
int mostrarMenuCadastro()
{
    int opcao;

    system("cls");

    printf("\n\t\tCadastrar Nova Conta\n");
    printf("\t1 - Cadastrar Conta Extraordinaria\n");
    printf("\t2 - Cadastrar Conta Recorrente\n");
    printf("\t3 - Cadastrar Conta Periodica\n");
    printf("\t0 - Retornar ao menu aterior\n");
    printf("\tDigite a opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

void voltarMenuAnterior()
{
    //mostrarMenu();
}

//Função principal do módulo. Ela chama o menu de cadastro e a partir dele
//chama as funções de cadastro de novas contas ou retorna ao menu anterior.
void cadastrarConta()
{
    int opcao;

    opcao = mostrarMenuCadastro();

    while(opcao != 0)
    {
        switch(opcao)
        {
            case 1: cadastrarContaExtraordinaria(); break;
            case 2: cadastrarContaRecorrente(); break;
            case 3: cadastrarContaPeriodica(); break;
        }

        opcao = mostrarMenuCadastro();
    }

    voltarMenuAnterior();
}

main()
{
    cadastrarConta();

    /*FILE * arq = fopen("ContasExtraordinarias.dat", "rb");
    mostrarArquivoExtra(arq);
    fclose(arq);

    arq = fopen("ContasRecorrentes.dat", "rb");
    mostrarArquivoRec(arq);
    fclose(arq);

    arq = fopen("ContasPeriodicas.dat", "rb");
    mostrarArquivoPer(arq);
    fclose(arq);*/

}
