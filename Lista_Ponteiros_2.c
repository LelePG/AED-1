
#include <stdio.h>
#include <stdlib.h>
int* cria_vetor(int tamanho);
void imprime_vetor(int *v,int t);
void apaga_vetor(int *vetor);
int main(int argc, char **argv)
{
	int *teste;
	int t;
	printf("Digite o tamanho do vetor: ");
	scanf("%d",&t);
	teste=cria_vetor(t);
	for(int c=0;c<t;c++){
		printf("Numero %d: ",c);
		scanf("%d",(teste+c));
	}
	//system("cls"); //Clean screen is not working
	imprime_vetor(teste,t);
	apaga_vetor(teste);
	return 0;
}

int* cria_vetor(int tamanho){
	int *vetor = (int*) malloc(tamanho*(sizeof(int)));
	return vetor;
	}

void apaga_vetor(int *vetor){
	free(vetor);
	printf("==Memória limpa==\n");
	}
	
void imprime_vetor(int *v,int t){
	for(int c=0;c<t;c++){
		printf("Numero na posição %d : %d\n",c,*(v+c));
	}
	
	}
