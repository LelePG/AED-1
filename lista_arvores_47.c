#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	int i;
	struct node *dir,*esq;
}node;

void add(int insere, node **p);
void limpa(node **p);
node* novo_nodo(int insere);
void copia(node **destino, node **source);
void imprime_pre_ordem(node **p);


int main(int argc, char const *argv[])
{
	node **p;
	p=(node**)malloc(sizeof(node*));
	*p = NULL;

    node **p2;
    p2=(node**)malloc(sizeof(node*));
    *p2 = NULL;

	add(4,p);
    add(2,p);
    add(1,p);
    add(3,p);
    add(6,p);
    add(5,p);
    add(7,p);

    copia(p2,p);
    printf("Árvore original: \n");
    imprime_pre_ordem(p);
    printf("\nÁrvore copiada:\n");
    imprime_pre_ordem(p2);   

    limpa(p);
    free(p);
	return 0;
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

void imprime_pre_ordem(node **p){
    if(*p!=NULL){
        printf("%d ",(*p)->i);
        imprime_pre_ordem(&(*p)->esq);
        imprime_pre_ordem(&(*p)->dir);
    }
}

void copia(node **destino, node **source){
    int i;
    if(*source!=NULL){
        i = (*source)->i;
        add(i,destino);

        //copia(destino, &(*source)->esq);
        //copia(destino, &(*source)->dir);

        //Usando apenas destino ele tem que fazer a busca a cada inserção, usando destino->esq, ele torna 
        //isso uma nova root de uma subárvore. Poupa o tempo de busca pra ver onde tem de ser inserido.
        //O novo nodo é inserido imediatamente porque quando eu insiro um novo nodo ele seta direita e esquerda como NULL
        //então acessando destino->esq e destino->dir já entra no if.
        
        copia(&(*destino)->esq, &(*source)->esq);
        copia(&(*destino)->dir, &(*source)->dir);
    }
}
