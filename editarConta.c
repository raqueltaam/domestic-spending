#include <stdio.h>

void editarVencimento(int *Dia) // edita o vencimento da conta
{
    printf("Entre com novo dia");
    scanf("%d",Dia);

}
void editarNome(char *nome[50]) //edita o nome da conta
{
    printf("Entre com novo nome");
    gets(nome);

}
void editarValor(float *valor) // edita o valor da conta
{
    printf("Entre com novo valor");
    scanf("%f",valor);

}
void editarParcela(int *parcela) // edita a parcela da conta
{
    printf("Entre com novo numero de parcelas");
    scanf("%d",parcela);
}
void editarData(int *Dia, int *Mes , int *Ano) // edita a data da conta
{
    printf("Entre com novo dia");
    scanf("%d",Dia);
    printf("Entre com novo mes");
    scanf("%d",Mes);
    printf("Entre com novo ano");
    scanf("%d",Ano);

}

void editarExtraordinarias() // edita as contas extraordinarias
{
    int idLido,sair=1,achou=0,ret;
    ContaExtraordina RegExtraordinaria;
    FILE *arq;
    char nomearq[]="ContasExtraordinarias.dat";

    arq=fopen(nomearq, "r+b");
    if (arq != NULL)
    {
        printf("Enter com o ID")
        scanf("%d",idLido)
        fseek(arq,0,SEEK_SET)
        while((ret = fread(&RegExtraordinaria, sizeof(ContaExtraordinaria), 1, arq)!=0)&&sair)
        {
            if(idLido==RegExtraordinaria.id)
            {
                sair=0;
                achou=1;
            }

        }
        if(achou)
        {
            editarNome(&RegExtraordinaria.nome);
            editarValor(&RegExtradinaria.valor);
            editarData(&RegExtraordinaria.lancamento.dia,&RegExtraordinaria.lancamento.mes,&RegExtraordinaria.lancamento.ano);
            fseek(arq,-1,SEEK_CUT);
            ret = fwrite(RegExtraordinaria, sizeof(ContaExtraordinaria), 1, arq);
            fclose(arq);

        }
        else
            printf("Nao foi achado esse ID");

    }
    else
        printf("Erro em abrir o arquivo");


}

void editarRecorrente() // edita as contas recorrentes
{
    int idLido,sair=1,achou=0,ret;
    ContaRecorrente RegRecorrente;
    FILE *arq;
    char nomearq[]="ContasMensais.dat";

    arq=fopen(nomearq, "r+b");
    if (arq != NULL)
    {
        printf("Enter com o ID")
        scanf("%d",idLido)
        fseek(arq,0,SEEK_SET)
        while((ret = fread(&RegRecorrente, sizeof(ContaRecorrente), 1, arq)!=0)&&sair)
        {
            if(idLido==RegRecorrente.id)
            {
                sair=0;
                achou=1;
            }

        }
        if(achou)
        {
            editarNome(&RegRecorrente.nome);
            editarValor(&RegRecorrente.valor);
            editarParcela(&RegRecorrente.parcela);
            editarVencimento(&RegRecorrente.diaVencimento);
            editarData(&RegRecorrente.lancamento.dia,&RegRecorrente.lancamento.mes,&RegRecorrente.lancamento.ano);
            fseek(arq,-1,SEEK_CUT);
            ret = fwrite(RegRecorrente, sizeof(ContaRecorrente), 1, arq);
            fclose(arq);
        }
        else
            printf("Nao foi achado esse ID");

    }
    else
        printf("Erro em abrir o arquivo");
}

void editarPeriodica() // edita as contas periodicas
{
    int idLido,sair=1,achou=0,ret;
    ContaPeriodica RegPeriodica;
    FILE *arq;
    char nomearq[]="ContasPeridocas.dat";

    arq=fopen(nomearq, "r+b");
    if (arq != NULL)
    {
        printf("Enter com o ID")
        scanf("%d",idLido)
        fseek(arq,0,SEEK_SET)
        while((ret = fread(&RegPeriodica, sizeof(ContaPeriodica), 1, arq)!=0)&&sair)
        {
            if(idLido==RegPeriodica.id)
            {
                sair=0;
                achou=1;
            }

        }
        if(achou)
        {
            editarNome(&RegPeriodica.nome);
            editarValor(&RegPeriodica.valor);
            editarData(&RegPeriodica.vencimento.dia,&RegPeriodica.vencimento.mes,&RegPeriodica.vencimento.ano);
            fseek(arq,-1,SEEK_CUT);
            ret = fwrite(RegPeriodica, sizeof(ContaPeriodica), 1, arq);
            fclose(arq);
        }
        else
            printf("Nao foi achado esse ID");


    }
    else
        printf("Erro em abrir o arquivo");
}

void editarConta() // inicia o processo de editar conta
{
    int numLido;

    printf("Qual conta gostaria de editar ?");
    printf("\n\t[1]Conta Extraordinaria\n\t[2]Conta Mensal\n\t[3]Conta Periodica\n\t[0]Voltar ao menu Anterior\n");
    scanf("%d",&numLido);
    switch (numLido)
    {
    case 1:
        editarExtraordinarias();break;
    case 2:
        editarMensal();break;
    case 3:
        editarPeriodica();break;
    case 0:
        mostrarMenu();break;
    }

}

main()
{
    int op;
    editarConta();
    op = mostrarMenu();//voltar menu
    exercutarOperacao(op);
}
