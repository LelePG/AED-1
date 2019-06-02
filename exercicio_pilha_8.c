#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 20

#define bool int
#define true 1
#define false 0

typedef struct stack{
	char frase[MAX];
	char top;
	char bottom;
} stack;


void listar(stack *s);
void pop(stack *s, char *c);
bool push(stack *s,char *c);
bool full(stack *s);
bool empty(stack *s);
void reset(stack *s);

int main(int argc, char const *argv[])
{
	stack *s = (stack*) malloc (sizeof(stack));
	char ch;
	printf("Digite a entrada: \n");
	while(scanf("%c",&ch) && ch!='\n'){
		if(ch == '('){
            push(s,&ch);
        }
        else if(ch == ')'){
            pop(s,&ch);
            if(s->top==0 && ch == ')'){
            printf("A parentização está incorreta. Não posso ter um ')' sem antes ter um '('.");
            free(s);
            return 0;
            }
        }

	}
	//o while não verifica se eu tiver mais ( do que )
	if(s->top==0){
	printf("A parentização está correta.");
	}
	else{
	printf("A parentização está incorreta. Tem mais '(' do que ')'");
	}

	//listar(s);
	free(s);
	return 0;
}

void reset(stack *s){
	s->top = 0;
	s->bottom = 0;
}

bool empty(stack *s){
	return s->top==0;
}

bool full(stack *s){
	return s->top==MAX;
}

bool push(stack *s,char *c){
	if(!full(s)){
		s->frase[s->top] = *c;
		s->top++;
		return true;
	}
	return false;
}

void pop(stack *s, char *c){
	if(empty(s)){
		//printf("--EMPTY STACK. CANNOT DELETE--\n");
		return;
	}
	s->top--;
	*c = s->frase[s->top];
}

void listar(stack *s){
	stack *s_aux = (stack*) malloc(sizeof(stack));
	char aux;
	while(!empty(s)){//esvazia a pilha pra mostrar
		pop(s,&aux);
		push(s_aux,&aux);
		printf(" %c ",aux);
	}

	while(!empty(s_aux)){//enche a pilha de novo
		pop(s_aux,&aux);
		push(s,&aux);
	}

	free(s_aux);
}
