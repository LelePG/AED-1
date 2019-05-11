#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char const *argv[])
{
	char *s,aux;
	int c=0,c2;
	s = (char*) malloc (sizeof(char));
	printf("Digite a frase: \n");
	//monta frase
	while(scanf("%c",&s[c]) && s[c]!='\n'){
		if(s[c]!=' '){//nao considera espaços
			c++;
			s = (char*) realloc (s,(c+1)*sizeof(char));
		}
	}
	s[c] = '\0';
	//fim monta frase
	
	for(c=0;c<strlen(s);c++){
		for(c2=0;c2<strlen(s)-1;c2++){
			if(s[c2]>s[c]){
			aux=s[c2];
			s[c2]=s[c];
			s[c]=aux;
			}
		}
	}

	printf("%s\n",s );
	return 0;
}