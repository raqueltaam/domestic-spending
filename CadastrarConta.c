#include <stdio.h>

//conta quantos registos existem no
int gerarId()
{

}

//Le a estrutura da conta extraordinaria
void lerContaExtraordinaria(ContaExtraordinaria * c)
{
    c.id = gerarId();
    printf("Digite o titulo: ");
    gets(c->nome);
    printf("Digite o valor da conta: ");
    scanf("%f", &c->valor);

}

//Le a estrutura da conta recorrente
void lerContaRecorrente(ContaRecorrente * c)
{
    c.id = gerarId();
    printf("Digite o titulo: ");
    gets(c->nome);
    printf("Digite o valor da conta: ");
    scanf("%f", &c->valor);
    printf("Digite o numero de parcelas: ");
    scanf("%d", &c->parcelas);
    printf("Digite o vencimento(dia/mes/ano): ");
    scanf("%d/%d/%d", &c->data.dia, &c->data.mes, &c->data.ano);
}

//Le a estrutura da conta periodica
void lerContaPeriodica(ContaPeriodica * c)
{
    c.id = gerarId();
    printf("Digite o titulo: ");
    gets(c->nome);
    printf("Digite o valor da conta: ");
    scanf("%f", &c->valor);
    printf("Digite o vencimento(dia/mes/ano): ");
    scanf("%d/%d/%d", &c->data.dia, &c->data.mes, &c->data.ano);

}

//Cadastra uma nova conta extraordinaria no seu respectivo arquivo
//Retorna 1 caso tenha sucesso e 0 caso falhe
int cadastrarContaExtraordinaria(ContaExraordinaria conta)
{
    int retorno;
    FILE * arquivo;
    arquivo = fopen("ContasExtraordinarias.dat", "a+b");

    if(arquivo != NULL)
    {
        retorno = fwrite(&conta, sizeof(ContaExtraordinaria), 1, arquivo);
        if(retorno)
            return 1;
        else
            return 0;
    }
}

//Cadastra uma nova conta recorrente no seu respectivo arquivo
//Retorna 1 caso tenha sucesso e 0 caso falhe
int cadastrarContaRecorrente(ContaRecorrente conta)
{
    int retorno;
    FILE * arquivo;
    arquivo = fopen("ContasRecorrentes.dat", "a+b");

    if(arquivo != NULL)
    {
        retorno = fwrite(&conta, sizeof(ContaRecorrente), 1, arquivo);
        if(retorno)
            return 1;
        else
            return 0;
    }
}

//Cadastra uma nova conta periodica no seu respectivo arquivo
//Retorna 1 caso tenha sucesso e 0 caso falhe
int cadastrarContaPeriodica(ContaPeriodica conta)
{
    int retorno;
    FILE * arquivo;
    arquivo = fopen("ContasPeriodicas.dat", "a+b");

    if(arquivo != NULL)
    {
        retorno = fwrite(&conta, sizeof(ContaExtraordinaria), 1, arquivo);
        if(retorno)
            return 1;
        else
            return 0;
    }


}

//Mostra o menu na tela e retorna a opcao digitada
int mostrarMenuCadastro()
{
    int opcao;

    system("cls");

    printf("Cadastrar Nova Conta");
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
    mostrarMenu();
}

//
void cadastrarConta()
{
    int opcao;

    mostrarMenuCadastro();

    switch(opcao)
    {
        case 1: cadastrarContasExtraordinarias(c); break;
        case 2: cadastrarContasRecorrentes(c); break;
        case 3: cadastrarContasPeriodicas(c); break;
        case 0: retornarMenuAnterior(c); break;
    }

}
