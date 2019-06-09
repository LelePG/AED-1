#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define bool int
#define true 1
#define false 0
#define MAX 40

typedef struct stack{
char str[MAX];
int bottom;
int top;
int devide;
}stack;

bool empty(stack *s);
bool full (stack *s);
void push (stack *s, char *c);
void pop (stack *s, char *c);
void listar(stack *s);
bool verifica_palindromo(stack *s);

int main(){
stack *S = (stack*) malloc(sizeof(stack));
char aux;
printf("Digite a palavra para verificar se é um palindromo. ");
while(scanf("%c",&aux) && aux != '\n'){
    push(S,&aux);
}
if(verifica_palindromo(S)){
    printf("A palavra é um palíndromo. ");
}
else{
    printf("A palavra não é um palindromo. ");
}
free(S);
return 0;
}

bool verifica_palindromo(stack *s){
stack *s_aux = (stack*) malloc (sizeof(stack));
stack *invertido = (stack*) malloc (sizeof(stack));
char aux,aux2;
while(!empty(s)){
    pop(s,&aux);//preciso liberar essa pilha pra poder ter ela invertida
    push(s_aux,&aux);
    push(invertido,&aux);
}

while(!empty(s_aux)){//preencho s de novo com o conteudo armazenado em s_aux;
    pop(s_aux,&aux);
    push(s,&aux);
}
while(!empty(s) && !empty(invertido)){
    pop(s,&aux);
    pop(invertido,&aux2);
    if(aux!=aux2){
        return false;
    }

}
free(s_aux);
free(invertido);
return true;

}

void listar(stack *s){
char aux;
while(!empty(s)){
    pop(s,&aux);
    printf("%c",aux);
    }
}

void pop (stack *s, char *c){
if(empty(s)){
printf("EMPTY STACK \n");
return;
}
s->top--;
*c = s->str[s->top];


}
void push (stack *s, char *c){
if(full(s)){
    printf("STACK FULL. EXIT REQUIRED \n");
    exit(1);
return;
}
s->str[s->top] = *c;
s->top++;

}

bool empty(stack *s){
return s->top == 0;
}

bool full (stack *s){
return s->top == MAX;
}
