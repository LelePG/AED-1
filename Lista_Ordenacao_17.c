#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void insere(char** s,char* nome);
void aloca(char **s);

int n, adicionados =0;
int main(int argc, char const *argv[])
{
	int c;
	char **s,nome[10];
	printf("Quantos nomes deseja listar?\n");
	scanf("%d",&n);
	getchar();//tira o \n na entrada
    //aloca memoria pra s
	s = (char**) malloc (n* sizeof(char*));
	if(s==NULL){
		printf("EXITING\n");
	}
	for(c=0;c<n;c++){
		s[c] = (char*) malloc(10*sizeof(char));
		if(s[c]==NULL){
			printf("EXITING\n");
		}
	}
	//fim aloca

	for(c=0;c<n;c++){
		printf("Digite o nome:\n");
		scanf("%[^\n]",nome);
		getchar();
		insere(s,nome);
	}
	printf("LISTA:\n");
	for(c=0;c<n;c++){
		printf("%s\n",s[c] );
	}

    for(c=0;c<n;c++){
		free(s[c]);
    }
		free(s);
	return 0;
}

void insere(char** s,char* nome){
	int c1,c2;
	char temp [10];
    strcpy(s[adicionados],nome);
    for(c1=0;c1<adicionados+1;c1++){
        strcpy(temp,s[c1]);
        c2 = c1 -1;
        while(c2>=0 && strcmp(s[c2],temp)>0){
            strcpy(s[c2+1],s[c2]);
            c2--;
        }
        strcpy(s[c2+1],temp);
    }
	adicionados++;
}

