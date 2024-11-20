#include "funcoes.h"
//funçao para apagar o cadastro do funcioario em qualquer posiçao
void remover_em_posicao(tipolista_conta *l)
{
    // declaracao de variaveis
    int posicao;
    int escolha;
    int cont_posicao = 1;
    tipoApontador_conta aux;
    tipoApontador_conta anterior = NULL;

    //verifica se a lista esta vazia
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

        //se o usuario digitar 0, cancela a operaçao
        if (posicao == 0)
        {
            return;
        }

        //verifica se a posicao fornecida e valida
        if (posicao < 1 || posicao > tamanho(l))
        {
            vaiparaxy(07, 23);
            printf("                                                            ");
            vaiparaxy(07, 23);
            printf("SEM FUNCIONARIO CADASTRADO NESSA POSICAO");
            getch();
        }
      //repete ate o usuario fornecer uma posicao valida
    } while (posicao < 1 || posicao > tamanho(l));
    //Ponteiro auxiliar começa no primeiro elemente da lista
    aux = l->primeiro; 
    //Percorre a lista ate encontrar a posicao desejada  
    while (aux != NULL && cont_posicao < posicao)
    {
        anterior = aux;//Atualiza o ponteiro anterior
        aux = aux->proximo;//Avança para o proximo elemente
        cont_posicao++;//Incrementa o contador na posiçao
    }

    //Se o elemento foi encontrado na posiçao espeficada
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
            printf("%s", aux->conteudo.status);

            vaiparaxy(07, 23);
            printf("(1)Excluir || (0)Voltar tela inicial:");
            scanf("%d", &escolha);

            //Executa conforme a escolha do usuario
            switch (escolha)
            {
            case 1:
                //Caso a exclusão seja confirmada, realiza a remoção da conta
                if (aux == l->primeiro)
                {
                    l->primeiro = aux->proximo;
                    if (l->primeiro == NULL)
                    {
                        l->ultimo = NULL;
                    }
                }
                //Se o elemento a ser removido é o último
                else if (aux == l->ultimo)
                {
                    anterior->proximo = NULL;
                    l->ultimo = anterior;
                }
                else
                {
                    anterior->proximo = aux->proximo;
                }

                free(aux);//Libera a memória do elemento removido
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
          //Repete o processo até o usuário escolher voltar (escolha 0)
        } while (escolha != 0);
    }
}