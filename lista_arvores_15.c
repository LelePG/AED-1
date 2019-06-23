#include <stdlib.h>
#include <stdio.h>
#define bool int
#define true 1
#define false 0

typedef struct node{
	int i;
	struct node *dir,*esq;
}node;

void add (int insere, node**p);
void limpa(node *p);
bool binaria(node *p);
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
    //add(8,p);
    //add(0,p);

    if(binaria(*p)){
    	printf("A árvore é extritamente binária.\n");
    }
    else{
    	printf("A árvore não é extritamente binária.\n");
    }
    
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

bool binaria(node *p){
	if((p->esq==NULL && p->dir!=NULL)||(p->esq!=NULL && p->dir==NULL)){//nesse caso, não posso usar um else nessa estrutura de if, senão ele nunca chega na minha and lá embaixo
		return false;
	}
	else if(p->esq==NULL && p->dir ==NULL){
		return true;
	}
	return(binaria(p->esq) && binaria(p->dir));//retorna uma and entre as duas possibilidades.

}

