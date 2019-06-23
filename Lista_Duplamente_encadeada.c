#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Pessoa{
	char nome[20];
	int telefone;
}Pessoa;

typedef struct node{
	Pessoa p;
	struct node *next;
	struct node *prev;
}node;

node* create (void);
void adicionar(node *h, Pessoa *p);
void delete_name(node *h, char *s);
void listar(node *h);
int menu(void);
int tamanho(node *h);
void deleta_index(node *h, int n);
void limpa_lista(node *h);

int main(int argc, char const *argv[])
{
	node *head;
	int i;//indice pra excluir
	Pessoa add;//pessoa pra adicionar
	char d[20];//nome pra deletar por nome
	head = create();
	while (1){
		switch (menu()){
			case 0:
				printf("Nome: \n");
				scanf("%s", add.nome);
				printf("Telefone: \n");
				scanf("%d",&add.telefone);
				adicionar(head,&add);
				break;
			case 1:
				printf("A lista tem %d elementos. Quer excluir qual? \n", tamanho(head));
				scanf("%d",&i);
				deleta_index(head,i);
				break;
			case 2:
				printf("Nome que deseja excluir: \n");
				scanf("%s",d);
				delete_name(head,d);
				break;
			case 3:
				limpa_lista(head);
				break;
			case 4:
				listar(head);
				break;
			case 5:
				free(head);
				return 0;
			default:
				printf("Error. Select again.\n");
		}
	}

}

void limpa_lista(node *h){
	node *count;
	for(count = h->next; h->next!=NULL;h= h->next);
	for(count; count->prev!=NULL;count = count->prev){
		free(count->next);
	}
	count->next = NULL;//pra não perder a cabeça da lista


}

int menu(void){
	int e;
	printf("---AGENDA LISTA DUPLAMENTE ENCADEADA---\n");
	printf("0 - INSERE PESSOA\n");
	printf("1 - DELETA A PESSOA DE ACORDO COM ÍNDICE\n");
	printf("2 - DELETA A PESSOA POR NOME\n");
	printf("3 - LIMPA A LISTA\n");
	printf("4 - LISTA NA TELA TODAS AS PESSOAS\n");
	printf("5 - SAIR DO PROGRAMA\n");
	scanf("%d",&e);
	return e;
}

void deleta_index(node *h, int n){
    node *count;
	int c;
	if(n<0 || n>tamanho(h)){
		printf("Invalid Index. Try again\n");
		return;
	}
	for(c=0,count = h;c<n;c++,count = count->next);//onde count parar é a posição que eu tenho que excluir
    if(count->next==NULL){//caso eu tenha que excluir o ultimo elemento, se comporta diferente porque a lista é duplamente encadeada
        count->prev->next = NULL;
        free(count);
    }
    else{
    	count->next->prev = count->prev;
        count->prev->next = count->next;
        free(count);
    }
}

int tamanho(node *h){
	node* count;
	int c;
	for(c=0,count=h->next; count!=NULL;c++,count = count->next);
	return c;

}
void listar(node *h){
	node *count;
	if(h->next==NULL){
		printf("--EMPTY LIST--\n");
		return;
	}
	for(count= h->next; count!=NULL; count =  count->next){
		printf("-------------\n");
		printf("Name: %s\n",count->p.nome);
		printf("Telefone: %d\n",count->p.telefone);
		printf("-------------\n");
	}

}

void delete_name(node *h, char *s){
	node *count;
	for (count = h->next;count!=NULL;count = count->next){
		if(strcmp(count->p.nome,s)==0){
			count->next->prev = count->prev;
			count->prev->next = count->next;
			free(count);
			return;
		}
	}
	printf("Name not found\n");
}

void adicionar(node *h, Pessoa *p){
	node *count, *novo;
	for(count = h; count->next!=NULL;count= count->next);//acha a última posição
	novo = create();
	novo->p = *p;
	novo->prev = count;
	count->next = novo;
}

node* create (void){
	node *aux = (node*) malloc (sizeof(node));
	if(aux==NULL){
		printf("Error\n");
		exit(1);
	}
	aux->prev = NULL;
	aux->next = NULL;
	return aux;
}
