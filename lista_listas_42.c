#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int n;
	struct nodo *next;
}nodo;


void imprime_lista(nodo *head);
nodo* final (nodo *head);
void adiciona(nodo *head,int valor);
int qtd_maiores(nodo *head, int valor);

int main(int argc, char const *argv[])
{
	int n;
	nodo *head1 = (nodo*) malloc(sizeof(nodo));
	head1->next = NULL;//cabeça da lista
	adiciona(head1,0);
	adiciona(head1,1);
	adiciona(head1,2);
	adiciona(head1,3);
	adiciona(head1,4);
	adiciona(head1,5);

	printf("Número para verificar: \n");
	scanf("%d",&n);
	printf("A lista ");
	imprime_lista(head1);
	printf("tem %d números maiores que %d\n",qtd_maiores(head1,n),n);
	free(head1);
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


int qtd_maiores(nodo *head, int valor){
	int c =0;
	nodo *count;
	for(count=head->next;count!=NULL;count = count->next){
		if(count->n > valor){
			c++;
		}
	}

	return c;
}