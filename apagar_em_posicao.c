#include "funcoes.h"
void remover_em_posicao(tipolista_conta *l, tipolista_mov *m)
{
    int posicao;
    int escolha;
    int cont_posicao = 1;
    tipoApontador_conta aux;
    tipoApontador_conta anterior = NULL;

    listar_cadastros(l);

    if (l->primeiro == NULL)
    {
        vaiparaxy(07, 05);
        printf("Nenhum funcionario cadastrado");
        getch();
        return;
    }

    do
    {

        vaiparaxy(07, 23);
        printf("                                                            ");
        vaiparaxy(07, 23);
        printf("Digite a posicao a ser apagada ou 0 para cancelar: ");
        scanf("%d", &posicao);

        if (posicao == 0)
        {
            return;
        }

        if (posicao < 1 || posicao > tamanho(l))
        {
            vaiparaxy(07, 23);
            printf("                                                            ");
            vaiparaxy(07, 23);
            printf("SEM FUNCIONARIO CADASTRADO NESSA POSICAO");
            getch();
        }

    } while (posicao < 1 || posicao > tamanho(l));

    aux = l->primeiro;
    while (aux != NULL && cont_posicao < posicao)
    {
        anterior = aux;
        aux = aux->proximo;
        cont_posicao++;
    }

    if (aux != NULL)
    {
        do
        {
            tela();
            vaiparaxy(03, 03);
            printf("EXCLUIR CADASTRO NA POSICAO INFORMADA");
            vaiparaxy(40, 03);
            printf("  || FUNCIONARIO NA POSICAO %d", posicao);
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
            printf("(1)Excluir || (0)Voltar tela inicial:");
            scanf("%d", &escolha);

            if (aux->conteudo.v1_saldo != 0)
            {
                limpa_msg();
                vaiparaxy(07, 23);
                printf("Conta nao pode ser removida");
                getch();
                break;
            }
            
            /*tipoApontador_mov aux2;
            tipoApontador_mov aux_m;
            aux_m->conteudo.codigo_conta = aux->conteudo.codigo_conta;
            aux_m = conta_movi(m, aux_m->conteudo.codigo_conta);*/
            tipoApontador_mov aux_m;
           
            if(aux_m->conteudo.sequencial != 0){
                limpa_msg();
                vaiparaxy(07, 23);
                printf("Conta nao pode ser removida possui registro de movimentacao");
                getch();
                break;
            }
            
          
            switch (escolha)
            {
            case 1:
                if (aux == l->primeiro)
                {
                    l->primeiro = aux->proximo;
                    if (l->primeiro == NULL)
                    {
                        l->ultimo = NULL;
                    }
                }
                else if (aux == l->ultimo)
                {
                    anterior->proximo = NULL;
                    l->ultimo = anterior;
                }
                else
                {
                    anterior->proximo = aux->proximo;
                }

                free(aux);
                tela();
                tela_cadastros();
                vaiparaxy(03, 03);
                printf("EXCLUIR CADASTRO NA POSICAO INFORMADA");
                vaiparaxy(40, 03);
                printf("  || FUNCIONARIO NA POSICAO %d", posicao);
                vaiparaxy(07, 23);
                printf("                                                 ");
                vaiparaxy(07, 23);
                printf("Funcionario removido com sucesso\n");
                getch();
                // salvar_alteracao(l);

                return;
                break;
            case 0:
                return;
                break;
            default:
                vaiparaxy(07, 23);
                printf("                                                                     ");
                vaiparaxy(07, 23);
                printf("Digito Invalido");
                getch();
            }
        } while (escolha != 0);
    }
}