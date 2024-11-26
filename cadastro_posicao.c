/*Autor......: Gabriel Dalecio
  Data.......: 24/11/2024
  Equipe.....: RA10002691 - Gabriel Dalecio 1
               RA165808-2024 - Gabriel Ribeiro 2
  Objetivo...: Cadastro na Posicao */
#include "funcoes.h"
//Funcao para Cadastrar na posicao
void cadastro_na_posicao(tipolista_conta *l)
{
    
    tipoApontador_conta aux;
    tipoApontador_conta p;
    reg_contas conta;
    int resp;
    int confirma;
    int b;

    do
    {   // Verifica se a lista está vazia
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
            // Se digitar 0 sai do loop
            vaiparaxy(07, 23);
            printf("Digite 0 para cancelar e voltar");

            vaiparaxy(40, 05);
            printf("                                    ");
            vaiparaxy(40, 05);
            scanf("%d", &conta.codigo_conta);
            
            if (conta.codigo_conta == 0)
            {
                return;
            }

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
          
            

            int posicao;
            do
            {
                vaiparaxy(07, 23);
                printf("                                        ");
                vaiparaxy(07, 23);
                printf("Digite a posicao a ser cadastrado: ");
                scanf("%d", &posicao);
                // Valida se a posição está dentro do intervalo válido
                if (posicao < 1 || posicao > tamanho(l))
                {
                    vaiparaxy(07, 23);
                    printf("                                         ");
                    vaiparaxy(07, 23);
                    printf("Posicao invalida");
                    getch();
                }

            } while (posicao < 1 || posicao > tamanho(l));

            vaiparaxy(07, 23);
            printf("                                             ");
            vaiparaxy(07, 23);
            printf("Confirma?(1-SIM || 2-NAO): ");
            scanf("%d", &confirma);

            if (confirma == 1)
            {
                // Aloca memória para o novo nó
                aux = (tipoApontador_conta)malloc(sizeof(tipoitem_conta));
                aux->proximo = NULL;
                aux->conteudo = conta;
                // Insere o novo nó no início da lista
                aux->proximo = l->primeiro;
                l->primeiro = aux;
            }
            else
            {
                // Se não for para inserir no início, encontra a posição correta e insere
                aux = l->primeiro;

                for (b = 1; b <= confirma - 2; b++)
                {
                    aux = aux->proximo;
                }
                p->proximo = aux->proximo;
                aux->proximo = p;
            }
        }
        vaiparaxy(07, 23);
        printf("                                                 ");
        vaiparaxy(07, 23);
        printf("Deseja Cadastrar outro (1-SIM || 2-NAO)");
        scanf("%d", &resp);
    } while (resp == 1);
}