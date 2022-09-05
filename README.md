# ProjetoJoin
Projeto de Threads em C com uso de paralelismo e Join.
<br/>	O objetivo é converter uma string, digitada pelo teclado, em maiuscula.
Caso a string seja maior que um determinado limite,usaremos de threads e subdividiremos a string em pedaços menores que 
podem ser realizados por tarefas simultâneas, então juntaremos os pedaços com a syscall join().
<br/>	Neste projeto usamos a biblioteca pthread.h,  com ela nós criamos uma função computa_tudo, que quebra a string em pedaços
menores de tamanho até LIMITE (definido na biblioteca ModuloThreads.h), após isso nós criamos uma thread e passamos para ela
o pedaço da string retirado. Cada thread escreve sua saída maiuscula numa linha da matriz de caracteres chamada 
conjuntoDeStrings e posteriormente juntamos os pedaços novamente em stringOUT.<br/>
Projeto da disciplina de sistemas operacionais do CEUB, Brasília-DF.
