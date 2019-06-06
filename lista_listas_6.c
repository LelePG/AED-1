
#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int n;
	struct nodo *next;
}nodo;

void imprime_lista(nodo *head);
nodo* final (nodo *head);
void adiciona(nodo *head,int valor);
nodo* une(nodo *head1,nodo *head2);

int main(int argc, char const *argv[])
{

    nodo *head1,*head2,*head3;
	head1 = (nodo*) malloc(sizeof(nodo));
	head1->next = NULL;
	head2 = (nodo*) malloc(sizeof(nodo));
	head2->next = NULL;

	adiciona(head1,0);
	adiciona(head1,1);
	adiciona(head1,2);

	adiciona(head2,3);
	adiciona(head2,4);
	adiciona(head2,5);
         adiciona(head2,6);
	adiciona(head2,8);


	head3 = une(head1,head2);
	printf("--LISTA ENCADEADA 1-- : \n");
	imprime_lista(head1);
	printf("--LISTA ENCADEADA 2-- : \n");
	imprime_lista(head2);
	printf("--LISTA ENCADEADA 3-- : \n");
	imprime_lista(head3);
	free(head1);
	free(head2);
	free(head3);
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

nodo* une(nodo *head1,nodo *head2){
	nodo *count;
	nodo *ret;
    ret = (nodo*) malloc(sizeof(nodo));
	count = head1->next;
	while(count!=NULL){//copia toda a lista 1 pra lista 3
	    adiciona(ret,count->n);
        count= count->next;
	}
	count = head2->next;
	while(count!=NULL){//copia toda a lista 2 pra lista 3
        adiciona(ret,count->n);
        count= count->next;
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


