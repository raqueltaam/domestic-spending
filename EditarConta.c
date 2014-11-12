#include <stdio.h>


void editarExtra()
{
    int idLido,sair=1,ret;
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
            arq=arq+sizeof(ContaExtraordinaria)
            ret = fread(&vetorExtra, sizeof(ContaExtraordinaria), 1, arq);
            if(idLido==ContaExtraordinaria.id)
            {
                sair=0;
            }


        }

        printf("Abriu");
    }
    else
        printf("Erro em abrir o arquivo");


}

void editarMensal()
{
    FILE *arq;
    char nomearq[]="ContasMensais.dat";

    arq=fopen(nomearq, "r+b");
    if (arq != NULL)
    {
        printf("Abriu");
    }
    else
        printf("Erro em abrir o arquivo");
}

void editarPeriodica()
{
    FILE *arq;
    char nomearq[]="ContasPeridocas.dat";

    arq=fopen(nomearq, "r+b");
    if (arq != NULL)
    {
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
