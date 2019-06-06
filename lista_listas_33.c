#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int n;
	struct nodo *next;
}nodo;

void imprime_lista(nodo *head);
nodo* final (nodo *head);
void adiciona(nodo *head,int valor);
void ordena(nodo *head);

int main(int argc, char const *argv[])
{

    nodo *head;
	head = (nodo*) malloc(sizeof(nodo));
	head->next = NULL;

	adiciona(head,3);
	adiciona(head,9);
	adiciona(head,7);
    adiciona(head,1);
	adiciona(head,8);

	printf("--LISTA-- : \n");
	imprime_lista(head);
	ordena(head);
	printf("--LISTA ORDENADA-- : \n");
	imprime_lista(head);
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


void imprime_lista(nodo *head){
nodo *count;
	printf("[ ");
	for(count = head->next;count!=NULL;count=count->next){
		printf(" %d ",count->n);
	}
	printf(" ]\n");

}

void ordena(nodo *head){
	nodo *count1,*count2;
	int aux;
	for(count1 = head->next;count1!=NULL;count1 = count1->next){
		for(count2 = count1;count2!=NULL;count2 = count2->next){
			if(count2->n<count1->n){
				aux = count1->n;//copio só os conteúdos porque não posso perder a ordem da lista
				count1->n = count2->n;
				count2->n = aux;

			}
		}

	}
}
