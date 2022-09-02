# ProjetoJoin
Projeto de Threads em C com uso de paralelismo e Join.
O objetivo é converter uma string, digitada pelo teclado, em maiuscula.
Caso a string seja maior que um determinado limite,usaremos de threads e subdividiremos a string em pedaços menores que 
podem ser realizados por tarefas simultâneas, então juntaremos os pedaços com a syscall join().
