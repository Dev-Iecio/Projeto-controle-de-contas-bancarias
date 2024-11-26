/*Autor......: Gabriel Ribeiro
  Data.......: 24/11/2024
  Equipe.....: RA10002691 - Gabriel Dalecio 1
               RA165808-2024 - Gabriel Ribeiro 2
  Objetivo...: Apagar o ultimo cadastro da lista */
#include "funcoes.h"
// Funcao Mostrar e apagar Ultimo
void mostrar_e_apagar_ultimo(tipolista_conta *l, tipolista_mov *m)
{
    tela();
    vaiparaxy(03, 03);
    printf("TELA DELETAR ULTIMO CADASTRO");
    int escolha = 5;
    tipoApontador_mov aux_m;
    // Verifica se a lista de contas está vazia
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
            // Se o saldo for diferente de zero, a conta não pode ser removida
            if (aux->conteudo.v1_saldo != 0)
            {
                limpa_msg();
                vaiparaxy(07, 23);
                printf("Conta nao pode ser removida");
                getch();
                break;
            }

            tipoApontador_mov aux_m;

            if (aux_m->conteudo.sequencial != 0)
            {
                limpa_msg();
                vaiparaxy(07, 23);
                printf("Conta nao pode ser removida possui registro de movimentacao");
                getch();
                break;
            }

            switch (escolha)
            {
            case 1:
                // Se o usuário escolher excluir, verifica se a lista contém um único item
                if (l->primeiro == l->ultimo)
                {

                    free(l->primeiro);
                    l->primeiro = NULL;
                    l->ultimo = NULL;
                }
                else
                {
                    // Se houver mais de um item, remove o último item da lista
                    tipoApontador_conta aux = l->primeiro;
                    tipoApontador_conta anterior = NULL;

                    while (aux->proximo != NULL)
                    {
                        anterior = aux;
                        aux = aux->proximo;
                    }

                    free(aux);
                    anterior->proximo = NULL;   // Atualiza o penúltimo item para ser o último
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
                // Se o usuário digitar uma opção inválida
                vaiparaxy(07, 23);
                printf("                                                                     ");
                vaiparaxy(07, 23);
                printf("Digito Invalido");
                getch();
            }

        } while (escolha != 1 && escolha != 0);
    }
}