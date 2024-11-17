#include "funcoes.h"
void consultar(tipolista_conta *l)
{
    tela();
    tipoApontador_conta aux;

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
        aux = l->primeiro;
    }
    while (aux != NULL)
    {
        tela();
        tela_cadastros();
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

        aux = aux->proximo;

        vaiparaxy(07, 23);
        printf("Pressione qualquer tecla para listar o proximo funcionario");
        getch();
    }
}