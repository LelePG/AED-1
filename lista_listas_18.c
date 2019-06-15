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
void copy (node *dest, node *src);

int main(int argc, char const *argv[])
{
	node *head1, *head2;
	head1 = inicialize();
	head2 = inicialize();
	add(head1,87);
	add(head1,-98);
	add(head1,12);
	add(head1,4);
	add(head1,5);
	add(head1,-6);
	printf("--LISTA NORMAL--\n");
	list(head1);
	copy(head2,head1);
	printf("\n--LISTA INVERTIDA--\n");
	list(head2);

	free(head1);
	free(head2);
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
void copy (node *dest, node *src){
	node *count;
	for(count = src;count->next!=NULL; count = count->next);//só leva esse ponteiro pro final
	for(count; count->prev!=NULL;count = count->prev){//volta pro inicio copiando as coisas
		add(dest,count->n);
	}
}
