#ifndef LISTASE_H
#define LISTASE_H
#include "Pilha.h"
#include <stdio.h>
#include <string.h>
#define ANSI_COLOR_RED      "\033[1;41m" 
#define ANSI_COLOR_GREEN    "\033[1;42m"
#define ANSI_COLOR_BLUE     "\033[1;44m" 
#define ANSI_COLOR_YELLOW   "\033[1;43m"
#define ANSI_COLOR_BLACK    "\033[1;40m"
#define ANSI_COLOR_RESET    "\033[1;45m" 
#include <conio.h>
#include <stdlib.h>

struct lista {
	carta c;
	struct lista* prox;
};
typedef struct lista Lista;


Lista* inicializa (void) {
	return NULL;
}

Lista* insere (Lista* l, carta c) {
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->c = c;
	novo->prox = l;
	return novo;
}

int vazia (Lista* l) {
	if (l == NULL)
		return 1;
	else
		return 0;
}

void libera (Lista* l) {
	Lista* p = l;
	while (p != NULL) {
		Lista* t = p->prox; /* guarda referência para o próximo elemento
*/
		free(p); /* libera a memória apontada por p */
		p = t; /* faz p apontar para o próximo */
	}
}

int uno (Lista* l) {
	Lista* p;
	int quantidade=0;
	for (p = l; p != NULL; p = p->prox){
		quantidade++;
	}
	return quantidade;
}

void imprime (Lista* l) {
	Lista* p; /* variável auxiliar para percorrer a lista */
	for (p = l; p != NULL; p = p->prox)
		if(strcmp(p->c.cor,"Yellow")==0) 
			printf(ANSI_COLOR_YELLOW "COR = [%s] NUMERO = [%d] EFEITO = [%s]\n"ANSI_COLOR_RESET,p->c.cor,p->c.numero,p->c.efeito);
		else
		if(strcmp(p->c.cor,"Blue")==0) 
			printf(ANSI_COLOR_BLUE "COR = [%s] NUMERO = [%d] EFEITO = [%s]\n"ANSI_COLOR_RESET,p->c.cor,p->c.numero,p->c.efeito);
		else
		if(strcmp(p->c.cor,"Red")==0) 
			printf(ANSI_COLOR_RED "COR = [%s] NUMERO = [%d] EFEITO = [%s]\n"ANSI_COLOR_RESET,p->c.cor,p->c.numero,p->c.efeito);
		else
		if(strcmp(p->c.cor,"Green")==0) 
			printf(ANSI_COLOR_GREEN "COR = [%s] NUMERO = [%d] EFEITO = [%s]\n"ANSI_COLOR_RESET,p->c.cor,p->c.numero,p->c.efeito);
		else
		if(strcmp(p->c.cor,"Black")==0) 
			printf(ANSI_COLOR_BLACK "COR = [%s] NUMERO = [%d] EFEITO = [%s]\n"ANSI_COLOR_RESET,p->c.cor,p->c.numero,p->c.efeito);
		
}


int busca (Lista** l, carta c) {
	Lista* p;
	for (p=*l; p!=NULL; p=p->prox)
		if (strcmp(p->c.cor,c.cor)==0)
			return 0;
		else if(p->c.numero == c.numero)
			return 0;
		else if (strcmp(p->c.efeito,c.efeito)==0 && (strcmp(c.efeito,"Normal")!=0))
			return 0;
		else if(strcmp(p->c.cor,"Black")==0)
			return 0; 
	return 1; /* não achou o elemento */
}

int busca2 (Lista** l, carta c) {
	Lista* p;
	for (p=*l; p!=NULL; p=p->prox)
		if (strcmp(p->c.cor,c.cor)==0 && p->c.numero == c.numero)
			return 0;
	return 1; /* não achou o elemento */
}

/* função retira: retira elemento da lista */
int retira (Lista** l, carta *c) {
	Lista* ant = NULL; /* ponteiro para elemento anterior */
	Lista* p = *l; /* ponteiro para percorrer a lista*/
	/* procura elemento na lista, guardando anterior */

	while (p != NULL && strcmp(p->c.cor,c->cor) != 0 || p->c.numero != c->numero) {
		ant = p;
		p = p->prox;
	}
	/* verifica se achou elemento */
	if (p == NULL)
		return 0; /* não achou: retorna lista original */
	/* retira elemento */
	if (ant == NULL) {
		/* retira elemento do inicio */
		*l = p->prox;
	} else {
		/* retira elemento do meio da lista */
		ant->prox = p->prox;
	}
	free(p);
	p = NULL;
	return 1;
}


#endif


