#include <stdlib.h>
#include <stdio.h>


typedef struct l_node{
	int i;
	struct l_node *prev,*next;
}l_node;

typedef struct node{
	int i;
	struct node *dir,*esq;
}node;
//não consegui fazer retornar, então simplesmente printei a lista usando lista encadeada
void add (int insere, node**p);
void limpa(node *p);
void pop(l_node *head);
l_node* cria_l_node(void);
void push(int inserir, l_node *head);
void imiprimir_lista(l_node *head);
void caminhos(node *p,l_node *head);
int ways =0;
int main(int argc, char const *argv[])
{
	node **p;
	p=(node**)malloc(sizeof(node*));
	*p = NULL;
	l_node *head = cria_l_node();
	add(4,p);
    add(2,p);
    add(1,p);
    add(3,p);
    add(6,p);
    add(5,p);
   // add(8,p);
   // add(9,p);
    add(7,p);

    caminhos(*p,head);
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



void caminhos(node *p,l_node *head){
	if(p==NULL){
		return;
	}
	push(p->i,head);
	if(p->dir==NULL && p->esq==NULL){
        printf("Caminho %d \n", ++ways);
        imiprimir_lista(head);
        pop(head);
        return;
	}
	caminhos(p->esq,head);
	caminhos(p->dir,head);
}

void imiprimir_lista(l_node *head){
	l_node *count;
	for(count =head->next;count!=NULL;count = count->next){
		printf("-> %d ",count->i);
	}
	printf("\n\n");
}

void push(int inserir, l_node *head){
	l_node *novo,*count;
	novo = cria_l_node();
	novo->i = inserir;
	novo->next = NULL;

	for(count =head;count->next!=NULL;count = count->next);//leva o count até o último elemento

	count->next = novo;
	novo->prev = count;

}

l_node* cria_l_node(void){
	l_node *aux = (l_node*) malloc(sizeof(l_node));
	if(aux==NULL){
		printf("Erro\n");
		exit (1);
	}
	return aux;
}

void pop(l_node *head){
	l_node *count;
	for(count =head;count->next!=NULL;count = count->next);
	count->prev->next = NULL;
	free(count);
}
