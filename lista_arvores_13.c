#include <stdio.h>
#include<stdlib.h>
#define bool int
#define true 1
#define false 0

typedef struct node{
    int i;
    struct node *dir,*esq;
}node;

void add(int insere, node **p);
void imprime_pre_ordem(node **p);
bool similares(node **p1, node **p2);
void limpa(node **p);
node* novo_nodo(int insere);

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
    add(8,p);
    add(0,p);

   // add(4,p2);
    add(2,p2);
    add(1,p2);
    add(3,p2);
    add(6,p2);
    add(5,p2);
    add(7,p2);
    add(8,p2);
    add(0,p2);

    printf("Árvore1: \n");
    imprime_pre_ordem(p);
    printf("\nÁrvore2: \n" );
    imprime_pre_ordem(p2);
    if(similares(p,p2)){
        printf("\nAs duas árvores são similares.\n");
    }
    else{
        printf("\nAs duas árvores não são similares.\n");
    }

    limpa(p);
    limpa(p2);
    free(p);
    free(p2);
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
void imprime_pre_ordem(node **p){
    if(*p!=NULL){
        printf("%d ",(*p)->i);
        imprime_pre_ordem(&(*p)->esq);
        imprime_pre_ordem(&(*p)->dir);
    }
}
bool similares(node **p1, node **p2){
//Elas vão ser diferentes quando uma delas tiver um nodo no lado que a outra não tem (dois primeiros if)
//Se as duas forem iguais a NULL, não tem porque continuar procurando naquele caminho, então retorna true;
//Se os dois nodos tem dois filhos, retorna uma end entre a função similares chamadas pros dois filhos.
    if(*p1==NULL && *p2!=NULL){
        return false;
    }
    else if(*p1!=NULL && *p2==NULL){
        return false;
    }
    else if(*p1==NULL && *p2==NULL){
        return true;
    }
    return similares(&(*p1)->dir,&(*p2)->dir) & similares(&(*p1)->esq,&(*p2)->esq);
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
