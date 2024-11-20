#include "funcoes.h"
//Funçao para Consultar por Ordem de Codigo
void consulta_ordem_codigo(tipolista_conta *l)
{
    tela();
    //Obtém o tamanho da lista
    int t = tamanho(l); 
    tipoApontador_conta i, j;
    reg_contas aux;

    //Verifica se a lista está vazia (nenhum funcionário cadastrado)
    if (l->primeiro == NULL)
    {
        tela();
        vaiparaxy(07, 05);
        printf("Nenhum funcionario cadastrado");
        getch();
        return;
    }

    // Laço de ordenação para ordenar as contas por código
    for (i = l->primeiro; i != NULL; i = i->proximo)
    {
        for (j = i->proximo; j != NULL; j = j->proximo)
        {
            // Compara o código de conta de i com o de j
            if (i->conteudo.codigo_conta > j->conteudo.codigo_conta)
            {
                // Troca os dados de i e j
                aux = i->conteudo;
                i->conteudo = j->conteudo;
                j->conteudo = aux;
            }
        }
    }

    // Após a ordenação, imprime os dados de cada conta na lista
    tipoApontador_conta aux2 = l->primeiro;
    while (aux2 != NULL)
    {
        tela();
        tela_cadastros();
        vaiparaxy(40, 05); 
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

        //Avança para o próximo nó
        aux2 = aux2->proximo;

        //Mensagem solicitando ao usuário para pressionar uma tecla para continuar
        vaiparaxy(07, 23);
        printf("Pressione qualquer tecla para listar o proximo funcionario");
        getch();
    }
}