/*Autor......: Gabriel Dalecio
  Data.......: 24/11/2024
  Equipe.....: RA10002691 - Gabriel Dalecio 1
               RA165808-2024 - Gabriel Ribeiro 2
  Objetivo...: funcao contar contas / verifica codigo existente */
#include "funcoes.h"
// Funcao para contar
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
// Funcao verificar o codigo
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

