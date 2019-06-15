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
void une(node* des, node* src1, node* src2);

int main(int argc, char const *argv[])
{
	node *head1, *head2 ,*head3;
	head1 = inicialize();
	head2 = inicialize();
	head3 = inicialize();
	
	add(head1,1);
	add(head1,3);
	add(head1,5);
	add(head1,7);
	add(head1,96);

	add(head2,2);
	add(head2,4);
	add(head2,6);
	add(head2,8);
	add(head2,10);

	printf("--LISTA 1--\n");
	list(head1);
	printf("\n--LISTA 2--\n");
	list(head2);
	une(head3,head2,head1);
	printf("\n--UNIÃO DAS LISTAS--\n");
	list(head3);

	free(head1);
	free(head2);
	free(head3);
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

void une(node* des, node* src1, node* src2){
	node *c1, *c2;

	for(c1 = src1->next,c2 = src2->next; c1!=NULL && c2!=NULL;){
		if(c1->n<c2->n){
			add(des,c1->n);
			c1 = c1->next;
		}
		else{
			add(des,c2->n);
			c2 = c2->next;
		}
	}

	while(c1!=NULL){
		add(des,c1->n);
		c1= c1->next;
	}

	while(c2!=NULL){
		add(des,c2->n);
		c2 = c2->next;
	}


}
