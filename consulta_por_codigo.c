/*Autor......: Gabriel Ribeiro
  Data.......: 24/11/2024
  Equipe.....: RA10002691 - Gabriel Dalecio 1
               RA165808-2024 - Gabriel Ribeiro 2
  Objetivo...: Consulta por codigo */
#include "funcoes.h"
// Funcao para consultar por codigo 
void consulta_por_codigo(tipolista_conta *l)
{
    tela();
    tipoApontador_conta aux;
    int opc;
    // Verifica se não há contas cadastradas na lista
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
                printf(" %d", aux->conteudo.codigo_conta);

                vaiparaxy(40, 07);
                printf(" %s", aux->conteudo.banco);

                vaiparaxy(40, 9);
                printf(" %s", aux->conteudo.agencia);

                vaiparaxy(40, 11);
                printf(" %s", aux->conteudo.numero_conta);

                vaiparaxy(40, 13);
                printf(" %s", aux->conteudo.tipo_conta);

                vaiparaxy(40, 15);
                printf(" %.2f", aux->conteudo.v1_saldo);

                vaiparaxy(40, 17);
                printf(" %.2f", aux->conteudo.v1_limite);

                vaiparaxy(40, 19);
                printf(" %d", aux->conteudo.status);

                vaiparaxy(07, 23);
                printf("Pressione qualquer tecla para continuar...");
                getch();
            }

        } while (opc != 0 && aux == NULL); // Repete até encontrar o código ou o usuário digitar 0 para sair

    } while (opc != 0); // Finaliza o loop quando o usuário digita 0
}