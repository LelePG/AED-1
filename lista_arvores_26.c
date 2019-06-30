#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	int i;
	struct node *dir,*esq;
}node;

void add(int insere, node **p);
void limpa(node **p);
node* novo_nodo(int insere);
int menor_valor(node *p);


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
    //add(0,p);
    printf("O menor valor é %d\n",menor_valor(*p) );
    limpa(p);
    free(p);
	return 0;
}


int menor_valor(node *p){
	int m;//como o maior valor que eu preciso encontrar na arvore binaria é a folha mais a esquerda, só
	//ir andando nessa direçao até terminar a árvore.
	while(p!=NULL){
		m = p->i;
		p = p->esq;
	}
	return m;
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
