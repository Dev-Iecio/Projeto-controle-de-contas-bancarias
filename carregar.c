#include "funcoes.h"
//Funçao para Carregar os cadastros das contas
void carregar(tipolista_conta *l)
{
    //Declara ponteiro para o arquivo e variáveis de controle
    FILE *ptr;
    char *nomearquivo = "contas.dat";
    char *modo_leitura = "rb";
    //Tenta abrir o arquivo em modo leitura binária 
    ptr = fopen(nomearquivo, modo_leitura);
    //Verifica se o arquivo foi aberto com sucesso
    if (ptr == NULL)
    {
        printf("ERRO AO ABRIR O ARQUIVO PARA LEITURA\n");
        return;  
    }

    reg_contas contas;
    
    //Limpa a lista antes de carregar novos dados (libera memória e zera a lista)
    tipoApontador_conta p = l->primeiro;
    while (p != NULL)
    {
        tipoApontador_conta temp = p;
        p = p->proximo;
        free(temp);  
    }
    l->primeiro = NULL;
    l->ultimo = NULL;

    //Lê os dados do arquivo e insere na lista encadeada
    while (fread(&contas, sizeof(reg_contas), 1, ptr) == 1)
    {
        //Aloca memória para um novo nó na lista
        tipoApontador_conta novo = (tipoApontador_conta)malloc(sizeof(tipoitem_conta));
        if (novo == NULL)
        {
            //Se a alocação falhar, imprime erro e fecha o arquivo
            printf("ERRO AO ALLOCAR MEMÓRIA PARA NOVO ELEMENTO\n");
            fclose(ptr);
            return;
        }
        //Preenche o novo nó com os dados lidos do arquivo
        novo->conteudo = contas;
        novo->proximo = NULL;

        //Se a lista estiver vazia, o novo nó será o primeiro e o último
        if (l->primeiro == NULL)
        {
            l->primeiro = novo;
            l->ultimo = novo;  
        }
        else
        {
            //Caso contrário, adiciona o novo nó ao final da lista
            l->ultimo->proximo = novo;
            l->ultimo = novo;
        }
    }
    //Fecha o arquivo após o término da leitura
    fclose(ptr);  
}
