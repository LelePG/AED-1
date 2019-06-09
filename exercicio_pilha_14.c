#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define bool int
#define true 1
#define false 0
#define MAX 10

typedef struct stack{
int vetor[MAX];
int bottom;
int top;
int devide;
}stack;

bool empty(stack *s);
bool full (stack *s);
bool push (stack *s, int *c);
void pop (stack *s, int *c);
void listar(stack *s);
void copia(stack *s1,stack *s2);



int main(){
stack *S = (stack*) malloc(sizeof(stack));
stack *S2 = (stack*) malloc(sizeof(stack));
int aux;
for(int c=0;c<3;c++){
    scanf("%d",&aux);
    push(S,&aux);
}
copia(S2,S);
printf("--ORIGINAL STACK--\n");
listar(S);
printf("--COPIED STACK--\n");
listar(S2);
free(S);
free(S2);
return 0;
}

void copia(stack *s1,stack *s2){
int aux;
stack *s_aux = (stack*) malloc(sizeof(stack));
while(!empty(s2)){//quero que s1 e s2 estejam na mesma ordem, e não uma seja inverso da outra.
    pop(s2,&aux);
    push(s_aux,&aux);
}
while(!empty(s_aux)){
    pop(s_aux,&aux);
    push(s1,&aux);
    push(s2,&aux);//desse jeito mantém as duas iguais;
}


}
void listar(stack *s){
int aux;
while(!empty(s)){
    pop(s,&aux);
    printf(" %d ",aux);
    }
    printf("\n");
}

void pop (stack *s, int *c){
if(empty(s)){
printf("EMPTY STACK \n");
return;
}
s->top--;
*c = s->vetor[s->top];


}
bool push (stack *s, int *c){
if(full(s)){
    printf("STACK FULL. EXIT REQUIRED \n");
    exit(1);
return false;
}
s->vetor[s->top] = *c;
s->top++;
return true;
}

bool empty(stack *s){
return s->top == 0;
}

bool full (stack *s){
return s->top == MAX;
}
