/**
    Autores
    Pedro Henrique Carneiro de Araújo 22108287
    Luiz Felipe Palharo 21908107
    Pedro Augusto Leite Prates 22008270
    Victor Furtado Estrada 22006647
   
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <process.h>
#include <locale.h>
#include <string.h> // possui funções para manipulação de strings.
#include "OperaString.c" // arquivo comm as funções para maiuscular a string.
#include "ModuloThreads.h"

int main()
{

    char stringEntrada[TAMANHO],stringSAIDA[TAMANHO];

    //pthread_t threads_id[TAMANHO]; // esse vetor armazena o numero de ID de cada thread, em teoria uma thread pra cada caractere
    setlocale(LC_ALL,"Portuguese"); // Fução para fazer o windows ler caracteres unicode portugues
    //incializa todas as posições com '\n' pra nao dar pau na hora de usar o len().
    for(int j=0;j<TAMANHO;j++){
        stringEntrada[j]='\n';
    }


    printf("Digite uma palavra:\n");
    scanf("%[^\n]s",stringEntrada); // lê uma linha inteira ignorando os espaços

    computa_tudo(stringEntrada,stringSAIDA);

    //computa_thread(&threads_id[0]);
    printf("A string digitada é :\n%s \ne seu tamanho é:%d\n",stringSAIDA,len(stringEntrada));

    pthread_exit(NULL); //essa linha serve para fazer a função main esperar a execução da thread para encerrar.
    return 0;
}
