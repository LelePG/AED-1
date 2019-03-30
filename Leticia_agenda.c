#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
char nome[20];
int telefone;
int idade;
} pessoa;

void menu(void);
void imprime_pessoa(void);
void remove_pessoa(void);
void adiciona_pessoa(void);

int *cont,*cont_p,*op;
void *pBuffer;
pessoa *p;
char procura_nome;

int main(){
   pBuffer = (void*) malloc (3*sizeof(int));//aloco mem�ria para as minhas tr�s vari�veis
   cont = pBuffer;
   cont_p = cont+1;
   op = cont_p +1;
   p =(pessoa*)op+1;//todas as variaveis colocadas no lugar
   *cont_p = 1;//coloca o valor na quantidade de pessoas
    while(1){
        menu();
        scanf("%d",op);
        if(*op ==1){
            adiciona_pessoa();
        }
        else if(*op==2){
            remove_pessoa();
        }
        else if(*op==3){
            imprime_pessoa();
        }
        else{
            return 0;
        }
   }

}

void menu (void){
printf("\n-----AGENDA-----\n");
printf("1- Adicionar pessoa\n");
printf("2- Remover pessoa\n");
printf("3- Imprimir lista\n");
printf("4- Sair\n");
}

void imprime_pessoa(void){//n~ao est'a funcionando.
    int c=0;//variavel pra controle
    printf("%s",(p-1)->nome);//ta adicionando os nomes.
    p = (int*)pBuffer+3;//posicao inciail do pBuffer
    for(*cont =1;*cont<*cont_p;*cont+=1){
        printf("%s",p->nome);
        printf("Idade: %d",p->idade);
        printf("Telefone : %d",p->telefone);
        p++;
        c++;
        if(c>10){
            return;
        }
    
    }
}


void remove_pessoa(void){
printf("remover");
}

void adiciona_pessoa(void){
    pBuffer  = (void*) realloc (pBuffer,3*sizeof(int)+(*cont_p)*sizeof(pessoa));
    getchar();//pra garabtir que nada vai bugar o nome
    printf("Nome: ");
    scanf("%[^\n]",p->nome);
    printf("Idade: ");
    scanf("%d",&p->idade);
    printf("Telefone: ");
    scanf("%d",&p->telefone);//usa p pra inserir os dados
    *cont_p++;//atualiza o contador do numero de pessoas
    p++;//coloca p pro final
    printf("adicionado");
}
