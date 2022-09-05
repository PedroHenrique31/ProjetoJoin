#ifndef MODULOTHREADS_H_INCLUDED
#define MODULOTHREADS_H_INCLUDED
// Essa struct será usada para passarmos ambas as strings por apenas um parâmetro.
typedef struct Strings{
    char *stringIN;
    char *stringOUT;
}Strings;

void encapsulaMaiuscula(Strings *parametro);
void* computa_tudo(char* stringIN,char* stringOUT); // essa função fará as chamadas de cada thread.


#endif // MODULOTHREADS_H_INCLUDED
