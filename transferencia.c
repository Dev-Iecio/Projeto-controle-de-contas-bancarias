#include "funcoes.h"

void transferencia(tipolista_conta *l, tipolista_mov *m)
{

    reg_movimentos movi;
    tipoApontador_mov aux;
    tipoApontador_conta aux_cont;
    reg_contas contas;
    tipoApontador_conta aux_conta_destino;

    float saldo_mais_limite;
    float valor_transferido = 0;
    float result_transderido = 0;
    int loop;
    int confirma_transferencia;

    do
    {
        tela_transferencia();
        vaiparaxy(07, 23);
        printf("Digite o codigo de uma conta ou 0 para sair: ");
        vaiparaxy(24, 07);
        scanf("%d", &movi.codigo_conta);

        if (movi.codigo_conta == 0)
        {
            return;
        }

        else
        {

            do
            {
                limpa_msg();
                aux_cont = verifica_codigo_conta(l, movi.codigo_conta);
                if (aux_cont == NULL)
                {
                    vaiparaxy(07, 23);
                    printf("Conta nao encontrada!");
                    getch();
                    limpa_msg();
                    vaiparaxy(24, 07);
                    printf("           ");
                    vaiparaxy(24, 07);
                    scanf("%d", &movi.codigo_conta);
                }
            } while (aux_cont == NULL);

            if (aux_cont != NULL)
            {

                // Exibindo as informações da conta
                vaiparaxy(24, 8);
                printf("%s", aux_cont->conteudo.banco);
                vaiparaxy(24, 9);
                printf("%s", aux_cont->conteudo.agencia);
                vaiparaxy(24, 10);
                printf("%s", aux_cont->conteudo.numero_conta);
                vaiparaxy(24, 11);
                printf("%s", aux_cont->conteudo.tipo_conta);
                vaiparaxy(24, 12);
                printf("%.2f", aux_cont->conteudo.v1_saldo);
                vaiparaxy(24, 13);
                printf("%.2f", aux_cont->conteudo.v1_limite);

                saldo_mais_limite = aux_cont->conteudo.v1_saldo + aux_cont->conteudo.v1_limite;
                vaiparaxy(24, 14);
                printf("%.2f", saldo_mais_limite);
                getch();
                saldo_mais_limite = 0;
            }

            vaiparaxy(62, 07);
            scanf("%d", &movi.codigo_conta2);

            do
            {
                while (movi.codigo_conta == movi.codigo_conta2)
                {
                    vaiparaxy(07, 23);
                    printf("Conta destino nao pode ser igual a conta origem");
                    getch();
                    limpa_msg();
                    vaiparaxy(62, 07);
                    printf("          ");
                    vaiparaxy(62, 07);
                    scanf("%d", &movi.codigo_conta2);
                }
                limpa_msg();
                aux_cont = verifica_codigo_conta(l, movi.codigo_conta2);
                if (aux_cont == NULL)
                {
                    vaiparaxy(07, 23);
                    printf("Conta nao encontrada!");
                    getch();
                    vaiparaxy(62, 07);
                    printf("          ");
                    limpa_msg();
                    vaiparaxy(62, 07);
                    scanf("%d", &movi.codigo_conta2);
                }
            } while (aux_cont == NULL);

            if (aux_cont != NULL)
            {

                // Exibindo as informações da conta
                vaiparaxy(62, 8);
                printf("%s", aux_cont->conteudo.banco);
                vaiparaxy(62, 9);
                printf("%s", aux_cont->conteudo.agencia);
                vaiparaxy(62, 10);
                printf("%s", aux_cont->conteudo.numero_conta);
                vaiparaxy(62, 11);
                printf("%s", aux_cont->conteudo.tipo_conta);
                vaiparaxy(62, 12);
                printf("%.2f", aux_cont->conteudo.v1_saldo);
                vaiparaxy(62, 13);
                printf("%.2f", aux_cont->conteudo.v1_limite);

                saldo_mais_limite = aux_cont->conteudo.v1_saldo + aux_cont->conteudo.v1_limite;
                vaiparaxy(62, 14);
                printf("%.2f", saldo_mais_limite);
                saldo_mais_limite = 0;
                // movi.saldo_conta2 = aux_cont->conteudo.v1_saldo;

                getch();
            }
            else
            {
                vaiparaxy(07, 23);
                printf("Conta nao encontrada!");
                getch();
                return;
            }

            vaiparaxy(46, 17);
            scanf("%f", &valor_transferido);

            aux_cont = verifica_codigo_conta(l, movi.codigo_conta);
            
            if (valor_transferido > aux_cont->conteudo.v1_saldo + aux_cont->conteudo.v1_limite)
            {
                vaiparaxy(07, 23);
                printf("Saldo insuficiente para realizar a transferencia.");
                getch();
                return;
            }

            if (aux_cont->conteudo.v1_saldo <= 0 && aux_cont->conteudo.v1_limite <= 0)
            {
                vaiparaxy(07, 23);
                printf("Saldo insuficiente para realizar a transferencia.");
                getch();
                return;
            }

            do
            {
                strcpy(movi.dt_movimento, le_movi(46, 18));

                if (strcmp(inverte_data(movi.dt_movimento), inverte_data(pesquisa_movin_data(m, contas.codigo_conta))) > 0)
                {
                    vaiparaxy(07, 23);
                    printf("Data Invalida");
                    getch();
                    limpa_msg();
                    vaiparaxy(07, 23);
                    printf("%s - %s", pesquisa_movin_data(m, contas.codigo_conta), inverte_data(movi.dt_movimento));
                    getch();
                    limpa_msg();
                }
            } while (strcmp(inverte_data(movi.dt_movimento), inverte_data(pesquisa_movin_data(m, contas.codigo_conta))) > 0);

            vaiparaxy(07, 23);
            printf("Confirma a Transferencia?(1-Sim | 2-Nao)");
            scanf("%d", &confirma_transferencia);
            limpa_msg();

            if (confirma_transferencia == 1)
            {

                aux_cont->conteudo.v1_saldo -= valor_transferido;
                saldo_mais_limite = aux_cont->conteudo.v1_saldo + aux_cont->conteudo.v1_limite;

                if (aux_cont->conteudo.v1_saldo < 0)
                {
                    aux_cont->conteudo.v1_limite -= valor_transferido;
                    vaiparaxy(24, 13);
                    printf("          ");
                    vaiparaxy(24, 13);
                    printf("%.2f", aux_cont->conteudo.v1_limite);
                }

                vaiparaxy(24, 14);
                printf("           ");
                vaiparaxy(24, 14);
                printf("%.2f", saldo_mais_limite);
                vaiparaxy(24, 15);
                printf("%.2f", aux_cont->conteudo.v1_saldo);

                aux_conta_destino = verifica_codigo_conta(l, movi.codigo_conta2);

                aux_conta_destino->conteudo.v1_saldo += valor_transferido;
                saldo_mais_limite = aux_conta_destino->conteudo.v1_saldo + aux_conta_destino->conteudo.v1_limite;

                vaiparaxy(62, 14);
                printf("            ");
                vaiparaxy(62, 14);
                printf("%.2f", saldo_mais_limite);
                vaiparaxy(62, 15);
                printf("%.2f", aux_conta_destino->conteudo.v1_saldo);
                vaiparaxy(07, 23);
                printf("Transferencia realizada com sucesso!");
                getch();

                // Inserindo os dados na lista
                reg_movimentos novo_movi;
                novo_movi.codigo_conta = movi.codigo_conta;
                novo_movi.codigo_conta2 = movi.codigo_conta2;
                strcpy(novo_movi.dt_movimento, movi.dt_movimento);
                strcpy(novo_movi.tp_movimento, "transferencia");
                novo_movi.v1_movimento = valor_transferido;
                novo_movi.v1_saldo = aux_cont->conteudo.v1_saldo;
                novo_movi.saldo_conta2 = aux_conta_destino->conteudo.v1_saldo;

                // Passo 2: Inserir o movimento na lista de movimentos.
                tipoApontador_mov novo_movi2 = (tipoApontador_mov)malloc(sizeof(tipoitem_mov));
                if (novo_movi2 == NULL)
                {
                    printf("Erro ao alocar memoria para o movimento.");
                    return;
                }

                novo_movi2->conteudo = novo_movi;
                novo_movi2->proximo = NULL;
                novo_movi2->anterior = m->ultimo;

                if (m->ultimo != NULL)
                {
                    m->ultimo->proximo = novo_movi2;
                }

                m->ultimo = novo_movi2;

                if (m->primeiro == NULL)
                {
                    m->primeiro = novo_movi2;
                }
            }
            else
            {
                break;
            }
        }

        vaiparaxy(07, 23);
        printf("Deseja realizar uma nova transferencia?(1-Sim || 2-Nao):");
        scanf("%d", &loop);
        saldo_mais_limite = 0;
    } while (loop == 1);
}
