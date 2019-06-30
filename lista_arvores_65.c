#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	int i;
	struct node *dir,*esq;
}node;

void add(int insere, node **p);
void limpa(node **p);
node* novo_nodo(int insere);
int soma_niveis_impares(node **p,int nivel);
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

    add(0,p);
    add(8,p);

    printf("A soma dos elementos nos níveis impares da árvore é %d\n",soma_niveis_impares(p,0));
    limpa(p);
    free(p);
	return 0;
}

int soma_niveis_impares(node **p,int nivel){
	int retornar=0;
	if(*p==NULL){//o teste de p==NULL tem sempre que ser o primeiro.
		return 0;
	}
	if(nivel%2==1){//se o número é primo, incremento a quantidade de primos
		printf("%d está em nivel impar\n",(*p)->i );
		retornar+= (*p)->i;
	}

	retornar+=soma_niveis_impares(&(*p)->esq,nivel+1);//e adiciono a quantidade de primos à direita e á esquerda
	retornar+=soma_niveis_impares(&(*p)->dir,nivel+1);

	return retornar;
}


void add(int insere, node **p){
    if(*p==NULL){
        *p = novo_nodo(insere);
    }
    else if(insere<(*p)->i){
        add(insere,&(*p)->esq);
    }
    else if(insere>(*p)->i){
        add(insere,&(*p)->dir);
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
﻿
