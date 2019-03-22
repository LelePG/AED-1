
/*7) Faça um programa que lê n números decimais (n fornecido pelo
usuário), armazenando-os em um vetor. Logo após, uma função deve
retirar os números duplicados que eventualmente possam existir neste
vetor, deixando apenas uma ocorrência de cada número. Ao final, o vetor
resultante deve ser impresso na tela.
*/
#include<stdio.h>
#include<stdlib.h>

int retira_duplicado(float* v, int n);

int main(){
int n;
float *vetor;
printf("Quantos números?");
scanf("%d",&n);
vetor = (float*) malloc (n*sizeof(float));
for(int c=0;c<n;c++){
    printf("Preencha a posição %d do vetor. ",c);
    scanf("%f",vetor+c);
}

n = retira_duplicado(vetor,n);// a funçao retorna o tamanho do vetor atualizado.
for(int c=0;c<n;c++){
    printf("%.2f\n",*(vetor+c));
}

return 0;
}


int retira_duplicado(float* v, int m){
float x;
int i,j,c;
for(i=0;i<m;i++){
    x = *(v+i);//pega o numero 
    for(j=i+1;j<m;j++){//compara com o resto do vetor,começando na posiçao a frente do numero que eu tava comparando
		if(v[j]==x){//só arruma uma posição por vez
			for(c =j;c<m;c++){//se é igual puxa todos os outros elementos uma posição pra tras
				v[c]=v[c+1];
			}
			m--;//atualiza a variavel do tamanho, porque eu vou excluir a ultima position
			v = (float*) realloc (v,m*sizeof(float));//arruma o tamanho do vetor. O valor de n eh menor do que o valor que estava antes sooo vai deletar a ultima posiçao.
			j--;//preciso fazer isso porque mudei o que tinha na posicao j quando puxei tudo pra tras.
		}
				
    }
}

return m;
}
