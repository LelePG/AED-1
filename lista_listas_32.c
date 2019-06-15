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
	if(h==NULL){
		return;
	}
	else if(h->prev == NULL){//só um caso especial caso eu tenha a head aqui. Não quero que ela apareça no display.
		list(h->next);
	}
	else{
		printf(" %d ",h->n);//aqui a lista é impressa da esquerda pra direita
		list(h->next);
		//printf(" %d ",h->n);//aqui da direita pra esquerda
	}
}
