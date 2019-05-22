#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MF 500
#define MAX 50

typedef enum  {argentino = 1, uruguayo, chileno, peruano, boliviano, paraguayo, brasilenio}tnacion;
typedef int tvecnaciones [7];
//typedef tnacion vecnacion[7];
typedef struct{
	
	int dia, mes, anio;
}tfecha;

typedef struct{
	
	char apeynombre[MAX];
	
	tfecha nacimiento;
	
	char sexo;
	
	tvecnaciones vecnaciones;
	//vecnacion naciones;
	
}templeado;

typedef templeado tvecempleado[MF];

void cargar_datos (int *ml, tvecempleado *vemp);
	
void ordenar_porNacimiento (int ml, tvecempleado vemp);
	
void mostrarNacidosAntesdeDosmil (int ml, tvecempleado vemp);
	
void buscaryListarMujeresMismoApellido (int ml, tvecempleado vemp);
	
void mostrarUruyArgconmasdeunaNacionalidad (int ml, tvecempleado vemp);
	
int porcArgentinos (int ml, tvecempleado vemp);

void mostrar_datos (int ml, tvecempleado vemp);

void validar_datos (int *num, int max, int min);

void validar_fecha (int *dia, int *mes, int *anio);

void validar_sexo (char *sexo);

void obtener_nacionalidad (tvecnaciones *vecnaciones);

void main (){#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MF 500
#define MAX 50
//
//typedef enum {false, true} bool;
typedef enum  {argentino = 1, uruguayo, chileno, peruano, boliviano, paraguayo, brasilenio}tnacion;
typedef int tvecnaciones [7];
//typedef tnacion vecnacion[7];
typedef struct{
	
	int dia, mes, anio;
}tfecha;

typedef struct{
	
	char apeynombre[MAX];
	
	tfecha nacimiento;
	
	char sexo;
	
	tvecnaciones vecnaciones;
	//vecnacion naciones;
	
}templeado;

typedef templeado tvecempleado[MF];

void cargar_datos (int *ml, tvecempleado *vemp);
	
void ordenar_porNacimiento (int ml, tvecempleado vemp);
	
void mostrarNacidosAntesdeDosmil (int ml, tvecempleado vemp);
	
void buscaryListarMujeresMismoApellido (int ml, tvecempleado vemp);
	
void mostrarUruyArgconmasdeunaNacionalidad (int ml, tvecempleado vemp);
	
int porcArgentinos (int ml, tvecempleado vemp);

void mostrar_datos (int ml, tvecempleado vemp);

void validar_datos (int *num, int max, int min);

void validar_fecha (int *dia, int *mes, int *anio);

void validar_sexo (char *sexo);

void obtener_nacionalidad (tvecnaciones *vecnaciones);

void main (){
	
	int ml;
	tvecempleado vemp;
	
	cargar_datos (&ml, &vemp);
	
	ordenar_porNacimiento (ml, vemp);//falta
	
	mostrarNacidosAntesdeDosmil (ml, vemp);
	
	buscaryListarMujeresMismoApellido (ml, vemp);
	
	mostrarUruyArgconmasdeunaNacionalidad (ml, vemp);
	
	printf ("\n|-Porcentaje de empleados Argentinos: %f",porcArgentinos (ml, vemp));
	
}

void cargar_datos (int *ml, tvecempleado *vemp){
	
	int i;
	//char aux;
	i=0;
	
	do{
		
		printf ("|-Ingrese apellidos y nombres (apellido, nombre) o 'f' para finalizar: ");
		fflush(stdin);
		fgets (vemp[i]->apeynombre, MAX, stdin);
		
		if (*vemp[i]->apeynombre != 'f'){
			
			printf ("\n|-Ingrese fecha de nacimiento (dd-mm-aa): ");
			scanf ("%i %i %i", &vemp[i]->nacimiento.dia, &vemp[i]->nacimiento.mes, &vemp[i]->nacimiento.anio);
			
			printf ("\n|-Validando fecha...\n");
			validar_fecha (&vemp[i]->nacimiento.dia, &vemp[i]->nacimiento.mes, &vemp[i]->nacimiento.anio);
			
			system("pause");
			
			printf ("\n|-Ingrese sexo (M/F): ");
			scanf ("%c\n", &vemp[i]->sexo);
			
			
			printf ("\n|-Validando sexo...\n");
			validar_sexo (&vemp[i]->sexo);
			
			system ("pause");
			
			obtener_nacionalidad(&vemp[i]->vecnaciones);
			
		}
		
		i++;
		
	}while ((*vemp[i]->apeynombre != 'f') && (i != MF));
	
	*ml = i;
}
void validar_datos (int *num, int max, int min){
	
	while ((*num < min) || (*num > max)){
		
		printf ("\n\t|-Error...");
		printf ("\n\t|-Reingrese datos: ");
		fflush(stdin);
		scanf ("%i", num);
	}
	printf ("\n\t->Datos validados!\n");
}

void validar_fecha (int *dia, int *mes, int *anio){
	
	printf ("\n\tValidando anio...\n");
	validar_datos (anio, 100000, 0);
	
	printf ("\n\tValidando mes...\n");
	validar_datos (mes, 12, 1);	
	
	switch (*mes){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:	
			printf ("\n\tValidando dia...\n");
			validar_datos (dia, 31, 1);
			break;
		case 2:
			if ((((*anio) % 4 == 0) && ((*anio) % 100 != 0)) || ((*anio) % 400 == 0)){
				
				printf ("\n\tValidando dia...\n");
				validar_datos (dia, 29, 1);
			}else{
				
				printf ("\n\tValidando dia...\n");	
				validar_datos (dia, 28, 1);
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			printf ("\n\tValidando dia...\n");
			validar_datos (dia, 30, 1);
			break;
	}
	
}

void validar_sexo (char *sexo){

	while (((*sexo != 'M') && (*sexo != 'F')) && ((*sexo != 'm') && (*sexo != 'f'))){//problemas con esta expresion logica
		
		printf ("\n|-Error..");
		printf ("\n|-Reingrese sexo(M/F): ");
		fflush (stdin);
		scanf ("%c", sexo);
	}
	
	printf ("\n->sexo validado...\n");
	
	
}
	/*bool validado = false;
	while (validado){
		switch (*sexo){
			case 'M':
			case 'm':
			case 'F':
			case 'f':
				validado = true;
				break;
			default :
				
				printf ("\n|-Error..");
				printf ("\n|-Reingrese sexo(M/F): ");
				fflush (stdin);
				scanf ("%c", sexo);
				break;
		}
	}
	if (validado == true) {
		
		printf ("\n->sexo validado...\n");
	}*/
	
/*	while (((*sexo != 'M') || (*sexo != 'm')) || ((*sexo != 'F') || (*sexo != 'f'))){
		
		printf ("\n|-Error..");
		printf ("\n|-Reingrese sexo(M/F): ");
		fflush (stdin);
		scanf ("%c", sexo);
	}
	
	printf ("\n->sexo validado...\n");*/
	
void obtener_nacionalidad(tvecnaciones *vecnaciones){
	
	int opc,i;
	
	for (i = 0; i <=brasilenio; i++)
	{
			*vecnaciones[i] = 0;
	}
	
	printf ("\n|-Nacionalidades: ");
	printf ("\n1. Argentino");
	printf ("\n2. Uruguayo");
	printf ("\n3. Chileno");
	printf ("\n4. Peruano");
	printf ("\n5. Boliviano");
	printf ("\n6. Paraguayo");
	printf ("\n7. Brasilenio");
	printf ("\n0. salir");
		
	printf ("\n|-Elija las nacionalidades o 0 para salir: ");
	fflush (stdin);
	scanf ("%i", &opc);
	
	printf ("\nValidando opcion...\n");
	validar_datos (&opc, 7, 0);
	
	while (opc != 0){
		
		*vecnaciones[opc] = 1;
//		cant_nac = cant_nac + 1;		
		printf ("\n|-Elija otra nacionalidad o 0 para salir: ");
		fflush (stdin);
		scanf ("%i", &opc);
		validar_datos (&opc, 7, 0);	
	}	
}

void mostrarNacidosAntesdeDosmil (int ml, tvecempleado vemp){
	
	int i;
	
	printf ("\n|-Listado de nacidos antes de 2000: ");
	
	for (i = 0; i<= ml; i++)
	
		if (vemp[i].nacimiento.anio < 2000)
				
			//	printf ("\n|-%i. %s ", i, vemp[i].apeynombre);
				mostrar_datos (ml, vemp);
	
}

void mostrar_datos (int ml, tvecempleado vemp){
	
	int i,j;
	
	printf ("\n|-numero\t -Apellidos y Nombres\t -  fecha de nacimiento\t - sexo\t - nacionalidades");
	
	for (i = 0; i <= ml; i++){
		
		printf ("\n|-%i.\t -%s\t -%i %i %i\t -%c\t\t", (i+1), vemp[i].apeynombre, vemp[i].nacimiento.dia, vemp[i].nacimiento.mes, vemp[i].nacimiento.anio, vemp[i].sexo);
				
		for (j = argentino; j <=brasilenio; i++){
		
			if (vemp[i].vecnaciones[j] == 1){
			
				switch (j){
			
					case argentino:
								printf ("Argentino\t");
								break;
					case uruguayo:
								printf ("Uruguayo\t");
								break;
					case chileno:
								printf ("Chileno\t");
								break;
					case peruano:
								printf ("Peruano\t");
								break;
					case boliviano:
								printf ("Boliviano\t");
								break;
					case paraguayo:
								printf ("Paraguayo\t");
								break;
					case brasilenio:
								printf ("Brasilenio\t");
								break;
				}	
			}
		}
	}
}

int porcArgentinos (int ml, tvecempleado vemp){
	
	int i, cant_Arg;
	
	cant_Arg = 0;
	
	for ( i = 0; i <= ml; i++){
		
		if ( vemp[i].vecnaciones[argentino] == 1)
			
				cant_Arg ++;	
	}
	
	return ((cant_Arg/ml)*100);
}

void buscaryListarMujeresMismoApellido (int ml, tvecempleado vemp){
	
	char apellido[MAX];
	
	int i;
	
	char *posicion;
	
	printf ("\n|-Ingrese apellido a buscar: ");
	fgets (apellido, MAX, stdin);
	
	printf ("\n|-Mujeres que se apellidan igual al ingresado y nacidas en verano: \n");
	
	for ( i = 0; i <= ml; i++){
									
		posicion = strstr(vemp[i].apeynombre, apellido);
		
		if ((posicion != NULL) && ((vemp[i].sexo == 'f') || (vemp[i].sexo == 'F')) && (vemp[i].nacimiento.mes >= 1) && (vemp[i].nacimiento.mes <= 3)){

			mostrar_datos (ml, vemp);
		}
	}
}

void mostrarUruyArgconmasdeunaNacionalidad (int ml, tvecempleado vemp){
	
	int i,j=argentino;
	
	for (i = 0; i <= ml; i++){
		
		while (( j <= brasilenio) && (( vemp[i].vecnaciones[uruguayo] == 1 ) || (vemp[i].vecnaciones[argentino] == 1))){//si son igual a 1 significa que es uruguayo o argentino
		
			if (((j != uruguayo) || (j != argentino)) && (vemp[i].vecnaciones[j] == 1)){
				
				mostrar_datos (ml, vemp);
			}
			
			j++;
		}	
	}
}

void ordenar_porNacimiento (int ml, tvecempleado vemp){

	

}
	
	int ml;
	tvecempleado vemp;
	
	cargar_datos (&ml, &vemp);
	
	ordenar_porNacimiento (ml, vemp);//falta
	
	mostrarNacidosAntesdeDosmil (ml, vemp);
	
	buscaryListarMujeresMismoApellido (ml, vemp);//falta
	
	mostrarUruyArgconmasdeunaNacionalidad (ml, vemp);//falta
	
	printf ("\n|-Porcentaje de empleados Argentinos: %f",porcArgentinos (ml, vemp));
	
}

void cargar_datos (int *ml, tvecempleado *vemp){
	
	int i;
	i=0;
	
	do{
		
		printf ("|-Ingrese apellidos y nombres (apellido, nombre) o 'f' para finalizar: ");
		fgets (vemp[i]->apeynombre, MAX, stdin);
		
		if (*vemp[i]->apeynombre != 'f'){
			
			printf ("\n|-Ingrese fecha de nacimiento (dd-mm-aa): ");
			scanf ("%i %i %i\n", vemp[i]->nacimiento.dia, vemp[i]->nacimiento.mes, vemp[i]->nacimiento.anio);
			
			validar_fecha (&vemp[i]->nacimiento.dia, &vemp[i]->nacimiento.mes, &vemp[i]->nacimiento.anio);
			
			system("pause");
			
			printf ("|-Ingrese sexo (M/F): ");
			scanf ("%c\n", &vemp[i]->sexo);
			
			validar_sexo (&vemp[i]->sexo);
		
			obtener_nacionalidad(&vemp[i]->vecnaciones);
			
		}
		
		i++;
		
	}while ((*vemp[i]->apeynombre != 'f') && (i <= MF));
	
	*ml = i;
}
void validar_datos (int *num, int max, int min){
	
	while ((*num < min) || (*num > max)){
		
		printf ("\n|-Error..");
		printf ("\n|-Reingrese datos: ");
		scanf ("%i", num);
	}
	
}

void validar_fecha (int *dia, int *mes, int *anio){
	switch (*dia){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:	
			validar_datos (dia, 31, 1);
			break;
		case 2:
			if ((((*anio) % 4 == 0) && ((*anio) % 100 != 0)) || ((*anio) % 400 == 0))
			
				validar_datos (dia, 29, 1);
			else
				validar_datos (dia, 28, 1);
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			validar_datos (dia, 30, 1);
			break;
	}
	validar_datos (mes, 12, 1);	
	validar_datos (anio, 100000, 0);
}

void validar_sexo (char *sexo){
	
	while ((*sexo != 'M') || (*sexo != 'F') || (*sexo != 'm') ||(*sexo != 'f')){
		
		printf ("\n|-Error..");
		printf ("\n|-Reingrese sexo(M/F): ");
		scanf ("%c", sexo);
	}
	
}
void obtener_nacionalidad(tvecnaciones *vecnaciones){
	
	int opc,i;
	
	for (i = 0; i <=brasilenio; i++)
	
			*vecnaciones[i] = 0;
	
	
	printf ("\n|-Nacionalidades: ");
	printf ("\n1. Argentino");
	printf ("\n2. Uruguayo");
	printf ("\n3. Chileno");
	printf ("\n4. Peruano");
	printf ("\n5. Boliviano");
	printf ("\n6. Paraguayo");
	printf ("\n7. Brasilenio");
	printf ("\n0. salir");
		
	printf ("\n|-Elija las nacionalidades o 0 para salir: ");
	scanf ("%i", &opc);
	
	validar_datos (&opc, 7, 0);
	
	while (opc != 0){
		
		*vecnaciones[opc] = 1;
//		cant_nac = cant_nac + 1;		
		scanf ("%i", &opc);
	}	
}

void mostrarNacidosAntesdeDosmil (int ml, tvecempleado vemp){
	
	int i;
	
	printf ("\n|-Listado de nacidos antes de 2000: ");
	
	for (i = 0; i<= ml; i++)
	
		if (vemp[i].nacimiento.anio < 2000)
				
			//	printf ("\n|-%i. %s ", i, vemp[i].apeynombre);
				mostrar_datos (ml, vemp);
	
}

void mostrar_datos (int ml, tvecempleado vemp){
	
	int i,j;
	
	printf ("\n|-numero\t -Apellidos y Nombres\t -  fecha de nacimiento\t - sexo\t - nacionalidades");
	
	for (i = 0; i <= ml; i++){
		
		printf ("\n|-%i.\t -%s\t -%i %i %i\t -%c\t\t %i", i, vemp[i].apeynombre, vemp[i].nacimiento.dia, vemp[i].nacimiento.mes, vemp[i].nacimiento.anio, vemp[i].sexo);
				
		for (j = argentino; j <=brasilenio; i++){
		
			if (vemp[i].vecnaciones[j] == 1){
			
				switch (j){
			
					case argentino:
								printf ("Argentino\t");
								break;
					case uruguayo:
								printf ("Uruguayo\t");
								break;
					case chileno:
								printf ("Chileno\t");
								break;
					case peruano:
								printf ("Peruano\t");
								break;
					case boliviano:
								printf ("Boliviano\t");
								break;
					case paraguayo:
								printf ("Paraguayo\t");
								break;
					case brasilenio:
								printf ("Brasilenio\t");
								break;
				}	
			}
		}
	}
}

int porcArgentinos (int ml, tvecempleado vemp){
	
	int i, cant_Arg;
	
	cant_Arg = 0;
	
	for ( i = 0; i <= ml; i++){
		
		if ( vemp[i].vecnaciones[argentino] == 1)
			
				cant_Arg ++;	
	}
	
	return ((cant_Arg/ml)*100);
	
}





