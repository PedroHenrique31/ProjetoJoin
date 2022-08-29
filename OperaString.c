#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <process.h>
#include <locale.h>
#define TAMANHO 1000 //defini o tamanho maximo da string pois em C puro strings são vetores
#define LIMITE 3 // Limite para dividirmos em substrings depois


void maiusculo(char *stringIn,char *stringOut);// protótipo da função maiusculo.
int len(char *stringIN); // recebe uma string e retorna seu tamanho, para nós podermos dividir.

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
//converte cada letra da string para maiusculo até atingir o TAMANHO ou encontrar o caractere de quebra de linha '\n'
void maiusculo(char stringIn[TAMANHO],char stringOut[TAMANHO]){
    int i=0;
     do{
        stringOut[i]=toupper(stringIn[i]);
        i++;
    }while((i<TAMANHO)&& (stringOut[i]!='\n'));
}
