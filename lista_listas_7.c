
#include<stdio.h>
#include<stdlib.h>

#define bool int
#define true 1
#define false 0

typedef struct nodo{
	int n;
	struct nodo *next;
}nodo;

void imprime_lista(nodo *head);
nodo* final (nodo *head);
void adiciona(nodo *head,int valor);
bool deleta(nodo*head, int rm);

int main(int argc, char const *argv[])
{
	int rm;

  	  nodo *head1;
	head1 = (nodo*) malloc(sizeof(nodo));
	head1->next = NULL;
	
	adiciona(head1,0);
	adiciona(head1,1);
	adiciona(head1,2);
	adiciona(head1,3);
	adiciona(head1,4);
	adiciona(head1,5);
    	adiciona(head1,6);
	adiciona(head1,8);

	printf("Deletar quantos elementos?\n" );
	scanf("%d",&rm);

	if(deleta(head1,rm)){
		printf("Posições deletadas com sucesso\n");
	}
	else{
		printf("Não foi possível deletar\n");
	}


	printf("--LISTA-- : \n");
	imprime_lista(head1);
	free(head1);
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

bool deleta(nodo *head,int rm){
	nodo *count;
	int c;
	for(c=0,count=head->next;c<rm && count!=NULL;c++,count = count->next);//verifica se eu tenho posições suficientes pra poder apagar
	if(count!=NULL){//se eu contei até quanto eu preciso e ainda tenho posições
		head->next = count;//a primeira posição é o count que eu parei
		return 1;
	}
	return 0;
}

void imprime_lista(nodo *head){
nodo *count;
	printf("[ ");
	for(count = head->next;count!=NULL;count=count->next){
		printf(" %d ",count->n);
	}
	printf(" ]\n");

}


