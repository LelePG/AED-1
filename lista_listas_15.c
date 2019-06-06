#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0
typedef struct nodo{
	int n;
	struct nodo *next;
}nodo;


void adiciona(nodo *head,int valor);
nodo* final (nodo *head);
void imprime_lista(nodo *head);
bool verifica_ordenacao_crescente(nodo *head);
bool verifica_ordenacao_decrescente(nodo *head);
int main(int argc, char const *argv[])
{
	nodo *head;
	head = (nodo*) malloc (sizeof(nodo));
	head->next = NULL;
	adiciona(head,0);
	adiciona(head,1);
	adiciona(head,7);
	adiciona(head,3);
	adiciona(head,4);
	adiciona(head,5);
	printf("--LISTA--\n");
	imprime_lista(head);
	if(verifica_ordenacao_crescente(head)){
		printf("A lista está organizada em ordem crescente\n");
	}
	else if(verifica_ordenacao_decrescente(head)){
		printf("A lista está organizada em ordem decrescente\n");
	}
	else{
		printf("A lista não está organizada\n");
	}
	free(head);
	return 0;
}

void adiciona(nodo *head,int valor){
	nodo *novo = (nodo*) malloc(sizeof(nodo));
	nodo *fim_lista;
	novo->n = valor;
	novo->next = NULL;//sempre adiciona no final
	fim_lista = final(head);
	fim_lista->next = novo;//final é uma função que acha o final da lista que começa em head
}

nodo* final (nodo *head){
	nodo *count;
	for(count = head;count->next!=NULL;count=count->next);
	return count;
}

void imprime_lista(nodo *head){
nodo *count;
	printf("[ ");
	for(count = head->next;count!=NULL;count=count->next){
		printf(" %d ",count->n);
	}
	printf(" ]\n");

}

bool verifica_ordenacao_crescente(nodo *head){
	nodo *count;
	count = head->next;
	while(count->next!=NULL){
		if(count->n > count->next->n){
			return false;
		}
		count = count -> next;
	}
	return true;
}

bool verifica_ordenacao_decrescente(nodo *head){
	nodo *count;
	count = head->next;
	while(count->next!=NULL){
		if(count->n < count->next->n){
			return false;
		}
		count = count -> next;
	}
	return true;
}

