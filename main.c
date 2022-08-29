/**
    Autores
    Pedro Henrique Carneiro de Ara�jo 22108287
    Luiz Felipe Palharo 21908107
    Pedro Augusto Leite Prates 22008270
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <process.h>
#include <locale.h>
#include "OperaString.c"



void* computa_thread(char* stringIN,char* stringOUT); // essa fun��o far� as chamadas de cada thread.


int main()
{

    char stringEntrada[TAMANHO],stringSAIDA[TAMANHO];
    int i=0;
    //pthread_t threads_id[TAMANHO]; // esse vetor armazena o numero de ID de cada thread, em teoria uma thread pra cada caractere
    setlocale(LC_ALL,"Portuguese"); // Fu��o para fazer o windows ler caracteres unicode portugues
    //incializa todas as posi��es com '\n' pra nao dar pau na hora de usar o len().
    for(int j=0;j<TAMANHO;j++){
        stringEntrada[j]='\n';
    }


    printf("Digite uma palavra:\n");
    scanf("%[^\n]s",stringEntrada); // l� uma linha inteira ignorando os espa�os

    computa_thread(stringEntrada,stringSAIDA);

    //computa_thread(&threads_id[0]);
    printf("A string digitada � :\n%s \ne seu tamanho �:%d\n",stringSAIDA,len(stringEntrada));

    pthread_exit(NULL); //essa linha serve para fazer a fun��o main esperar a execu��o da thread para encerrar.
    return 0;
}

void* computa_thread(char stringIN[TAMANHO],char stringOUT[TAMANHO]){
    //int id=*((int*) id_inicio_thread);//printf("fez o cast pra int\n");
    pthread_t threads_id[TAMANHO]; // esse vetor armazena o numero de ID de cada thread, em teoria uma thread pra cada caractere

    //printf("Numero de id da thread %d\n",id);

    int tamanhoString=len(stringIN);
    if(tamanhoString<=LIMITE){
        maiusculo(stringIN,stringOUT);
    }else{
        printf("String maior que limite, deve-se subdvidir e usar threads.\n");
        //pthread_create(&threads_id[0],NULL,maiusculo,&stringIN,&stringOUT);
    }


    //pthread_exit(NULL);
}

