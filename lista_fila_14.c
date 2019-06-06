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
int retorna_primeiro(fila *f1);

int main(int argc, char const *argv[])
{
	fila *f1 = (fila*) malloc (sizeof(fila));
	int content, tamanho1,c;
	tamanho1 = 5;//alterar aqui os tamanhos das filas
	printf("---PREENCHA A FILA 1.---\n");
	for(c =0;c<tamanho1;c++){
		scanf("%d",&content);
		push(f1,&content);
	}
	content = retorna_primeiro(f1);
	printf("--FILA--\n");
	listar(f1);
	printf("\nO elemento que estava armazenado na primeira posição da fila era %d.\n",content );
	free(f1);
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
int retorna_primeiro(fila *f1){
	int ret;
	ret = f1->first->n;
	f1->first= f1->first->next;
	return ret;
}