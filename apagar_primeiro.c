#include "funcoes.h"
void mostrar_apagar_primeiro(tipolista_conta *l, tipolista_mov *m)
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
}


