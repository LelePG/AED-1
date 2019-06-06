
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

typedef struct produto{
	int codProd; //código do produto
	char nomeProd[10]; //nome do produto
	float valor; //valor do produto
	int qtdeEstoque; //quantidade disponı́vel em estoque
	struct produto *next;
}produto;
typedef struct lista{//outra struct pra observar o maior e a posição dele
	produto *head;
	produto menor_p;
}lista;

void imprime_lista(lista *l);
produto* final (lista *l);
void adiciona(lista *l,int code,char* nome, int valor, int qtd);
bool acha_menor_valor(lista *l);

int main(int argc, char const *argv[])
{
	lista *l;
	l = (lista*) malloc(sizeof(lista));
	l->head = (produto*) malloc(sizeof(produto));
	l->head->next = NULL;
	
	adiciona(l,10,"10",10,10);
	adiciona(l,1,"1",1,1);
	adiciona(l,2,"2",2,2);
	adiciona(l,3,"3",3,3);
	adiciona(l,4,"4",4,4);

	printf("--LISTA-- : \n");
	imprime_lista(l);
	if(acha_menor_valor(l)){
		printf("O produto de menor valor é %s.\nCode: %d\nValor: %.2f\nQuantidade: %d\n",
			l->menor_p.nomeProd,l->menor_p.codProd,l->menor_p.valor,l->menor_p.qtdeEstoque);
	}
	else{
		printf("Não foi possivel achar o produto de menor valor\n");
	}
	free(l->head);
	free(l);
	return 0;
}


void adiciona(lista *l,int code,char* nome, int valor, int qtd){
	produto *novo = (produto*) malloc(sizeof(produto));
	produto *fim_lista;
	novo->codProd = code;
	strcpy(novo->nomeProd,nome);
	novo->valor = valor;
	novo->qtdeEstoque = qtd;
	fim_lista = final(l);
	fim_lista->next = novo;//final é uma função que acha o final da lista que começa em head
    novo->next = NULL;//sempre adiciona no final
}

produto* final (lista *l){
	produto *count;
	for(count = l->head;count->next!=NULL;count=count->next);
	return count;
}

bool acha_menor_valor(lista *l){
	produto *count;
	int c;
	l->menor_p.valor = 10000000;
	for(c=0,count=l->head->next;count!=NULL;count = count->next,c++){
		if(count->valor<l->menor_p.valor){
			l->menor_p = *count;
		}
	}
	if(c<0 || count!=NULL ){
		return 0;
	}
	return 1;
}

void imprime_lista(lista *l){
produto *count;

	for(count = l->head->next;count!=NULL;count=count->next){
		printf("---------------------\n");
		printf("Nome: %s\n",count->nomeProd );
		printf("Code: %d\n",count->codProd );
		printf("Valor: %.2f\n",count->valor );
		printf("Quantidade em estoque: %d\n", count->qtdeEstoque);
		printf("---------------------\n");

	}
}


