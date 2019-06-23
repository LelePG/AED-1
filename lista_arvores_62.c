#include <stdlib.h>
#include <stdio.h>


typedef struct node{
	int i;
	struct node *dir,*esq;
}node;

void add (int insere, node**p);
void limpa(node *p);
void imprimir_pre_ordem(node *ponteiro);
void altera_nodo (node **p);

int main(int argc, char const *argv[])
{
	node **p;
	p=(node**)malloc(sizeof(node*));
	*p = NULL;

	
	add(4,p);
    add(2,p);
    add(1,p);
    add(3,p);
    add(6,p);
    add(5,p);
    add(7,p);
    
    imprimir_pre_ordem(*p);
    altera_nodo(p);
    printf("\nNodos alterados:\n");
    imprimir_pre_ordem(*p);
    limpa(*p);
    free(p);
    return 0;
}

void add(int insere, node**p){
	if(*p==NULL){
		*p = (node*) malloc(sizeof(node));
		(*p)->i = insere;
		(*p)->dir = NULL;
		(*p)->esq = NULL;
		//printf("Inseri %d\n",insere );
		return;
	}
	else if(insere < (*p)->i){
		add(insere,&(*p)->esq);
		return;
	}
	else if(insere>(*p)->i){
		add(insere,&(*p)->dir);
		return;
	}
	else{
		printf("Número já existe.\n");
	}
}

void limpa(node *p){
	if(p!=NULL){
		limpa(p->esq);
		limpa(p->dir);
		free(p);
	}
}

void altera_nodo (node **p){
	if(*p==NULL){
		return;
	}
	
	altera_nodo(&(*p)->dir);
	altera_nodo(&(*p)->esq);

	if((*p)->dir!=NULL && (*p)->esq!=NULL){
		(*p)->i = (*p)->dir->i +(*p)->esq->i;
	}
	else if((*p)->dir!=NULL){
		(*p)->i = (*p)->dir->i + 0;
	}
	else if((*p)->esq!=NULL){
		(*p)->i = (*p)->esq->i + 0;
	}
	
}
void imprimir_pre_ordem(node *ponteiro){
	if(ponteiro!=NULL){
		printf("%d ",ponteiro->i);
		imprimir_pre_ordem(ponteiro->esq);
		imprimir_pre_ordem(ponteiro->dir);
	}
}