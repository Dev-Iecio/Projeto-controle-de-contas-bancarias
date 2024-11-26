/*Autor......: Gabriel Ribeiro
  Data.......: 24/11/2024
  Equipe.....: RA10002691 - Gabriel Dalecio 1
               RA165808-2024 - Gabriel Ribeiro 2
  Objetivo...: Consulta geral sem ordem */
#include "funcoes.h"
// Funcao Consultar 
void consultar(tipolista_conta *l)
{
    tela();
    tipoApontador_conta aux;
    // Verifica se a lista de contas está vazia
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
    // Enquanto houver contas na lista, percorre e exibe as informações
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
        // Verifica se a conta está ativa ou desativada e exibe a informação
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
        // Avança para a próxima conta na lista
        aux = aux->proximo;

        vaiparaxy(07, 23);
        printf("Pressione qualquer tecla para listar o proximo funcionario");
        getch();
    }
}