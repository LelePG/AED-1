#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char const *argv[])
{
	char **s, aux[10];
	int n,c,c2,troca;
	printf("Quantos nomes quer inserir? \n");
	scanf("%d",&n);
	s = (char**) malloc (n*sizeof(char*));

	for(c=0;c<n;c++){//ordena
		s[c] = (char*) malloc (10* sizeof(char*));
		printf("Digite um nome: \n");
		scanf("%s",s[c]);
	}

	for(c=0;c<n-1;c++){
		troca = c;
		for(c2=c+1;c2<n;c2++){
			if(strlen(s[c2])<strlen(s[troca])){
				troca = c2;
			}
		}
		strcpy(aux,s[troca]);
		strcpy(s[troca],s[c]);
		strcpy(s[c],aux);

	}//ordena

	printf("LISTA ORDENADA: \n");
	for(c=0;c<n;c++){
		printf("%s\n",s[c]);
	}
	return 0;
}
