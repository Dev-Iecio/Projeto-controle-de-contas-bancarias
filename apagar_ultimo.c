#include "funcoes.h"
void mostrar_e_apagar_ultimo(tipolista_conta *l)
{
    tela();
    vaiparaxy(03, 03);
    printf("TELA DELETAR ULTIMO CADASTRO");
    int escolha = 5;

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
            tipoApontador_conta aux = l->ultimo;
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

            vaiparaxy(07, 23);
            printf("                                                             ");
            vaiparaxy(07, 23);
            printf("(1)Excluir funcionario || (0)Voltar para tela inicial");
            vaiparaxy(61, 23);
            scanf("%d", &escolha);

            switch (escolha)
            {
            case 1:
                if (l->primeiro == l->ultimo)
                {

                    free(l->primeiro);
                    l->primeiro = NULL;
                    l->ultimo = NULL;
                }
                else
                {
                    tipoApontador_conta aux = l->primeiro;
                    tipoApontador_conta anterior = NULL;

                    while (aux->proximo != NULL)
                    {
                        anterior = aux;
                        aux = aux->proximo;
                    }

                    free(aux);
                    anterior->proximo = NULL;
                    l->ultimo = anterior;
                }
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
                vaiparaxy(07, 23);
                printf("                                                                     ");
                vaiparaxy(07, 23);
                printf("Digito Invalido");
                getch();
            }

        } while (escolha != 1 && escolha != 0);
    }
}