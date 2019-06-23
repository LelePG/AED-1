#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	int i;
	struct node *dir,*esq;
}node;

void add (int insere, node**p);
int conta_folhas(node *p);
int main(int argc, char const *argv[])
{
	node **p;
	p=(node**)malloc(sizeof(node*));
	*p = NULL;
	//O problema é inserir uma árvore binária...
	add(4,p);
    add(2,p);
    add(1,p);
    add(3,p);
    add(6,p);
    add(5,p);
    add(7,p);
    
    printf("%d nodes são folhas\n",conta_folhas(*p) );
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

int conta_folhas(node *p){
	int i =0;
	if(p==NULL){
		return 0;
	}
	if(p->dir == NULL && p->esq == NULL){
		return 1;
	}
	i+=conta_folhas(p->dir);
	i+=conta_folhas(p->esq);
	return i;
	
}