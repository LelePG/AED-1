#include<stdio.h>
#include<stdlib.h>
#define T 4
typedef struct nodo{
	int n;
	struct nodo *next;
}nodo;

void faz_lista(nodo *head,int *vetor);
void imprime_lista(nodo *head);
nodo* final (nodo *head);
void adiciona(nodo *head,int valor);

int main(int argc, char const *argv[])
{
	nodo *head = (nodo*) malloc(sizeof(nodo));
	head->next = NULL;//cabeça da lista

	int vetor[T] = {0,1,2,3};
	faz_lista(head,vetor);
	imprime_lista(head);
	free(head);
	return 0;
}



void faz_lista(nodo *head,int *vetor){
	int c;
	for(c=0;c<T;c++){
		adiciona(head,*(vetor+c));
	}
	printf("--LIST CREATED--\n");

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
	printf("\n[ ");
	for(count = head->next;count!=NULL;count=count->next){
		printf(" %d ",count->n);
	}
	printf(" ]\n");

}
