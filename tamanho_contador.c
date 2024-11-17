#include "funcoes.h"

int tamanho(tipolista_conta *l)
{
    int tamanho = 0;
    tipoApontador_conta aux;
    aux = l->primeiro;
    while (aux != NULL)
    {
        tamanho++;
        aux = aux->proximo;
    }
    return tamanho;
}

tipoApontador_conta verifica_codigo_conta(tipolista_conta *l, int cod)
{
    tipoApontador_conta aux;
    aux = l->primeiro;
    while (aux != NULL)
    {

        if (aux->conteudo.codigo_conta == cod)
        {
            return aux;
        }
        aux = aux->proximo;
    }
    return NULL;
}