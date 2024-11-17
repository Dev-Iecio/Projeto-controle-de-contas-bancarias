#include <windows.h>
#include "funcoes.h"

void tela(){
    int lin;

    system("cls");
    system("color 0a");

    for (lin = 1; lin < 25; lin++)
    {
        vaiparaxy(01, lin);
        printf("|");
        vaiparaxy(79, lin);
        printf("|");
    }
    vaiparaxy(01, 01);
    printf("+----------------------------------------------------------------------------+");
    vaiparaxy(01, 04);
    printf("+----------------------------------------------------------------------------+");
    vaiparaxy(01, 22);
    printf("+----------------------------------------------------------------------------+");
    vaiparaxy(01, 24);
    printf("+----------------------------------------------------------------------------+");

    vaiparaxy(03, 02);
    printf("GABRIEL DALECIO.RA10002691||GABRIEL RIBEIRO");
    vaiparaxy(03, 03);
    printf("SISTEMA DE CONTROLE BANCARIO");
    vaiparaxy(02, 23);
    printf("MSG: ");


}

void tela_cadastros()
{

    vaiparaxy(07, 05);
    printf("Codigo da conta...............:");
    vaiparaxy(07, 07);
    printf("(1)-Banco.....................:");
    vaiparaxy(07, 9);
    printf("(2)-Agencia...................:");
    vaiparaxy(07, 11);
    printf("(3)-Numero da Conta...........:");
    vaiparaxy(07, 13);
    printf("(4)-Tipo da Conta.............:");
    vaiparaxy(07, 15);
    printf("(5)-Saldo.....................:");
    vaiparaxy(07, 17);
    printf("(6)-Limite....................:");
    vaiparaxy(07, 19);
    printf("(7)-STATUS....................:");




}

void tela_consulta(){
    tela();
    vaiparaxy(03, 03);
    printf("                                              ");
    vaiparaxy(03,03);
    printf("CONSULTAS");

    vaiparaxy(07, 07);
    printf("(1)-Consultar fichario do cliente geral");
    vaiparaxy(07, 9);
    printf("(2)-Consulta por ordem de codigo");
    vaiparaxy(07, 11);
    printf("(3)-Consulta em ordem alfabetica");
    vaiparaxy(07, 13);
    printf("(4)-Consulta por codigo especifico");
    vaiparaxy(07,15);
    printf("(5)-Retornar");


}