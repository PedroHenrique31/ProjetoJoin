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
#define LIMITE 3 // Limite para dividirmos em substrings depois

void maiusculo(char *stringIn,char *stringOut);// protótipo da função maiusculo.
void* computa_thread(char* stringIN,char* stringOUT); // essa função fará as chamadas de cada thread.
int len(char *stringIN); // recebe uma string e retorna seu tamanho, para nós podermos dividir.

int main()
{

    char stringEntrada[TAMANHO],stringSAIDA[TAMANHO];
    int i=0;
    //pthread_t threads_id[TAMANHO]; // esse vetor armazena o numero de ID de cada thread, em teoria uma thread pra cada caractere
    setlocale(LC_ALL,"Portuguese"); // Fução para fazer o windows ler caracteres unicode portugues
    //incializa todas as posições com '\n' pra nao dar pau na hora de usar o len().
    for(int j=0;j<TAMANHO;j++){
        stringEntrada[j]='\n';
    }


    printf("Digite uma palavra:\n");
    scanf("%[^\n]s",stringEntrada); // lê uma linha inteira ignorando os espaços

    computa_thread(stringEntrada,stringSAIDA);

    //computa_thread(&threads_id[0]);
    printf("A string digitada é :\n%s \ne seu tamanho é:%d\n",stringSAIDA,len(stringEntrada));

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
void* computa_thread(char stringIN[TAMANHO],char stringOUT[TAMANHO]){
    //int id=*((int*) id_inicio_thread);//printf("fez o cast pra int\n");
    pthread_t threads_id[TAMANHO]; // esse vetor armazena o numero de ID de cada thread, em teoria uma thread pra cada caractere

    //printf("Numero de id da thread %d\n",id);

    int tamanhoString=len(stringIN);
    if(tamanhoString<=LIMITE){
        maiusculo(stringIN,stringOUT);
    }else{
        printf("String maior que limite, deve-se subdvidir e usar threads.\n");
        pthread_create(&threads_id[0],NULL,maiusculo,&stringIN,&stringOUT);
    }


    //pthread_exit(NULL);
}
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
