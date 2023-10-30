#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "batallas.h"

int batalla_inteligencia (entrenador_t* entrenador_1 ,entrenador_t* entrenador_2){
	int ganador;
    
	int suma_inteligencia_1 = entrenador_1->pokemones[0].inteligencia + entrenador_1->pokemones[1].inteligencia;
	int suma_inteligencia_2 = entrenador_2->pokemones[0].inteligencia + entrenador_2->pokemones[1].inteligencia;


	if(suma_inteligencia_1 > suma_inteligencia_2){
		ganador = 0;
	}else if (suma_inteligencia_1 < suma_inteligencia_2){
		ganador = 1;
	}else{
		int suma_fuerza_1= entrenador_1->pokemones[0].fuerza+ entrenador_1->pokemones[1].fuerza;
		int suma_fuerza_2= entrenador_2->pokemones[0].fuerza+ entrenador_2->pokemones[1].fuerza;
		if(suma_fuerza_1 > suma_fuerza_2){
			ganador = 0;
	    }else if (suma_fuerza_1 < suma_fuerza_2){
		    ganador = 1;

		}
	}
    return ganador;

}

int batalla_fuerza(entrenador_t* entrenador_1 ,entrenador_t* entrenador_2){
	int ganador;
	int fuerza_1 = entrenador_1->pokemones[2].fuerza; 
	int fuerza_2 = entrenador_2->pokemones[2].fuerza;
	if(fuerza_1 > fuerza_2){
		ganador = 0;
	}else if (fuerza_1 < fuerza_2){
		ganador = 1;
	}else{
		int agilidad_1= entrenador_1->pokemones[2].agilidad; 
		int agilidad_2= entrenador_1->pokemones[2].agilidad; 
		if(agilidad_1 > agilidad_2){
			ganador = 0;
	    }else if (agilidad_1 < agilidad_2){
		    ganador = 1;
	    }
	}
    return ganador;
}
int batalla_armonia(entrenador_t* entrenador_1 ,entrenador_t* entrenador_2){
	int ganador;
	int armonia_1 = entrenador_1->pokemones[0].fuerza+entrenador_1->pokemones[1].agilidad;
    int armonia_2 = entrenador_2->pokemones[0].fuerza+entrenador_2->pokemones[1].agilidad;
	if(armonia_1 > armonia_2){
		ganador = 0;
	}else if (armonia_1 < armonia_2){
		ganador = 1;
	}else{
		int inteligencia_1= entrenador_1->pokemones[2].inteligencia; 
		int inteligencia_2= entrenador_2->pokemones[2].inteligencia;  
		if(inteligencia_1 > inteligencia_2){
			ganador = 0;
	    }else if (inteligencia_1 < inteligencia_2){
		    ganador = 1;
		}
	}
    return ganador;
}
int batalla_voluntad(entrenador_t* entrenador_1 ,entrenador_t* entrenador_2){
	int ganador;
	int agilidad_1 = entrenador_1->pokemones[2].agilidad; 
	int agilidad_2 = entrenador_2->pokemones[2].agilidad;
	if(agilidad_1 > agilidad_2){
		ganador = 0;
	}else if (agilidad_1 < agilidad_2){
		ganador = 1;
	}else{
		int inteligencia_1= entrenador_1->pokemones[1].inteligencia; 
		int inteligencia_2= entrenador_1->pokemones[1].inteligencia; 
		if(inteligencia_1 > agilidad_2){
			ganador = 0;
	    }else if (inteligencia_1 < inteligencia_2){
		    ganador = 1;
	    }
	}
    return ganador;
}
int batalla_agilidad (entrenador_t* entrenador_1 ,entrenador_t* entrenador_2){
	int ganador;
    
	int suma_agilidad_1 = entrenador_1->pokemones[0].agilidad + entrenador_1->pokemones[1].agilidad;
	int suma_agilidad_2 = entrenador_2->pokemones[0].agilidad + entrenador_2->pokemones[1].agilidad;


	if(suma_agilidad_1 > suma_agilidad_2){
		ganador = 0;
	}else if (suma_agilidad_1 < suma_agilidad_2){
		ganador = 1;
	}else{
		int suma_fuerza_1= entrenador_1->pokemones[0].fuerza+ entrenador_1->pokemones[1].fuerza;
		int suma_fuerza_2= entrenador_2->pokemones[0].fuerza+ entrenador_2->pokemones[1].fuerza;
		if(suma_fuerza_1 > suma_fuerza_2){
			ganador = 0;
	    }else if (suma_fuerza_1 < suma_fuerza_2){
		    ganador = 1;

		}
	}
    return ganador;

}
void inteligencia_pokemones(entrenador_t* entrenador){
 	printf("%s :,%s,(%i),%s,(%i)\n",entrenador->nombre,entrenador->pokemones[0].nombre,
 	entrenador->pokemones[0].inteligencia,entrenador->pokemones[1].nombre,entrenador->pokemones[1].inteligencia);
 }


 void fuerza_pokemones(entrenador_t* entrenador){
 	printf("%s :,%s,(%i)\n",entrenador->nombre,entrenador->pokemones[2].nombre,entrenador->pokemones[2].fuerza);
 }


void armonia_pokemones(entrenador_t* entrenador){
 	printf("%s :,%s,(%i),%s,(%i)\n",entrenador->nombre,entrenador->pokemones[0].nombre,
 	entrenador->pokemones[0].fuerza,entrenador->pokemones[1].nombre,entrenador->pokemones[1].agilidad);
}
void agilidad_pokemones(entrenador_t* entrenador){
 	printf("%s :,%s,(%i),%s,(%i)\n",entrenador->nombre,entrenador->pokemones[0].nombre,
 	entrenador->pokemones[0].agilidad,entrenador->pokemones[1].nombre,entrenador->pokemones[1].agilidad);
 }
 void voluntad_pokemones(entrenador_t* entrenador){
 	printf("%s :,%s,(%i)\n",entrenador->nombre,entrenador->pokemones[2].nombre,entrenador->pokemones[2].agilidad);
 }
int main(){
	torneo_t* mi_torneo = torneo_crear("entrenadores.csv");
	while(mi_torneo->cantidad_entrenadores >1){

		torneo_jugar_ronda(mi_torneo,batalla_inteligencia);
  		torneo_listar(mi_torneo,inteligencia_pokemones);
  		torneo_jugar_ronda(mi_torneo ,batalla_fuerza);
        torneo_listar(mi_torneo,fuerza_pokemones);
        torneo_jugar_ronda(mi_torneo ,batalla_armonia);
        torneo_listar(mi_torneo,armonia_pokemones);
        torneo_jugar_ronda(mi_torneo ,batalla_agilidad);
        torneo_listar(mi_torneo,agilidad_pokemones);
        torneo_jugar_ronda(mi_torneo ,batalla_voluntad);
        torneo_listar(mi_torneo,voluntad_pokemones);

	}
	torneo_destruir( mi_torneo);
	return 0;
}
