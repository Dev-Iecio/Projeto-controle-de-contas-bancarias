/*Autor......: Gabriel Ribeiro
  Data.......: 24/11/2024
  Equipe.....: RA10002691 - Gabriel Dalecio 1
               RA165808-2024 - Gabriel Ribeiro 2
  Objetivo...: Telas */
#include <windows.h>
#include "funcoes.h"

void tela()
{
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
    printf("+-----------------------------------------------------------------------------+");
    vaiparaxy(01, 04);
    printf("+-----------------------------------------------------------------------------+");
    vaiparaxy(01, 22);
    printf("+-----------------------------------------------------------------------------+");
    vaiparaxy(01, 24);
    printf("+-----------------------------------------------------------------------------+");

    vaiparaxy(03, 02);
    printf("GABRIEL DALECIO.RA10002691||GABRIEL RIBEIRO.RA165808-2024");
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

void tela_consulta()
{
    tela();
    vaiparaxy(03, 03);
    printf("                                              ");
    vaiparaxy(03, 03);
    printf("CONSULTAS");

    vaiparaxy(07, 07);
    printf("(1)-Consultar fichario do cliente geral");
    vaiparaxy(07, 9);
    printf("(2)-Consulta por ordem de codigo");
    vaiparaxy(07, 11);
    printf("(3)-Consulta em ordem alfabetica");
    vaiparaxy(07, 13);
    printf("(4)-Consulta por codigo especifico");
    vaiparaxy(07, 15);
    printf("(5)-Retornar");
}

void tela_movimentacao()
{
    tela();
    vaiparaxy(03, 03);
    printf("                                              ");
    vaiparaxy(03, 03);
    printf("MOVIMENTACOES");

    vaiparaxy(07, 07);
    printf("(1)-Movimentacao de Debito e Credito");
    vaiparaxy(07, 9);
    printf("(2)-Transferencia entre contas bancarias");
    vaiparaxy(07, 11);
    printf("(3)-consulta Movimentacoes Bancarias");
    vaiparaxy(07, 13);
    printf("(4)-Retornar");
}

void tela_cadastro_mov()
{
    tela();
    vaiparaxy(7, 06);
    printf("Sequencia Movimentacao.:");
    vaiparaxy(7, 07);
    printf("Codigo da conta........:");
    vaiparaxy(7, 8);
    printf("Banco..................:");
    vaiparaxy(7, 9);
    printf("Agencia................:");
    vaiparaxy(7, 10);
    printf("Numero da Conta........:");
    vaiparaxy(7, 11);
    printf("Tipo da Conta..........:");
    vaiparaxy(7, 12);
    printf("Saldo..................:");
    vaiparaxy(7, 13);
    printf("Limite.................:");
    vaiparaxy(7, 14);
    printf("Saldo+Limite...........:");
    vaiparaxy(01, 16);
    printf("+-----------------------------------------------------------------------------+");
    vaiparaxy(7, 17);
    printf("(1)-Data Movimentacao..:");
    vaiparaxy(7, 18);
    printf("(2)-Tipo Movimentacao..:");
    vaiparaxy(7, 19);
    printf("(3)-Favorecido.........:");
    vaiparaxy(7, 20);
    printf("(4)-Valor Movimentacao.:");
    vaiparaxy(7, 21);
    printf("(5)- Novo Saldo........:");
}

void limpa_msg()
{
    vaiparaxy(07, 23);
    printf("                                                                      ");
}

void tela_transferencia()
{
    tela();
    vaiparaxy(01, 6);
    printf("+------------CONTA ORIGEM-----------------------------CONTA DESTINO-----------+");
    vaiparaxy(40, 7);
    printf("|");
    vaiparaxy(40, 8);
    printf("|");
    vaiparaxy(40, 9);
    printf("|");
    vaiparaxy(40, 10);
    printf("|");
    vaiparaxy(40, 11);
    printf("|");
    vaiparaxy(40, 12);
    printf("|");
    vaiparaxy(40, 13);
    printf("|");
    vaiparaxy(40, 14);
    printf("|");
    vaiparaxy(40, 15);
    printf("|");
    vaiparaxy(01, 16);
    printf("+-----------------------------------------------------------------------------+");

    vaiparaxy(03, 07);
    printf("Codigo da conta.....:");
    vaiparaxy(03, 8);
    printf("Banco...............:");
    vaiparaxy(03, 9);
    printf("Agencia.............:");
    vaiparaxy(03, 10);
    printf("Numero da Conta.....:");
    vaiparaxy(03, 11);
    printf("Tipo da Conta.......:");
    vaiparaxy(03, 12);
    printf("Saldo...............:");
    vaiparaxy(03, 13);
    printf("Limite..............:");
    vaiparaxy(03, 14);
    printf("Saldo+Limite........:");
    vaiparaxy(03, 15);
    printf("Novo Saldo..........:");

    vaiparaxy(41, 07);
    printf("Codigo da conta.....:");
    vaiparaxy(41, 8);
    printf("Banco...............:");
    vaiparaxy(41, 9);
    printf("Agencia.............:");
    vaiparaxy(41, 10);
    printf("Numero da Conta.....:");
    vaiparaxy(41, 11);
    printf("Tipo da Conta.......:");
    vaiparaxy(41, 12);
    printf("Saldo...............:");
    vaiparaxy(41, 13);
    printf("Limite..............:");
    vaiparaxy(41, 14);
    printf("Saldo+Limite........:");
    vaiparaxy(41, 15);
    printf("Novo Saldo..........:");

    vaiparaxy(22, 17);
    printf("Valor a Ser Trasferido.:");

    vaiparaxy(22, 18);
    printf("Data da Transferencia..:");
}

void tela_consultas_contas()
{
    tela();
    vaiparaxy(02, 05);
    printf("Cd");
    vaiparaxy(05, 05);
    printf("Banco");
    vaiparaxy(21, 05);
    printf("Agenc");
    vaiparaxy(28, 05);
    printf("Conta");
    vaiparaxy(38, 05);
    printf("Tipo Conta");
    vaiparaxy(54, 05);
    printf("Saldo");
    vaiparaxy(66, 05);
    printf("Limite");
    vaiparaxy(77, 05);
    printf("St");
    vaiparaxy(01, 06);
    printf("+-- --------------- ------ --------- --------------- ----------- ---------- --+");
}

void tela_consulta_movi(){
    tela();
    vaiparaxy(02, 05);
    printf("Codigo: ");
    vaiparaxy(01, 06);
    printf("+-----------------------------------------------------------------------------+");
    vaiparaxy(02, 07);
    printf("Dt.Movi");
    vaiparaxy(14, 07);
    printf("Favorecido");
    vaiparaxy(40, 07);
    printf("TpMovi");
    vaiparaxy(54, 07);
    printf("Vl.Movi");
    vaiparaxy(70, 07);
    printf("Saldo");
    vaiparaxy(01, 8);
    printf("+----------- ------------------------- ------------- --------------- ---------+");
}
