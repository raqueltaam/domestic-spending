#include <stdio.h>

void editarNome(char *nome[20])
{
    printf("Entre com novo nome");
    scanf("%s",conta->nome);

}
void editarValor(float *valor)
{
    printf("Entre com novo valor");
    scanf("%f",&valor);

}
void editarParcela(int *parcela)
{
    printf("Entre com novo numero de parcelas");
    scanf("%d",&parcela);
}
void editarVencimento(int Dia, int Mes , int Ano)
{
    printf("Entre com novo dia");
    scanf("%d",&Dia);
     printf("Entre com novo mes");
    scanf("%d",&Mes);
     printf("Entre com novo ano");
    scanf("%d",&Ano);

}

void editarExtra()
{
    int idLido,sair=1,achou=0,ret;
    ContaExtraordina vetorExtra;
    FILE *arq;
    char nomearq[]="ContasExtraordinarias.dat";

    arq=fopen(nomearq, "r+b");
    if (arq != NULL)
    {
        printf("Enter com o ID")
        scanf("%d",idLido)
        fseek(arq,0,SEEK_SET)
        while(arq!=EOF&&sair)
        {
            ret = fread(&vetorExtra, sizeof(ContaExtraordinaria), 1, arq);
            if(idLido==vetorExtra.id)
            {
                sair=0;
                achou=1;
            }

        }
        if(achou)
        {
            editarNome(&vetorExtra.nome);
            editarValor(&vetorExtra.valor);
        }
        else
            printf("Nao foi achado esse ID");


        printf("Abriu");
    }
    else
        printf("Erro em abrir o arquivo");


}

void editarMensal()
{
    int idLido,sair=1,achou=0,ret;
    ContaMensal vetorMensal;
    FILE *arq;
    char nomearq[]="ContasMensais.dat";

    arq=fopen(nomearq, "r+b");
    if (arq != NULL)
    {
        printf("Enter com o ID")
        scanf("%d",idLido)
        fseek(arq,0,SEEK_SET)
        while(arq!=EOF&&sair)
        {
            arq=arq+sizeof(ContaMensal);
            ret = fread(&vetorMensal, sizeof(ContaMensal), 1, arq);
            if(idLido==vetorMensal.id)
            {
                sair=0;
                achou=1
            }

        }
        if(achou)
        {
            editarNome(&vetorMensal.nome);
            editarValor(&vetorMensal.valor);
            editarParcela(&vetorMensal.parcela);
            editarVencimento(&vetorMensal.data.dia,&vetorMensal.data.mes,&vetorMensal.data.ano);
        }
        else
            printf("Nao foi achado esse ID");

        printf("Abriu");
    }
    else
        printf("Erro em abrir o arquivo");
}

void editarPeriodica()
{
    int idLido,sair=1,achou=0,ret;
    ContaPeriodica vetorPeriodica;
    FILE *arq;
    char nomearq[]="ContasPeridocas.dat";

    arq=fopen(nomearq, "r+b");
    if (arq != NULL)
    {
        printf("Enter com o ID")
        scanf("%d",idLido)
        fseek(arq,0,SEEK_SET)
        while(arq!=EOF&&sair)
        {
            arq=arq+sizeof(ContaPeriodica);
            ret = fread(&vetorPeriodica, sizeof(ContaPeriodica), 1, arq);
            if(idLido==vetorPeriodica.id)
            {
                sair=0;
                achou=1
            }

        }
        if(achou)
        {
            editarNome(&vetorPeriodica.nome);
            editarValor(&vetorPeriodica.valor);
        }
        else
            printf("Nao foi achado esse ID");


        printf("Abriu");
    }
    else
        printf("Erro em abrir o arquivo");
}

void editarConta()
{
    int numLido;

    printf("Qual conta gostaria de editar ?");
    printf("\n\t[1]Conta Extraordinaria\n\t[2]Conta Mensal\n\t[3]Conta Periodica\n\t[0]Voltar ao menu Anterior\n");
    scanf("%d",&numLido);
    switch (numLido)
    {
    case 1:
        editarExtra();break;
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
    editarConta();
}
