#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct pessoa{
int matricula;
char nome[30];
float nota;
}pessoa;

void ordena_matricula(pessoa *p);
void ordena_nome(pessoa *p);
void ordena_nota(pessoa *p);
int n;
int main(int argc, char const *argv[])
{
int c;
printf("Quantas pessoas? ");
scanf("%d",&n);
pessoa vetor[n];
for(c=0;c<n;c++){
    printf("Dados da pessoa %d\n",c+1);
    printf("Matricula: ");
    scanf("%d",&vetor[c].matricula);
    printf("Nome: ");
    scanf("%s",vetor[c].nome);
    printf("Nota: ");
    scanf("%f",&vetor[c].nota);
}

printf("Ordenar por:\n");
printf("1-Matricula\n2-Nome\n3-Nota\n");
scanf("%d",&c);
switch(c){
    case 1:
    ordena_matricula(vetor);
    break;
    case 2:
    ordena_nome(vetor);
    break;
    case 3:
    ordena_nota(vetor);
    break;
    default:
    printf("Opçao invalida");
}

for(c=0;c<n;c++){
    printf("Dados da pessoa %d\n",c+1);
    printf("Matricula: %d\n",vetor[c].matricula);
    printf("Nome: %s\n",vetor[c].nome);
    printf("Nota: %.2f\n",vetor[c].nota);
}

return 0;
}


void ordena_matricula(pessoa *p){
int c,c2;
pessoa aux;
for(c=0;c<n;c++){
    aux= p[c];
    c2 = c -1;
    while(c2>=0 && p[c2].matricula>aux.matricula){
        p[c2+1] = p[c2];
        c2--;
    }
    p[c2+1] = aux;

}
printf("ORDENADO POR MATRICULA\n");


}
void ordena_nome(pessoa *p){
int c,c2;
pessoa aux;
for(c=0;c<n;c++){
    aux = p[c];
    c2 = c -1;
    while(c2>=0 && strcmp(p[c2].nome,aux.nome)>0){
    p[c2+1] = p[c2];
    c2--;
    }
    p[c2+1] = aux;
}
printf("ORDENADO POR NOME\n");
}
void ordena_nota(pessoa *p){
int c,c2;
pessoa aux;
for(c=0;c<n;c++){
    aux = p[c];
    c2 = c -1;
    while(c2>=0 && p[c2].nota>aux.nota){
    p[c2+1] = p[c2];
    c2--;
    }
    p[c2+1] = aux;
}
printf("ORDENADO POR NOTA\n");
}
﻿
