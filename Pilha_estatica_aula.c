#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define MAX 50

#define bool int
#define true 1
#define false 0

//PILHA ESTÁTICA
typedef struct Pessoa{
	char nome[20];
	int idade;
}Pessoa;

typedef struct stack{
	Pessoa pessoas[MAX];
	int top;
	int bottom;
}stack;

int menu(void);
void pop(stack *s,Pessoa *p);
void pop_name(stack *s, char* str);
bool push(stack *s, Pessoa *p);
bool full(stack *s);
bool empty(stack *s);
void reset(stack *s);
void listar(stack *s);
int main(){
	int choice;
	char nome[20];
	stack *S;
	Pessoa aux;
	S = (stack *) malloc (sizeof(stack));
	while(1){
		choice = menu();
		switch (choice){
			case 0:
                if(full(S)){
                printf("**STACK FULL. CANNOT ADD.**\n");
                break;
                }
                printf("--ADDING PERSON--\n");
                printf("Name: ");
                scanf("%s",aux.nome);
                printf("Age: ");
                scanf("%d",&aux.idade);
				push(S,&aux);
				break;
			case 1:
                pop(S,&aux);
				break;
			case 2:
				printf("Qual nome deseja remover? \n");
				scanf("%s", nome);
                pop_name(S,nome);
				break;
			case 3:
                while(!empty(S)){
                    pop(S,&aux);
                }
                reset(S);
                printf("**STACK CLEAN**\n");
				break;
			case 4:
                if(empty(S)){
                printf("**EMPTY STACK. CANNOT LIST.**\n");
                break;
                }
				listar(S);
				break;
			case 5:
                free(S);
				exit(1);
			default:
				printf("Opção inválida\n");


		}

	}
}

int menu(void){
	int e;
	printf("------AGENDA PILHA-------\n");
	printf("0 - INSERE PESSOA\n");
	printf("1 - DELETA A PESSOA DO TOPO DA PILHA\n");
	printf("2 - DELETA A PESSOA POR NOME\n");
	printf("3 - LIMPA A PILHA\n");
	printf("4 - LISTA NA TELA TODAS AS PESSOAS\n");
	printf("5 - SAIR DO PROGRAMA\n");
	scanf("%d",&e);
	return e;
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

bool push(stack *s, Pessoa *p){
    if(!full(s)){
        s->pessoas[s->top] = *p;
        s->top++;
        return true;
    }
    else{
        return false;
    }

}

void pop(stack *s,Pessoa *p){
if(empty(s)){
    printf("**EMPTY STACK**\n");
    return;
}
s->top--;
*p = s->pessoas[s->top];

}

void listar(stack *s){
 stack *s_aux;
 s_aux = (stack*) malloc(sizeof(stack));
Pessoa aux;
    while(!empty(s)){
    pop(s,&aux);
    push(s_aux,&aux);//copia os elementos pra stack auxiliar assim eu não perco eles
    printf("------------\n");
    printf("Name: %s\nAge: %d\n",aux.nome,aux.idade);
    printf("------------\n");
    }
    while(!empty(s_aux)){//copia as coisas de volta pra stack original
    pop(s_aux,&aux);
    push(s,&aux);
    }
}

void pop_name(stack *s, char* str){
	if(!empty(s)){
		stack *aux;
		Pessoa p;
		aux = (stack*) malloc (sizeof(stack));
		while(!empty(s)){
			pop(s,&p);
			if(strcmp(p.nome,str)==0){//achei a igual
				while(!empty(aux)){//simplesmente sobreescrevi ela e passei tudo que eu tava tirando de volta pro lugar
					pop(aux,&p);
					push(s,&p);
				}
				return;
			}
			push(aux,&p);
		}

		printf("--ERROR NAME DOES NOT EXIST--\n");
		while(!empty(aux)){
			pop(aux,&p);
			push(s,&p);
		}
		free (aux);
		

	}
}
