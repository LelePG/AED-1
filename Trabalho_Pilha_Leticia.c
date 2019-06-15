//LETÍCIA PEGORARO GARCEZ 18100304

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char equip[31];
	struct node *next;
};

struct node *newNode();
void printStack(struct node *head);
void push(struct node *head, char *equip);
struct node *pop(struct node *head);
char *top(struct node *head);
int isEmpty(struct node *head);

int main(){
	struct node *head = newNode();
	head->next = NULL;
	int option;
	char pushEquip[31];
	struct node *popEquip;

	do{
		printf("1 - Push\n2 - Pop\n3 - Print Stack\n4 - Top\n0 - Exit\n");
		scanf("%d", &option);
		getchar();

		switch(option){
			case 1:
				printf("Equip: ");
				fgets(pushEquip, 31, stdin);
				printf("\n");
				push(head, pushEquip);
				break;

			case 2:
				if((popEquip = pop(head))){
					printf("%s\n\n", popEquip->equip);
					free(popEquip);
				}
				break;

			case 3:
				printStack(head);
				printf("\n");
				break;

			case 4:
				printf("%s\n\n", top(head));
				break;

			default:
				break;
		}

	} while(option != 0);

	free(head);
	return 0;
}


//VOCÊS DEVEM COMPLETAR ESTA FUNÇÃO
void push(struct node *head, char *equip){
    struct node *new_n,*aux;
    new_n = newNode();
    strcpy(new_n->equip, equip);
    new_n ->next = NULL;
    for(aux = head;aux->next!=NULL;aux = aux->next);//coloca aux na ultima posição da pilha
    aux->next = new_n;
}

//VOCÊS DEVEM COMPLETAR ESTA FUNÇÃO
struct node *pop(struct node *head){
struct node *retornar = newNode();
if(!isEmpty(head)){
    struct node *aux,*liberar;
    for(liberar = head;liberar->next!=NULL;liberar= liberar->next);//para no ultimo elemento da estrutura
    for(aux = head;aux->next!=liberar;aux = aux->next);//penultimo elemento
    *retornar = *liberar;//vai retornar o ultimo elemento
    free(liberar);//limpa a memria que ela usava;
    aux->next = NULL;
    return retornar;
}
    retornar = NULL;
    printf("Error. Empty stack. Nothing to pop.\n");
    return retornar;//se a pilha está vazia retorna null
}

//VOCÊS DEVEM COMPLETAR ESTA FUNÇÃO
char *top(struct node *head){
char *return_top = (char*) malloc (31*sizeof(char));//31 é o tamanho da string lá em cima
if(!isEmpty(head)){//se a pilha não estiver vazia
    struct node *aux;
    for(aux = head;aux->next!=NULL;aux = aux->next);//coloca aux na ultima posição da pilha
    strcpy(return_top,aux->equip);
}
else{
    return_top = "Error. Empty stack.";
}
 return return_top;
}

int isEmpty(struct node *head){
	if(head->next == NULL)
		return 1;
	else return 0;
}

void printStack(struct node *head){
	if(head->next == NULL)
		printf("Pilha Vazia\n");

	struct node *printer = head->next;

	while(printer != NULL){
		printf("%s", printer->equip);
		printer = printer->next;
	}
}

struct node *newNode(){
	struct node *new = malloc (sizeof (struct node));
	return new;
}

