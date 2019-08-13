#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TipoAluno{
	char nome[50];
	int matricula;
	float coeficiente;
}TAluno;

void menu (int *op, int *sair){
	fflush(stdin);
	printf("============ Sistema de Cadastro ===========\n");
	printf("\nMENU\n");
	printf("1 Incluir Aluno\n");
	printf("2 Consultar Aluno\n");
	printf("3 Excluir Aluno\n");
	printf("4 Sair\n");
	printf("Qual operaçao quer realizar? \n");
	scanf("\n%d", op);

}

int *checkmatricula(int matricula,TAluno *aluno, int qtdea){
	int i=0,temp = qtdea; 
	while(temp!=0){
		temp--;
		if(matricula==aluno[i].matricula){
			printf("Matricula ja cadastrada\n");
			return 0;
		}else{
			aluno[i].matricula = matricula;
			i++;
			return 1;
		}
	}
}

void Cad_aluno(int qtdea, TAluno *aluno){
	int matricula=0, i=0, check;
	while(qtdea>0){
	printf("Digite a matricula do aluno: ");
	scanf("\n%i", &matricula);
	check = checkmatricula(matricula,aluno,qtdea);
	if(check){
	printf("Digite o nome do aluno: ");
	scanf("\n%s", &aluno[i].nome);
	printf("Digite o coeficiete do aluno: ");
	scanf("\n%f", &aluno[i].coeficiente);
	qtdea--;
		}
		//printf("%s\n %i\n %f\n", temp->nome, temp->matricula, temp->coeficiente);
		//aluno[i] = temp;
		i++;
		printf("%s\n %i\n %f\n", aluno[i].nome, aluno[i].matricula, aluno[i].coeficiente);
	}
}

void cons_aluno (TAluno *aluno, int qtdea){
	int i, matricula;
	printf("Digite o numero da matricula do aluno que deseja procurar: ");
	scanf("\n%i", &matricula);
	for(i=0; i<qtdea; i++){
		if(matricula==aluno[i].matricula){
			printf("\n%s %i %f", aluno[i].nome, aluno[i].matricula, aluno[i].coeficiente);
		}else{
			printf("Matricula nao cadastrada!!");
		}
	}
	
}

int main (){
	TAluno *aluno;
	int qtdea, *op,*sair=1;
	printf("Digite a quantidade de alunos: ");
	scanf("%i", &qtdea);
	aluno = (TAluno *)malloc(sizeof(TAluno)*qtdea);
	menu(&op,&sair);
	if(op==4){
		sair=0;
	}
	while(sair>0){
		if(op == 1){
			Cad_aluno(qtdea,&aluno);
			menu(&op,&sair);
			printf("%s\n %i\n %f\n", aluno[0].nome, aluno[0].matricula, aluno[0].coeficiente);
			if(op==4){
				sair=0;
			}
		}else if(op == 2){
			cons_aluno(aluno,qtdea);
			menu(&op,&sair);
			if(op==4){
				sair=0;
			}	
/*		}else if(op == 3){
			del_aluno();
	*/	}else if(op>3){
			printf("operacao invalida");
			menu(&op,&sair);
			if(op==4){
				sair=0;
			}
		}
	}
	return 0;
}