#include <stdlib.h>
#include<stdio.h>

#define MAX 10
#define bool int
#define true 1
#define false 0

typedef struct stack{
	int numeros[MAX];
	int top;
	int bottom;
	int devide;

}stack;

void listar(stack *s);
void pop (stack *s, int *n);
bool push(stack *s, int *n);
bool full(stack *s);
bool empty(stack *s);
void reset (stack *s);
void fib_preenche(stack *s, int *c);
int main(int argc, char const *argv[])
{
	stack *p1 = (stack*) malloc (sizeof(stack));
	int c;
	printf("Quantos numeros da sequencia de Fibonaci quer armazenar? ");
	scanf("%d",&c);
	fib_preenche(p1,&c);
	listar(p1);
	free(p1);
	return 0;
}

void fib_preenche(stack *s, int *c){
int guarda1,guarda2,aux;
while(*c>0){
    if(s->top == 1 || s->top == 0 ){
        aux = 1;
        push(s,&aux);
        (*c)--;
        continue;
    }
    pop(s,&guarda1);
    pop(s,&guarda2);
    aux = guarda1+guarda2;
    push(s,&guarda2);
    push(s,&guarda1);
    push(s,&aux);
    (*c)--;

    }

}

void reset (stack *s){
	s->top =0;
	s->bottom =0;
	s->devide =0;
}
bool empty(stack *s){
	return s->top==0;
}
bool full(stack *s){
	return s->top==MAX;
}
bool push(stack *s, int *n){
	if(!full(s)){
		s->numeros[s->top] = *n;
		s->top++;
		return true;
	}
	printf("--STACK FULL. ABORTING.--\n");
	return false;

}
void pop (stack *s, int *n){
	if(!empty(s)){
		s->top--;
		*n = s->numeros[s->top];
	}
}
void listar(stack *s){
	int aux;
	stack *s_aux = (stack*) malloc (sizeof (stack));
	while(!empty(s)){
		pop(s,&aux);
		printf(" %d \n", aux);
		push(s_aux,&aux);
	}
	while(!empty(s_aux)){//coloca de volta em s tudo que eu preciso manter guardado.
		pop(s_aux,&aux);
		push(s,&aux);
	}
	free(s_aux);
}
