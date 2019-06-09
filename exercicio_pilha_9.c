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
void ordena(stack *s);

int main(){
stack *S = (stack*) malloc(sizeof(stack));
int aux,c;
for(c=0;c<5;c++){
    scanf("%d",&aux);
    push(S,&aux);

}
ordena(S);
printf("----ORDENADA----\n");
listar(S);
free(S);
return 0;
}

void ordena(stack *s){
stack *temp = (stack*) malloc (sizeof(stack));
int aux_s,aux_temp;

while(!empty(s)){
    pop(s,&aux_s);
    pop(temp,&aux_temp);
    if(aux_s >= aux_temp){
        if(aux_temp!=0){
        push(temp,&aux_temp);
        }
        push(temp,&aux_s);
    }
    else{
        while(aux_s < aux_temp && !empty(temp)){
            push(s,&aux_temp);
            pop(temp,&aux_temp);
        }
        push(s,&aux_temp);
        push(temp,&aux_s);
    }

}
while(!empty(temp)){
    pop(temp,&aux_s);
    push(s,&aux_s);
}
free(temp);
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
//printf("EMPTY STACK \n");
return;
}
s->top--;
*c = s->vetor[s->top];


}
bool push (stack *s, int *c){
if(full(s)){
    printf("STACK FULL. EXIT REQUIRED \n");
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
