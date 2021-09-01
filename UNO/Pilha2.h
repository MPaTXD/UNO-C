#ifndef PILHA2_H
#define PILHA2_H
#include <stdio.h>
#include <stdlib.h>
#define MAX 19


typedef struct {
	int numero;
	char *cor;
	char *tipo;
} carta;
	
typedef struct {
	int topo;
	carta c[MAX];
} tp_pilha2;


void inicializa_pilha(tp_pilha *p){
	p->topo = -1;
}

int pilha_vazia(tp_pilha *p){
	if(p->topo == -1){
		return 1;
	}else{
		return 0;
	}
}

int pilha_cheia(tp_pilha *p){
	if(p->topo == MAX-1){
		return 1;
	}else{
		return 0;
	}
}

int push(tp_pilha *p, carta c){
	if(pilha_cheia(p)){
		return 0;
	}else{
		p->topo++;
		p->c[p->topo] = c;
		return 1;
	}
}

int pop(tp_pilha *p, carta *c){
	if(pilha_vazia(p)){
		return 0;
	}else{
		*c = p->c[p->topo];
		p->topo--;
		return 1;
	}
}

int altura_pilha(tp_pilha *p){
	return p->topo+1;
}

void imprime_pilha(tp_pilha p){
	carta c;
	printf("\n");
	while(!pilha_vazia(&p)){
		pop(&p,&c);
		printf("COR = [%s] NUMERO = [%d]\n",c.cor,c.numero);
	}
}

#endif
