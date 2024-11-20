#include "funcoes.h"
//Funçao Consultar "Fichario"
void consultar(tipolista_conta *l)
{
    tela();
    tipoApontador_conta aux;
    //Verifica se a lista está vazia (nenhum funcionário cadastrado)
    if (l->primeiro == NULL)
    {
        tela();
        vaiparaxy(07, 05);
        printf("Nenhum funcionario cadastrado");
        getch();
        return;
    }
    else
    {
        //Se a lista não estiver vazia, começa a percorrer a lista a partir do primeiro nó
        aux = l->primeiro;
    }
    //Loop para percorrer todos os elementos da lista
    while (aux != NULL)
    {
        tela();
        tela_cadastros();
        //Exibe os dados de cada conta na tela, posicionando corretamente os dados
        vaiparaxy(40, 05);
        printf("%d", aux->conteudo.codigo_conta);
        vaiparaxy(40, 07);
        printf("%s", aux->conteudo.banco);
        vaiparaxy(40, 9);
        printf("%s", aux->conteudo.agencia);
        vaiparaxy(40, 11);
        printf("%s", aux->conteudo.numero_conta);
        vaiparaxy(40, 13);
        printf("%s", aux->conteudo.tipo_conta);
        vaiparaxy(40, 15);
        printf("%.2f", aux->conteudo.v1_saldo);
        vaiparaxy(40, 17);
        printf("%.2f", aux->conteudo.v1_limite);
        vaiparaxy(40, 19);
        printf("%d", aux->conteudo.status);
        //Verifica o status da conta e exibe a mensagem correspondente
        if (aux->conteudo.status == 1)
        {
            vaiparaxy(43, 19);
            printf("(Conta ativa)");
        }
        if (aux->conteudo.status == 2)
        {
            vaiparaxy(43, 19);
            printf("(Conta desativada)");
        }
        //Avança para o próximo elemento da lista
        aux = aux->proximo;
        //Mensagem para o usuário pressionar qualquer tecla para continuar
        vaiparaxy(07, 23);
        printf("Pressione qualquer tecla para listar o proximo funcionario");
        getch();
    }
}