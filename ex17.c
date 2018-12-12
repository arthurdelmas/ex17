/***************************************************************************
 *   exN.c                                 Version 20160609.110111       *
 *                                                                         *
 *   Convert ER into AFD                                                   *
 *   Copyright (C) 2016         by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation version 2 of the License.                *
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
/**
 * @file exN.c
 * @ingroup GroupUnique
 * @brief diga algo curto (titulo)
 * @details diga algo detalhado 
 * @version 20160609.110101
 * @date 2016-06-09
 * @author Ruben Carlo Benante <<rcb@beco.cc>>
 * @par Webpage
 * <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @copyright (c) 2016 GNU GPL v2
 * @note This program is free software: you can redistribute it
 * and/or modify it under the terms of the
 * GNU General Public License as published by
 * the Free Software Foundation version 2 of the License.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA. 02111-1307, USA.
 * Or read it online at <<http://www.gnu.org/licenses/>>.
 *
 *
 * @todo Now that you have the template, hands on! Programme!
 * @warning Be carefull not to lose your mind in small things.
 * @bug This file right now does nothing usefull
 *
 */

/*
 * Instrucoes para compilar:
 *   $gcc exN.c -o exN.x -Wall
 *        -Wextra -ansi -pedantic-errors -g -O0 -DDEBUG=1
 * ou preferencialmente use o:
 *   $make
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <getopt.h> /* get options from system argc/argv */
#include <string.h> /* Strings functions definitions */
#include "exN.h" /* library with definitions */

/* #include <time.h> */ /* Time and date functions */
/* #include <math.h> */ /* Mathematics functions */
/* #include <assert.h> */ /* Verify assumptions with assert */
/* #include <dlfcn.h> */ /* Dynamic library */
/* #include <malloc.h> */ /* Dynamic memory allocation */
/* #include <unistd.h> */ /* UNIX standard function */
/* #include <limits.h> */ /* Various C limits */
/* #include <ctype.h> */ /* Character functions */
/* #include <errno.h> */ /* Error number codes errno */
/* #include <signal.h> */ /* Signal processing */
/* #include <stdarg.h> */ /* Functions with variable arguments */
/* #include <pthread.h> */ /* Parallel programming with threads */
/* #include <fcntl.h> */ /* File control definitions */
/* #include <termios.h> */ /* Terminal I/O definitions POSIX */
/* #include <sys/stat.h> */ /* File status and information */
/* #include <float.h> */ /* Float constants to help portability */
/* #include <setjmp.h> */ /* Bypass standard function calls and return */
/* #include <stddef.h> */ /* Various types and MACROS */
/* #include <SWI-Prolog.h> */ /* Prolog integration with C */
/* #include <ncurses.h> */ /* Screen handling and optimisation functions */
/* #include <allegro.h> */ /* A game library for graphics, sounds, etc. */
/* #include <libintl.h> */ /* Internationalization / translation */
/* #include <locale.h> */ /* MACROS LC_ for location specific settings */
/* #include "libeco.h" */ /* I/O, Math, Sound, Color, Portable Linux/Windows */

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This is the main event of the evening
 * @details Ladies and Gentleman... It's tiiiime!
 * Fightiiiiing at the blue corner,
 * he, who has compiled more C code than any other adversary in the history,
 * he, who has developed UNIX and Linux, and is an inspiration to maaany languages
 * and compilers, the GNU C Compiler, GCC!
 * Fightiiiiing at the red corner, the challenger, in his first fight, lacking of any
 * valid experience but angrily, blindly, and no doubtfully, will try to
 * compile this program without errors. He, the student, the apprentice,
 * the developer, beco!!
 *
 * @param[in] argc Argument counter
 * @param[in] argv Argument strings (argument values)
 *
 * @retval 0 If succeed (EXIT_SUCCESS).
 * @retval 1 Or another error code if failed.
 *
 * @par Example
 * @code
 *    $./exN -h
 * @endcode
 *
 * @warning   Be carefull with...
 * @bug There is a bug with...
 * @todo Need to do...
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20160609.110101
 * @date 2016-06-09
 *
 */
int main(int argc, char *argv[])
{
    int opt; /* return from getopt() */

    IFDEBUG("Starting optarg loop...\n");

    /* getopt() configured options:
     *        -h  help
     *        -c  copyrithg and version notes
     *        -v  verbose
     *        -f  given file name
     */
    opterr = 0;
    while((opt = getopt(argc, argv, "vhcf:")) != EOF)
        switch(opt)
        {
            case 'h':
                help();
                break;
            case 'c':
                copyr();
                break;
            case 'v':
                verb++;
                break;
            case '?':
                break;
            case 'f':
                strcpy(sfile, optarg);
                break;
            default:
                printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
                return EXIT_FAILURE;
        }

    if(verb)
        printf("Verbose level set at: %d\n", verb);
    /* ...and we are done */

    exN_init(); /* global initialization function: ainda a saber para que usar se precisar */

    return EXIT_SUCCESS;
}

/**
 * @brief identifica o tipo da informacao: nao operador, operador unario ou operador binario
 * @param [in] info informacao
 * @return 0 p/ nao operador, 1 p/ operador unario, 2 p/ operador binario
 */

int tipo_operador(char info)
{
    if(info == '.' || info == '|')
        return 2;
    if(info == '*')
        return 1;
    return 0;
} 
/**
 * @brief responsavel em quebra a expressao regular em expressoes minimas, e armazenando numa arvore binaria
 * @param [in] expReg Expressao Regular
 * @param [out] raiz Arvore Binaria
 */

/**
 * @brief responsavel em quebra a Expressao Regular em expressoes miminas, e armazenando numa arvore binaria
 * @param [in] expReg Expressao Regular
 * @param [out] raiz Arvore Binaria
 */

void quebraExpressao(char *expReg, t_arvore **raiz)
{
    const int nOp= 3; /*numero de operadores*/
    char operadores[3] = { '|', '.', '*'} /*operadores em ordem crescente de prioridade*/,
         *op = malloc(2*sizeof(char)) /*operador*/,
         *partEsq, *partDir; /*Quebra da expressoes partes esquerda e direita*/
    int i, parentese= 0 /*parentese aberto*/;
    size_t j;
    
    if(!expReg)
        return;
    /*Procurando pelo operador de menor prioridade, sera o ponto de bisseccao da expressao*/
    for(i=0; i<nOp; i++)
    {
        for(j=0; j<strlen(expReg); j++) /*expressao escolhida, de baixa prioridade para alta*/
        {
            if(expReg[j] == '(') /* para caso esteja entrando no parentese onde torna a expressao prioritaria*/
                parentese++;
            else if(expReg[j] == ')') /* saindo do parentese */
                parentese--;
            else if (expReg[j] == operadores[i] && parentese == 0) /* verificando se entrou o operador, caso nao esteja dentro do parentese */
            {
                separador(expReg, &partEsq, &partDir, op, j);

                insere_arvore(raiz, *raiz, op);

                /* caso foi alcancado uma expressao minima */
                if(strlen(partEsq) == 1)
                    insere_arvore(raiz, *raiz, partEsq);
                else
                    quebraExpressao(partEsq, raiz);

                /* caso foi alcancado uma expressao minima */
                if(strlen(partDir) == 1)
                    insere_arvore(raiz, *raiz, partDir);
                else
                    quebraExpressao(partDir, raiz);
                
                return;
            }
        }
     }
     return;

}

/**
 * @brief Separar a expressao regular no ponto pre determinado
 * @param [in] expReg ER(expressao regular)
 * @param [out] partEsq parte esquerda da ER
 * @param [out] partDir parte direita da ER
 * @param [in] size ponto de bisseccao
 */
void separador(char *expReg, char **partEsq, char **partDir, char *op, int size)
{
    char *esq, *dir;
    
    esq=malloc((size+1)*sizeof(char));
    dir=malloc((strlen(expReg)-size)*sizeof(char));
    
    strncpy(esq, expReg, size);
    esq[size] = '\0';
    strcpy(dir, expReg+size+1);
         
    /*
     *Retirar os parenteses no caso da expressao regular esteja contida nelas
    */

    *partEsq=esq;
    *partDir=dir;

    op[0]=expReg[size];
    op[1]='\0';
    
    /*retira os parenteses caso toda a expressao esteja contida nas mesmas*/
    if(*esq == '(' && *(esq+strlen(esq)-1) == ')')
    {
        esq= esq+1;
        esq[strlen(esq)-1]= '\0';
    }

    /*retira os parenteses caso toda a expressao esteja contida nas mesmas*/
    if(*dir == '(' && dir[strlen(dir)-1] == ')')
    {
        dir= dir+1;
        dir[strlen(dir)-1]= '\0';
    }

    return;
}
/**
 * @brief realiza as operacoes de acordo com a arvore binaria, na ordem pos ordem
 * @param [in] raiz arvore binaria
 */
void transformacao(t_arvore *raiz)
{
    t_arvore *pl= raiz;

    /* parada da recursividade */
    if(!pl)
        return;

    transformacao(pl -> esq);
    /* caso o operador seja unario, o operador apenas opera com o ramo esquerdo (predefinindo a escolha)*/
    if(pl -> tipo_op == 1)
    {
        operacao_geral(&pl->Q, pl->esq->Q, pl->esq->Q, pl->expReg[0]);
        return;
    }
    else
        transformacao(pl->dir);
    
    /*operador binario*/
    if(pl->tipo_op==2)
    {
        operacao_geral(&pl->Q, pl->esq->Q, pl->dir->Q, pl->expReg[0]);
        return;
    }

    /*não operador(ER minima)*/
    mini_quintupla(&pl->Q, pl->expReg);
    return;
}

/**
 * @brief realiza qualquer operacao dada
 * @param [out] res resultado da operacao
 * @param [in] q1 quintupla 1
 * @param [in] q2 quintupla 2
 * @param [in] op operador
 */

void operacao_geral(quintupla_t *res, quintupla_t q1, quintupla_t q2, char op)
{
    switch(op)
    {
        case '.':
            operacao_e(res, q1, q2);
            break;
        case '|':
            operacao_ou(res, q1, q2);
            break;
        case '*':
            operacao_estrela(res, q1);
            break;
        default:
            printf("\n\nErro!!!, operador nao existe %c\n\n", op);
    }
    return;
}

/**
 * @brief realiza a operacao concatenacao
 * @param [out] res resultado da operacao
 * @param [in] q1 quintupla 1
 * @param [in] q2 quintupla 2
 */

void operacao_e(quintupla_t *res, quintupla_t q1, quintupla_t q2)
{
    res->K= q1.K + q2.K;
    res->A= q1.A > q2.A ? q1.A : q2.A; /* a lei maior prevalece, sendo, a < b < c < d ...  */
    res->S= q1.S; /* estado inicial de q1 prevalece */

    res->F= NULL;
    copia_lestado(&res->F, q2.F); /*os estados finais de q2 prevalece*/

    /*ambas as transicoes de q1 e q2 sao mantidas e eh adicionado transicoes*/
    res->D= NULL;
    copia_ltrans(&res->D, q1.D);
    copia_ltrans(&res->D, q2.D);

    /*transicoes adicionadas sao as que vao unir os finais de q1 com o inicial de q2*/
    transicoes_finais(&res->D, q1.F, q2.S);

    return;
}    

/**
 * @brief realiza a operacao ou
 * @param [out] res resultado da operacao
 * @param [in] q1 quintupla 1
 * @param [in] q2 quintupla 2
 */

void operacao_ou(quintupla_t *res, quintupla_t q1, quintupla_t q2)
{
    /*eh adicionado mais dois estados alem dos que ja exitem nas quintuplas q1 e q2*/
    res->K= q1.K + q2.K + 2;
    res->A= q1.A > q2.A ? q1.A : q2.A; /* prevalece o maior alfabeto*/
    res->S= id_estado; /*o estado inicial eh um dos novos estados adicionados*/
    char lei[]= "E";

    res->F= NULL;
    insere_estado(&res->F, id_estado+1); /*o estado final eh um dos novos estados adicionados*/

    res->D= NULL;
    /*As transicoes de q1 e q2 sao mantidas*/
    copia_ltrans(&res->D, q1.D);
    copia_ltrans(&res->D, q2.D);

    /*o novo estado inicial eh conectado aos antigos estados inicial de q1 e q2*/
    insere_transicao(&res->D, res->S, lei, q1.S);
    insere_transicao(&res->D, res->S, lei, q2.S);

    /*O novo estado final eh conectado com os antigos estados finais de q1 e q2*/
    transicoes_finais(&res->D, q1.F, res->F->estado);
    transicoes_finais(&res->D, q2.F, res->F->estado);

    /*atualizando os estados totais*/
    id_estado+= 2;

    return;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints help information and exit
 * @details Prints help information (usually called by opt -h)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160609.110101
 * @date 2016-06-09
 *
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s v.%s - %s\n", "exN", VERSION, "Convert AFD into Exp Reg");
    printf("\nUsage: %s [-h|-v|-c]\n", "exN");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-c,  --copyright, --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
    /* add more options here */
    printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
    printf("\nTodo:\n\tLong options not implemented yet.\n");
    printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "Ruben Carlo Benante", "rcb@beco.cc");
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints version and copyright information and exit
 * @details Prints version and copyright information (usually called by opt -V)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160609.110101
 * @date 2016-06-09
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "exN", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software:  you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
    if(verb>3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written
 * @return Void
 * @todo Need to implement it. Its empty now.
 * @author Ruben Carlo Benante
 * @version 20160609.110101
 * @date 2016-06-09
 *
 */
void exN_init(void)
{
    IFDEBUG("exN_init()");
    /* initialization */
    return;
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20150619.231433      */

