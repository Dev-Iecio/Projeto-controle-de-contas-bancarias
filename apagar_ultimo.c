#include "funcoes.h"
//Função que exibe o último cadastro e permite ao usuário removê-lo
void mostrar_e_apagar_ultimo(tipolista_conta *l)
{
    tela();
    vaiparaxy(03, 03);
    printf("TELA DELETAR ULTIMO CADASTRO");
    int escolha = 5;

    //Verifica se a lista esta vazia
    if (l->primeiro == NULL)
    {
        vaiparaxy(07, 05);
        printf("Nenhum funcionario cadastrado.\n");
        getch();
        return;
    }
    else
    {
        do
        {
            //Ponteiro auxiliar que aponta para o último cadastro
            tipoApontador_conta aux = l->ultimo;
            //Exibe as informações do último cadastro na tela
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

            //Exibe as opções para o usuário: excluir ou voltar
            vaiparaxy(07, 23);
            printf("                                                             ");
            vaiparaxy(07, 23);
            printf("(1)Excluir funcionario || (0)Voltar para tela inicial");
            vaiparaxy(61, 23);
            scanf("%d", &escolha);

            switch (escolha)
            {
            case 1:
                //Se o usuário escolheu excluir o último cadastro

                //Verifica se a lista tem apenas um elemento
                if (l->primeiro == l->ultimo)
                {
                //Caso a lista tenha um único cadastro, libera a memória e ajusta ambos os ponteiros (primeiro e último)
                    free(l->primeiro);
                    l->primeiro = NULL;
                    l->ultimo = NULL;
                }
                else
                {
                //Caso a lista tenha mais de um elemento, percorre até o penúltimo elemento
                    tipoApontador_conta aux = l->primeiro;
                    tipoApontador_conta anterior = NULL;

                //Encontra o penultimo elemento
                    while (aux->proximo != NULL)
                    {
                        anterior = aux;
                        aux = aux->proximo;
                    }

                    free(aux);
                    anterior->proximo = NULL;
                    l->ultimo = anterior;
                }
                //Exibe msg de Sucesso
                tela();
                tela_cadastros();

                vaiparaxy(07, 23);
                printf("                                                                  ");
                vaiparaxy(07, 23);
                // salvar_alteracao(l);
                printf("Funcionario removido com sucesso.\n");
                getch();
                break;

            case 0:
                return;

            default:
            //Se o usuário fornecer uma escolha inválida
                vaiparaxy(07, 23);
                printf("                                                                     ");
                vaiparaxy(07, 23);
                printf("Digito Invalido");
                getch();
            }
        //Repete até o usuário escolher uma opção válida
        } while (escolha != 1 && escolha != 0);
    }
}