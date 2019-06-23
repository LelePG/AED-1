#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	int i;
	struct node *dir,*esq;
}node;

void add (int insere, node**p);
int conta_nodes(node *p);
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
    printf("%d nodes\n",conta_nodes(*p) );
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

int conta_nodes(node *p){
	int i =1;//um acumulador pra guardar todos os meus valores
	if(p->esq!=NULL){//se eu tenho alguma coisa pra esquerda, vou até o final e volto adicionando 1(valor de i)
		i+=conta_nodes(p->esq);
	}
	if(p->dir!=NULL){//se tenho alguma coisa pra direita, vou até o final e volto adicionando i;
		i+=conta_nodes(p->dir);
	}
	return i;
}