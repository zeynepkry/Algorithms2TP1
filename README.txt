
INTRODUCCION:en este tp  cree un torneo y pedi memoria para el despues lei entrenadores y sus pokemones desde el archivo y carga vector de entrenadores,sigue leer el archivo y segun elementos agrandar el vector.Despues en la funcion torneo_jugar_ronda mando entrenadores en el vector a batallas.Elimine entrenadores derrotados y achice el vector de entrenadores con realloc.Finalmente mando entrenador victorioso a listar entrenador,y imprime su nombre y sus pokemones segun el batalla que lucho.


LINEA DE COMPILACION: gcc *.c -o torneo_pokemon -std=c99   -Wall -Werror -Wconversion 
LINEA DE EJECUCION: ./torneo_pokemon 


1.PUNTEROS:use punteros como parametros en todo mi tp
2.ARITMETICA DE PUNTEROS: use aritmetica de puneros en la funcion torneo_jugar_ronda
3.PUNTEROS A FUNCIONES:Recibio ,como parametro, puntero a funcion ganador_batalla en la funcion torneo_jugar_ronda y formatear_entrenador en la funcion torneo_listar.
4.MALLOC Y REALLOC:use malloc y realloc en la funcion torneo_crear para crear torneo y agrandar array de entrenadores y despues use en la funcion torneo_jugar_ronda para eliminar entrenadores derrotados y achiar array.

