
#include <stdio.h>
#include <stdlib.h>
int** cria_matriz(int linhas, int colunas);
void limpa_matriz(int**p,int m);
void imprime_matriz(int**m, int l, int c);

int main(int argc, char **argv){
	int m,n;
	int **ma;
	printf("Numero de linhas: ");
	scanf("%d",&m);
	printf("Numero de colunas: ");
	scanf("%d",&n);
	ma = cria_matriz(m,n);
	imprime_matriz(ma,m,n);//nessa chamada tem que imprimir a matriz de 9s
	limpa_matriz(ma,m);
	imprime_matriz(ma,m,n);//isso aqui tem que ter lixo ou dar segmentation fault por que a memoria foi limpa.
	

	return 0;
}

int** cria_matriz(int linhas, int colunas){
	int** matriz = (int**)malloc(colunas*sizeof(int*));//esse ponteiro pra ponteiro aloca o numero de linhas
	for(int i=0;i<linhas;i++){
			matriz[i]=(int*)malloc(linhas*sizeof(int));//cada linha recebe o numero de colunas que precisa receber
		for(int j=0;j<colunas;j++){ 
			matriz[i][j]=9;//pra ver se ta preenchendo mesmo
			}
	}
	return matriz;
	
	}

void limpa_matriz(int**p,int m){
	for(int i=0;i<m;i++){
		free(p[i]);
	}
	free(p);
	printf("==Memoria limpa==\n");
}

void imprime_matriz(int**m, int l, int c){//recebe o ponteiro pra matriz, o numero de linhas e o numero de colunas.
	int i,j;
	for(int i=0;i<l;i++){
		for(int j=0;j<c;j++){
			printf("%d ",m[i][j]);
		}
	printf("\n");
	}
}