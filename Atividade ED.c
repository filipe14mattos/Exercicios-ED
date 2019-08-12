#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TipoAluno{
	char nome[50];
	int matricula;
	float coeficiente;
}TAluno;

void Cad_aluno(TAluno *aluno){
	int matricula;
	printf("Digite a matricula do aluno: ");
	scanf("\n%i", &matricula);
	checkmatricula(matricula, aluno);
}

int main (){
	TAluno *aluno;
	int qtdea, *fim;
	printf("Digite a quantidade de alunos: ");
	scanf("%i", &qtdea);
	aluno = malloc(qtdea*sizeof(TAluno));
	fim = 0;
	menu
}