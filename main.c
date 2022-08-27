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
#include <process.h>
#include <locale.h>
#define TAMANHO 1000 //defini o tamanho maximo da string pois em C puro strings são vetores
#define LIMITE 6 // Limite para dividirmos em substrings depois

void maiusculo(char *stringIn,char *stringOut);// protótipo da função maiusculo.
void* computa_thread(void* id_inicio_thread); // essa função fará as chamadas de cada thread.
int main()
{

    char stringEntrada[TAMANHO],stringSAIDA[TAMANHO];
    int i=0;
    pthread_t threads_id[TAMANHO]; // esse vetor armazena o numero de ID de cada thread, em teoria uma thread pra cada caractere


    setlocale(LC_ALL,"Portuguese"); // Fução para fazer o windows ler caracteres unicode portugues
    printf("Digite uma palavra:\n");
    scanf("%[^\n]s",stringEntrada); // lê uma linha inteira ignorando os espaços

    maiusculo(stringEntrada,stringSAIDA);
    printf("A string digitada é :\n%s\n",stringSAIDA);

    pthread_exit(NULL); //essa linha serve para fazer a função main esperar a execução da thread para encerrar.
    return 0;
}
//converte cada letra da string para maiusculo até atingir o TAMANHO ou encontrar o caractere de quebra de linha '\n'
void maiusculo(char stringIn[TAMANHO],char stringOut[TAMANHO]){
    int i=0;
     do{
        stringOut[i]=toupper(stringIn[i]);
        i++;
    }while((i<TAMANHO)&& (stringOut[i]!='\n'));
}
