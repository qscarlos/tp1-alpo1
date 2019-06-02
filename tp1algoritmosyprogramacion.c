#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MF 500
#define MAX 50
#define MAxNAC 8

typedef enum {false, true} bool;
typedef enum  {argentina = 1, uruguaya, chilena, peruana, boliviana, paraguaya, brasilenia}naciones;
typedef int tvecnaciones [MAxNAC];

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

typedef templeado tvecempleados[MF];

/////////////////////////////////////////////////////////////////////////////

void cargar_datos (int *ml, tvecempleados vemp);

	void validar_fecha (int *dia, int *mes, int *anio);
	void validar_sexo (char *sexo);
	void obtener_nacionalidad (tvecnaciones vecnaciones);
	void validar_datos (int *num, int max, int min);

void menu (int ml, tvecempleados vemp, char apellido[]);

	void opciones_Aejecutar (int ml, tvecempleados vemp, char apellido[], int opc);	
	void ordenar_porNacimiento (int ml, tvecempleados vemp);
	void mostrarNacidosAntesdeDosmil (int ml, tvecempleados vemp);
	
	void mostrarUruyArgconmasdeunaNacionalidad (int ml, tvecempleados vemp);
		int buscar_otraNacionalidad (int max_naciones, tvecnaciones vecnaciones);
	
	void BuscaryMostrar_MujerVeranomismoApellido (int ml, tvecempleados vemp, char apellido []);
		bool mujer_nacidaVerano (char sexo, int mes);
		
	float porcArgentinos (int ml, tvecempleados vemp);

void mostrar_datos (int numero, char nombres[MAX], int dia, int mes, int anio, char sexo, tvecnaciones vecnaciones);

/////////////////////////////////////////////////////////////////////////////

void main (){
	
	int ml;
	char apellido[MAX];
	tvecempleados vemp;
	
	cargar_datos (&ml, vemp);
	printf("\n");
	system("pause");
	
	menu (ml, vemp, apellido);
	
}

void menu (int ml, tvecempleados vemp, char apellido[]){
	
	int opcion;
	printf ("\n\t\t\t|----MENU----|\n");
	
	printf ("1. Mostrar nacidos antes del 2000 ordenado por nacimiento.\n");
	printf ("2. Buscar y mostrar datos de apellido de mujer ingresado por usuario, nacidas en verano.\n");
	printf ("3. Mostrar Uruguayos y Argentinos con mas de 1 nacionalidad.\n");
	printf ("4. Mostrar porcentaje de empleados Argentinos.\n");
	printf ("0. salir.\n");
	printf ("\n|-seleccione la opcion a realizar o 0 para salir: ");
	
	scanf ("%i", &opcion);
	printf ("\n\tValidando opcion...\n");
	validar_datos (&opcion, 4, 0);
	
	while (opcion != 0){
		
		opciones_Aejecutar (ml, vemp, apellido, opcion);
		
		printf ("\n\t\t\t|----MENU----|\n");
	
		printf ("1. Mostrar nacidos antes del 2000 ordenado por nacimiento.\n");
		printf ("2. Buscar y mostrar datos de apellido de mujer ingresado por usuario, nacidas en verano.\n");
		printf ("3. Mostrar Uruguayos y Argentinos con mas de 1 nacionalidad.\n");
		printf ("4. Mostrar porcentaje de empleados Argentinos.\n");
		printf ("0. salir.\n");
		printf ("\n|-seleccione la opcion a realizar o 0 para salir: ");
		
		scanf ("%i", &opcion);
		printf ("\n\tValidando anio...\n");	
		validar_datos (&opcion, 4, 0);
	}
	if (opcion == 0)
		
			printf ("\n\t\tAdios!!...\n");
		
	system ("pause");
}
void opciones_Aejecutar (int ml, tvecempleados vemp, char apellido[], int opc){
	
	switch (opc) {
		case 1:
		
			ordenar_porNacimiento (ml, vemp);//falta
			printf ("\n");
		
			mostrarNacidosAntesdeDosmil (ml, vemp);	
			system("pause");
				
			break;
		case 2:
			
			printf ("\n|-Ingrese apellido a buscar: ");
			fflush (stdin);	
			fgets (apellido, MAX, stdin);
	
			BuscaryMostrar_MujerVeranomismoApellido (ml, vemp, apellido);
			system("pause");
		
			break;
		case 3:
			
			mostrarUruyArgconmasdeunaNacionalidad (ml, vemp);
			system("pause");
				
			break;
		case 4:
					
			printf ("\n|-Porcentaje de empleados Argentinos: %f", porcArgentinos(ml, vemp));
			printf ("\n");
			break;
	}
}

void cargar_datos (int *ml, tvecempleados vemp){
	
	int i;
	//char aux;
	i=0;
	
	do{
		
		printf ("|-Ingrese apellidos y nombres (apellido,+ nombre) o 'f' para finalizar: ");
		
		fflush(stdin);
		
		fgets (vemp[i].apeynombre, MAX, stdin);
		
		if (*vemp[i].apeynombre != 'f'){
			
			printf ("\n|-Ingrese fecha de nacimiento (dd-mm-aa): ");
			scanf ("%i %i %i", &vemp[i].nacimiento.dia, &vemp[i].nacimiento.mes, &vemp[i].nacimiento.anio);
			
			printf ("\n|-Validando fecha...\n");
			validar_fecha (&vemp[i].nacimiento.dia, &vemp[i].nacimiento.mes, &vemp[i].nacimiento.anio);
			printf ("\n");	
			system("pause");
			
			printf ("\n|-Ingrese sexo (M/F): ");
			fflush (stdin);
			scanf("%c", &vemp[i].sexo);
			
			printf ("\n|-Validando sexo...\n");
			validar_sexo (&vemp[i].sexo);
			
			system ("pause");
			
			obtener_nacionalidad(vemp[i].vecnaciones);
			
			i++;
		}
		
	}while ((*vemp[i].apeynombre != 'f') && (i != MF));
	
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

	bool validado = true;

	while (!validado){
		
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
			
	printf ("\n\t->sexo validado...\n");
	printf("\n");
}
	
	
void obtener_nacionalidad(tvecnaciones vecnaciones){
	
	int opc,i;
	
	for (i = 0; i < MAxNAC; i++)
	{
			vecnaciones[i] = 0;
	}
	
	printf ("\n|-Nacionalidades: ");
	printf ("\n1. Argentina");
	printf ("\n2. Uruguaya");
	printf ("\n3. Chilena");
	printf ("\n4. Peruana");
	printf ("\n5. Boliviana");
	printf ("\n6. Paraguaya");
	printf ("\n7. Brasilenia");
	printf ("\n0. salir");
		
	printf ("\n|-Elija las nacionalidades o 0 para salir: ");
	fflush (stdin);
	scanf ("%i", &opc);
	
	printf ("\nValidando opcion...\n");
	validar_datos (&opc, MAxNAC, 0);
	
	while (opc != 0){
		
		vecnaciones[opc] = 1;
//		cant_nac = cant_nac + 1;		
		printf ("\n|-Elija otra nacionalidad o 0 para salir: ");
		fflush (stdin);
		scanf ("%i", &opc);
		validar_datos (&opc, MAxNAC, 0);	
	}
	printf ("\n");	
}

void mostrarNacidosAntesdeDosmil (int ml, tvecempleados vemp){
	
	int i;
	
	printf ("\n|-Listado de nacidos antes de 2000: ");
	
	printf ("\n|-numero\t Apellidos y Nombres\t fecha de nacimiento\t  sexo\t  nacionalidades\n");
	
	for (i = 0; i< ml; i++){
		if (vemp[i].nacimiento.anio < 2000)
				
			//	printf ("\n|-%i. %s ", i, vemp[i].apeynombre);
			mostrar_datos (i, vemp[i].apeynombre, vemp[i].nacimiento.dia, vemp[i].nacimiento.mes, vemp[i].nacimiento.anio, vemp[i].sexo, vemp[i].vecnaciones);
	}
	printf ("\n");		
}

void mostrar_datos (int numero, char nombres[MAX], int dia, int mes, int anio, char sexo, tvecnaciones vecnaciones){
	
	int j;
		
	printf ("|-%i.", (numero+1));
	printf ("\t%s\t", nombres);
	printf ("-%i", dia);
	printf ("-%i", mes);
	printf ("-%i\t", anio);
	printf ("%c\t", sexo);
	
	for (j = argentina; j <=brasilenia; j++){

		if (vecnaciones[j] == 1){
	
			switch (j){
			
				case argentina:
							printf ("  Argentina");
							break;
				case uruguaya:
							printf ("  Uruguaya");
							break;
				case chilena:
							printf ("  Chilena");
							break;
				case peruana:
							printf ("  Peruana");
							break;
				case boliviana:
							printf ("  Boliviana");
							break;
				case paraguaya:
							printf ("  Paraguaya");
							break;
				case brasilenia:
							printf ("  Brasilenia");
							break;
			}
			printf ("\n");	
		}
	}
}

float porcArgentinos (int ml, tvecempleados vemp){
	
	int i, cant_Arg;
	
	cant_Arg = 0;
	
	for ( i = 0; i < ml; i++){
		
		if (vemp[i].vecnaciones[argentina] == 1)//me toma solo argentina, si elijo 2 nacionalidades ej arg y urug y urug y chil no me toma el porcentaje de el primero arg.
			
				cant_Arg++;	
	}
	
	return ((cant_Arg/ml)*100);
}

bool mujer_nacidaVerano (char sexo, int mes){
	
	
	if (((sexo == 'f') || (sexo == 'F'))&&((mes >= 1) && (mes <= 3))){
		
		return true;	
	
	}else{
		
		return false;
	}
	
}

void BuscaryMostrar_MujerVeranomismoApellido (int ml, tvecempleados vemp, char apellido []){	

	int i;
	
	char *posicion;
	bool encontrada = false;
	
	printf ("\n|-Mujeres que se apellidan igual al ingresado y nacidas en verano: \n");
	
	printf ("\n|-numero\t Apellidos y Nombres\t fecha de nacimiento\t  sexo\t  nacionalidades\n");
	for ( i = 0; i <= ml; i++){
									
		posicion = strstr(vemp[i].apeynombre, apellido);
		
		if ((posicion != NULL) && ( mujer_nacidaVerano(vemp[i].sexo, vemp[i].nacimiento.mes) == true)){

			mostrar_datos (i, vemp[i].apeynombre, vemp[i].nacimiento.dia, vemp[i].nacimiento.mes, vemp[i].nacimiento.anio, vemp[i].sexo, vemp[i].vecnaciones);
			encontrada = true;
		}
	}
	
	if (encontrada == false)
		
		printf ("\n\t->No hay mujeres nacidas en verano que se apelliden igual al apellido buscado...\n");
	
	printf ("\n");
}

int buscar_otraNacionalidad (int max_naciones, tvecnaciones vecnaciones){

	int i=argentina;
	bool encontrado = false;

	while ((i  < max_naciones) && (encontrado==false)){
		
		if ((i != argentina) && (vecnaciones[argentina] == 1) && ( vecnaciones[i] == 1)){
		
			encontrado = true;
		}else{
			if ((i != uruguaya) && (vecnaciones[uruguaya] == 1) && ( vecnaciones[i] == 1))
				encontrado = true;
		}
		i++;
	}
	
	if (encontrado == true){
		return 0;	
	}/*else{
	
		return 1;
	}*/
}


void mostrarUruyArgconmasdeunaNacionalidad (int ml, tvecempleados vemp){
	
	int i;
	
	bool mas_nac = false;
	
	printf ("\n|-argentinos y uruguayos con mas de 1 nacionalidad: \n");

	printf ("\n|-numero\t Apellidos y Nombres\t fecha de nacimiento\t  sexo\t  nacionalidades\n");

	for ( i = 0; i< ml; i++) {
	
		if (buscar_otraNacionalidad(MAxNAC, vemp[i].vecnaciones) == 0){
				
			mostrar_datos (i, vemp[i].apeynombre, vemp[i].nacimiento.dia, vemp[i].nacimiento.mes, vemp[i].nacimiento.anio, vemp[i].sexo, vemp[i].vecnaciones);

			printf ("\n");

			mas_nac = true;
		}
	}
	
	if (mas_nac == false)
			
			printf ("\n\t->no hay empleados Uruguayos ni Argentinos con mas de 1 nacionalidad...\n");
	
	printf ("\n");			
}

void ordenar_porNacimiento (int ml, tvecempleados vemp){

	


}
