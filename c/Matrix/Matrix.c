#include <stdio.h>
#include <stdlib.h>


//metodo importante! para liberar espaço armazenado pela locaçao dinamica.
void destructorMatriz(int **matriz, int linhas, int colunas) {//recebe como parametro: o ponteiro do ponteiro-> **matriz,// linhas e colunas.
    for (int i = 0; i < linhas; i++) {//i ->(representa as linhas) roda ate os valores de linhas
        for (int j = 0; j < colunas; j++) { //j ->(representa as linhas) roda ate os valores de colunas
            free(matriz[i][j]); //free do espaço armazenado sizeof(int) em determinada posição [i][j]
        
        }
        free(matriz); ////free do espaço armazenado sizeof(int)
    }
}

//metodo para escrever em arquivo
void sendToTxtMatrix(int **matriz, int linhas, int colunas) {
    FILE *file;
    file = fopen("Matrix.txt", "wt");
    
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; i++) {
            fprintf(file, "[%d] ", matriz[i][j]);

        }
        fprintf(file, "\n");
    }
    fclose(file);   
}

void printMatrix(int **matriz, int linhas, int colunas) { //recebe como parametro: o ponteiro do ponteiro-> **matriz,
// linhas e colunas.
    for (int i = 0; i < linhas; i++) {//i ->(representa as linhas) roda ate os valores de linhas
        for (int j = 0; j < colunas; j++) { //j ->(representa as linhas) roda ate os valores de colunas
            printf("[%d] " ,matriz[i][j]); //printf dos valores em determinada posição [i][j]
        
        }
        printf("\n"); //\n para quebrar a linha e iniciar outra
    }
}

int createMatriz(int linhas, int colunas) { //recebe como parametro , linhas e colunas.
    int **mat; //declaro um ponteiro de ponteiro

    mat = malloc(sizeof(int) * linhas); 
    
    /*locacao de memoria para n linhas, como os valores da matriz,
    são valores inteiros, armazeno espaços para inteiros -> sizeof(int)
    */

    for (int i = 0; i < linhas; i++) { 
        //para cada linha faço a locação dinamica de n colunas. sizeof(int) * colunas
        mat[i] = malloc(sizeof(int) * colunas);

    }
    //inicio de 2 laços de repetição, 
    for (int y = 0; y < linhas; y++) { //Y ->(representa as linhas) roda ate os valores de linhas 
        for (int x = 0; x < colunas; x++) { //x ->(representa as colunas) roda ate os valores de colunas
            printf("[%d] [%d]: ", y, x); //printf da posicao onde o valor da matriz sera gravado 
            scanf("%d", &mat[y][x]);
        }
        printf("\n"); //\n para quebrar a linha e iniciar outra
    }
    return mat; //retornar o valor do edereço dos valores gravados da matriz
} 

int main(void) {
    // declaro um ponteiro de ponteiro-int **matriz
    //int valor de linha e colunas.
    int **matriz, linhas, colunas; 

    /*
        do while, para que os valores sejam  maiores que 0, 
        ou seja fazer as acoes abaixo enquanto linhas ou colunas forem <= 0
    */
    do {
        //leio do teclado valores de linhas e colunas
        printf("linhas: ");
        scanf("%d", &linhas);
        printf("colunas: ");
        scanf("%d", &colunas);
   
    } while (linhas <= 0 || colunas <= 0);

    /* 
    o ponteiro do ponteiro(matriz) = creatMatriz(linhas, colunas),
     ou seja o endereço dos valores alocados na funcao. 
    */
    matriz = createMatriz(linhas, colunas);

    //chamado o metodo para printar os valores
    printMatrix(matriz, linhas, colunas);

    //gravar em arquivos
    sendToTxtMatrix(matriz, linhas, colunas);

    //chamado para liberar espaço armazenado pela locação dinamica.
    destructorMatriz(matriz, linhas, colunas);
    
}
