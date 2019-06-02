#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10
#define bool int
#define true 1
#define false 0

typedef struct stack{
	int numeros[MAX];
	int top;
	int bottom;
	int maior;
	int menor;
	int media;
}stack;

bool empty(stack *s);
bool full(stack *s);
bool push(stack*s, int *n);
void pop(stack *s, int *n);
void listar(stack *s);
void encontra_coisas(stack *s);

int main(int argc, char const *argv[])
{
	stack *s;
	s = (stack *) malloc (sizeof(stack));

	for(int c=0;c<10;c++){//só coloca valores na pilha
		push(s,&c);
	}

	printf("--Lista--\n");
	listar(s);
	encontra_coisas(s);//encontrar coisas esvazia a pilha
	printf("\nO maior número é %d\n",s->maior );
	printf("O menor número é %d\n",s->menor );
	printf("A média é %d\n",s->media );
	free(s);
	return 0;
}

void reset(stack *s){
	s->top = 0;
	s->bottom = 0;
	s->maior = 0;
	s->menor = 1000000;
	s->media = 0;
}

bool empty(stack *s){
	return s->top ==0;
}

bool full(stack *s){
	return s->top == MAX;
}

bool push(stack*s, int *n){
	if(!full(s)){
		s->numeros[s->top] = *n;
		s->top++;
		return true;
	}
return false;
}

void pop(stack *s, int *n){
	if(empty(s)){
		printf("empty stack\n");
		return;
	}
	s->top--;
	*n = s->numeros[s->top];
}

void listar(stack *s){
	int aux;
	stack *s_aux = (stack*) malloc(sizeof(stack));
	while(!empty(s)){
		pop(s,&aux);
		printf(" %d ",aux );
		push(s_aux,&aux);

	}
	while(!empty(s_aux)){
		pop(s_aux,&aux);
		push(s,&aux);

	}
	free(s_aux);
}

void encontra_coisas(stack *s){
	int aux,topo;
	topo = s->top-1;
	while(!empty(s)){
		pop(s,&aux);
		if(aux>s->maior){
			s->maior = aux;
		}
		else if(aux<s->menor){
			s->menor = aux;
		}
		s->media+=aux;
	}
	s->media/=topo;

}