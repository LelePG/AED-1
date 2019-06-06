
#include<stdio.h>
#include<stdlib.h>

#define bool int
#define true 1
#define false 0

typedef struct nodo{
	int n;
	struct nodo *next;
}nodo;
typedef struct lista{//outra struct pra observar o maior e a posição dele
	nodo *head;
	int maior;
	int pos;
}lista;

void imprime_lista(lista *l);
nodo* final (lista *l);
void adiciona(lista *l,int valor);
bool acha_maior(lista *l);

int main(int argc, char const *argv[])
{
	lista *l;
	l = (lista*) malloc(sizeof(lista));
	l->head = (nodo*) malloc(sizeof(nodo));
	l->head->next = NULL;
	
	adiciona(l,0);
	adiciona(l,1);
	adiciona(l,12);
	adiciona(l,3);
	adiciona(l,4);
	adiciona(l,55);
	adiciona(l,6);
	adiciona(l,8);

	printf("--LISTA-- : \n");
	imprime_lista(l);
	if(acha_maior(l)){
		printf("O maior número é %d na posição %d\n",l->maior,l->pos);
	}
	else{
		printf("Não foi possivel achar o maior número\n");
	}
	free(l->head);
	free(l);
	return 0;
}


void adiciona(lista *l,int valor){
	nodo *novo = (nodo*) malloc(sizeof(nodo));
	nodo *fim_lista;
	novo->n = valor;
	fim_lista = final(l);
	fim_lista->next = novo;//final é uma função que acha o final da lista que começa em head
    novo->next = NULL;//sempre adiciona no final
}

nodo* final (lista *l){
	nodo *count;
	for(count = l->head;count->next!=NULL;count=count->next);
	return count;
}

bool acha_maior(lista *l){
	nodo *count;
	int c;
	for(c=0,count=l->head->next;count!=NULL;count = count->next,c++){
		if(count->n>l->maior){
			l->maior = count->n;
			l->pos = c;
		}
	}
	if(c<0 || count!=NULL ){
		return 0;
	}
	return 1;
}

void imprime_lista(lista *l){
nodo *count;
	printf("[ ");
	for(count = l->head->next;count!=NULL;count=count->next){
		printf(" %d ",count->n);
	}
	printf(" ]\n");

}


