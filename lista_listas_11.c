
#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int n;
	struct nodo *next;
}nodo;

void imprime_lista(nodo *head);
nodo* final (nodo *head);
void adiciona(nodo *head,int valor);
int pares(nodo *head);

int main(int argc, char const *argv[])
{

   	 nodo *head;
	head = (nodo*) malloc(sizeof(nodo));
	head->next = NULL;

	adiciona(head,0);
	adiciona(head,1);
	adiciona(head,2);
	adiciona(head,3);
	adiciona(head,4);
	adiciona(head,5);
   	adiciona(head,6);
	adiciona(head,8);

	printf("--LISTA-- : \n");
	imprime_lista(head);
	printf("A lista possui %d numeros pares.\n",pares(head)); ;
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

int pares(nodo *head){
	int p = 0;
	nodo *count;
	for(count = head;count->next!=NULL;count=count->next){
		if(count->n%2==0){
			p++;
		}
	}
	return p;
}

void imprime_lista(nodo *head){
nodo *count;
	printf("[ ");
	for(count = head->next;count!=NULL;count=count->next){
		printf(" %d ",count->n);
	}
	printf(" ]\n");

}


