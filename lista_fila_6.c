#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define bool int
#define true 1
#define false 0


typedef struct nodo{
    int n;
    struct nodo *next;
}nodo;

typedef struct fila{
	nodo *first;
	nodo *last;
} fila;


void listar(fila *f);
void pop(fila *f, int *c);
bool push(fila *f, int *c);
bool full(fila *f);
bool empty(fila *f);
void reset(fila *f);
void tamanho_igual(fila *f1, fila*f2);

int main(int argc, char const *argv[])
{
	fila *f1 = (fila*) malloc (sizeof(fila));
	fila *f2 = (fila*) malloc (sizeof(fila));
	int content, tamanho1, tamanho2,c;
	tamanho1 = 5;//alterar aqui os tamanhos das filas
	tamanho2 = 5;
	printf("---PREENCHA A FILA 1.---\n");
	for(c =0;c<tamanho1;c++){
		scanf("%d",&content);
		push(f1,&content);
	}
	printf("---PREENCHA A FILA 2.---\n");
	for(c=0;c<tamanho2;c++){
		scanf("%d",&content);
		push(f2,&content);
	}
	tamanho_igual(f1,f2);
	free(f1);
	free(f2);
	return 0;
}

void reset(fila *f){
	f->first = NULL;
    f->last = NULL;
}

bool empty(fila *f){
	return f->first==NULL;
}

bool full(fila *f){
	return false;
}

bool push(fila *f,int *c){
	nodo *novo = (nodo*) malloc (sizeof(nodo));
	if(novo==NULL){
        printf("Erro de alocação.");
        return false;
	}
	novo->n = *c;
	novo->next = NULL;

	if(f->last != NULL){
		f->last->next=novo;
	}
	else{
		f->first = novo;
	}
	f->last = novo;
	return true;
}

void pop(fila *f, int *c){
	nodo *nodo_aux;
	if(f->first == NULL){
		printf("--EMPTY STACK. CANNOT DELETE--\n");
		return;
	}
	else{
		nodo_aux = f->first;
		*c = f->first->n;//recebe o conteudo do primeiro item da fila
		f->first = f->first->next;
	}
	if(f->first == NULL){
		f->last = NULL;
	}
	free(nodo_aux);
}

void listar(fila *f){
	nodo *count;
	if(f->first == NULL){
	   printf("FILA VAZIA");
	   return;
	  }
	for(count = f->first;count!=NULL;count= count ->next){
		printf(" %d ",count->n);
	}
	free(count);
}
void tamanho_igual(fila *f1, fila*f2){
	int aux;
	while(!empty(f1) && !empty(f2)){
		pop(f1,&aux);
		pop(f2,&aux);
	}
	if(empty(f1) && !empty(f2)){
		printf("A segunda fila tem mais elementos que a segunda.\n");
	}
	else if(!empty(f1) && empty(f2)){
		printf("A primeira fila tem mais elementos que a segunda.\n");
	}
	else{
		printf("As duas filas tem o mesmo número de elementos.\n");
	}
}	