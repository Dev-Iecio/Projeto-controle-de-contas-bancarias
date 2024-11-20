#include "funcoes.h"
//Função que cadastra uma conta em qualquer posiçao
void cadastro_na_posicao(tipolista_conta *l)
{
    // declaracao de variaveis
    tipoApontador_conta aux;
    tipoApontador_conta p;
    reg_contas conta;
    int resp;
    int confirma;
    int b;

    do
    {
        //Verifica se a lista está vazia, caso esteja, informa o usuário e retorna
        if (l->primeiro == NULL)
        {
            tela();
            vaiparaxy(07, 05);
            printf("LISTA NAO INICIADA CADASTRE UM FUNCIONARIO NO INICIO");
            vaiparaxy(07, 23);
            printf("                                                         ");
            getch();
            return;
        }

        tela();
        tela_cadastros();
        vaiparaxy(03, 03);
        printf("                                        ");
        vaiparaxy(03, 03);
        printf("CADASTRO NA POSICAO ");

        do
        {
            //Solicita o código da conta e verifica se é 0 para cancelar
            vaiparaxy(07, 23);
            printf("Digite 0 para cancelar e voltar");

            vaiparaxy(40, 05);
            printf("                                    ");
            vaiparaxy(40, 05);
            scanf("%d", &conta.codigo_conta);
            // Se digitar 0 sai do loop
            if (conta.codigo_conta == 0)
            {
                return;
            }
            // Verifica se a conta já está cadastrada
            aux = verifica_codigo_conta(l, conta.codigo_conta);

            if (aux != NULL)
            {
                vaiparaxy(07, 23);
                printf("                                  ");
                vaiparaxy(07, 23);
                printf("Funcionario ja cadastrado ");
                getch();
            }

        } while (aux != NULL && conta.codigo_conta != 0);
        //Se o código da conta for válido, continua o cadastro
        if (conta.codigo_conta != 0)
        {
            vaiparaxy(07, 23);
            printf("                                            ");

            vaiparaxy(40, 07);
            printf("                          ");
            vaiparaxy(40, 07);
            fflush(stdin);
            fgets(conta.banco, 50, stdin);

            vaiparaxy(40, 9);
            printf("                          ");
            vaiparaxy(40, 9);
            fflush(stdin);
            fgets(conta.agencia, 10, stdin);

            vaiparaxy(40, 11);
            printf("                          ");
            vaiparaxy(40, 11);
            fflush(stdin);
            fgets(conta.numero_conta, 50, stdin);

            vaiparaxy(40, 13);
            printf("                          ");
            vaiparaxy(40, 13);
            fflush(stdin);
            fgets(conta.tipo_conta, 10, stdin);

            vaiparaxy(40, 15);
            printf("                          ");
            vaiparaxy(40, 15);
            fflush(stdin);
            scanf("%f", &conta.v1_saldo);

            vaiparaxy(40, 17);
            printf("                          ");
            vaiparaxy(40, 17);
            fflush(stdin);
            scanf("%f", &conta.v1_limite);
            //Solicita o status da conta (ativa ou desativada)
            do
            {
                vaiparaxy(07, 23);
                printf("(1)-Conta ativa (2)-Conta desativada");
                vaiparaxy(40, 19);
                printf("                     ");
                vaiparaxy(40, 19);
                fflush(stdin);
                scanf("%d", &conta.status);
            } while (conta.status != 1 && conta.status != 2);
          
            
            //Solicita a posição em que a conta será cadastrada
            int posicao;
            do
            {
                vaiparaxy(07, 23);
                printf("                                        ");
                vaiparaxy(07, 23);
                printf("Digite a posicao a ser cadastrado: ");
                scanf("%d", &posicao);
                //Verifica se a posição é válida
                if (posicao < 1 || posicao > tamanho(l))
                {
                    vaiparaxy(07, 23);
                    printf("                                         ");
                    vaiparaxy(07, 23);
                    printf("Posicao invalida");
                    getch();
                }

            } while (posicao < 1 || posicao > tamanho(l));
            //Pergunta se o usuário confirma os dados
            vaiparaxy(07, 23);
            printf("                                             ");
            vaiparaxy(07, 23);
            printf("Confirma?(1-SIM || 2-NAO): ");
            scanf("%d", &confirma);
            //Se confirmado, cria o novo item e insere na posição indicada
            if (confirma == 1)
            {

                aux = (tipoApontador_conta)malloc(sizeof(tipoitem_conta));
                aux->proximo = NULL;
                aux->conteudo = conta;

                //Insere o item no início da lista
                aux->proximo = l->primeiro;
                l->primeiro = aux;
            }
            else
            {
                //Se não confirmado, percorre a lista até a posição indicada
                aux = l->primeiro;
                //Percorre até a posição anterior à indicada
                for (b = 1; b <= confirma - 2; b++)
                {
                    aux = aux->proximo;
                }
                //Insere o novo item na posição correta
                p->proximo = aux->proximo;
                aux->proximo = p;
            }
        }
        //Pergunta se o usuário deseja cadastrar outra conta
        vaiparaxy(07, 23);
        printf("                                                 ");
        vaiparaxy(07, 23);
        printf("Deseja Cadastrar outro (1-SIM || 2-NAO)");
        scanf("%d", &resp);
        //Continua se a resposta for '1' (sim)
    } while (resp == 1);
}