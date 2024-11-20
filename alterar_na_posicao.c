#include "funcoes.h"
//Funçao para alterar os Dados da conta bancaria na lista
void alterar_na_posicao(tipolista_conta *l)
{
    // declaracao de variaveis
    tipoApontador_conta aux;
    int resp;
    int campo;
    reg_contas func;

    //Verificar se a lista esta vazia
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
        //Inicia o Loop para o processo de alteraçao
        do
        {
            listar_cadastros(l);
            //laço que solicita o codigo a ser alterado
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
                //Funcao para verificar se o codigo existe na lista
                aux = verifica_codigo_conta(l, func.codigo_conta);

                //Codigo nao encontrado, msg de erro
                if (aux == NULL && func.codigo_conta != 0)
                {
                    vaiparaxy(07, 23);
                    printf("                                                         ");
                    vaiparaxy(07, 23);
                    printf("Funcionario nao cadastrado");
                    getch();
                }

            } while (aux == NULL && func.codigo_conta != 0);

            //Se o codigo for valido, Diferente de 0
            if (func.codigo_conta != 0)
            {
                tela();
                tela_cadastros();
                vaiparaxy(07, 23);
                printf("                                                  ");
                vaiparaxy(20, 03);
                printf("ALTERACAO CADASTRO");
                func = aux->conteudo;
            
            //Exibir as informaçoes atuais do cadastro
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
                printf("%d", func.status);
                
                //Exibe o status da conta
                if (func.status == 1)
                {
                    vaiparaxy(43, 19);
                    printf("(Conta ativa)");
                }
                if (func.status == 2)
                {
                    vaiparaxy(43, 19);
                    printf("(Conta desativada)");
                }

                //Laço para escolher o campo a ser alterado
                do
                {
                    do
                    {
                        vaiparaxy(07, 23);
                        printf("                                                          ");
                        vaiparaxy(07, 23);
                        printf("Digite o campo a ser alterado(0-SAIR):");
                        scanf("%d", &campo);
                        
                        //Verificar se a opçao e valida
                        if (campo < 0 || campo > 7)
                        {
                            vaiparaxy(07, 23);
                            printf("                                                       ");
                            vaiparaxy(07, 23);
                            printf("Posicao invalida");
                            getch();
                        }
                    } while (campo < 0 || campo > 7);

                    //realiza alteraçao no campo selecionado
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

                            vaiparaxy(07, 23);
                            printf("                                              ");
                            vaiparaxy(07, 23);
                            printf("Alteracao de saldo somente por movimentacao");
                            getch();
                            break;
                        case 6:
                            vaiparaxy(40, 17);
                            printf("                                    ");
                            vaiparaxy(40, 17);
                            scanf("%f", &func.v1_limite);
                            break;
                        case 7:

                            do
                            {
                                vaiparaxy(07, 23);
                                printf("(1)-Conta ativa (2)-Conta desativada");
                                vaiparaxy(40, 19);
                                printf("                     ");
                                vaiparaxy(40, 19);
                                fflush(stdin);
                                scanf("%d", &func.status);
                            } while (func.status != 1 && func.status != 2);
                        default:
                            break;
                        }
                    }

                } while (campo != 0);
                
                //Pergunta se o usuario confirma as alteraçoes
                vaiparaxy(07, 23);
                printf("                                                    ");
                vaiparaxy(07, 23);
                printf("Confirma a alteracao(1-SIM || 2-NAO)");
                scanf("%d", &resp);
                if (resp == 1)
                {
                    //atualiza os dados dos cadastros
                    aux->conteudo = func; 
                }
            }
            //Pergunta se o usuario deseja alterar outro cadastro
            vaiparaxy(07, 23);
            printf("                                              ");
            vaiparaxy(07, 23);
            printf("Deseja alterar outro funcionario:(1-SIM || 0-NAO)");
            scanf("%d", &resp);

        } while (resp == 1);
    }
}