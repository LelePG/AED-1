
#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int n;
	struct nodo *next;
}nodo;

void imprime_lista(nodo *head);
nodo* final (nodo *head);
void adiciona(nodo *head,int valor);
nodo* pares(nodo *head);

int main(int argc, char const *argv[])
{

    nodo *head,*head_par;
	head = (nodo*) malloc(sizeof(nodo));
	head->next = NULL;

	adiciona(head,0);
	adiciona(head,1);
	adiciona(head,2);
	adiciona(head,3);
	adiciona(head,4);
	adiciona(head,5);
        adiciona(head,6);
	adiciona(head,7);

	printf("--LISTA-- : \n");
	imprime_lista(head);
	head_par = pares(head);
	printf("--LISTA DE NUMEROS PARES--\n"); 
	imprime_lista(head_par);
	free(head);
	free(head_par);
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

nodo* pares(nodo *head){
	nodo *count;
	nodo *ret = (nodo*) malloc(sizeof(nodo));
	ret->next = NULL;
	for(count = head->next;count!=NULL;count=count->next){
		if(count->n%2==0){
			adiciona(ret,count->n);
		}
	}
	return ret;
}

void imprime_lista(nodo *head){
nodo *count;
	printf("[ ");
	for(count = head->next;count!=NULL;count=count->next){
		printf(" %d ",count->n);
	}
	printf(" ]\n");

}


