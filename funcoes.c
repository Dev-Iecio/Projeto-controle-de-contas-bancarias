#include "funcoes.h"

int tamanho(tipolista_conta *l)
{
    int tamanho = 0;
    tipoApontador_conta aux;
    aux = l->primeiro;
    while (aux != NULL)
    {
        tamanho++;
        aux = aux->proximo;
    }
    return tamanho;
}

tipoApontador_conta verifica_codigo_conta(tipolista_conta *l, int cod)
{
    tipoApontador_conta aux;
    aux = l->primeiro;
    while (aux != NULL)
    {

        if (aux->conteudo.codigo_conta == cod)
        {
            return aux;
        }
        aux = aux->proximo;
    }
    return NULL;
}

void cadastro_final_lista(tipolista_conta *l)
{
    tipoApontador_conta aux;
    reg_contas conta;
    int resp;
    int confirma_cadastro;

    do
    {

        tela();
        vaiparaxy(03, 03);
        printf("                                       ");
        vaiparaxy(03, 03);
        printf("TELA PARA CADASTRO NO FINAL DA LISTA");
        tela_cadastros();

        do
        {
            vaiparaxy(07, 23);
            printf("Digite 0 para cancelar e voltar");

            vaiparaxy(40, 05);
            printf("                               ");
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
                printf("                                                           ");
                vaiparaxy(07, 23);
                printf("Funcionario ja cadastrado");
                getch();
            }
        } while (aux != NULL && conta.codigo_conta != 0);

        if (conta.codigo_conta != 0)
        {

            vaiparaxy(07, 23);
            printf("                                                                ");

            vaiparaxy(40, 07);
            printf("                     ");
            vaiparaxy(40, 07);
            fflush(stdin);
            fgets(conta.banco, 50, stdin);

            vaiparaxy(40, 9);
            printf("                     ");
            vaiparaxy(40, 9);
            fflush(stdin);
            fgets(conta.agencia, 10, stdin);

            vaiparaxy(40, 11);
            printf("                     ");
            vaiparaxy(40, 11);
            fflush(stdin);
            fgets(conta.numero_conta, 50, stdin);

            vaiparaxy(40, 13);
            printf("                     ");
            vaiparaxy(40, 13);
            fflush(stdin);
            fgets(conta.tipo_conta, 10, stdin);

            vaiparaxy(40, 15);
            printf("                     ");
            vaiparaxy(40, 15);
            fflush(stdin);
            scanf("%f", &conta.v1_saldo);

            vaiparaxy(40, 17);
            printf("                     ");
            vaiparaxy(40, 17);
            fflush(stdin);
            scanf("%f", &conta.v1_limite);

            vaiparaxy(40, 19);
            printf("                     ");
            vaiparaxy(40, 19);
            fflush(stdin);
            scanf("%d", &conta.status);

            vaiparaxy(07, 23);
            printf("Confirma?(1-SIM || 2-NAO):");
            scanf("%d", &confirma_cadastro);
        }
        if (confirma_cadastro == 1)
        {
            aux = (tipoApontador_conta)malloc(sizeof(tipoitem_conta));
            aux->proximo = NULL;
            aux->conteudo = conta;
            if (l->primeiro == NULL)
            {
                l->primeiro = aux;
                l->ultimo = aux;
            }
            else
            {
                l->ultimo->proximo = aux;
                l->ultimo = aux;
            }
        }

        vaiparaxy(07, 23);
        printf("                                          ");
        vaiparaxy(07, 23);
        printf("Deseja continuar cadastrando?(1-SIM || 2-NAO):");
        scanf("%d", &resp);
    } while (resp == 1);
}

void cadastro_inicio_lista(tipolista_conta *l)
{

    tipoApontador_conta aux;
    reg_contas conta;
    int resp;
    int confirma;

    do
    {
        tela();
        vaiparaxy(03, 03);
        printf("                                        ");
        vaiparaxy(03, 03);
        printf("CADASTRO NO INICIO DA LISTA ");
        tela_cadastros();

        do
        {
            vaiparaxy(07, 23);
            printf("Digite 0 para cancelar e voltar");

            vaiparaxy(40, 05);
            printf("                       ");
            vaiparaxy(40, 05);
            scanf("%d", &conta.codigo_conta);

            // 0 sai do loop
            if (conta.codigo_conta == 0)
            {
                return;
            }

            aux = verifica_codigo_conta(l, conta.codigo_conta);

            if (aux != NULL)
            {
                vaiparaxy(07, 23);
                printf("                                                 ");
                vaiparaxy(07, 23);
                printf("Funcionario jah cadastrado");
                getch();
            }
        } while (aux != NULL && conta.codigo_conta != 0);

        if (conta.codigo_conta != 0)
        {

            vaiparaxy(07, 23);
            printf("                                               ");

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

            vaiparaxy(40, 19);
            printf("                          ");
            vaiparaxy(40, 19);
            fflush(stdin);
            scanf("%d", &conta.status);

            vaiparaxy(07, 23);
            printf("Confirma?(1-SIM || 2-NAO)");
            scanf("%d", &confirma);
        }
        if (confirma == 1)
        {
            aux = (tipoApontador_conta)malloc(sizeof(tipoitem_conta));
            aux->proximo = NULL;
            aux->conteudo = conta;

            if (l->primeiro == NULL)
            {
                l->primeiro = aux;
                l->ultimo = aux;
            }
            else
            {
                l->primeiro = aux->proximo;
                l->primeiro = aux;
            }
            if (l->ultimo == NULL)
            {
                l->ultimo = l->primeiro;
            }
        }
        vaiparaxy(07, 23);
        printf("                                                      ");
        vaiparaxy(07, 23);
        printf("Deseja Cadastrar outro (1-SIM || 2-NAO)");
        scanf("%d", &resp);

    } while (resp == 1);
}

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
        tela();
        tela_cadastros();
        vaiparaxy(03, 03);
        printf("                                        ");
        vaiparaxy(03, 03);
        printf("CADASTRO NA POSICAO ");

        do
        {
            vaiparaxy(07, 23);
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

        do
        {
            vaiparaxy(07, 23);
            printf("                                    ");
            vaiparaxy(07, 23);
            printf("Digite a posicao a ser cadastrado: ");
            scanf("%d", &resp);

            if (resp < 1 || resp > tamanho(l))
            {
                vaiparaxy(07, 23);
                printf("                                     ");
                vaiparaxy(07, 23);
                printf("Posicao invalida");
                getch();
                return;
            }

        } while (resp < 1 || resp > tamanho(l));

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

            vaiparaxy(40, 19);
            printf("                          ");
            vaiparaxy(40, 19);
            fflush(stdin);
            scanf("%d", &conta.status);

            vaiparaxy(07, 23);
            printf("                               ");
            vaiparaxy(07, 23);
            printf("Confirma?(1-SIM || 2-NAO): ");
            scanf("%d", &confirma);

            if (confirma == 1)
            {
                aux = (tipoApontador_conta)malloc(sizeof(tipoitem_conta));
                aux->proximo = NULL;
                aux->conteudo = conta;

                if (l->primeiro = NULL)
                {
                    l->primeiro = aux;
                    l->ultimo = aux;
                }
                else
                {
                    aux = l->primeiro;

                    for (b = 1; b <= resp - 2; b++)
                    {
                        aux = aux->proximo;
                    }
                    p->proximo = aux->proximo;
                    aux->proximo = p;
                }
            }
            vaiparaxy(07, 23);
            printf("                                               ");
            vaiparaxy(07, 23);
            printf("Deseja Cadastrar outro (1-SIM || 2-NAO)");
            scanf("%d", &resp);
        }

    } while (resp == 1);
}

void consultar(tipolista_conta *l)
{
    tela();
    tipoApontador_conta aux;

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
    while (aux != NULL)
    {
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

        aux = aux->proximo;

        vaiparaxy(07, 23);
        printf("Pressione qualquer tecla para listar o proximo funcionario");
        getch();
    }
}

void menu_contas_bancarias(tipolista_conta *l)
{

    int opc;

    do
    {
        tela();
        vaiparaxy(04, 05);
        printf("1-Cadastrar conta no final da lista");
        vaiparaxy(04, 07);
        printf("2-Cadastrar conta no inicio da lista");
        vaiparaxy(04, 9);
        printf("3-Cadastrar conta em uma posicao da lista");
        vaiparaxy(04, 11);
        printf("4-Remover conta no final da lista");
        vaiparaxy(04, 13);
        printf("5-Remover conta no inicio da lista");
        vaiparaxy(04, 15);
        printf("6-Remover conta em uma posicao da lista");
        vaiparaxy(04, 17);
        printf("7-Alteracao do cadastro de conta");
        vaiparaxy(04, 19);
        printf("8-Consultar contas");
        vaiparaxy(04, 21);
        printf("9-Voltar");
        vaiparaxy(07, 23);
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            cadastro_final_lista(l);
            break;

        case 2:
            cadastro_inicio_lista(l);
            break;

        case 3:
            cadastro_na_posicao(l);
            break;
        case 8:
            consultar(l);
            break;
        default:
            break;
        }
    } while (opc != 9);
}