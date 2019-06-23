#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	int i;
	struct node *dir,*esq;
}node;

void add (int insere, node**p);
void limpa(node *p);
int maior_valor(node *p);
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
    printf("O maior valor é %d\n",maior_valor(*p) );
    limpa(*p);
    free(p)
	return 0;
}

//essa função funciona pra qualquer arvore
/*int maior_valor(node *p){
	if(p==NULL){
		return -1000000;//um numero estupidamente baixo.
	}
	int m = p->i;//essa verificação tem que acontecer depois de verificar se o ponteiro é NULL, senão dá erro.
	
	if( maior_valor(p->esq) > m){
		m = maior_valor(p->esq);
	}
	if(maior_valor(p->dir) > m){
		m = maior_valor(p->dir);
	}
	return m;
}*/

int maior_valor(node *p){
	int m;//como o maior valor que eu preciso encontrar na arvore binaria é a folha mais a esquerda, só
	//ir andando nessa direçao até terminar a árvore.
	while(p!=NULL){
		m = p->i;
		p = p->dir;
	}
	return m;
}

void add (int insere, node**p){
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
