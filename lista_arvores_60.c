#include <stdio.h>
#include<stdlib.h>

typedef struct node{
	int i;
	struct node *dir,*esq;
}node;

void add(int insere, node **p);
void imprime_pre_ordem(node **p);
void limpa(node **p);
node* novo_nodo(int insere);
int qtd_divisores_soma(node **p);

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

    printf("Árvore: \n");
    imprime_pre_ordem(p);
    printf("\n%d nodos são divisores da soma de seus filhos.\n",qtd_divisores_soma(p));

    limpa(p);
    free(p);
    return 0;
}

void add(int insere, node **p){
	if(*p==NULL){
		*p=novo_nodo(insere);
		return;
	}
	else if(insere < (*p)->i){
		add(insere,&(*p)->esq);
	}
	else if(insere > (*p)->i){
		add(insere,&(*p)->dir);
	}
}
void imprime_pre_ordem(node **p){
	if(*p!=NULL){
		printf("%d ",(*p)->i);
		imprime_pre_ordem(&(*p)->esq);
		imprime_pre_ordem(&(*p)->dir);
	}
}
void limpa(node **p){
	if(*p!=NULL){
		limpa(&(*p)->esq);
		limpa(&(*p)->dir);
		free(*p);
	}
}
node* novo_nodo(int insere){
	node *n = (node*) malloc(sizeof(node));
	if(n==NULL){
		printf("ERRO\n");
		exit(1);
	}
	n->esq=NULL;
	n->dir=NULL;
	n->i = insere;
	return n;
}

int qtd_divisores_soma(node **p){
	int i=0;
	if(*p==NULL){
		return 0;
	}
	else if(((*p)->esq->i + (*p)->dir->i)%(*p)->i==0){
		printf("\n%d é divisor de %d + %d.",(*p)->i, (*p)->esq->i,(*p)->dir->i );
		return 1;
	}
	i = qtd_divisores_soma(&(*p)->esq) + qtd_divisores_soma(&(*p)->dir);
	return i;
}