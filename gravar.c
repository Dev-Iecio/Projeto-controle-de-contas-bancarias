#include "funcoes.h"
//Funcao para Gravar os Cadastros de Contas
void gravar(tipolista_conta *l)
{
    //Declara um ponteiro para o arquivo e um nome para o arquivo de destino
    FILE *ptr;
    char *nomearquivo = "contas.dat";
    char *modo_gravacao = "wb";  

    //Abre o arquivo para gravação no modo binário ("wb")
    ptr = fopen(nomearquivo, modo_gravacao);
    //Verifica se o arquivo foi aberto corretamente
    if (ptr == NULL)
    {
        printf("Erro ao abrir o arquivo para gravação\n");
        exit(1);  
    }

    //Ponteiro para percorrer a lista de contas
    tipoApontador_conta p = l->primeiro;

    //Loop para percorrer a lista de contas e gravar cada uma no arquivo
    while (p != NULL)
    {
        //Grava o conteúdo da conta no arquivo
        fwrite(&p->conteudo, sizeof(reg_contas), 1, ptr);
        //Avança para o próximo item da lista  
        p = p->proximo;  
    }
    //Fecha o arquivo após a gravação
    fclose(ptr); 
}