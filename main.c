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
#include <string.h> // possui funções para manipulação de strings.
#include "OperaString.c" // arquivo comm funções para tratar as strings.


// Essa struct será usada para passarmos ambas as strings por apenas um parâmetro.
typedef struct Strings{
    char *stringIN;
    char *stringOUT;
}Strings;

void encapsulaMaiuscula(Strings *parametro);
void* computa_tudo(char* stringIN,char* stringOUT); // essa função fará as chamadas de cada thread.


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

void* computa_tudo(char stringIN[TAMANHO],char stringOUT[TAMANHO]){
    //int id=*((int*) id_inicio_thread);//printf("fez o cast pra int\n");
    pthread_t threads_id[TAMANHO]; // esse vetor armazena o numero de ID de cada thread, em teoria uma thread pra cada caractere
    Strings param;
    char parteDaString[TAMANHO];

    //printf("Numero de id da thread %d\n",id);

    int tamanhoString=len(stringIN);
    if(tamanhoString<=LIMITE){
        maiusculo(stringIN,stringOUT);
    }else{
        printf("String maior que limite, deve-se subdvidir e usar threads.\n");

        int numOps=tamanhoString/LIMITE,deslocamento=0;printf("serão usadas: %d operações\n",numOps);

        for(int a=0;a<numOps;a++){
            deslocamento=a*LIMITE; // anda de 3 em caracteres.
            strncpy(parteDaString,stringIN+deslocamento,LIMITE);parteDaString[LIMITE+1]='\0';
            printf("parte da string: %s\n",parteDaString);
        }

        param.stringIN=stringIN;
        param.stringOUT=stringOUT;

        //encapsulaMaiuscula(&param);
        pthread_create(&threads_id[0],NULL,encapsulaMaiuscula,&param);
    }


    //pthread_exit(NULL);
}
void encapsulaMaiuscula(Strings *parametro){
    char *strIN=NULL,*strOUT=NULL;

    strIN=parametro->stringIN;
    strOUT=parametro->stringOUT;

    maiusculo(strIN,strOUT);
    printf("encapsular maiusuclo gerou:\n%s \n",strOUT);// so pra ver
}

