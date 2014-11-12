#include <stdio.h>

enum menu {cadastrar = 1, editar, excluir, listar};

//mostra o menu do CRUD de contas e retorna a opcao selecionada
int mostrarMenu()
{
    int opcao;
    printf("Contas Diversas\n\n");
    printf("1 - Cadastrar nova conta\n");
    printf("2 - Editar conta ja cadastrada\n");
    printf("3 - Excluir conta\n");
    printf("4 - Listar contas cadastradas\n");
    printf("0 - Sair\n");

    printf("Digite a opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

void exercutarOperacao (int op)
{
    switch(op)
    {
        case cadastrar: cadastrarConta() break;
        case editar: editarConta() break;
        case excluir: excluirConta() break;
        case listar: listarConta() break;
    }
}

main()
{
    int op;

    op = mostrarMenu();
    exercutarOperacao(op);
}
