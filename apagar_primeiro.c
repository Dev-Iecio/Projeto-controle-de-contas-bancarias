#include "funcoes.h"
//Função que exibe o primeiro cadastro e permite ao usuário removê-lo
void mostrar_apagar_primeiro(tipolista_conta *l)
{
    tela();
    vaiparaxy(03, 03);
    printf("TELA DELETAR O PRIMEIRO CADASTRO");
    tipoApontador_conta aux;
    int escolha = 5;

    //Verifica se a lista esta vazia
    if (l->primeiro == NULL)
    {
        vaiparaxy(07, 05);
        printf("Nenhum funcionario cadastrado.\n");
        getch();
        return;
    }
    else
    {   
        //Atribui o primeiro elemento da lista ao ponteiro auxiliar
        aux = l->primeiro;
    }
    //Inicio do laço para exibir/excluir o primeiro cadastro
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

        //Verifica a escolha do usuario
        switch (escolha)
        {
        case 1:
            //Caso o usuario opte por excluir o primeiro cadastro

            //Veriica se o primeiro cadastro e o unico da lista
            if (l->primeiro->proximo == NULL)
            {
                free(l->primeiro);
                l->primeiro = NULL;
                l->ultimo = NULL;

                //Exibe msg de sucesso na exclusao
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
                //Se o primeiro cadastro não for o único, move o ponteiro 'primeiro' para o próximo
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
            //Caso o usuário forneça uma escolha inválida
            vaiparaxy(07, 23);
            printf("                                                                     ");
            vaiparaxy(07, 23);
            printf("Digito Invalido");
            getch();
        }
      //Repete o loop até o usuário escolher excluir ou voltar
    } while (escolha != 1 && escolha != 0);
}