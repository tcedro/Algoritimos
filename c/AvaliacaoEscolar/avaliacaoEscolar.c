#include <stdio.h>
#include <stdlib.h>

typedef struct {
    
    int matricula;
    float *provas, frequencia, total;
    

}Aluno;

void imprimeAluno(Aluno aluno) {
    printf("====================================\n");
        
    printf("matricula: %d\n", aluno.matricula);
        
    printf("nota1: %.2f\n", aluno.provas[0]);
    printf("nota2: %.2f\n", aluno.provas[1]);
    printf("nota3: %.2f\n", aluno.provas[2]);
    printf("total: %.2f\n", aluno.total);

    printf("frequencia: %.2f\n", aluno.frequencia);
    
    if(aluno.total < 60) { printf("Aluno reprovado por nota!\n");}
    
    else if(aluno.frequencia < 80) { printf("Aluno reprovado por falta!\n");} 
    
    else { printf("Aluno aprovado!\n");}

}

void matricularAluno(Aluno *aluno, int n) {
    for (int i = 0; i < n; i++){
        printf("====================================\n");
        printf("Matricula: ");
        scanf("%d", &aluno[i].matricula);
        
        aluno[i].provas = malloc(sizeof(float) * 3); 
        
        printf("prova1: ");
        scanf("%f", &aluno[i].provas[0]);
        printf("prova2: ");
        scanf("%f", &aluno[i].provas[1]);
        printf("prova3: ");
        scanf("%f", &aluno[i].provas[2]);
        
        aluno[i].total = aluno[i].provas[0] + aluno[i].provas[1] + aluno[i].provas[2];
        
        printf("freq: ");
        scanf("%f", &aluno[i].frequencia);
        
    }
}

void desalocarMallocs(int n, Aluno *aluno) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            free(aluno[i].provas);
        }
    }
    free(aluno);
} 

void print(Aluno *aluno, int n) {
    for (int i = 0; i < n; i++){
        imprimeAluno(aluno[i]);
        printf("\n");
    }
}

int getAlunos() {
    int n;

    do {
        printf("Quantos alunos: ");
        scanf("%d", &n);
    } while (n <= 0);
    
    return n;
}


int main() {
    int n = getAlunos();

    Aluno *aluno = malloc(sizeof(int) * n);

    matricularAluno(aluno, n);

    print(aluno, n);
    
    return 0;
}