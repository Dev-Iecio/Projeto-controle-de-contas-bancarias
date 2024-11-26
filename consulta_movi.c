/*Autor......: Gabriel Ribeiro
  Data.......: 24/11/2024
  Equipe.....: RA10002691 - Gabriel Dalecio 1
               RA165808-2024 - Gabriel Ribeiro 2
  Objetivo...: Consultar movimentaçoes */
#include "funcoes.h"
// Funcao Consultar Movimentacoes
void consulta_movi(tipolista_conta *l, tipolista_mov *m)
{
    reg_movimentos movi;
    tipoApontador_mov aux;
    tipoApontador_conta aux_cont;
    int posicao = 0;
    tela_consulta_movi();
    
    // Solicita ao usuário o código de uma conta ou 0 para sair
    vaiparaxy(07, 23);
    printf("Digite o codigo de uma conta ou 0 para sair: ");
    vaiparaxy(9, 5);
    scanf("%d", &movi.codigo_conta);
    // Se o usuário digitar 0, sai da função
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
            // Exibe informações da conta
            vaiparaxy(11, 5);
            printf("- %s", aux_cont->conteudo.banco);
            vaiparaxy(24, 5);
            printf("Agen:");
            vaiparaxy(29, 5);
            printf("%s", aux_cont->conteudo.agencia);
            vaiparaxy(35, 5);
            printf("Cta:");
            vaiparaxy(40, 5);
            printf("%s", aux_cont->conteudo.numero_conta);
            vaiparaxy(48, 5);
            printf("Tp:");
            vaiparaxy(51, 5);
            printf("%s", aux_cont->conteudo.tipo_conta);

            
        }
        else
        {
            // Se a conta não for encontrada, exibe uma mensagem de erro
            vaiparaxy(07, 23);
            printf("Conta não encontrada!");
            getch();
            return;
        }
    }
    // Verifica se há movimentações registradas
    if (m->primeiro == NULL)
    {
        // Se não houver movimentações, exibe uma mensagem
        vaiparaxy(07, 23);
        printf("Nenhuma movimentacao foi feita");
        
        getch();
        limpa_msg();
        return;
    }
    else
    {
        // Caso existam movimentações, percorre a lista de movimentações
        aux = m->primeiro;
        int linha = 9;
      
        // Percorre a lista de movimentações
        for (; aux != NULL; aux = aux->proximo)
        {
          
            if (aux->conteudo.codigo_conta == movi.codigo_conta)
            {
                vaiparaxy(02, linha);
                printf("%s", aux->conteudo.dt_movimento);

                vaiparaxy(14, linha);
                printf("%s", aux->conteudo.favorecido);

                vaiparaxy(40, linha);
                printf("%s", aux->conteudo.tp_movimento);

                vaiparaxy(54, linha);
                printf("%.2f", aux->conteudo.v1_movimento);

                vaiparaxy(70, linha);
                printf("%.2f", aux->conteudo.saldo_atualizado);

                linha++;
            }
        }
        
    }

    getch(); // Aguarda a tecla pressionada para continuar
}
/*#include "funcoes.h"
void listar_cadastros(tipolista_conta *l)
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