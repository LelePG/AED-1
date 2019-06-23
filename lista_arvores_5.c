#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	int i;
	struct node *dir,*esq;
}node;

void add (int insere, node**p);
int conta_altura(node *p);//conta quantos nodos tem da raiz até o primeiro NULL encontrado.
void limpa(node *p);
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
    printf("A árvore tem altura %d.\n",conta_altura(*p) );
    limpa(*p);
    free(p);
	return 0;
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

int conta_altura(node *p){
	int h_dir=1,h_esq =1;
	if(p==NULL||(p->dir==NULL && p->esq ==NULL)){
		return 0;
	}
	h_dir+=conta_altura(p->dir);
	h_esq+=conta_altura(p->esq);
	if(h_dir>h_esq){
		return h_dir;
	}
	return h_esq;
	
}
void limpa(node *p){
	if(p!=NULL){
		limpa(p->esq);
		limpa(p->dir);
		free(p);
	}
}
