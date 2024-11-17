#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>

#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct
{
    int codigo_conta;
    char banco[50];
    char agencia[10];
    char numero_conta[50];
    char tipo_conta[10];
    float v1_saldo;
    float v1_limite;
    int status;
} reg_contas;

typedef struct tipoitem_conta *tipoApontador_conta;

typedef struct tipoitem_conta
{
    reg_contas conteudo;
    tipoApontador_conta proximo;

} tipoitem_conta;

typedef struct
{
    tipoApontador_conta primeiro;
    tipoApontador_conta ultimo;
} tipolista_conta;

typedef struct
{
    int sequencial;
    int codigo_conta;
    char dt_movimento[10];
    char tp_movimento[10];
    float v1_movimento;
    float v1_saldo;
} reg_movimentos;

void vaiparaxy(int x, int y);

// tela padrao
void tela();

// tela cadastros
void tela_cadastros();

void tela_consulta();

// funçao para verificar se o usuario esta digitando um codigo que ja existe em outra conta
tipoApontador_conta verifica_codigo_conta(tipolista_conta *l, int cod);

// funçao para cadastrar uma conta no final da lista
void cadastro_final_lista(tipolista_conta *l);

// cadastrar no inicio
void cadastro_inicio_lista(tipolista_conta *l);

// cadastrar na posicao
void cadastro_na_posicao(tipolista_conta *l);

void mostrar_e_apagar_ultimo(tipolista_conta *l);

void gravar(tipolista_conta *l);

void carregar(tipolista_conta *l);

void mostrar_apagar_primeiro(tipolista_conta *l);

void remover_em_posicao(tipolista_conta *l);

void alterar_na_posicao(tipolista_conta *l);

// void salvar_alteracao(tipolista_conta *l);

// void menu_consulta_contas(tipolista_conta *l);

void consultar(tipolista_conta *l);

void consulta_ordem_codigo(tipolista_conta *l);

void consulta_ordem_alfabetica(tipolista_conta *l);

void consulta_por_codigo(tipolista_conta *l);

void menu_consulta(tipolista_conta *l);

int tamanho(tipolista_conta *l);

void listar_cadastros(tipolista_conta *l);

// funçao menu de opçoes de cadastros
void menu_contas_bancarias(tipolista_conta *l);

#endif