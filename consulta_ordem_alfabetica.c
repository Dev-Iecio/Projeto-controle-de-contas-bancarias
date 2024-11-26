/*Autor......: Gabriel Dalecio
  Data.......: 24/11/2024
  Equipe.....: RA10002691 - Gabriel Dalecio 1
               RA165808-2024 - Gabriel Ribeiro 2
  Objetivo...: Consulta por Ordem Alfabetica */
#include "funcoes.h"
void consulta_ordem_alfabetica(tipolista_conta *l)
{
    tela();
    int t = tamanho(l); // Obtém o tamanho da lista
    tipoApontador_conta i, j;
    reg_contas aux;

    if (l->primeiro == NULL)
    {
        tela();
        vaiparaxy(07, 05);
        printf("Nenhum funcionario cadastrado");
        getch();
        return;
    }

    // Laço de ordenação (Bubble Sort) para ordenar por nome do banco
    for (i = l->primeiro; i != NULL; i = i->proximo)
    {
        for (j = i->proximo; j != NULL; j = j->proximo)
        {
            // Compara o nome do banco de i com o de j
            if (strcmp(i->conteudo.banco, j->conteudo.banco) > 0)
            {
                // Troca os dados de i e j
                aux = i->conteudo;
                i->conteudo = j->conteudo;
                j->conteudo = aux;
            }
        }
    }

    // Após a ordenação, imprime os dados de cada conta
    tipoApontador_conta aux2 = l->primeiro;
    while (aux2 != NULL)
    {  
        tela();
        tela_cadastros();
        vaiparaxy(40, 05); // Ajusta o cursor na tela para a linha 5, coluna 40
        printf("%d", aux2->conteudo.codigo_conta);

        vaiparaxy(40, 07);
        printf("%s", aux2->conteudo.banco);

        vaiparaxy(40, 9);
        printf("%s", aux2->conteudo.agencia);

        vaiparaxy(40, 11);
        printf("%s", aux2->conteudo.numero_conta);

        vaiparaxy(40, 13);
        printf("%s", aux2->conteudo.tipo_conta);

        vaiparaxy(40, 15);
        printf("%.2f", aux2->conteudo.v1_saldo);

        vaiparaxy(40, 17);
        printf("%.2f", aux2->conteudo.v1_limite);

        vaiparaxy(40, 19);
        printf("%d", aux2->conteudo.status);

        aux2 = aux2->proximo; // Avança para o próximo nó

        vaiparaxy(07, 23);
        printf("Pressione qualquer tecla para listar o proximo funcionario");
        getch();
    }
}