#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	int i;
	struct node *dir,*esq;
}node;

void add (int insere, node**p);
int conta_nao_folhas(node *p);
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
    add(8,p);
    add(0,p);
    printf("%d nodes não são folhas\n",conta_nao_folhas(*p) );
	return 0;
}

void add (int insere, node**p){
	if(*p==NULL){
		*p = (node*) malloc(sizeof(node));
		(*p)->i = insere;
		(*p)->dir = NULL;
		(*p)->esq = NULL;
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

int conta_nao_folhas(node *p){
	int i =1;
	if(p==NULL){
		return 0;
	}
	else if(p->dir!=NULL || p->esq!=NULL){
		i+=conta_nao_folhas(p->esq);
		i+=conta_nao_folhas(p->dir);
		return i;
	}
	
}