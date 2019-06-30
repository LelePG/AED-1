#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	int i;
	struct node *dir,*esq;
}node;

void add(int insere, node **p);
void limpa(node **p);
node* novo_nodo(int insere);
int qtd_primos(node **p);

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
    add(9,p);
    add(13,p);

    printf("%d nós da árvore tem um número primo.\n",qtd_primos(p));
    limpa(p);
    free(p);
	return 0;
}

int qtd_primos(node **p){
	int retornar=0;
	int c,divisores =0;
	if(*p==NULL){//o teste de p==NULL tem sempre que ser o primeiro.
		return 0;
	}

	for(c=1;c<=(*p)->i;c++){//conta os divisores do número
		if((*p)->i%c==0){
			divisores++;
		}
	}
	if(divisores==2 || (*p)->i==1 || (*p)->i==0){//se o número é primo, incremento a quantidade de primos
		//printf("%d é primo\n",(*p)->i );
		retornar+= 1;
	}

	retornar+=qtd_primos(&(*p)->esq);//e adiciono a quantidade de primos à direita e á esquerda
	retornar+=qtd_primos(&(*p)->dir);
	return retornar;//retorno
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
