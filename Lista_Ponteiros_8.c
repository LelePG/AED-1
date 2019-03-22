/*
Crie uma função que receba como parâmetros dois vetores de inteiros, v1 e v2, e as
suas respectivas quantidades de elementos, n1 e n2. A função deverá retornar um
ponteiro para um terceiro vetor, v3, com capacidade para (n1 + n2) elementos,
alocado dinamicamente, contendo a união de v1 e v2. Por exemplo, se v1 = {11, 13, 45,
7} e v2 = {24, 4, 16, 81, 10, 12}, v3 irá conter {11, 13, 45, 7, 24, 4, 16, 81, 10, 12}. O
cabeçalho dessa função deverá ser o seguinte: int* uniao(int *v1, int n1, int *v2, int
n2); Em seguida, crie a função principal do programa para chamar a função uniao
passando dois vetores informados pelo usuário (ou declarados estaticamente). Em
seguida, o programa deve exibir na tela os elementos do vetor resultante. Não
esqueça de liberar a memória alocada dinamicamente.
 * 
 */


#include <stdio.h>
#include <stdlib.h>
void preenche(int *v,int n);
int* uniao(int *v1, int n1, int *v2, int n2);
int main(int argc, char **argv)
{
	int *v1,*v2,*v3;
	int n1,n2;
	printf("Tamanho do primeiro vetor: ");
	scanf("%d",&n1);
	v1 = (int*) malloc (n1*sizeof(int)); 
	printf("Preencha o primeiro vetor: \n");
	preenche(v1,n1);
	printf("Tamanho do segundo vetor: ");
	scanf("%d",&n2);
	printf("Preencha o segundo vetor: \n");
	v2 = (int*) malloc (n2*sizeof(int)); 
	preenche(v2,n2);
	v3 = uniao(v1,n1,v2,n2);
	for(int c=0;c<n1+n2;c++){
		printf("%d ",v3[c]);
	}
	
	
	return 0;
}

void preenche(int *v,int n){
	for(int c=0;c<n;c++){
		printf("Pos %d: ",c);
		scanf("%d",&v[c]);
	}
}

int* uniao(int *v1, int n1, int *v2, int n2){
	int *v3 = (int*)malloc((n1+n2)*sizeof(int));
	int i;
		for(i=0;i<n1;i++){
		v3[i] = v1[i];
		}
		for(i=0;i<n2;i++){
		v3[i+n1] = v2[i];//contando com o i=0, n1 eh ate onde eu tava adicionando as coisas
		}
		free(v1);
		free(v2);
	return v3;
			
	
	}
