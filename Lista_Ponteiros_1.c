
#include <stdio.h>
#include <stdlib.h>
int *vetor;
void preenche_vetor(int *v,int tam);

int main(){
	int tamanho,c=0;
	printf("Digite o tamanho");
	scanf("%d",&tamanho);
	vetor=(int*)malloc(tamanho*sizeof(int));
	preenche_vetor(vetor,tamanho);
	//while(*(vetor+c)){ nao da pra usar caso tenha um zero no vetor
	for(int c=0;c<tamanho;c++){
		printf("Posição %d : %d\n",c,*(vetor+c));
	}
	free(vetor);
	return 0;
}
void preenche_vetor(int *v,int tam){
	for(int c=0;c<tam;c++){
		printf("Digite um número");
		scanf("%d",v+c);
		}
	}
