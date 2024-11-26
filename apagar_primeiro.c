/*Autor......: Gabriel Ribeiro
  Data.......: 24/11/2024
  Equipe.....: RA10002691 - Gabriel Dalecio 1
               RA165808-2024 - Gabriel Ribeiro 2
  Objetivo...: Apagar 1 cadastro da lista */
#include "funcoes.h"
// Funcao para apagar Primeiro
void mostrar_apagar_primeiro(tipolista_conta *l, tipolista_mov *m)
{
    tela();
    vaiparaxy(03, 03);
    printf("TELA DELETAR O PRIMEIRO CADASTRO");
    tipoApontador_conta aux;
    int escolha = 5;
    // Verifica se a lista de contas está vazia
    if (l->primeiro == NULL)
    {
        vaiparaxy(07, 05);
        printf("Nenhum funcionario cadastrado.\n");
        getch();
        return;
    }
    else
    {
        aux = l->primeiro; // Se houver itens, começa com o primeiro item da lista
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
        // Verifica se o saldo da conta é diferente de zero. Se for, a conta não pode ser excluída
        if (aux->conteudo.v1_saldo != 0)
        {
            limpa_msg();
            vaiparaxy(07, 23);
            printf("Conta nao pode ser removida");
            getch();
            break;
        }

        tipoApontador_mov aux_m;
           
            if(aux_m->conteudo.sequencial != 0){
                limpa_msg();
                vaiparaxy(07, 23);
                printf("Conta nao pode ser removida possui registro de movimentação");
                getch();
                break;
            }

       
        switch (escolha)
        {
        case 1:
            // Se o usuário escolher excluir, verifica se a lista contém apenas um item
            if (l->primeiro->proximo == NULL)
            {
                // Se a lista tem apenas um item, libera a memória do primeiro item e torna a lista vazia
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
                // Se houver mais de um item, remove o primeiro item da lista
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
            // Se o usuário digitar uma opção inválida
            vaiparaxy(07, 23);
            printf("                                                                     ");
            vaiparaxy(07, 23);
            printf("Digito Invalido");
            getch();
        }
    } while (escolha != 1 && escolha != 0);
}


