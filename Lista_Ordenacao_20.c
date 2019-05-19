#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void ordena_quick(char *s, int esquerda,int direita);

int main(int argc, char const *argv[])
{
char *s;
int t =1,sp=0;//quantidade de letras na string
printf("Digite uma frase:  ");
s =(char*) malloc(sizeof(char));
    if(s==NULL){
        printf("SAIR");
        exit(1);
    }

while(scanf("%c",&s[t-1]) && s[t-1]!='\n'){
    if(s[t-1]==' '){//desconsidera os espaços da frase
        sp++;
    }
    else{
        s = (char*) realloc(s,(t+1)*sizeof(char));
        if(s==NULL){
            printf("SAIR");
            exit(1);
        }
    t++;
    }

}
//s[t-1] = '\0';
printf("%s",s);
ordena_quick(s,0,strlen(s)-1);
printf("Letras em ordem decrescente:\n");
//printf("%s\n",s);
printf("%d espaços em branco foram desconsiderados. ",sp);
free(s);
return 0;
}

void ordena_quick(char *s, int esquerda,int direita){
char aux,c_meio;
int e,d;
e = esquerda;
d = direita;
c_meio = s[(e+d)/2];
do{
    while(s[e]>c_meio){
        e++;
    }
    while(s[d]<c_meio){
        d--;
    }
    if(e<=d){
        aux=s[e];
        s[e]=s[d];
        s[d]=aux;
        e++;
        d--;
    }
}while(e<=d);
if(esquerda<d){
    ordena_quick(s,esquerda,d);
}
if(direita>e){
    ordena_quick(s,e,direita);
}
}


