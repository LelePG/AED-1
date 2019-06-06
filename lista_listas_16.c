#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int n;
	struct nodo *next;
}nodo;


void imprime_lista(nodo *head);
nodo* final (nodo *head);
void adiciona(nodo *head,int valor);
void copia_lista(nodo *head,nodo *head2);

int main(int argc, char const *argv[])
{
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
	printf("--LISTA ENCADEADA--\n");
	imprime_lista(head1);
	copia_lista(head1,head2);
	printf("--LISTA ENCADEADA (COPY)--\n");
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

void copia_lista(nodo *head,nodo *head2){
	nodo *count;
	for(count=head->next;count!=NULL;count = count->next){
		adiciona(head2,count->n);
	}

}