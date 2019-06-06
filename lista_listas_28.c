#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int n;
	struct nodo *next;
}nodo;

void imprime_lista(nodo *head);
nodo* final (nodo *head);
void adiciona(nodo *head,int valor);
void elimina(nodo *head, int v);

int main(int argc, char const *argv[])
{
	int x;
    nodo *head = (nodo*) malloc(sizeof(nodo));
	head->next = NULL;

	adiciona(head,3);
	adiciona(head,4);
	adiciona(head,2);
   	 adiciona(head,4);
	adiciona(head,2);

	printf("--LISTA ENCADEADA -- : \n");
	imprime_lista(head);
	printf("Apagar ocorrência de: \n");
	scanf("%d",&x);
	elimina(head,x);
	printf("--LISTA SEM OCORRÊNCIAS DE %d--\n",x );
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

void elimina(nodo *head, int v){
	nodo *count,*anterior;
	count = head->next;
	for(count = head->next,anterior=head;count!=NULL;){
		if(count->n==v){
			anterior->next = count->next;
			//free(count);
			count = anterior;
		}
		count= count->next;
		anterior=anterior->next;
	}



}

void imprime_lista(nodo *head){
nodo *count;
	printf("[ ");
	for(count = head->next;count!=NULL;count=count->next){
		printf(" %d ",count->n);
	}
	printf(" ]\n");

}
