#include <stdio.h>

void deletarConta(int *status)
{
    int num;
    printf("Gostaria de deletar mesmo a conta\n");
    printf("[0]Nao [1]Sim");
    scanf("%d",&num);
    if(num==1)
    {
        status=0;
    }
    else
    {
        int op;
        op = mostrarMenu();//volta menu
        exercutarOperacao(op);
    }

}



void deletarExtraordinarias()
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

            deletarConta(&RegExtraordinaria.ativo);
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

void deletarRecorrente()
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
            deletarConta(&RegRecorrente.ativo);
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

void deletarPeriodica()
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
            deletarConta(&RegPeriodica.ativo);
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

void deletarConta()
{
    int numLido;

    printf("Qual conta gostaria de deletar ?");
    printf("\n\t[1]Conta Extraordinaria\n\t[2]Conta Mensal\n\t[3]Conta Periodica\n\t[0]Voltar ao menu Anterior\n");
    scanf("%d",&numLido);
    switch (numLido)
    {
    case 1:
        deletarExtraordinarias();break;
    case 2:
        deletarMensal();break;
    case 3:
        deletarPeriodica();break;
    case 0:
        mostrarMenu();break;
    }

}

main()
{
    int op;
    editarConta();
    op = mostrarMenu();//volta menu
    exercutarOperacao(op);
}
