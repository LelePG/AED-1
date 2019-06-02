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



stack* inverter(stack *s);
void listar(stack *s);
void pop (stack *s, int *n);
bool push(stack *s, int *n);
bool full(stack *s);
bool empty(stack *s);
void reset (stack *s);
int valor_topo(stack *s);


int main(int argc, char const *argv[])
{
	stack *s = (stack*) malloc (sizeof(stack));
	int c;
	for(c=0;c<7;c++){
		push(s,&c);
	}
	
	printf("O valor armazenado no topo da pilha era %d.\n",valor_topo(s));
	printf("Pilha atualizada: \n");
	listar(s);
	printf("\n");
	free(s);
	return 0;
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
	while(!empty(s)){
		pop(s,&aux);
		printf(" %d ", aux);
	}
}

int valor_topo(stack *s){
	int aux;
	pop(s,&aux);
	return aux;

}