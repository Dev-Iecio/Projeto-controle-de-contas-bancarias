#include "funcoes.h"
void carregar(tipolista_conta *l)
{
    tela();
    vaiparaxy(07,23);
    printf("Cadastro e movimentacoes foram preenchidos");
    getch();
    FILE *ptr;
    char *nomearquivo = "contas.dat";
    char *modo_leitura = "rb"; 
    ptr = fopen(nomearquivo, modo_leitura);

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
