#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define bool int
#define true 1
#define false 0
#define MAX 10


typedef struct conteudo{
    int n;
}conteudo;

typedef struct nodo{
    conteudo c;
    struct nodo *next;
}nodo;
typedef struct fila{
	nodo *first;
	nodo *last;
} fila;

typedef struct stack{
int vetor[MAX];
int bottom;
int top;
int devide;
}stack;

bool P_empty(stack *s);
bool P_full (stack *s);
bool P_push (stack *s, int *c);
void P_pop (stack *s, int *c);
void P_listar(stack *s);

void F_listar(fila *f);
void F_pop(fila *f, conteudo *c);
bool F_push(fila *f, conteudo *c);
bool F_full(fila *f);
bool F_empty(fila *f);
void F_reset(fila *f);



int main(){
stack *S = (stack*) malloc(sizeof(stack));
fila *F = (fila*) malloc(sizeof(fila));
conteudo x;
for(int c=0;c<5;c++){//quero adicionar 5 elementos na fila
scanf("%d",&x.n);
F_push(F,&x);
}
printf("--FILA NORMAL--\n");
F_listar(F);
while(!F_empty(F)){
F_pop(F,&x);
P_push(S,&x.n);
}
printf("\n--FILA INVERTIDA--\n");
P_listar(S);
return 0;
}

void P_listar(stack *s){
int aux;
while(!P_empty(s)){
    P_pop(s,&aux);
    printf(" %d",aux);
    }
    printf("\n");
}
void P_pop (stack *s, int *c){
if(P_empty(s)){
printf("EMPTY STACK \n");
return;
}
s->top--;
*c = s->vetor[s->top];


}
bool P_push (stack *s, int *c){
if(P_full(s)){
    printf("STACK FULL. EXIT REQUIRED \n");
    exit(1);
return false;
}
s->vetor[s->top] = *c;
s->top++;
return true;
}
bool P_empty(stack *s){
return s->top == 0;
}
bool P_full (stack *s){
return s->top == MAX;
}

void F_reset(fila *f){
	f->first = NULL;
    f->last = NULL;
}
bool F_empty(fila *f){
	return f->first==NULL;
}
bool F_full(fila *f){
	return false;
}
bool F_push(fila *f,conteudo *c){
	nodo *novo = (nodo*) malloc (sizeof(nodo));
	if(novo==NULL){
        printf("Erro de alocação.");
        return false;
	}
	novo->c = *c;
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
void F_pop(fila *f, conteudo *c){
	nodo *nodo_aux;
	if(f->first == NULL){
		printf("--EMPTY STACK. CANNOT DELETE--\n");
		return;
	}
	else{
		nodo_aux = f->first;
		*c = f->first->c;//recebe o conteudo do primeiro item da fila
		f->first = f->first->next;
	}
	if(f->first == NULL){
		F_reset(f);
	}
	free(nodo_aux);
}

void F_listar(fila *f){
	nodo *count;
	for(count = f->first;count!=NULL;count= count ->next){
		printf(" %d",count->c.n );
	}
	free(count);
}
