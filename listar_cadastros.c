#include "funcoes.h"
//Funçao para Listar os Cadastros de Contas
void listar_cadastros(tipolista_conta *l)
{
    tipoApontador_conta aux;
    int posicao = 1;
    tela();

    //Verifica se a lista está vazia
    if (l->primeiro == NULL)
    {
        vaiparaxy(07, 05);
        printf("Nenhum funcionario cadastrado\n");
        getch();
        return;
    }

    //Loop para percorrer a lista e imprimir as informações de cada conta
    aux = l->primeiro;
    vaiparaxy(04, 05);
    printf("Contas cadastradas:\n");

    while (aux != NULL)
    {
        //Exibe as informações da conta na posição atual da lista
        vaiparaxy(04, 06 + posicao);
        printf("Posicao %d : Codigo: %d | Banco: %s |",
               posicao,
               aux->conteudo.codigo_conta,
               aux->conteudo.banco);
        vaiparaxy(38, 06 + posicao);
        printf(" | Agencia: %s\n", aux->conteudo.agencia);

        aux = aux->proximo;
        posicao++;
    }
}

