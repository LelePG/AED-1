#include<stdio.h>
#include<stdlib.h>
#define T 4
typedef struct nodo{
	int n;
	struct nodo *next;
}nodo;


void imprime_lista(nodo *head);
nodo* final (nodo *head);
void adiciona(nodo *head,int valor);
int tamanho_lista(nodo *head);
void copia_lista(nodo *head,int *vetor);

int main(int argc, char const *argv[])
{
	nodo *head = (nodo*) malloc(sizeof(nodo));
	head->next = NULL;//cabeça da lista
	int *vetor = (int*) malloc (sizeof(int));
	adiciona(head,0);
	adiciona(head,1);
	adiciona(head,2);
	adiciona(head,3);
	adiciona(head,4);
	adiciona(head,5);
	printf("--LISTA ENCADEADA--\n");
	imprime_lista(head);
	copia_lista(head,vetor);
	free(head);
	free(vetor);
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

int tamanho_lista(nodo *head){
	nodo *count;
	int t =0;
	for(count = head;count->next!=NULL;count=count->next){
		t++;
	}
	return t;;
}
void copia_lista(nodo *head,int *vetor){
	nodo *count;
	int count2;
	vetor = (int*) realloc(vetor,tamanho_lista(head)*sizeof(int));
	for(count = head->next,count2=0;count!=NULL;count=count->next,count2++){
		vetor[count2] = count->n;
	}
	//imprime o vetor
	printf("---VETOR:---\n");
	for(count2 = 0;count2<tamanho_lista(head);count2++){
		printf(" %d ",vetor[count2]);
	}
}
