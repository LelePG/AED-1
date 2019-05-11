
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define p_pos (pessoa*)procura+1;//Definindo a posicao de p porque uso isso varias vezes no codigo

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
void arruma_ponteiros(void* pBuffer);//coloca os ponteiros no lugar
void verifica(void* pBuffer);//verifica alocaçao
void p_final(void);//coloca p no fim do buffer
//ordenaçao por nome
void ordena_insertion(void);
void ordena_bubble(void);
void ordena_selection(void);
void ordena_merge(void);
void ordena_quick(void);

void *pBuffer;
int *cont,*cont2,*cont_p,*op;
pessoa *procura;//variavel auxiliar
pessoa *p;

int main(){
    pBuffer = (void*) malloc (4*sizeof(int) + sizeof(pessoa));//a variavel pessoa alocada aqui eh a minha auxiliar
    verifica(pBuffer);
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
        		ordena_insertion();
       		break;
         case 6:
            ordena_bubble();
            break;
         case 7:
        		ordena_selection();
        		break;
         case 8:
            ordena_merge();
            break;
        	case 9:
        		ordena_quick();
        		break;
        	case 10:
        		free(pBuffer);
        		return 0;
        	default:
        		printf("Opção inválida\n");

        }

   }

}


void menu (int *op){//OK
printf("\n-----AGENDA-----\n");
printf("1- Adicionar pessoa\n");
printf("2- Remover pessoa\n");
printf("3- Imprimir lista\n");
printf("4- Imprimir pessoa\n");
printf("5- Ordena com Insertion Sort\n");
printf("6- Ordena com Bubble Sort\n");
printf("7- Ordena com Selection Sort\n");
printf("8- Ordena com Merge Sort\n");
printf("9- Ordena com Quick Sort\n");
printf("10- Sair\n");
scanf("%d",op);
getchar();// tira o barra n
}
void verifica(void* buffer){//OK
if(buffer==NULL){
		printf("----ERRO! SAINDO DO PROGRAMA.----\n");
		exit(1);
	}
}
void arruma_ponteiros(void* pBuffer){//OK
    cont = pBuffer;
    cont2 = cont+1;
    cont_p = cont2+1;
    op = cont_p +1;
    procura =(pessoa*) op+1;//vou usar como variavel pessoa auxiliar
    p =(pessoa*)procura+1;
}
void adiciona_pessoa(void){//OK
    *cont_p=*cont_p+1;//atualizo o contador de pessoas
    pBuffer  = (void*) realloc (pBuffer,4*sizeof(int)+sizeof(pessoa) +(*cont_p)*sizeof(pessoa));//atualizo o tamanho do buffer
    //Por algum motivo preciso sempre que eu for usar o cont_p no realloc preciso usar o tamanho de cont_p+1 ou dá erro.
    verifica(pBuffer);
    arruma_ponteiros(pBuffer);
    p_final();//p tem que ir pro final pra mim adicionar a nova pessoa na ultima posicao
    printf("Nome: ");//colect data
    scanf("%[^\n]",p->nome);
    printf("Idade: ");
    scanf("%d",&p->idade);
    printf("Telefone: ");
    scanf("%d",&p->telefone);
    printf("---NOVO INDIVÍDUO ADICIONADO---\n");
}
void p_final(void){//OK
    p = p_pos;
    for(*cont = 1;*cont<*cont_p;*cont = *cont+1){
        p++;
    }
}
void imprime_pessoas(void){//OK
    p = p_pos;//coloca p na posição original dele pra ir avançando pelo buffer
    for(*cont =0;*cont<*cont_p;*cont=(*cont)+1){
        printf("---PESSOA %d---\n",*cont+1);//Pessoa 1,2,3...
        printf("Nome: %s\n",p->nome);
        printf("Idade: %d\n",p->idade);
        printf("Telefone : %d\n",p->telefone);
        p++;//p vai assumindo os valores que eu preciso apresentar, no final ele para no fim do buffer
    }
}
void remove_pessoa(void){//OK
    printf("Digite quem deseja excluir: ");
    scanf("%[^\n]",procura->nome);
    p =p_pos;//coloco o ponteiro de pessoas no lugar dele
    for(*cont =0;*cont<*cont_p;*cont=(*cont)+1){//procura pelo buffer
       if(strcmp(p->nome,procura->nome)==0){//se achou
        for(*cont2 = *cont;*cont2<*cont_p;*cont2++){
            *p = *(p+1);//puxa todas uma casa pra trás
            p++;//e avança o ponteiro
        }
        pBuffer  = (void*) realloc (pBuffer,4*sizeof(int) +sizeof(pessoa)+(*cont_p)*sizeof(pessoa));//atualizo o tamanho do buffer.
        //Por algum motivo preciso sempre que eu for usar o cont_p no realloc preciso usar o tamanho de cont_p+1 ou dá erro, por isso decremento depois.
        *cont_p = *cont_p -1;
        verifica(pBuffer);
        arruma_ponteiros(pBuffer);
        printf("-- %s EXCLUÍDO --\n",procura->nome);
        return;
       }
    p++;
    }
    printf("----PESSOA NÃO ENCONTRADA----");
}
void mostra_pessoa(void){//OK
    printf("Digite o nome da pessoa que vc quer ver os dados: ");
    scanf("%[^\n]",procura->nome);
    p =p_pos;//coloco o ponteiro de pessoas no lugar dele
    for(*cont =0;*cont<*cont_p;*cont=(*cont)+1){//procura pelo buffer
        if(strcmp(p->nome,procura->nome)==0){//se achou
            printf("----PESSOA ENCONTRADA-----\n");
            printf("Nome : %s\n",p->nome);
            printf("Idade : %d\n",p->idade);
            printf("Telefone: %d\n",p->telefone);
            return;
        }
    p++;
    }
    printf("----PESSOA NÃO ENCONTRADA-----\n");
}
void ordena_insertion(void){//OK
p = p_pos;
for(*cont =0;*cont<*cont_p;(*cont)++){
    *procura = *(p + (*cont));
    *cont2 = *cont -1;
      while ((*cont2) >= 0 && strcmp((p+(*cont2))->nome,procura->nome)>0) {
        *(p +*cont2+1) = *(p+*cont2);//copio uma pessoa pro lugar da outra, nao precisa strcpy
        (*cont2)--;
      }

      *(p+1+*cont2) = *procura;
   }
printf("-----LISTA ORDENADA COM INSERTION SORT-----\n");
}
void ordena_bubble(void){//OK
    p=p_pos;
    for(*cont = 0;*cont < *cont_p-1;(*cont)++){
        for(*cont2 = 0;*cont2<*cont_p-1;(*cont2)++){
            if(strcmp((p+*cont2)->nome,(p+*cont2+1)->nome)>0){
                *procura = *(p+*cont2+1);
                *(p+*cont2+1) = *(p+*cont2);
                *(p+*cont2) = *procura;
            }
        }
    }
    printf("-----LISTA ORDENADA COM BUBBLE SORT-----\n");;

}
void ordena_selection(void){//OK
//posso usar op que seleciona a operaçao aqui dentro como variavel, porque a proxima vez que usar ela vai ser inserindo outro valor
   p=p_pos;
    for(*cont =0;*cont<*cont_p-1;(*cont)++){
        *op = *cont;
        for(*cont2 = (*cont)+1;*cont2<*cont_p;(*cont2)++){
            if(strcmp((p+*cont2)->nome,(p+*op)->nome)<0){
                *op = *cont2;
            }
        }
    *procura =*(p+*op);
    *(p+*op) = *(p+*cont);
    *(p+*cont) = *procura;
    }
printf("-----LISTA ORDENADA COM SELECTION SORT-----\n");
}

void ordena_merge(void){//FAZER
printf("-----LISTA ORDENADA COM MERGE SORT-----\n");
}
void ordena_quick(void){//FAZER
printf("-----LISTA ORDENADA COM QUICK SORT-----\n");
}

