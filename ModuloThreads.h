#ifndef MODULOTHREADS_H_INCLUDED
#define MODULOTHREADS_H_INCLUDED
// Essa struct ser� usada para passarmos ambas as strings por apenas um par�metro.
typedef struct Strings{
    char *stringIN;
    char *stringOUT;
}Strings;

void encapsulaMaiuscula(Strings *parametro);
void* computa_tudo(char* stringIN,char* stringOUT); // essa fun��o far� as chamadas de cada thread.


#endif // MODULOTHREADS_H_INCLUDED
