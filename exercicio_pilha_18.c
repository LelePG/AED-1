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

void esvazia(fila *fila_impar,fila *fila_par,stack *s);

int main(){
stack *s = (stack*) malloc(sizeof(stack));
fila *fila_impar = (fila*) malloc(sizeof(fila));
fila *fila_par = (fila*) malloc(sizeof(fila));
conteudo x;
while(scanf("%d",&x.n) && x.n!=0){
    if(x.n%2==0){
    F_push(fila_par,&x);
    }
    else{
    F_push(fila_impar,&x);
    }

};

printf("--FILA PAR--\n");
F_listar(fila_impar);
printf("\n--FILA IMPAR--\n");
F_listar(fila_par);

esvazia(fila_impar,fila_par, s);

printf("\n--PILHA--\n");
P_listar(s);

free(fila_impar);
free(fila_par);
free(s);
return 0;
}
void esvazia(fila *fila_impar,fila *fila_par,stack *s){
conteudo aux_i,aux_p;
int aux;
while(!F_empty(fila_impar) && !F_empty(fila_par)){
    F_pop(fila_impar,&aux_i);
    if(aux_i.n>0){//se for positivo insere, se não remove da pilha, para ambos os casos, começando pela impar
        P_push(s,&aux_i.n);
    }
    else{
        P_pop(s,&aux);
    }
    F_pop(fila_par,&aux_p);// se for positivo insere, se não, remove da pilha, para ambos os casos
    if(aux_p.n>0){
        P_push(s,&aux_p.n);
    }
    else{
        P_pop(s,&aux);
    }

}

while(!F_empty(fila_impar)){//se ficar mais coisa na pilha impar
 F_pop(fila_impar,&aux_i);
    if(aux_i.n>0){
        P_push(s,&aux_i.n);
    }
    else{
        P_pop(s,&aux);
    }
}
while(!F_empty(fila_par)){//se ficar mais coisa na pilha impar
 F_pop(fila_par,&aux_p);
    if(aux_p.n>0){
        P_push(s,&aux_p.n);
    }
    else{
        P_pop(s,&aux);
    }
}

}


void P_listar(stack *s){
int aux;
while(!P_empty(s)){
    P_pop(s,&aux);
    printf(" %d\n",aux);
    }
    printf("\n");
}
void P_pop (stack *s, int *c){
if(P_empty(s)){
printf("\nEMPTY STACK \n");
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
