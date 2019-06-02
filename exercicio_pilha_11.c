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
stack* inverter(stack *s);

int main(int argc, char const *argv[])
{
	stack *s = (stack*) malloc (sizeof(stack));
	stack *s2;
	int c;
	for(c=0;c<7;c++){
		push(s,&c);
	}
	printf("--PILHA NORMAL--\n");
	listar(s);
	s2 = inverter(s);
	printf("\n--PILHA INVERTIDA--\n");
	listar(s2);

	free(s);
	free(s2);
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
	stack *s_aux = (stack*) malloc (sizeof (stack));
	while(!empty(s)){
		pop(s,&aux);
		printf(" %d ", aux);
		push(s_aux,&aux);
	}
	while(!empty(s_aux)){//coloca de volta em s tudo que eu preciso manter guardado.
		pop(s_aux,&aux);
		push(s,&aux);
	}
	//free(s_aux);
}

stack* inverter(stack *s){
	stack *s2 = (stack*) malloc (sizeof(stack));
	int aux;
	while(!empty(s)){
		pop(s,&aux);
		push(s2,&aux);
	}

	return s2;
}