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

int *cont,*cont2,*cont_p,*op;
void *pBuffer;
pessoa *p;

int main(){
   pBuffer = (void*) malloc (4*sizeof(int));//aloco mem�ria para as minhas 4 vari�veis
   cont = pBuffer;
   cont2 = cont+1;
   cont_p = cont2+1;
   op = cont_p +1;
   p =op+1;//todas as variaveis colocadas no lugar
   *cont_p = 0;//coloca o valor na quantidade de pessoas
    while(1){
        menu();
        scanf("%d",op);
        getchar();//tira o \n que buga a entrada do nome
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

void imprime_pessoa(void){//Tá funcionando direitinho
    p = op+1;//coloca p na posição original dele pra ir avançando pelo buffer
    for(*cont =0;*cont<*cont_p;*cont=(*cont)+1){
        printf("--PESSOA %d--\n",*cont+1);//Pessoa 1,2,3...
        printf("Nome: %s\n",p->nome);
        printf("Idade: %d\n",p->idade);
        printf("Telefone : %d\n",p->telefone);
        p++;//p vai assumindo os valores que eu preciso apresentar, no final ele para no fim do buffer
    }
}


void remove_pessoa(void){//a princípio tá funcionando, mas o cont_p tá ficando meio louco.
char compara[20];//ok funciona, como eu tiro isso daqui ahora;
printf("Digite quem deseja excluir: ");
scanf("%[^\n]",compara);
 p = op+1;//coloco o ponteiro de pessoas no lugar dele
 for(*cont =0;*cont<*cont_p;*cont=(*cont)+1){//procura pelo buffer
       if(strcmp(p->nome,compara)==0){//se achou
        for(*cont2 = *cont;*cont2<*cont_p;*cont2++){
            p = p+*cont2;//puxa todas uma casa pra trás
        }
        *cont_p = *cont_p -1;//arruma o contador de pessoas
        pBuffer  = (void*) realloc (pBuffer,4*sizeof(int)+(*cont_p)*sizeof(pessoa));//realoca o buffer, excluindo a última posição que vai ter lixo
        printf("-- %s EXCLUÍDO --\n",compara);
        return;
       }
    }
}


void adiciona_pessoa(void){//terceira pessoa adicionada o valor fica estranho, mas não muda nenhum endereço....
    *cont_p=*cont_p+1;//atualizo o contador de pessoas
    pBuffer  = (void*) realloc (pBuffer,4*sizeof(int)+(*cont_p)*sizeof(pessoa));//atualizo o tamanho do buffer
    printf("Nome: ");//colect data
    scanf("%[^\n]",p->nome);
    printf("Idade: ");
    scanf("%d",&p->idade);
    printf("Telefone: ");
    scanf("%d",&p->telefone);
    p++;//p is buffer's last position
    printf("---NOVO INDIVÍDUO ADICIONADO---\n");
}
