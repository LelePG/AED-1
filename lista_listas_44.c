#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int n;
	struct nodo *next;
}nodo;


void imprime_lista(nodo *head);
nodo* final (nodo *head);
void adiciona(nodo *head,int valor);
int qt_primos(nodo *head);

int main(int argc, char const *argv[])
{
	nodo *head1 = (nodo*) malloc(sizeof(nodo));
	head1->next = NULL;//cabeça da lista
	adiciona(head1,13);
	adiciona(head1,1);
	adiciona(head1,29);
	adiciona(head1,3);
	adiciona(head1,4);
	adiciona(head1,5);

	printf("A lista ");
	imprime_lista(head1);
	printf(" tem %d números primos.\n",qt_primos(head1));
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
	printf(" ]");

}


int qt_primos(nodo *head){
	int c =0,primos,div =0;
	nodo *count;
	for(count=head->next;count!=NULL;count = count->next){
		for(c=1,div=0;c<=count->n;c++){
			if(count->n%c==0){
				div++;
			}
		}
		if(div==2  || count->n == 1  ){
			primos++;
			//printf("%d\n",count->n );
		}
	}

	return primos;
}