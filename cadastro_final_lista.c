#include "funcoes.h"
//Função para cadastrar uma conta no final da lista
void cadastro_final_lista(tipolista_conta *l)
{
    // declaracao de variaveis
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
        //Loop para verificar o código da conta
        do
        {
            vaiparaxy(07, 23);
            printf("Digite 0 para cancelar e voltar");

            vaiparaxy(40, 05);
            printf("                               ");
            vaiparaxy(40, 05);
            scanf("%d", &conta.codigo_conta);
            //Se o usuário digitar 0, cancela o cadastro e sai da função
            if (conta.codigo_conta == 0)
            {
                return;
            }
            //Verifica se o código da conta já existe na lista
            aux = verifica_codigo_conta(l, conta.codigo_conta);

            if (aux != NULL)
            {
                vaiparaxy(07, 23);
                printf("                                                           ");
                vaiparaxy(07, 23);
                printf("Funcionario ja cadastrado");
                getch();
            }
            //Repete até que o código seja único ou o usuário cancele
        } while (aux != NULL && conta.codigo_conta != 0);
        //Se o codigo for valido (0 nao)
        if (conta.codigo_conta != 0)
        {

            vaiparaxy(07, 23);
            printf("                                                                ");
            //Coleta as informações da conta
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
            //Coleta o status da conta (ativa ou desativada)
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
            vaiparaxy(07, 23);
            printf("                                         ");
            vaiparaxy(07,23);
            printf("Confirma?(1-SIM || 2-NAO):");
            scanf("%d", &confirma_cadastro);
        }
        //Se o usuário confirmar o cadastro
        if (confirma_cadastro == 1)
        {
            aux = (tipoApontador_conta)malloc(sizeof(tipoitem_conta));
            aux->proximo = NULL;
            aux->conteudo = conta;
            //Se a lista estiver vazia, a nova conta será tanto o primeiro quanto o último elemento
            if (l->primeiro == NULL)
            {
                l->primeiro = aux;
                l->ultimo = aux;
            }
            else
            {
            //Caso contrário, adiciona a nova conta no final da lista
                l->ultimo->proximo = aux;
                l->ultimo = aux;
            }
        }
        //Pergunta ao usuário se deseja continuar cadastrando mais contas
        vaiparaxy(07, 23);
        printf("                                          ");
        vaiparaxy(07, 23);
        printf("Deseja continuar cadastrando?(1-SIM || 2-NAO):");
        scanf("%d", &resp);
        //Continua se o usuário responder "SIM"
    } while (resp == 1);
}