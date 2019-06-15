#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int n;
	struct node *next;
	struct node *prev;
}node;

node* inicialize(void);
void add (node *h, int i);
void list (node *h);
int n_nodes (node *h);

int main(int argc, char const *argv[])
{
	node *head1;
	head1 = inicialize();
	add(head1,87);
	add(head1,-98);
	add(head1,12);
	add(head1,4);
	add(head1,5);
	add(head1,-6);
	add(head1,7);
	printf("--LISTA--\n");
	list(head1);
	printf("\n A lista tem %d posições.\n",n_nodes(head1));

	free(head1);
	return 0;
}

node* inicialize(void){
	node *h = (node*) malloc (sizeof(node));
	if(h==NULL){
		printf("ERROR!\n");
		exit(1);
	}
	h->next = NULL;
	h->prev = NULL;
	return h;
}

void add (node *h, int i){
	node *new,*count;
	new = inicialize();
	new->n = i;
	for(count = h;count->next!=NULL;count = count->next);
	new->prev = count;
	count->next = new;
}

void list (node *h){
	node *count;
	for(count = h->next; count!=NULL;count = count->next){
		printf(" %d ",count->n);
	}
	free(count);
}


int n_nodes (node *h){
	if(h==NULL){
		return -1;//deveria ser 0, mas como minha lista tem cabeça e eu não quero que ela apareça na conta, usar -1 soluciona o problema
	}
	else{
		return n_nodes(h->next)+1;
	}

}
