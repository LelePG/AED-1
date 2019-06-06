#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int n;
	struct nodo *next;
}nodo;

void imprime_lista(nodo *head);
nodo* final (nodo *head);
void adiciona(nodo *head,int valor);
void divide(nodo *head1,nodo *head2, nodo *head3);


int main(int argc, char const *argv[])
{

    nodo *head1,*head_par,*head_impar;
	
	head1 = (nodo*) malloc(sizeof(nodo));
	head_par = (nodo*) malloc(sizeof(nodo));
	head_impar = (nodo*) malloc(sizeof(nodo));
	
	adiciona(head1,0);
	adiciona(head1,1);
	adiciona(head1,2);
	adiciona(head1,5);
	adiciona(head1,7);
	adiciona(head1,21);
   	 adiciona(head1,29);
	adiciona(head1,8);

	divide(head1,head_par,head_impar);

	printf("--LISTA-- : \n");
	imprime_lista(head1);
	printf("--LISTA PAR-- : \n");
	imprime_lista(head_par);
	printf("--LISTA ÍMPAR-- : \n");
	imprime_lista(head_impar);
	free(head);
	free(head_par);
	free(head_impar);
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

void divide(nodo*head1,nodo*head_par,nodo*head_impar){
	nodo *count;
	for(count = head1->next;count!=NULL;count=count->next){
		if(count->n%2==0){
			adiciona(head_par,count->n);
		}
		else{
			adiciona(head_impar,count->n);
		}
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

