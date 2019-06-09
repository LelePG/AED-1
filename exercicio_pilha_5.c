#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define bool int
#define true 1
#define false 0
#define MAX 20

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
bool verifica_reverso(stack *s);

int main(){
stack *S = (stack*) malloc(sizeof(stack));
char ch;
while(scanf("%c",&ch) && ch!= '\n'){
    push(S,&ch);
}
if(verifica_reverso(S)){
printf("A palavra pode ser dividida em duas metades, onde a segunda é o reverso da primeira\n");
}
else{
printf("A palavra não pode ser dividida em duas metades, onde a segunda é o reverso da primeira\n");
}
free(S);
return 0;
}

bool verifica_reverso(stack *s){
if(strlen(s->str)%2==1){//não tem numero par de letras já difere
    return false;
}
stack *s_aux;
s_aux = (stack*) malloc (sizeof(stack));
char ch_aux,ch_aux2;
s->devide = strlen(s->str)/2;
while(s_aux->top<s->devide){//copia até a metade em uma segunda pilha
    pop(s,&ch_aux);
    push(s_aux,&ch_aux);
}
while(!empty(s_aux) && !empty(s)){//verifica se a pilha com metade da palavra invertida é igual a segunda metade.
    pop(s,&ch_aux);
    pop(s_aux,&ch_aux2);
        if(ch_aux!=ch_aux2){
        return false;
        }
}
return true;
free(s_aux);
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
    printf("STACK FULL \n");
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
