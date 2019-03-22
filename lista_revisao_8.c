/* 
8) Faça um programa que leia uma string (de 80 caracteres) chamada linha
e, com uma função, identifique cada palavra (substring) desta linha
copiando-a para um novo vetor. Ao final, o programa deve imprimir as
palavras separadas, uma palavra por linha.
Dicas: i) faça uma função para identificar o fim e/ou o início de cada substring em linha*/

#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int acha_subpalavra(char *s);
int main(){
	char *s = (char*) malloc (80* sizeof(char));
	int sub,c;
	printf("Digite a string: ");
	scanf("%[^\n]",s);
	sub = acha_subpalavra(s);
	printf("Foram encontradas %d subpalavras no vetor. \n",sub);
	for(c=0;*(s+c)!=0;c++){
		(s[c] ==' '||s[c]=='.')?printf("\n"):printf("%c",*(s+c));
	}
	return 0;
}

int acha_subpalavra(char *s){//acabou ficando meio descenessario isso pq soh acho a qtd de subpalavras e arrumo o vetor... 
	int subpalavra = 1;
	char *nova = (char*) malloc (strlen(s)*sizeof(char));
	for(int c=0;c<=strlen(s);c++){
		if(s[c] ==' ' || s[c]=='.'){//colocar o \n aqui nao funciona depois
			subpalavra++;
		}
		else{
			*(nova+c) = *(s+c);
		}
	}
		s=nova;
		free(nova);
 	return subpalavra;
}