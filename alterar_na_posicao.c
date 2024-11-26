/*Autor......: Gabriel Ribeiro
  Data.......: 24/11/2024
  Equipe.....: RA10002691 - Gabriel Dalecio 1
               RA165808-2024 - Gabriel Ribeiro 2
  Objetivo...: Alterar cadastro na posiçao */
#include "funcoes.h"
// Funcao Alterar na Posicao
void alterar_na_posicao(tipolista_conta *l)
{
    tipoApontador_conta aux;
    int resp;
    int campo;
    reg_contas func;
    // Se a lista estiver vazia
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
                // Se o código não for encontrado
                if (aux == NULL && func.codigo_conta != 0)
                {
                    vaiparaxy(07, 23);
                    printf("                                                         ");
                    vaiparaxy(07, 23);
                    printf("Funcionario nao cadastrado");
                    getch();
                }

            } while (aux == NULL && func.codigo_conta != 0);

            // Se o código da conta for válido (não for 0)
            if (func.codigo_conta != 0)
            {
                tela();
                tela_cadastros();
                vaiparaxy(07, 23);
                printf("                                                  ");
                vaiparaxy(20, 03);
                printf("ALTERACAO CADASTRO");
                func = aux->conteudo; // Copia os dados da conta para a estrutura 'func'

                // Exibe as informações da conta a ser alterada
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

                do  // Inicia a interação para escolher o campo a ser alterado
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
                    // Se o campo for inválido, exibe uma mensagem de erro
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
                                if(func.v1_saldo != 0) // Se o saldo não for zero, o status não pode ser alterado
                                {
                                    vaiparaxy(07,23);
                                    printf("O status nao pode ser alterado se tiver saldo ou debito");
                                    func.status = 1;
                                    getch();
                                    break;
                                }
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
}