#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "batallas.h"
const int MIN_ENT= 2;
#define PRIMERO 0
#define SEGUNDO 1
#define TERCERO 2
//PRE:recibio torneo
//POST:destruir el torneo en el caso de aslgo fue mal o en el fin de todo
void torneo_destruir(torneo_t* torneo){
	for(int i =0;i <torneo->cantidad_entrenadores;i++){
	    free(torneo->entrenadores[i].pokemones);
    }
	free(torneo->entrenadores);
	free(torneo);
}
//PRE:recibio torneo,y el archivo abierto
//POST:le asignara los valores al vector de entrenadores
 int leer_archivo(torneo_t * torneo,entrenador_t* aux_entrenador,FILE*arch_entrenadores){
   int cantidad_leidos = fscanf(arch_entrenadores,"%[^;];%[^;];%i;%i;%i;%[^;];%i;%i;%i;%[^;];%i;%i;%i\n",
    aux_entrenador[torneo->cantidad_entrenadores].nombre,aux_entrenador[torneo->cantidad_entrenadores].pokemones[PRIMERO].nombre,
    &(aux_entrenador[torneo->cantidad_entrenadores].pokemones[PRIMERO].fuerza),&(aux_entrenador[torneo->cantidad_entrenadores].pokemones[PRIMERO].agilidad),
    &(aux_entrenador[torneo->cantidad_entrenadores].pokemones[PRIMERO].inteligencia),
	aux_entrenador[torneo->cantidad_entrenadores].pokemones[SEGUNDO].nombre,&(aux_entrenador[torneo->cantidad_entrenadores].pokemones[SEGUNDO].fuerza),
	&(aux_entrenador[torneo->cantidad_entrenadores].pokemones[SEGUNDO].agilidad),&(aux_entrenador[torneo->cantidad_entrenadores].pokemones[SEGUNDO].inteligencia),
	aux_entrenador[torneo->cantidad_entrenadores].pokemones[TERCERO].nombre,&(aux_entrenador[torneo->cantidad_entrenadores].pokemones[TERCERO].fuerza),&(aux_entrenador[torneo->cantidad_entrenadores].pokemones[TERCERO].agilidad),
	&(aux_entrenador[torneo->cantidad_entrenadores].pokemones[TERCERO].inteligencia));
	
	return cantidad_leidos;
}
//PRE:recibio ruta del archivo valida
//POST:Creará la estructura torneo_t , reservando la memoria necesaria para el mismo.Devolverá un puntero a un torneo , en el cual los participantes ya estarán cargados.
//abre el archivo,segun leidos agrande el vector,cierre el archivo
torneo_t* torneo_crear(char *ruta_archivo){
	
	FILE *arch_entrenadores = fopen(ruta_archivo,"r");
	if ( arch_entrenadores == NULL ){
		perror(" El archivo no se pude abrir \n");
		return NULL;
	}
	torneo_t* torneo =  malloc(sizeof(torneo_t));
    if(torneo == NULL){
    	printf("No se pudo dar memoria 1\n");
    	fclose(arch_entrenadores);
	    return  NULL;
    }
	torneo->cantidad_entrenadores = 0;
	torneo->ronda =0;

	entrenador_t* aux_entrenador = malloc(sizeof(entrenador_t));
	if(aux_entrenador == NULL){
		printf("No se pudo dar memoria 2\n");
	    free(torneo);
        return NULL ;
	}
	aux_entrenador->pokemones = malloc(3*sizeof(pokemon_t));
	if(aux_entrenador->pokemones == NULL){
		printf("No se pudo dar memoria 3\n");
		free(aux_entrenador);
		free(torneo);
		fclose(arch_entrenadores);
		return NULL ;
	}
	int cantidad_leidos = 0;
	torneo->entrenadores = aux_entrenador;
	cantidad_leidos = leer_archivo(torneo,torneo->entrenadores,arch_entrenadores);
	//para chequear si el archivo tiene formato correcto
	if(cantidad_leidos!=13 && cantidad_leidos!=EOF){
		printf("archivo esta mal escribido1\n");
		fclose(arch_entrenadores);
		free(torneo->entrenadores[torneo->cantidad_entrenadores].pokemones);
		torneo_destruir(torneo);
		return NULL ;
	}
    (torneo->cantidad_entrenadores)++;
   
    while(cantidad_leidos == 13){
    	//printf("%i\n",cantidad_leidos );
	    torneo->entrenadores = realloc(torneo->entrenadores,(unsigned int) ((torneo->cantidad_entrenadores)+1) * sizeof(entrenador_t));
    	if(torneo->entrenadores == NULL){
    		printf("No se pudo dar memoria 5\n");
			return NULL ;
    	}
        torneo->entrenadores[torneo->cantidad_entrenadores].pokemones = malloc(3*sizeof(pokemon_t));
		if(torneo->entrenadores[torneo->cantidad_entrenadores].pokemones == NULL){
			printf("No se pudo dar memoria 6\n");
		    return NULL ;
		}
		cantidad_leidos = leer_archivo(torneo,torneo->entrenadores,arch_entrenadores);
		//para chequear si el archivo tiene formato correcto
  		if(cantidad_leidos!=13 && cantidad_leidos!=EOF){
			printf("archivo esta mal escribido1\n");
			fclose(arch_entrenadores);
			free(torneo->entrenadores[torneo->cantidad_entrenadores].pokemones);
			torneo_destruir(torneo);
			return NULL ;
		}
		if(cantidad_leidos == 13){
  			(torneo->cantidad_entrenadores)++;
		
  		}
    }
	free(torneo->entrenadores[torneo->cantidad_entrenadores].pokemones);
	fclose( arch_entrenadores);
	return torneo;
}
//PRE:recibio torneo
//POST:achica el vector de entrenadores y devuelve cantidad actualizado de entrenadores
int eliminar_entrenador(torneo_t* torneo){
	//para chequear si la cantidad de entrenadores es par o impar
	if(torneo->cantidad_entrenadores%2 == 0){
         torneo->cantidad_entrenadores = torneo->cantidad_entrenadores/2;
	}else{
		 torneo->cantidad_entrenadores = (torneo->cantidad_entrenadores/2)+1;
	}
	torneo->entrenadores = realloc(torneo->entrenadores,(unsigned int) ((torneo->cantidad_entrenadores)) * sizeof(entrenador_t));
		if(torneo->entrenadores == NULL){
			printf("No se pudo dar memoria 5\n");
			return  -1;
		}
		return torneo->cantidad_entrenadores;
		
}
//PRE:recibio torneo no null
//POST:deja en la siguiente ronda al ganador de la batalla.El vector de entrenadores queda solo con aquellos que ganaron la batalla.Devolverá 0
int torneo_jugar_ronda(torneo_t* torneo , int (* ganador_batalla)(entrenador_t* ,entrenador_t *)){
	if(torneo == NULL){
		return ERROR;
	}
	if(ganador_batalla == NULL){
		return ERROR;
	}
	int ganador;
	if (torneo->cantidad_entrenadores == 1 && torneo->ronda == 0){
		//printf("no hay nadie para luchar\n");
		return ERROR;
	}
		int k = 0;
		//pone este condicion para en el caso de si un entrenador no tiene algien siguiente para luchar
		if(torneo->cantidad_entrenadores%2 == 0){
			for( int i = 0;i<torneo->cantidad_entrenadores;i+=2){ 
					ganador = (*ganador_batalla)(&(torneo->entrenadores[i]),&(torneo->entrenadores[i+1]));
				//segun el ganador cambio lugares en el vecor
				if(ganador == 0){
					free(torneo->entrenadores[i+1].pokemones);
					torneo->entrenadores[k] = torneo->entrenadores[i];
					k++;
				}else{
					free(torneo->entrenadores[i].pokemones);
					torneo->entrenadores[k] = torneo->entrenadores[i+1];
					k++;
	    		}
			}
        }else{
        	int i = 0;
        	while(i<torneo->cantidad_entrenadores){
        		//si entrenador actual es el ultimo gana directamente
        		if(i+2 >= torneo->cantidad_entrenadores){
        			torneo->entrenadores[k] = torneo->entrenadores[i];
        		}else{
        			ganador = (*ganador_batalla)(&(torneo->entrenadores[i]),&(torneo->entrenadores[i+1]));
        			if(ganador == 0){ 
						free(torneo->entrenadores[i+1].pokemones);
						torneo->entrenadores[k] = torneo->entrenadores[i];
						k++;
					}else{
						free(torneo->entrenadores[i].pokemones);
						torneo->entrenadores[k] = torneo->entrenadores[i+1];
						k++;
		    		}
        		}
        		i+=2;
        	}
        }
		eliminar_entrenador(torneo);
		torneo->ronda++;
		

	//printf("cantidad_entrenadores :%i\n",torneo->cantidad_entrenadores);
	
    return 0;
}

//PRE:recibir torneo valida
//POST:Mostrará por pantalla el nombre de cada entrenador , junto a sus pokémones
void torneo_listar(torneo_t* torneo, void (*formatear_entrenador)(entrenador_t*)){
	if(torneo == NULL){
		return;
	}
	printf("Torneo Pokemon: Ronda %i \n",torneo->ronda);
	(*formatear_entrenador)(&(torneo->entrenadores[torneo->cantidad_entrenadores-1]));
}






