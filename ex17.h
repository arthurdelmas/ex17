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
typedef struct st_lef
{
    unsigned short int f;
    struct st_lef *prox;
} t_lef;

/* tipo lista encadeada simples da funcao de transicao */
typedef struct st_lft
{
    unsigned short int ei;  /* estado inicial */
    char *le;               /* le (string com rotulos) */
    unsigned short int ef;  /* estado final */
    struct st_lft *prox;
} t_lft;

/* tipo quintupla: representacao formal de um automato */
typedef struct st_quintupla
{
    unsigned short int K;   /* conjunto de estados */
    char A;                 /* alfabeto */
    unsigned short int S;   /* estado inicial */
    t_lef *F;               /* lista de estados finais */
    t_lft *D;               /* lista da funcao de transicao d(ei, le, ef) */
} t_quintupla;

/* ---------------------------------------------------------------------- */
/* prototypes */

void help(void); /* print some help */
void copyr(void); /* print version and copyright information */
void exN_init(void); /* global initialization function */
int tipo_operador(char info)
void quebraExpressao(char *expReg, t_arvore **raiz); /*quebra a expressao e armazena na arvore binaria*/    
void separador(char *expReg, char **partEsq, char **partDir, char *op, int size); /*separa a expressao regular no ponto pre determinado*/
void transformacao(t_arvore *raiz); /* realiza as operacoes de acordo com a arvore binaria, na ordem pos ordem */
void operacao_geral(quintupla_t *res, quintupla_t q1, quintupla_t q2, char op);
void operacao_e(quintupla_t *res, quintupla_t q1, quintupla_t q2);/*operacao concatenacao*/
void operacao_ou(quintupla_t *res, quintupla_t q1, quintupla_t q2);/*operacao ou*/
void operacao_estrela(quintupla_t *res, quintupla_t q); /* operacao estrela */
void transicoes_finais(ltrans_t **dest, lest_t *list, int novoFinal); /*Gera transicoes que dao novos estados para os estados finais*/
void copia_lestado(lest_t **dest, lest_t *list);
void copia_ltrans(ltrans_t **dest, ltrans_t *list);
void mini_quintupla(quintupla_t *q, char *lei);
void AFND_AFD_init(const char *entrada);
void estados_simultaneos(quintupla_t Q, lconj_t **simultaneo);
void estados_novos(quintupla_t Qantigo, quintupla_t *Qnovo, lconj_t *simultaneo);
int novo_estado(lest_t *list, lconj_t **conj_estados); /*gera um estado para afd*/
void modelando_conjunto(lconj_t *simultaneo, lest_t **list);
int igualdade_conjunto(lest_t *list, lest_t *list2);
void copia_estado(lest_t **estados, lconj_t *simultaneo, int s); /*Copia estados para um conjunto de estados*/
void primeiro_estado(lest_t **estados, lconj_t *simultaneo, int s); /*Manda o primeiro estado para o conjunto simultaneo*/
void definir_final(lconj_t *conjunto, lest_t *final, lest_t **list);
void AFD_ER_init(const char *arquivo);
void estados_limite(quintupla_t *Q);
int lista_unitaria(ltrans_t *list);
void uniao(ltrans_t **list);
void concatena(ltrans_t **list, int est);
int estado_eliminar(quintupla_t Q);
void concatena_aux(char **dest, char *ch, char *ch2);
char *estrela(ltrans_t **list, int ei_ef); /*verificacao do estado*/
nt definir_tamanho(char *ch, char *ch2); /* define o tamanho da memoria*/





