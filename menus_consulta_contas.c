#include "funcoes.h"

/*int tamanho(tipolista_conta *l)
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
}*/

/*void cadastro_final_lista(tipolista_conta *l)
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
            fgets(conta.status, 13, stdin);

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
}*/

/*void cadastro_inicio_lista(tipolista_conta *l)
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
            fgets(conta.status, 13, stdin);

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
                aux->proximo = l->primeiro;
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
}*/

/*void cadastro_na_posicao(tipolista_conta *l)
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
            fgets(conta.status, 13, stdin);

            int posicao;
            do
            {
                vaiparaxy(07, 23);
                printf("                                        ");
                vaiparaxy(07, 23);
                printf("Digite a posicao a ser cadastrado: ");
                scanf("%d", &posicao);

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
            printf("                               ");
            vaiparaxy(07, 23);
            printf("Confirma?(1-SIM || 2-NAO): ");
            scanf("%d", &confirma);

            if (confirma == 1)
            {

                aux = (tipoApontador_conta)malloc(sizeof(tipoitem_conta));
                aux->proximo = NULL;
                aux->conteudo = conta;

                aux->proximo = l->primeiro;
                l->primeiro = aux;
            }
            else
            {
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
}*/

/*void mostrar_e_apagar_ultimo(tipolista_conta *l)
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
}*/

/*void mostrar_apagar_primeiro(tipolista_conta *l)
{
    tela();
    vaiparaxy(03, 03);
    printf("TELA DELETAR O PRIMEIRO CADASTRO");
    tipoApontador_conta aux;
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
        aux = l->primeiro;
    }
    do
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

        vaiparaxy(07, 23);
        printf("                                                          ");
        vaiparaxy(07, 23);
        printf("(1)Excluir funcionario || (0)Voltar para tela inicial ");
        vaiparaxy(61, 23);
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            if (l->primeiro->proximo == NULL)
            {
                free(l->primeiro);
                l->primeiro = NULL;
                l->ultimo = NULL;
                tela();
                tela_cadastros();
                vaiparaxy(07, 23);
                printf("                                                     ");
                vaiparaxy(07, 23);
                printf("Funcionario removido com sucesso.\n");
                getch();
                return;
            }
            else
            {
                l->primeiro = aux->proximo;
                free(aux);
                tela();
                tela_cadastros();
                vaiparaxy(07, 23);
                printf("                                                     ");
                vaiparaxy(07, 23);
                printf("Funcionario removido com sucesso.\n");
                getch();
                return;
            }
            // salvar_alteracao(l);
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
    } while (escolha != 1 && escolha != 0);
}*/

/*void remover_em_posicao(tipolista_conta *l)
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
            printf("%s", aux->conteudo.status);

            vaiparaxy(07, 23);
            printf("(1)Excluir || (0)Voltar tela inicial:");
            scanf("%d", &escolha);

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
}*/

/*void listar_cadastros(tipolista_conta *l)
{
    tipoApontador_conta aux;
    int posicao = 1;
    tela();

    if (l->primeiro == NULL)
    {
        vaiparaxy(07, 05);
        printf("Nenhum funcionario cadastrado\n");
        getch();
        return;
    }

    aux = l->primeiro;
    vaiparaxy(04, 05);
    printf("Contas cadastradas:\n");

    while (aux != NULL)
    {
        vaiparaxy(04, 06 + posicao);
        printf("Posicao %d : Codigo: %d | Banco: %s |",
               posicao,
               aux->conteudo.codigo_conta,
               aux->conteudo.banco);
        vaiparaxy(38, 06 + posicao);
        printf(" | Agencia: %s\n", aux->conteudo.agencia);

        aux = aux->proximo;
        posicao++;
    }
}*/

/*void alterar_na_posicao(tipolista_conta *l)
{
    tipoApontador_conta aux;
    int resp;
    int campo;
    reg_contas func;

    if (l->primeiro == NULL)
    {
        tela();
        vaiparaxy(07, 05);
        printf("Nenhum funcionario cadastrado\n");
        getch();
        return;
    }
    else
    {

        do
        {
            listar_cadastros(l);
            do
            {

                vaiparaxy(07, 23);
                printf("                                                  ");
                vaiparaxy(20, 03);
                printf("ALTERACAO CADASTRO");
                vaiparaxy(07, 23);
                printf("Digite o codigo do cadastro || (0-SAIR):");
                vaiparaxy(48, 23);
                scanf("%d", &func.codigo_conta);
                aux = verifica_codigo_conta(l, func.codigo_conta);

                if (aux == NULL && func.codigo_conta != 0)
                {
                    vaiparaxy(07, 23);
                    printf("                                                         ");
                    vaiparaxy(07, 23);
                    printf("Funcionario nao cadastrado");
                    getch();
                }

            } while (aux == NULL && func.codigo_conta != 0);

            if (func.codigo_conta != 0)
            {
                tela();
                tela_cadastros();
                vaiparaxy(07, 23);
                printf("                                                  ");
                vaiparaxy(20, 03);
                printf("ALTERACAO CADASTRO");
                func = aux->conteudo;

                vaiparaxy(40, 05);
                printf("%d", func.codigo_conta);
                vaiparaxy(40, 07);
                printf("%s", func.banco);
                vaiparaxy(40, 9);
                printf("%s", func.agencia);
                vaiparaxy(40, 11);
                printf("%s", func.numero_conta);
                vaiparaxy(40, 13);
                printf("%s", func.tipo_conta);
                vaiparaxy(40, 15);
                printf("%.2f", func.v1_saldo);
                vaiparaxy(40, 17);
                printf("%.2f", func.v1_limite);
                vaiparaxy(40, 19);
                printf("%s", func.status);

                do
                {
                    do
                    {
                        vaiparaxy(07, 23);
                        printf("                                                          ");
                        vaiparaxy(07, 23);
                        printf("Digite o campo a ser alterado(0-SAIR):");
                        scanf("%d", &campo);
                        if (campo < 0 || campo > 7)
                        {
                            vaiparaxy(07, 23);
                            printf("                                                       ");
                            vaiparaxy(07, 23);
                            printf("Posicao invalida");
                            getch();
                        }
                    } while (campo < 0 || campo > 7);

                    if (campo != 0)
                    {
                        switch (campo)
                        {
                        case 1:
                            vaiparaxy(40, 07);
                            printf("                                       ");
                            vaiparaxy(40, 07);
                            fflush(stdin);
                            fgets(func.banco, 50, stdin);
                            break;
                        case 2:
                            vaiparaxy(40, 9);
                            printf("                                       ");
                            vaiparaxy(40, 9);
                            fflush(stdin);
                            fgets(func.agencia, 10, stdin);
                            break;
                        case 3:
                            vaiparaxy(40, 11);
                            printf("                                       ");
                            vaiparaxy(40, 11);
                            fflush(stdin);
                            fgets(func.numero_conta, 50, stdin);
                            break;
                        case 4:
                            vaiparaxy(40, 13);
                            printf("                                     ");
                            vaiparaxy(40, 13);
                            fflush(stdin);
                            fgets(func.tipo_conta, 10, stdin);
                            break;
                        case 5:
                            vaiparaxy(40, 15);
                            printf("                                    ");
                            vaiparaxy(40, 15);
                            scanf("%f", &func.v1_saldo);
                            break;
                        case 6:
                            vaiparaxy(40, 17);
                            printf("                                    ");
                            vaiparaxy(40, 17);
                            scanf("%f", &func.v1_limite);
                            break;
                        case 7:
                            vaiparaxy(40, 19);
                            printf("                                     ");
                            vaiparaxy(40, 19);
                            fflush(stdin);
                            fgets(func.status, 13, stdin);
                            break;

                        default:
                            break;
                        }
                    }

                } while (campo != 0);
                vaiparaxy(07, 23);
                printf("                                                    ");
                vaiparaxy(07, 23);
                printf("Confirma a alteracao(1-SIM || 2-NAO)");
                scanf("%d", &resp);
                if (resp == 1)
                {
                    aux->conteudo = func;

                }
            }
            vaiparaxy(07, 23);
            printf("                                              ");
            vaiparaxy(07, 23);
            printf("Deseja alterar outro funcionario:(1-SIM || 0-NAO)");
            scanf("%d", &resp);

        } while (resp == 1);
    }
}*/

// Funçoes para as consultas
/*void consultar(tipolista_conta *l)
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
        tela();
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

        aux = aux->proximo;

        vaiparaxy(07, 23);
        printf("Pressione qualquer tecla para listar o proximo funcionario");
        getch();
    }
}*/
/*void consulta_ordem_codigo(tipolista_conta *l)
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

    // Laço de ordenação (Bubble Sort)
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

    // Após a ordenação, imprime os dados de cada conta
    tipoApontador_conta aux2 = l->primeiro;
    while (aux2 != NULL)
    {

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
        printf("%s", aux2->conteudo.status);

        aux2 = aux2->proximo; // Avança para o próximo nó

        vaiparaxy(07, 23);
        printf("Pressione qualquer tecla para listar o proximo funcionario");
        getch();
    }
}*/
/*void consulta_ordem_alfabetica(tipolista_conta *l)
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
        printf("%s", aux2->conteudo.status);

        aux2 = aux2->proximo; // Avança para o próximo nó

        vaiparaxy(07, 23);
        printf("Pressione qualquer tecla para listar o proximo funcionario");
        getch();
    }
}*/
/*void consulta_por_codigo(tipolista_conta *l)
{
    tela();
    tipoApontador_conta aux;
    int opc;

    if (l->primeiro == NULL)
    {
        tela();
        vaiparaxy(07, 05);
        printf("Nenhum funcionario cadastrado\n");
        getch();
        return;
    }

    do
    {

        do
        {
            listar_cadastros(l);
            vaiparaxy(07, 23);
            printf("Digite o codigo da conta que voce vai consultar || (0-SAIR):");
            scanf("%d", &opc);

            // Verifica se a conta existe com o código fornecido
            aux = verifica_codigo_conta(l, opc);

            if (aux == NULL && opc != 0)
            {
                // Se o código não for encontrado, exibe uma mensagem
                vaiparaxy(07, 23);
                printf("                                                               ");
                vaiparaxy(07, 23);
                printf("Codigo nao encontrado!");
                getch();
            }
            else if (aux != NULL)
            {
                tela();
                // Se a conta for encontrada, imprime os detalhes
                tela_cadastros();  // Atualiza a tela para mostrar os dados
                vaiparaxy(40, 05); // Ajusta o cursor na linha 5, coluna 40
                printf("Codigo: %d", aux->conteudo.codigo_conta);

                vaiparaxy(40, 07);
                printf("Banco: %s", aux->conteudo.banco);

                vaiparaxy(40, 9);
                printf("Agencia: %s", aux->conteudo.agencia);

                vaiparaxy(40, 11);
                printf("Numero da Conta: %s", aux->conteudo.numero_conta);

                vaiparaxy(40, 13);
                printf("Tipo de Conta: %s", aux->conteudo.tipo_conta);

                vaiparaxy(40, 15);
                printf("Saldo: %.2f", aux->conteudo.v1_saldo);

                vaiparaxy(40, 17);
                printf("Limite: %.2f", aux->conteudo.v1_limite);

                vaiparaxy(40, 19);
                printf("Status: %s", aux->conteudo.status);

                vaiparaxy(07, 23);
                printf("Pressione qualquer tecla para continuar...");
                getch();
            }

        } while (opc != 0 && aux == NULL); // Repete até encontrar o código ou o usuário digitar 0 para sair

    } while (opc != 0); // Finaliza o loop quando o usuário digita 0
}*/
void menu_consulta(tipolista_conta *l)
{
    int opc;

    do
    {
        tela_consulta();
        vaiparaxy(07, 23);
        printf("Informe a sua opcao: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            consultar(l);
            break;
        case 2:
            consulta_ordem_codigo(l);
            break;
        case 3:
            consulta_ordem_alfabetica(l);
            break;
        case 4:
            consulta_por_codigo(l);
            break;
        case 5:

            break;
        default:
            break;
        }
    } while (opc != 5);
}

void menu_contas_bancarias(tipolista_conta *l, tipolista_mov *m)

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
        case 4:
            mostrar_e_apagar_ultimo(l,m);
            break;
        case 5:
            mostrar_apagar_primeiro(l,m);
            break;
        case 6:
            remover_em_posicao(l,m);
            break;
        case 7:
            alterar_na_posicao(l);
            break;
        case 8:
            menu_consulta(l);
            break;

        default:
            break;
        }
    } while (opc != 9);
}
void menu_movimentacao(tipolista_conta *l, tipolista_mov *m)
{
    int opc;
    do
    {
        tela_movimentacao();
        vaiparaxy(07,23);
        scanf("%d",&opc);
        switch (opc)
        {
        case 1:
            cadastro_mov(l,m);
            break;
        case 2:
            transferencia(l,m);
            
            break;
        case 3:
            consulta_movi(l,m);
            break;
        case 4:
            break;
        default:
            break;
        }
    } while (opc != 4);
}