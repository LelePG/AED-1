#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int n;
	struct nodo *next;
}nodo;

void imprime_lista(nodo *head);
nodo* final (nodo *head);
void adiciona(nodo *head,int valor);
nodo* Inter(nodo *head1,nodo *head2);
int existe(int x,nodo *head);

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
	adiciona(head2,2);
	adiciona(head2,2);
    	adiciona(head2,0);
	adiciona(head2,8);


	head3 = Inter(head1,head2);
	printf("--LISTA ENCADEADA 1-- : \n");
	imprime_lista(head1);
	printf("--LISTA ENCADEADA 2-- : \n");
	imprime_lista(head2);
	printf("--INTERSECÇÃO-- : \n");
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

nodo* Inter (nodo *head1,nodo *head2){
	nodo *count,*count2;
	nodo *ret;
    ret = (nodo*) malloc(sizeof(nodo));
	for(count = head1->next;count!=NULL;count= count->next){
		for(count2 = head2->next;count2!=NULL;count2= count2->next){
			if(count->n==count2->n && !existe(count->n,ret)){//Se eu tenho o mesmo numero e esse numero não existe no vetor intersecção
				adiciona(ret,count->n);
			}
		}		
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

int existe(int x,nodo *head){
    nodo *count;
    for(count = head->next;count!=NULL;count = count->next){
        if(x==count->n){
        return 1;
        }
    }
    return 0;
}
