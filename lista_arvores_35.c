#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	int i;
	struct node *dir,*esq;
}node;

void add (int insere, node**p);
void limpa(node *p);
int n_folhas(node*p);
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

    add(10,p);
    add(9,p);
    add(11,p);
    //add(0,p);
    printf("A árvore tem %d folhas.\n",n_folhas(*p));
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
		printf("Inseri %d\n",insere );
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

int n_folhas(node*p){
	int i=0;
	if(p==NULL){//o teste de p==NULL tem sempre que ser o primeiro.
		return 0;
	}
	else if(p->dir==NULL && p->esq==NULL){
		return 1;
	}
	i+=n_folhas(p->esq);
	i+=n_folhas(p->dir);
	return i;
}

