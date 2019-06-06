#include<stdio.h>
#include<stdlib.h>

#define bool int
#define true 1
#define false 0

typedef struct nodo{
	int n;
	struct nodo *next;
}nodo;


void imprime_lista(nodo *head);
nodo* final (nodo *head);
void adiciona(nodo *head,int valor);
nodo* divide_lista(nodo *head,int n);


int main(int argc, char const *argv[])
{
	int v;
	nodo *head1 = (nodo*) malloc(sizeof(nodo));
	head1->next = NULL;//cabeça da lista
	nodo *head2 = (nodo*) malloc(sizeof(nodo));
	head2->next = NULL;
	adiciona(head1,0);
	adiciona(head1,1);
	adiciona(head1,2);
	adiciona(head1,3);
	adiciona(head1,4);
	adiciona(head1,5);
	printf("Dividir em: \n" );
	scanf("%d",&v);
	head2 = divide_lista(head1,v);
	printf("--LISTA 1--\n");
	imprime_lista(head1);
	printf("--LISTA 2--\n");
	imprime_lista(head2);
	free(head1);
	free(head2);
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


nodo* divide_lista(nodo *head,int n){
	nodo *ret = (nodo*) malloc(sizeof(nodo));
	nodo *count;
	for(count=head->next;count!=NULL;count = count->next){
		if(count->n == n){
			ret->next = count->next;
			count->next = NULL;
			printf("--LISTA DIVIDIDA--\n");
			return ret;
		}
		
	}
	printf("Erro ao dividir lista. Tente novamente");	
	return NULL;

}
