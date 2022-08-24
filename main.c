/**
    Autores
    Pedro Henrique Carneiro de Araújo 22108287
    Luiz Felipe Palharo 21908107
    Pedro Augusto Leite Prates 22008270
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <locale.h>
#define TAMANHO 1000
#define LIMITE 6

int main()
{

    char stringEntrada[TAMANHO],stringSAIDA[TAMANHO];
    setlocale(LC_ALL,"Portuguese");
    printf("Digite uma palavra:\n");
    scanf("%[^\n]s",stringEntrada);
    for(int i=0;i<TAMANHO;i++){
        stringSAIDA[i]=toupper(stringEntrada[i]);
    }
    printf("A string digitada é :\n%s\n",stringSAIDA);
    return 0;
}
