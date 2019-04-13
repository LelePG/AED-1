//Implemente a seguinte função.A função deve imprimir os valores que estão no
//buffer passado por parâmetro. Os valores estão intercalados
//na seguinte ordem: int, float, double. A variável nTotal indica o total de trios (int, float e double) no buffer.

//Letícia Pegoraro Garcez

#include <stdio.h>
#include <stdlib.h>
typedef struct {
int i;
float f;
double d;
}tripla;

void imprimeBuffer(void *pBuffer, unsigned int nTotal);
void preencheBuffer(void *pBuffer, unsigned int nTotal);

int main()
{
   void *pBuffer;
   int nTotal;
   printf("Quantos conjuntos quer adicionar no buffer?");
   scanf("%d",&nTotal);
   pBuffer = (void*) malloc (nTotal*(sizeof(tripla)));
	if (pBuffer == NULL){//se não alocou sai do programa
	printf("ERRO");
	exit(1);
	}
   preencheBuffer(pBuffer,nTotal);
   imprimeBuffer(pBuffer,nTotal);
   free(pBuffer);
}

void imprimeBuffer(void *pBuffer, unsigned int nTotal){
	tripla *t;
	t = pBuffer;//contador display
	printf("\n\n---IMPRIMINDO BUFFER ---\n\n");
	for(int c=0;c<nTotal;c++){
		printf("\n--Tripla número %d--\n",c+1);
		printf("Inteiro: %d\n",t->i);
		printf("Float: %f\n",t->f);
		printf("Double: %lf\n",t->d );
		t++;//atualiza o contador display
	}
}

void preencheBuffer(void *pBuffer, unsigned int nTotal){
	tripla *t;
	t = pBuffer;//contador display
	for(int c=0;c<nTotal;c++){
        printf("-- INSIRA TRIPLA %d --\n",c+1);
		printf("Digite um inteiro:\n");
		scanf("%d",&t->i);
		printf("Digite um float: \n");
		scanf("%f",&t->f);
		printf("Digite um double: \n");
		scanf("%lf",&t->d);
		t++;//atualiza o contador display
	}
}
