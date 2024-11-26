/*Autor......: Gabriel Dalecio
  Data.......: 24/11/2024
  Equipe.....: RA10002691 - Gabriel Dalecio 1
               RA165808-2024 - Gabriel Ribeiro 2
  Objetivo...: Funcao para carregar */
#include "funcoes.h"
// Funcao para carregar 
void carregar(tipolista_conta *l)
{
    tela();
    vaiparaxy(07,23);
    printf("Cadastro e movimentacoes foram preenchidos");
    getch();
    // Declaração de variáveis para abrir e ler o arquivo
    FILE *ptr;
    char *nomearquivo = "contas.dat";
    char *modo_leitura = "rb"; 
    ptr = fopen(nomearquivo, modo_leitura);
    // Verifica se o arquivo foi aberto corretamente
    if (ptr == NULL)
    {
        printf("ERRO AO ABRIR O ARQUIVO PARA LEITURA\n");
        return;  
    }

    reg_contas contas;
    

    tipoApontador_conta p = l->primeiro;
    while (p != NULL)
    {
        tipoApontador_conta temp = p;
        p = p->proximo;
        free(temp);  
    }
    l->primeiro = NULL;
    l->ultimo = NULL;

    // Lê os dados do arquivo e insere na lista ligada
    while (fread(&contas, sizeof(reg_contas), 1, ptr) == 1)
    {
        tipoApontador_conta novo = (tipoApontador_conta)malloc(sizeof(tipoitem_conta));
        if (novo == NULL)
        {
            printf("ERRO AO ALLOCAR MEMÓRIA PARA NOVO ELEMENTO\n");
            fclose(ptr);
            return;
        }

        novo->conteudo = contas;
        novo->proximo = NULL;

        // Verifica se a lista está vazia e insere o novo nó
        if (l->primeiro == NULL)
        {
            l->primeiro = novo;
            l->ultimo = novo;  
        }
        else
        {
            l->ultimo->proximo = novo;
            l->ultimo = novo;
        }
    }

    fclose(ptr);  
}
