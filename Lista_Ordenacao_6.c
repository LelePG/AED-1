#include<stdio.h>
#include<stdlib.h>

int n=5;//tamanho do vetor
 int main(int argc, char const *argv[])
{
	int *v = (int*) malloc (n*sizeof(int));
	int c,inserir,c2;
	printf("Insira um vetor ordenado de %d posiçoes:\n",n);

	for(c=0;c<n;c++){
		scanf("%d",&v[c]);
	}

	printf("Numero a ser inserido:\n");
	scanf("%d",&inserir);

	v = (int*) realloc(v,(n+1)*sizeof(int));//nao funciona pra inserir no inicio e no fim
	for(c=-1;c<n;c++){//inicio em -1 pra poder inserir alguma coisa no primeiro elemento do vetor
		if(v[c]<inserir && v[c+1]>inserir){
			for(c2 = n;c2>c+1;c2--){
				v[c2] = v[c2-1];
			}
			v[c+1] = inserir;
			break;
		}
		else if(inserir>v[n-1] ){//caso tenha que inserir o numero na ultima posicao(n eh a nova posicao que eu criei entao vai estar vazia)
			v[n] = inserir;
			break;
		}
	}

    printf("Vetor ordenado:\n");
	for(c=0;c<n+1;c++){
		printf("%d\n",v[c]);
	}
}
