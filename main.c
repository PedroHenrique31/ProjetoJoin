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
#include <locale.h>
#define TAMANHO 1000 //defini o tamanho maximo da string pois em C puro strings s�o vetores
#define LIMITE 6 // Limite para dividirmos em substrings depois

void maiusculo(char *stringIn,char *stringOut);// prot�tipo da fun��o maiusculo.
int main()
{

    char stringEntrada[TAMANHO],stringSAIDA[TAMANHO];
    int i=0;
    setlocale(LC_ALL,"Portuguese"); // Fu��o para fazer o windows ler caracteres unicode portugues
    printf("Digite uma palavra:\n");
    scanf("%[^\n]s",stringEntrada); // l� uma linha inteira ignorando os espa�os

    maiusculo(stringEntrada,stringSAIDA);
    printf("A string digitada � :\n%s\n",stringSAIDA);
    return 0;
}
//converte cada letra da string para maiusculo at� atingir o TAMANHO ou encontrar o caractere de quebra de linha '\n'
void maiusculo(char stringIn[TAMANHO],char stringOut[TAMANHO]){
    int i=0;
     do{
        stringOut[i]=toupper(stringIn[i]);
        i++;
    }while((i<TAMANHO)&& (stringOut[i]!='\n'));
    return stringOut;
}
