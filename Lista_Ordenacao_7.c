#include <stdio.h>

int main(int argc, char const *argv[])
{
	int vetor[10] = {1,4,9,13,17,25,29,33,38,40};
	int c,encontrar;
	printf("Insira o numero que quer procurar: \n");
	scanf("%d",&encontrar);
	for(c=0;c<10;c++){
		if(vetor[c]==encontrar){
			printf("Number %d was found in array\n",encontrar);
			return 0;
		}
		
	}
	printf("Number %d was not found in array\n",encontrar);
	return 0;
}