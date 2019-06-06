#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int n;
	struct nodo *next;
}nodo;

void imprime_lista(nodo *head);
nodo* final (nodo *head);
void adiciona(nodo *head,int valor);
void verifica_igualdade(nodo *head1, nodo *head2);

int main(int argc, char const *argv[])
{

    nodo *head1,*head2;
	head1 = (nodo*) malloc(sizeof(nodo));
	head1->next = NULL;
	head2 = (nodo*) malloc(sizeof(nodo));
	head2->next = NULL;

	adiciona(head1,0);
	adiciona(head1,1);
	adiciona(head1,2);

	adiciona(head2,0);
	//adiciona(head2,1);
	adiciona(head2,4);
	//adiciona(head2,2);

	printf("--LISTA ENCADEADA 1-- : \n");
	imprime_lista(head1);
	printf("--LISTA ENCADEADA 2-- : \n");
	imprime_lista(head2);
	verifica_igualdade(head1,head2);
	free(head1);
	free(head2);
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

void verifica_igualdade(nodo *head1, nodo *head2){
	nodo *c1,*c2;
	for(c1 = head1->next,c2 = head2->next;c1!=NULL && c2!=NULL;c1=c1->next,c2=c2->next){
		if(c1->n!=c2->n){
			printf("AS LISTAS NÃO SÃO IGUAIS\n");
			return;
		}
	}
	if(c1==NULL && c2==NULL){//se as duas terminaram
		printf("AS DUAS LISTAS SÃO IGUAIS\n");
		return;
	}
	printf("AS LISTAS NÃO SÃO IGUAIS\n");
}
