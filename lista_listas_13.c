
#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int n;
	struct nodo *next;
}nodo;

void imprime_lista(nodo *head);
nodo* final (nodo *head);
void adiciona(nodo *head,int valor);
int media(nodo *head);

int main(int argc, char const *argv[])
{

    nodo *head;
	head = (nodo*) malloc(sizeof(nodo));
	head->next = NULL;

	adiciona(head,4);
	adiciona(head,4);
	adiciona(head,4);
	adiciona(head,7);
	adiciona(head,4);
	adiciona(head,5);
    adiciona(head,6);
	adiciona(head,4);

	printf("--LISTA-- : \n");
	imprime_lista(head);
	printf("A media da lista é %d.\n",media(head)); ;
	free(head);
	return 0;
}


void adiciona(nodo *head,int valor){
	nodo *novo = (nodo*) malloc(sizeof(nodo));
	nodo *fim_lista;
	novo->n = valor;
	fim_lista = final(head);
	fim_lista->next = novo;//final é uma função que acha o final da lista que começa em head
    novo->next = NULL;//sempre adiciona no final
}

nodo* final (nodo *head){
	nodo *count;
	for(count = head;count->next!=NULL;count=count->next);
	return count;
}

int media(nodo *head){
	int d,p = 0;
	nodo *count;
	for(count = head,d=0;count->next!=NULL;count=count->next,d++){
		p+=count->n;
	}
	return p/d;
}

void imprime_lista(nodo *head){
nodo *count;
	printf("[ ");
	for(count = head->next;count!=NULL;count=count->next){
		printf(" %d ",count->n);
	}
	printf(" ]\n");

}


