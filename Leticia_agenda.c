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

int main(){
   pBuffer = (void*) malloc (3*sizeof(int));//aloco mem�ria para as minhas tr�s vari�veis
   cont = pBuffer;
   cont_p = cont+1;
   op = cont_p +1;
   p =op+1;//todas as variaveis colocadas no lugar
   *cont_p = 0;//coloca o valor na quantidade de pessoas
    while(1){
        menu();
        scanf("%d",op);
        getchar();//tira o \n
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

void imprime_pessoa(void){
    p = op+1;//coloca p na posição original dele pra ir avançando ele pelo buffer
   /* *cont = 0;
    do{
        printf("--PESSOA %d--\n",*cont+1);
        printf("Nome: %s\n",p->nome);
        printf("Idade: %d\n",p->idade);
        printf("Telefone : %d\n",p->telefone);
        p++;//p vai assumindo os valores que eu preciso ir arrumando
        *cont=*cont+1;
    }while(*cont!=*cont_p);
    */
    for(*cont =0;*cont<*cont_p;*cont=(*cont)+1){
        printf("--PESSOA %d--\n",*cont+1);
        printf("Nome: %s\n",p->nome);
        printf("Idade: %d\n",p->idade);
        printf("Telefone : %d\n",p->telefone);
        p++;//p vai assumindo os valores que eu preciso ir arrumando
    }
}


void remove_pessoa(void){//a princípio tá funcionando, mas em algum momento buga um dos contadores...
char compara[20];//só pra fazer a função funcionar;
printf("Digite quem deseja excluir: ");
scanf("%[^\n]",compara);
 p = op+1;//coloco o ponteiro de pessoas no lugar dele
 for(*cont =0;*cont<*cont_p;*cont=(*cont)+1){
       if(strcmp(p->nome,compara)==0){//se é igual
        for(int c = *cont;c<*cont_p;c++){
            p = p+c;//puxa todas uma casa pra trás
        }
        *cont_p = *cont_p -1;//arruma o contador de pessoas
        pBuffer  = (void*) realloc (pBuffer,3*sizeof(int)+(*cont_p)*sizeof(pessoa));//realoca o buffer
        return;
       }
    }
}


void adiciona_pessoa(void){//terceira pessoa adicionada o valor fica estranho, mas não muda nenhum endereço....
    *cont_p=*cont_p+1;//atualizo o contador de pessoas
    pBuffer  = (void*) realloc (pBuffer,3*sizeof(int)+(*cont_p)*sizeof(pessoa));//atualizo o tamanho do vetor
    printf("Nome: ");//colect data
    scanf("%[^\n]",p->nome);
    printf("Idade: ");
    scanf("%d",&p->idade);
    printf("Telefone: ");
    scanf("%d",&p->telefone);
    p++;//p is buffer's last position
    printf("---NOVO INDIVÍDUO ADICIONADO---\n");
}
