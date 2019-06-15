#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

typedef struct node{
	int n;
	struct node *next;
}node;

void add (node* head, int v);
node* find_end(node *head);
void list(node *head);
bool troca(node* head, int i1,int i2);

int main(int argc, char const *argv[])
{
	node *head = (node*) malloc (sizeof(node));
	int t1,t2;
	add(head,1);
	add(head,2);
	add(head,3);
	add(head,5);
	add(head,12);
	add(head,9);
	add(head,45);
	add(head,-5);
	printf("A lista é: \n");
	list(head);
	printf("Quais elementos quer trocar de posição? \n");
	scanf("%d%d",&t1,&t2);
	if(troca(head,t1,t2)){
		printf("\n--Troca realizada com sucesso--\n");
		printf("Nova lista: \n");
		list(head);
	}
	else{
		printf("\n--Troca não realizada--\n");
	}

	return 0;
}

void add (node* head, int v){
	node *new = (node*)malloc(sizeof(node));
	node *end;

	new->n = v;
	new->next = NULL;
	end = find_end(head);
	end->next = new;

}
node* find_end(node *head){
node *count;
for(count = head;count->next!=NULL;count = count->next);
return count;
}

void list(node *head){
 node *count;
 for(count = head->next;count!=NULL;count = count->next){
 	printf(" %d ",count->n);

 }

}

bool troca(node* head, int i1,int i2){
	node *count;
	bool ret = true;
	for(count = head->next; count!=NULL;count = count->next){
		if(count->n == i1){
			count->n = i2;
			ret = !ret;
		}
		else if( count->n == i2){//se tudo der certo ret troca de valor duas vezes, então volta a ficar verdadeiro no fim das contas
			count->n =i1;
			ret = !ret;
		}

	}
	return ret;

}
