/*Autor......: Gabriel Dalecio
  Data.......: 24/11/2024
  Equipe.....: RA10002691 - Gabriel Dalecio 1
               RA165808-2024 - Gabriel Ribeiro 2
  Objetivo...: Cadastro Movimentacoes */
#include "funcoes.h"
// Funcao Cadastrar Movi
void cadastro_mov(tipolista_conta *l, tipolista_mov *m)
{
    reg_movimentos movi;
    tipoApontador_mov aux;
    tipoApontador_conta aux_cont;
    reg_contas contas;

    float condicao_sald_limite;
    float saldo_mais_limite;
    char dt_data_inv[11], dt_maior[11], dt_maior_inv[11], favorecido[50];
    int opc;
    int loop;
    int confirma;
    char data[11];

    int movimentacoes_conta = 0;

    float result_movi;

    do
    {

        tela_cadastro_mov();
        vaiparaxy(07, 23);
        printf("Digite o codigo de uma conta ou 0 para sair: ");
        vaiparaxy(31, 07);
        scanf("%d", &movi.codigo_conta);

        if (movi.codigo_conta == 0)
        {
            return;
        }
        else
        {
            limpa_msg();
            aux_cont = verifica_codigo_conta(l, movi.codigo_conta);
            if (aux_cont != NULL)
            {
                // Se a conta for encontrada e estiver desativada, exibe mensagem de erro
                if (aux_cont->conteudo.status == 2)
                {
                    limpa_msg();
                    vaiparaxy(07, 23);
                    printf("Conta desativada");
                    getch();
                    break;
                    return;
                }

                vaiparaxy(31, 06);
                printf("%d", movimentacoes_conta);
                // Exibindo as informações da conta
                vaiparaxy(31, 8);
                printf("%s", aux_cont->conteudo.banco);
                vaiparaxy(31, 9);
                printf("%s", aux_cont->conteudo.agencia);
                vaiparaxy(31, 10);
                printf("%s", aux_cont->conteudo.numero_conta);
                vaiparaxy(31, 11);
                printf("%s", aux_cont->conteudo.tipo_conta);
                vaiparaxy(31, 12);
                printf("%.2f", aux_cont->conteudo.v1_saldo);
                vaiparaxy(31, 13);
                printf("%.2f", aux_cont->conteudo.v1_limite);

                saldo_mais_limite = aux_cont->conteudo.v1_saldo + aux_cont->conteudo.v1_limite;
                vaiparaxy(31, 14);
                printf("%.2f", saldo_mais_limite);
                // Se o saldo e limite da conta forem ambos 0 ou negativos, exibe erro
                if (aux_cont->conteudo.v1_saldo <= 0 && aux_cont->conteudo.v1_limite <= 0)
                {
                    limpa_msg();
                    vaiparaxy(07, 23);
                    printf("Saldo e limite Indisponivel");
                    getch();
                    break;
                    return;
                }
                // Conta quantas movimentações foram feitas nesta conta
                tipoApontador_mov temp = m->primeiro;
                while (temp != NULL)
                {

                    if (temp->conteudo.codigo_conta == movi.codigo_conta)
                    {
                        movimentacoes_conta++;
                    }
                    temp = temp->proximo;
                }

                vaiparaxy(31, 06);
                printf("%d", movimentacoes_conta);

                getch();
            }
            else
            {
                vaiparaxy(07, 23);
                printf("Conta nao encontrada!");
                getch();
                return;
            }
        }

        /*do
        {

            strcpy(movi.dt_movimento, le_movi(31, 17));
            // Compara a data informada com a última data de movimentação
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
        } while (strcmp(inverte_data(movi.dt_movimento), inverte_data(pesquisa_movin_data(m, contas.codigo_conta))) > 0);*/
        do
        {
            // Lê a data de movimentação
            strcpy(movi.dt_movimento, le_movi(31, 17));

            // Compara a data informada com a última data de movimentação
            if (strcmp(inverte_data(movi.dt_movimento), inverte_data(pesquisa_movin_data(m, contas.codigo_conta))) > 0)
            {

                
                /*char *data_inv = inverte_data(movi.dt_movimento);
                char *data_maior_inv = inverte_data(pesquisa_movin_data(m, movi.codigo_conta));

                do
                {
                   
                    if (strcmp(data_inv, data_maior_inv) < 0)
                    {
                        limpa_msg();
                        vaiparaxy(07, 23);
                        printf("A data nao pode ser menor que a ultima data %s", data_maior_inv);
                        strcpy(movi.dt_movimento, le_movi(31, 17));
                        data_inv = inverte_data(movi.dt_movimento);
                    }
                } while (strcmp(data_inv, data_maior_inv) < 0); */

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

        // Pergunta se a movimentação será débito ou crédito
        vaiparaxy(07, 23);
        printf("1-Debito | 2-Credito:");

        scanf("%d", &opc);
        limpa_msg();
        // Exibe o tipo de movimentação escolhida (débito ou crédito)
        switch (opc)
        {
        case 1:
            vaiparaxy(31, 18);
            printf("Debito");
            break;
        case 2:
            vaiparaxy(31, 18);
            printf("Credito");
            break;

        default:
            printf("Opção inválida\n");
            break;
        }

        // Leitura do favorecido
        vaiparaxy(31, 19);
        fflush(stdin);
        fgets(movi.favorecido, 50, stdin); // Lê o favorecido

        // Leitura do valor da movimentação
        vaiparaxy(31, 20);
        scanf("%f", &movi.v1_movimento);
        // Verifica se o saldo ou limite são suficientes para a movimentação
        if (aux_cont->conteudo.v1_limite <= 0 && movi.v1_movimento > aux_cont->conteudo.v1_saldo)
        {
            limpa_msg();
            vaiparaxy(07, 23);
            printf("Saldo e limite nao disponivel");
            getch();
            break;
            return;
        }

        if (aux_cont->conteudo.v1_saldo <= 0 && movi.v1_movimento > aux_cont->conteudo.v1_limite)
        {
            limpa_msg();
            vaiparaxy(07, 23);
            printf("Saldo e limite nao disponivel");
            getch();
            break;
            return;
        }

        // Calculando o saldo resultante após a movimentação
        vaiparaxy(31, 21);
        result_movi = saldo_mais_limite - movi.v1_movimento;

        printf("%.2f", result_movi);
        getch();

        // Confirmação da movimentação
        vaiparaxy(07, 23);
        printf("Confirma a movimentacao?(1-SIM | 2-NAO): ");
        scanf("%d", &confirma);

        switch (confirma)
        {
        case 1:

            // Alocação de memória para um novo nó de movimentação
            aux = (tipoApontador_mov)malloc(sizeof(tipoitem_mov));
            if (aux == NULL)
            {
                vaiparaxy(07, 23);
                printf("Erro ao alocar memoria para movimentacao");
                getch();
                return;
            }

            // Preenchendo os dados da lista de movimentação
            aux->conteudo.codigo_conta = aux_cont->conteudo.codigo_conta;
            strcpy(aux->conteudo.dt_movimento, movi.dt_movimento);
            strcpy(aux->conteudo.favorecido, movi.favorecido);
            aux->conteudo.v1_movimento = movi.v1_movimento;
            aux->conteudo.v1_saldo = aux_cont->conteudo.v1_saldo;
            aux->conteudo.sequencial = movimentacoes_conta;
            aux->conteudo.saldo_atualizado = result_movi;
            strcpy(aux->conteudo.tp_movimento, (opc == 1) ? "Debito" : "Credito");

            // O novo movimento será o último por enquanto
            aux->proximo = NULL;
            aux->anterior = NULL;

            // Se a lista de movimentações estiver vazia
            if (m->primeiro == NULL)
            {
                m->primeiro = aux;
                m->ultimo = aux;
            }
            else
            {
                // Se já houver movimentações, adiciona no final
                m->ultimo->proximo = aux;
                aux->anterior = m->ultimo;
                m->ultimo = aux;
            }

            // Atualiza o saldo na conta após a movimentação
            aux_cont->conteudo.v1_saldo = aux_cont->conteudo.v1_saldo - movi.v1_movimento;

            vaiparaxy(31, 06); // Localize o lugar onde exibir
            printf("%d", movimentacoes_conta);

            break;

        case 2:
            break;

        default:
            break;
        }

        limpa_msg();
        vaiparaxy(07, 23);
        printf("Deseja realizar outra movimentacao:(1-sim | 2-nao): ");
        scanf("%d", &loop);

        // movimentacoes_conta = 0;
    } while (loop == 1);
}
