#include<stdio.h>

int n=5;//tamanho do vetor
 int main(int argc, char const *argv[])
{
	int v[n];
	int c;
	printf("Insira %d numeros\n",n);
	for(c=0;c<n;c++){
		scanf("%d",&v[c]);
	}
	for(c=0;c<n;c++){
		if(v[c]>v[c+1] && c+1!=n){ //a posicao n esta fora do escopo do vetor
			return 0;
		}
	}
	printf("ORDENADO\n");

	return 0;
}