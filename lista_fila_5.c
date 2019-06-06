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
	int maior,menor;
	float media;
} fila;


void listar(fila *f);
void pop(fila *f, int *c);
bool push(fila *f, int *c);
bool full(fila *f);
bool empty(fila *f);
void reset(fila *f);
void acha_coisas(fila *f);

int main(int argc, char const *argv[])
{
	fila *f = (fila*) malloc (sizeof(fila));
	char again = 'y';
	int content;
	printf("---PREENCHA A FILA. DIGITE N PARA SAIR---\n");
	while(again!='n' && again!='N'){
        printf("Número: ");
        scanf("%d",&content);
        getchar();
        push(f,&content);
        printf("Continuar? y/n\n");
        scanf("%c",&again);
    }
    printf("--FILA INSERIDA--\n");
    listar(f);
    acha_coisas(f);
    printf("\n--O MAIOR ELEMENTO É %d, O MENOR ELEMENTO É %d E A MÉDIA ARITMÉTICA É %.2f--\n",f->maior,f->menor,f->media);
	free(f);
	return 0;
}

void reset(fila *f){
	f->first = NULL;
    f->last = NULL;
    f->maior =0;
    f->menor = 100000000;
    f->media = 0;
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

void acha_coisas(fila *f){//Não usei a estrutura de fila aqui....
	int conteudo;
	int div = 1;
	while(!empty(f)){
		pop(f,&conteudo);
		if(conteudo > f->maior){
			f->maior = conteudo;
		}
		if(conteudo < f->menor){
			f->menor = conteudo;
		}
		f->media+=conteudo;
		div++;
	}
	f->media/=div;

}
