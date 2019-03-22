/*Criar um tipo abstrato de dados que represente uma pessoa, contendo nome, 
 * data de nascimento e CPF. Crie uma variável que 
 *é um ponteiro para este TAD (no programa principal).
 *Depois crie uma função que receba este ponteiro e 
 *preencha os dados da estrutura e também uma uma função que receba 
 *este ponteiro e imprima os dados da estrutura. 
 *Finalmente, faça a chamada a esta função na função principal.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct data{
	int dia,mes,ano;
	}data;

typedef struct individuo{
	char nome[50];
	data nascimento;
	char cpf[14];//cpf com pontos e traço
	}individuo;
	
void imprime(individuo *p);
void preencha(individuo *p);


int main(){
	individuo *pessoa = (individuo*)malloc(sizeof(individuo));
	preencha(pessoa);
	imprime(pessoa);
	return 0;
	}
	
void preencha(individuo *p){
	printf("Digite o nome: ");
	scanf("%[^\n]",p->nome);
	printf("Digite a data de nascimento separada por espaços (dd mm aaaa) : ");
	scanf("%d %d %d",&p->nascimento.dia,&p->nascimento.mes,&p->nascimento.ano);
	printf("Digite o cpf: ");
	scanf("%s",p->cpf);
	}

void imprime(individuo *p){
	printf("A pessoa física %s, portador do cpf %s,\nnasceu em %d/%d/%d. ",p->nome,p->cpf,p->nascimento.dia,p->nascimento.mes,p->nascimento.ano);
	}
