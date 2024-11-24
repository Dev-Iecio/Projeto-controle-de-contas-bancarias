#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

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
    int codigo_conta2;
    char dt_movimento[11];
    char tp_movimento[11];
    char favorecido[50];
    float v1_movimento;
    float v1_saldo;
    float saldo_atualizado;
    float saldo_conta2;
} reg_movimentos;

typedef struct tipoitem_mov *tipoApontador_mov;

typedef struct tipoitem_mov
{
    reg_movimentos conteudo;
    tipoApontador_mov proximo;  // Aponta para o próximo nó
    tipoApontador_mov anterior; // Aponta para o nó anterior
} tipoitem_mov;

typedef struct
{
    tipoApontador_mov primeiro; // Aponta para o primeiro nó
    tipoApontador_mov ultimo;   // Aponta para o último nó
} tipolista_mov;

void vaiparaxy(int x, int y);

// tela padrao
void tela();

// tela cadastros
void tela_cadastros();

void tela_consulta();

void tela_movimentacao();

void tela_cadastro_mov();

void tela_transferencia();

void tela_consultas_contas();

void tela_consulta_movi();

void limpa_msg();

char *inverte_data(char *dt_data);

char *pesquisa_movin_data(tipolista_mov *m, int codigo_conta);

char *le_movi(int col, int lin);

//int verifica_maior_data(char *data1, char *data2);

// funçao para verificar se o usuario esta digitando um codigo que ja existe em outra conta
tipoApontador_conta verifica_codigo_conta(tipolista_conta *l, int cod);

// funçao para cadastrar uma conta no final da lista
void cadastro_final_lista(tipolista_conta *l);

// cadastrar no inicio
void cadastro_inicio_lista(tipolista_conta *l);

// cadastrar na posicao
void cadastro_na_posicao(tipolista_conta *l);

void mostrar_e_apagar_ultimo(tipolista_conta *l,tipolista_mov *m);

void gravar(tipolista_conta *l);

void carregar(tipolista_conta *l);

void gravar_movi(tipolista_mov *m);

void carregar_movi(tipolista_mov *m);

void mostrar_apagar_primeiro(tipolista_conta *l, tipolista_mov *m);

void remover_em_posicao(tipolista_conta *l, tipolista_mov *m);

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
void menu_contas_bancarias(tipolista_conta *l, tipolista_mov *m);

void menu_movimentacao(tipolista_conta *l, tipolista_mov *m);

void cadastro_mov(tipolista_conta *l, tipolista_mov *m);

void transferencia(tipolista_conta *l, tipolista_mov *m);

void consulta_movi(tipolista_conta *l, tipolista_mov *m);

int conta_movi(tipolista_mov *m, int cod);
#endif