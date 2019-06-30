#include <stdio.h>
#include <stdlib.h>
#define bool int
#define true 1
#define false 0

typedef struct node{
	int i;
	struct node *dir,*esq;
}node;

void add(int i, node **p);
void imprime_pre_ordem(node **p);
bool binariaBusca(node **p);
void limpa(node **p);
node* novo_nodo(int i);

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
    printf("Árvore: \n");
    imprime_pre_ordem(p);
    printf("\n");
    if(binariaBusca(p)){//O que torna a árvore binária de busca ou não, é a função de inserção.
    //Modificar ela, caso eu queria uma árvore que não seja de busca binária
    	printf("A árvore é uma árvore de busca Binária. \n");
    }
    else{
    	printf("A árvore não é uma árvore de busca Binária. \n");
    }
    limpa(p);
    free(p);
	return 0;
}

node* novo_nodo(int i){
	node *n = (node*) malloc(sizeof(node));
	if(n==NULL){
		printf("ERRO\n");
		exit(1);
	}
	n->dir=NULL;
	n->esq=NULL;
	n->i=i;
	return n;
}
void add( int insere, node **p){
	if(*p==NULL){
		*p = novo_nodo(insere);
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
		printf("%d ", (*p)->i);
		imprime_pre_ordem(&(*p)->esq);
		imprime_pre_ordem(&(*p)->dir);
	}
}
bool binariaBusca(node **p){
	//a condição pra árvore ser binária de busca é que os números menores que o do nodo atual estão pra esquerda
	// e os maiores estão pra direita
	if(*p==NULL || ((*p)->esq==NULL && (*p)->dir==NULL) ){//preciso verificar primeiro se o nodo é null, depois se os nodos direito e esquerdo são NULL
		//quando a folha não tem filhos, entra na segunda condição. A primeira é necessária quando tem um filho.
		return true;
	}
	else if((*p)->esq!=NULL &&(*p)->i < (*p)->esq->i){//se eu tiver algo maior do que o conteúdo do nodo atual na esquerda está errado
		return false;
	}
	else if ((*p)->dir!=NULL && (*p)->i >(*p)->dir->i){//se eu tiver algo menor que o conteúdo do nodo atual na direita está errado
		return false;
	}

	return binariaBusca(&(*p)->esq) & binariaBusca(&(*p)->dir);//retorna uma end entre os resultados da direita e da esquerda

}
void limpa(node **p){
	if(*p!=NULL){
		limpa(&(*p)->dir);
		limpa(&(*p)->esq);
		free(*p);
	}
}
