#include <stdlib.h>
#include <stdio.h>

typedef struct{
	char nome[30];
	float nota[3];
}Disciplina;

typedef struct{
	char nome[30];
	int matricula;
	Disciplina disciplinas[5];
}Aluno;

Aluno* alocaTurma(int alunos){
	Aluno* turma;
	turma=calloc(sizeof(Aluno), alunos);
	return turma;
}

void LeTurma(Aluno* alunos, int n){
	int i, j;
	char disciplina[30];
	printf("Turma possui %d alunos \n Insira seus nomes e matrícula: " , n);
	for(i=0; i<n; i++){
		fgets(alunos[i].nome , 30, stdin);
		fgets(alunos[i].matricula , 30, stdin);
	}
	for(i=0; i<5; i++){
		printf("Agr o nome da matéria %d : " , i);
		fgets(disciplina, 30, stdin);
		for(j=0; j<n; j++){
			alunos[j].disciplinas[i].nome=disciplina;	
		}
	}
	for(i=0; i<n; i++){
		printf("nota do aluno #%d" , n);
		scanf("%f" ,&alunos[i].disciplinas[ /// AHHHH cabou o tempo.... :(((
	}
}

int main(){
	Aluno *Turma;
	int n, i;
	float media;
	
	printf("Digite o numero de alunos: \n");
	scanf("%d" , &n);	
	
	Turma=alocaTurma(n);
	LeTurma(Turma , n);
	
	return 0;
}
