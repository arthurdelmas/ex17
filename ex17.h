/***************************************************************************
 *   exN.h                                 Version 20160609.110111       *
 *                                                                         *
 *   Library for exN, a program that converts ER into AFND               *
 *   Copyright (C) 2016         by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License                *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the author, please write to:                               *
 *   Ruben Carlo Benante                                                   *
 *   Email: rcb@beco.cc                                                    *
 *   Webpage: http://www.beco.cc                                           *
 *   Phone: +55 (81) 3184-7555                                             *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION
#define VERSION "20160609.110111" /**< Version Number */
#endif

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /**< Activate/deactivate debug mode */
#endif

/** @brief Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SBUFF 256 /**< String buffer */

/* ---------------------------------------------------------------------- */
/* globals */

static int verb=0; /**< verbose level, global within the file */

/* tipo lista encadeada simples dos estados finais */
typedef struct st_estlist
{
    int estado;
    struct st_estlist *prox;
} lest_t;

/* tipo lista encadeada simples da funcao de transicao */
typedef struct st_translist
{
    int ei;     /* estado inicial */
    char *lei;
    int ef;     /* estado final */
    struct st_translist *prox;
} ltrans_t;

/* lista de conjuntos de estdados*/
typedef struct st_conjlist
{
    int id;
    struct st_estlist *estados;
    struct st_conjlist *prox;
}lconj_t;

/* tipo quintupla: representacao formal de um automato */
typedef struct st_quintupla
{
    int K;   /* conjunto de estados */
    char A;                 /* alfabeto */
    int S;   /* estado inicial */
    lest_t *F;               /* lista de estados finais */
    ltrans_t *D;               /* lista da funcao de transicao d(ei, le, ef) */
}quintupla_t;

typedef struct st_arvore
{
    char *expReg;
    int tipo_op; /*tipo de operador, 0->nao operador, 1 ->operador unario, 2->operador binario*/
    quintupla_t Q;
    struct st_arvore *esq, *dir, *pai;
}t_arvore;
/* Variaveis Global*/

int id_estado= 0;

/* ---------------------------------------------------------------------- */
/* prototypes */

void help(void); /* print some help */
void copyr(void); /* print version and copyright information */

/* Tranformacao ER para AFND*/

void ER_AFND_init(char *expReg); /* global initialization function */
void entrada_ER(char *expReg, char *entrada);
void quebraExpressao(char *expReg, t_arvore **raiz);
void transformacao(t_arvore *raiz);
void salva_quintupla(quintupla_t Q, char *arquivo);

void separador(char *expReg, char **partEsc, char **partDir, char *op, int size);
void mini_quintupla(quintupla_t *q, char *lei);
void transicoes_finais(ltrans_t **dest, lest_t *list, int novoFinal);

void operacao_estrela(quintupla_t *res, quintupla_t q);
void operacao_ou(quintupla_t *res, quintupla_t q1, quintupla_t q2);
void operacao_e(quintupla_t *res, quintupla_t q1, quintupla_t q2);
void operacao_geral(quintupla_t *res, quintupla_t q1, quintupla_t q2, char op);

void copia_ltrans(ltrans_t **dest, ltrans_t *list);
void copia_lestado(lest_t **dest, lest_t *list);

int tipo_operador(char info);
void insere_arvore(t_arvore **raiz, t_arvore *ant, char *info);

/*--------------------------------------------------------------*/
/* ----------------------AFND para AFD--------------------------*/
void AFND_AFD_init(const char *arquivo);
void estados_simultaneos(quintupla_t Q, lconj_t **simultaneo); /* Gerar os estados simultaneos*/
void estados_novos(quintupla_t Qantigo, quintupla_t *Qnovo, lconj_t *simultaneo); /* Gerar a quintupla para AFD*/
void salva_quintupla(quintupla_t Q, char *arquivo); /* armazena uma quintupla no arquivo com o nome dado, ou imprime na tela*/

void coleta_final(lest_t **list, FILE *stream); /* auxiliar da funcao entrada_dados(), coleta do arquivo os estados finais*/
void coleta_transicao(ltrans_t **list, FILE *stream); /* auxiliar da funcao entrada_dados(), coleta do arquivo as transicoes*/
int novo_estado(lest_t *list, lconj_t **conj_estados); /* gera um novo estado (AFD) caso não haja estado igual*/
void modelando_conjunto(lconj_t *simultaneo, lest_t **list); /* A list entra com o conjunto de indices para os conjuntos de estados simultaneos*/

int igualdade_conjunto(lest_t *list, lest_t *list2); /* verifica se dois conjuntos sao identicos*/
void primeiro_estado(lest_t **estados, lconj_t *simultaneo, int s); /* busca entre o estados simultaneos o que o estados inicial, tal conjunto se torna o estado inicial da AFD*/
void copia_estado(lest_t **estados, lconj_t *simultaneo, int s); /* copia um conjunto dos estados simultanenos para um conjunto separado*/
void definir_final(lconj_t *conjunto, lest_t *final, lest_t **list);

void insere_conjunto(lconj_t **list, int id);
void insere_conjuntoFULL(lconj_t **conjunto, lest_t *list, int id);

/* ------------------------------------------------------------ */
/* ------------------------ AFD para ER ----------------------- */

void AFD_ER_init(const char *arquivo);
void coleta_transicao(ltrans_t **list, FILE *stream);
void coleta_final(lest_t **list, FILE *stream);

void uniao(ltrans_t **list);
void concatena(ltrans_t **list, int est);
char *estrela(ltrans_t **list, int ei_ef);

void concatena_aux(char **dest, char *ch, char *ch2);
void estados_limite(quintupla_t *Q);
int lista_unitaria(ltrans_t *list);
int definir_tamanho(char *ch, char *ch2);
int estado_eliminar(quintupla_t Q);
int busca_semelhantes(ltrans_t *list, ltrans_t **pl, ltrans_t **pl2);

/* ------------------------------------------------------------ */
/*----------------------- Geral ------------------------------- */

void entrada_Automato(quintupla_t *Q, const char *entrada); /* coleta a quintupla de arquivo formatado especifico*/

void insere_estado(lest_t **list, int est);
void insere_transicao(ltrans_t **list, int ei, char *lei, int ef);

void imprime_transicao(ltrans_t *list, FILE *stream);
void imprime_estados(lest_t *list, FILE *stream);
void imprime_arvore(t_arvore *raiz, FILE *stream);

lconj_t *busca_conjunto(lconj_t *list, int id);
ltrans_t *busca_simultaneo(ltrans_t *list, int ref); /* Busca uma transicao cujo o estado de referencia (ref) seja simutaneo*/
ltrans_t *busca_transicao(ltrans_t *list, int ei, char *lei);
ltrans_t *busca_transicao_lei(ltrans_t *list, int ei, int ef);
ltrans_t *busca_por_ei(ltrans_t *list, int est);
ltrans_t *busca_por_ef(ltrans_t *list, int est);

void remove_estado(lest_t **list, lest_t *r);
void remove_transicao(ltrans_t **list, ltrans_t *r);
void remove_conjunto(lconj_t **list, lconj_t *r);
void apaga_estados(lest_t **list);
void apaga_conjunto(lconj_t **list);
void apaga_transicao(ltrans_t **list);

/* --------------------------------------------------- */
