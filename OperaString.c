#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <process.h>
#include <locale.h>
#include "OperaString.h"
#include "ModuloThreads.h"


//void maiusculo(char *stringIn,char *stringOut);// prot�tipo da fun��o maiusculo.
//int len(char *stringIN); // recebe uma string e retorna seu tamanho, para n�s podermos dividir.

int len(char stringIN[TAMANHO]){
    int tam=0;
    _Bool ehOfimLinha=(stringIN[tam]=='\n');
    _Bool ehLimiteString=(tam==TAMANHO);

    while(!ehLimiteString && !ehOfimLinha){
        tam++;
        ehOfimLinha=(stringIN[tam]=='\n');
        ehLimiteString=(tam==TAMANHO);
    }
    return tam;
}
//converte cada letra da string para maiusculo at� atingir o TAMANHO ou encontrar o caractere de quebra de linha '\n'
void maiusculo(char stringIn[TAMANHO],char stringOut[TAMANHO]){
    int i=0;
     do{
        stringOut[i]=toupper(stringIn[i]);
        i++;
    }while((i<TAMANHO)&& (stringOut[i]!='\n'));
}
