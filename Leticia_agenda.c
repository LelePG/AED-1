#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define p_pos (pessoa*)procura+20;//pra nao precisar ficar voltando

typedef struct{
char nome[20];
int telefone;
int idade;
} pessoa;

void menu(int *op);
void imprime_pessoas(void);
void remove_pessoa(void);
void adiciona_pessoa(void);
void mostra_pessoa(void);
void arruma_ponteiros(void* pBuffer);
void verifica(void* pBuffer);//alocaçao
void p_final(void);//coloca p no fim do buffer

void *pBuffer;
int *cont,*cont2,*cont_p,*op;
char *procura;//20 pos como o nome
pessoa *p;

int main(){
    pBuffer = (void*) malloc (4*sizeof(int) + 20*sizeof(char));
    verifica(pBuffer);//aloco memória para as minhas 4 variáveis
    arruma_ponteiros(pBuffer);
    *cont_p = 0;
    while(1){
        menu(op);
        switch(*op){
        	case 1:
        		adiciona_pessoa();
        		break;
        	case 2:
        		remove_pessoa();
        		break;
        	case 3:
        		imprime_pessoas();
        		break;
            case 4:
                mostra_pessoa();
                break;
        	case 5:
        		free(pBuffer);
        		return 0;
        	default:
        		printf("Opção inválida\n");

        }

   }

}



void menu (int *op){
printf("\n-----AGENDA-----\n");
printf("1- Adicionar pessoa\n");
printf("2- Remover pessoa\n");
printf("3- Imprimir lista\n");
printf("4- Imprimir pessoa\n");
printf("5- Sair\n");
scanf("%d",op);
getchar();// tira o barra n
}

void verifica(void* buffer){
if(buffer==NULL){
		printf("ERRO! Saindo do programa.\n");
		exit(1);
	}
}

void arruma_ponteiros(void* pBuffer){
    cont = pBuffer;
    cont2 = cont+1;
    cont_p = cont2+1;
    op = cont_p +1;
    procura =(char*) op+1;
    p =(pessoa*)procura+20;
}


void adiciona_pessoa(void){//tenho que lidar com a mudança de endereço, mas desisto 4 now
    *cont_p=*cont_p+1;//atualizo o contador de pessoas
    pBuffer  = (void*) realloc (pBuffer,4*sizeof(int) + 20*sizeof(char)+(*cont_p)*sizeof(pessoa));//atualizo o tamanho do buffer
    verifica(pBuffer);
    arruma_ponteiros(pBuffer);
    p_final();
    printf("Nome: ");//colect data
    scanf("%[^\n]",p->nome);
    printf("Idade: ");
    scanf("%d",&p->idade);
    printf("Telefone: ");
    scanf("%d",&p->telefone);
    printf("---NOVO INDIVÍDUO ADICIONADO---\n");
}

void p_final(void){//leva p pro final
    p = p_pos;
    for(*cont = 1;*cont<*cont_p;*cont = *cont+1){
        p++;
    }
}
void imprime_pessoas(void){//Tá funcionando direitinho
    p = p_pos;//coloca p na posição original dele pra ir avançando pelo buffer
    for(*cont =0;*cont<*cont_p;*cont=(*cont)+1){
        printf("--PESSOA %d--\n",*cont+1);//Pessoa 1,2,3...
        printf("Nome: %s\n",p->nome);
        printf("Idade: %d\n",p->idade);
        printf("Telefone : %d\n",p->telefone);
        p++;//p vai assumindo os valores que eu preciso apresentar, no final ele para no fim do buffer
    }
}

void remove_pessoa(void){//a princípio tá funcionando
    printf("Digite quem deseja excluir: ");
    scanf("%[^\n]",procura);
    p =p_pos;//coloco o ponteiro de pessoas no lugar dele
    for(*cont =0;*cont<*cont_p;*cont=(*cont)+1){//procura pelo buffer
       if(strcmp(p->nome,procura)==0){//se achou
        for(*cont2 = *cont;*cont2<*cont_p;*cont2++){
            *p = *(p+1);//puxa todas uma casa pra trás
            p++;//e avança o ponteiro
        }
        *cont_p = *cont_p -1;//arruma o contador de pessoas
        pBuffer  = (void*) realloc (pBuffer,4*sizeof(int) + 20*sizeof(char)+(*cont_p)*sizeof(pessoa));//atualizo o tamanho do buffer
        verifica(pBuffer);
        printf("-- %s EXCLUÍDO --\n",procura);
        return;
       }
    p++;
    }
    printf("Name not found");
}

void mostra_pessoa(void){
    printf("Digite o nome da pessoa que vc quer ver os dados: ");
    scanf("%[^\n]",procura);
    p =p_pos;//coloco o ponteiro de pessoas no lugar dele
    for(*cont =0;*cont<*cont_p;*cont=(*cont)+1){//procura pelo buffer
        if(strcmp(p->nome,procura)==0){//se achou
            printf("----Pessoa encontrada-----\n");
            printf("Nome : %s\n",p->nome);
            printf("Idade : %d\n",p->idade);
            printf("Telefone: %d\n",p->telefone);
            return;
        }
    p++;
    }
    printf("----Pessoa nao encontrada-----\n");
}
