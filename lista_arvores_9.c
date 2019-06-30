#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	int i;
	struct node *dir,*esq;
}node;

void add (int insere, node**p);
void previous(node *q , node **r);
void deleta(node **p);
void deleta_pares(node **p);
void imprime_pre_ordem(node *p);

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
    //add(9,p);
    imprime_pre_ordem(*p);
    printf("Excluindo números pares...\n");
    deleta_pares(p);
    imprime_pre_ordem(*p);
    limpa(*p);
    free(p);
	return 0;
}

void imprime_pre_ordem(node *p){
	if(p!=NULL){
		printf("%d ",p->i);
		imprime_pre_ordem(p->esq);
		imprime_pre_ordem(p->dir);
	}
}
void deleta_pares(node **p){
//se eu coloco um nodo folha no deleta pares, ele retorna como NULL, por issoa  verfiicação de NULL tem que ser feita
//depois da função deleta. Dá falha de segmentação caso eu entre com NULL na função deleta_pares ali embaixo.
    if(*p!=NULL && ((*p)->i%2)==0){
		printf("deletar %d\n",(*p)->i );
		deleta(p);//só preciso deletar esse nodo, não me importa o conteúdo relacionado pra saber que tenho que deletar.
	}

	if(*p==NULL){
		return;
	}

	deleta_pares(&(*p)->esq);
	deleta_pares(&(*p)->dir);

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

void deleta(node **p){
	node *aux = NULL;
	if( ((*p)->esq==NULL && (*p)->dir == NULL)){//isso aqui deleta folhas, mas sempre dá falha de segmentação.
       *p =NULL;
		return;
	}

	if((*p)->dir == NULL){
		aux = *p;
		*p=(*p)->esq;
		free(aux);
		return;
	}

	if((*p)->esq==NULL){
		aux = *p;
		*p = (*p)->dir;
		free(aux);
		return;
	}
	else if((*p)->esq!=NULL){
		previous(*p,&(*p)->esq);
	}

}

void previous(node *q , node **r){//essa eu não entendi como funciona.
	node *aux;
	if((*r)->dir!=NULL){
		previous(q,&(*r)->dir);
		return;
	}
	q->i = (*r)->i;
	aux = *r;
	*r = (*r)->esq;
	free(aux);
}

