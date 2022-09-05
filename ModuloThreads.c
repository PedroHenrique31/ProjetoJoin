#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <process.h>
#include <locale.h>
#include <string.h> // possui funções para manipulação de strings.
#include "ModuloThreads.h"
#define TAMANHO 1000 //defini o tamanho maximo da string pois em C puro strings são vetores
#define LIMITE 3 // Limite para dividirmos em substrings depois

void* computa_tudo(char stringIN[TAMANHO],char stringOUT[TAMANHO]){
    //int id=*((int*) id_inicio_thread);//printf("fez o cast pra int\n");
    pthread_t threads_id[TAMANHO]; // esse vetor armazena o numero de ID de cada thread, em teoria uma thread pra cada caractere
    Strings param;
    char parteDaString[TAMANHO],conjuntoDeStrings[TAMANHO][TAMANHO];// Uma matriz gigantesca para acomodar as strings.

    //printf("Numero de id da thread %d\n",id);

    int tamanhoString=len(stringIN);
    if(tamanhoString<=LIMITE){
        maiusculo(stringIN,stringOUT);
    }else{
        printf("String maior que limite, deve-se subdvidir e usar threads.\n");

        int numOps=(tamanhoString/LIMITE)+1,deslocamento=0;printf("serão usadas: %d operações\n",numOps);

        /* Esse trecho realizará partição da string em numOps partes e atribuirá a cada uma uma thread
         * Cada resultado de encaspulaMaiuscula sera escrito numa linha da matriz conjuntoDeStrings.
         */
        for(int a=0;a<numOps;a++){
            deslocamento=a*LIMITE; // anda de 5 em caracteres.
            strncpy(parteDaString,stringIN+deslocamento,LIMITE);// pega os primeiros LIMITE caracteres
            parteDaString[LIMITE+1]='\0';//adiciona null ao final da para ela ser uma string
            /*adiciona a string em param, pra passarmos para funcao encapsula maiuscula*/
            param.stringIN=parteDaString;printf("parteDaString: %s ",parteDaString);
            param.stringOUT=conjuntoDeStrings[a];// passa uma linha de conjuntoDeStrings para param
            pthread_create(&threads_id[a],NULL,encapsulaMaiuscula,&param);
            printf("Criada na thread:%d\n",threads_id[a]);
        }
        // aqui será dado numOps comandos de join, para o programa esperar as numOps threads terminarem.
        for(int i=0;i<numOps;i++){
            pthread_join(threads_id[i],NULL);
        }
        printf("Agora veremos como esta o texto escrito na matriz\n");
        int m=0;
        for(int i=0;i<numOps;i++){
            printf("%s\n",conjuntoDeStrings[i]);
        }
        //printf("numero de caracteres na matriz:%d\n",len(parteDaString));

        //encapsulaMaiuscula(&param);
        //pthread_create(&threads_id[0],NULL,encapsulaMaiuscula,&param);
        //transcreve string para stringOUT
        int posicaoString=0;
        for(int i=0;i<numOps;i++){
            for(int j=0;j<LIMITE;j++){
                stringOUT[posicaoString]=conjuntoDeStrings[i][j];
                posicaoString++;

            }//FIM PERCORRE COLUNA DA MATRIZ
            if(stringOUT[posicaoString]=='\n'){
                break;
            }
        }//FIM PERCORRE stringOUT
    }


    //pthread_exit(NULL);
}
void encapsulaMaiuscula(Strings *parametro){
    char *strIN=NULL,*strOUT=NULL;

    strIN=parametro->stringIN;
    strOUT=parametro->stringOUT;

    maiusculo(strIN,strOUT);
    //printf("encapsular maiusuclo gerou:\n%s \n",strOUT);// so pra ver
}

