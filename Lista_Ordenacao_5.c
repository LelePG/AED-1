#include<stdio.h>

int n=5;//tamanho do vetor
 int main(int argc, char const *argv[])
{
	int v[n];
	int c,c2,aux;
	printf("Insira %d numeros\n",n);
	
	for(c=0;c<n;c++){
		scanf("%d",&v[c]);
	}
//Insertion sort
	for(c=0;c<n;c++){
		c2 = c-1;
		aux = v[c];
		while(c2>=0 && v[c2] <aux){//modifica a relacao v[c2]>aux pra ficar em ordem decrescente
			v[c2+1] = v[c2];
			c2--;
		}
		v[c2 +1] = aux;
	}

	printf("\nLISTA EM ORDEM DECRESCENTE: ");
	for(c=0;c<n;c++){
		printf("\n%d ",v[c]);
	}
return 0;
}