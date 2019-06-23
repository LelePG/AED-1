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
bool iguais(node *p1,node *p2);

int main(int argc, char const *argv[])
{
	node **p,**p2;
	p=(node**)malloc(sizeof(node*));
	*p = NULL;

	p2=(node**)malloc(sizeof(node*));
	*p2 = NULL;

	add(4,p);
    add(2,p);
    add(1,p);
    add(3,p);
    add(6,p);
    add(5,p);
    add(7,p);
    add(8,p);
    //add(0,p);

    add(4,p2);
    add(2,p2);
    add(1,p2);
    add(3,p2);
    add(6,p2);
    add(5,p2);
    add(7,p2);
    add(8,p2);
   // add(0,p2);

    if(iguais(*p,*p2)){
    	printf("As duas árvores são iguais.\n");
    }
    else{
    	printf("As duas árvores não são iguais\n");
    }
    limpa(*p);
    free(p);
    limpa (*p2);
    free(p2);
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

bool iguais(node *p1, node *p2){//o valor padrão de retorno é um.
	if(p1==NULL && p2==NULL){//se os dois foram iguais retorna true
		return true;
	}
	else if(p1==NULL || p2==NULL){//se entra nesse if, significa que os dois não são null, então retorna false.
		return false;
	}
	if(p1->i!=p2->i){
		return false;
	}
	return (iguais(p1->esq,p2->esq) && iguais(p1->dir,p2->dir));//se em algum momento elas diferirem, uma delas dá false,
	//o que retorna false sempre em cadeia pra todas as recursões;
}