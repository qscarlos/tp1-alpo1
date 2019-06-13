#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MF 500
#define MAX 100
#define MAX_NAC 8
#define MAX_FECHA 11
#define dato_ape_nomb 0
#define dato_ape 1
#define dato_fecha 2
#define dato_sexo 3
#define dato_nac 4
#define dato_nac_mayor_2000 5
#define dato_arg_uru_1nac 6
#define dato_muj_no_nac_vera 7
#define print_arg "argentina"
#define print_uru "uruguaya"
#define print_chi "chilena"
#define print_per "peruana"
#define print_bol "boliviana"
#define print_par "paraguaya"
#define print_bra "brasilera"
#define min_pos_vec 0

typedef enum {false, true} bool;

enum {argentina = 1, uruguaya, chilena, peruana, boliviana, paraguaya, brasilera} naciones;

typedef enum { apellido_nombre, apellido, fecha, sexo, ciudadania, nac_mayor_2000, arg_uru_1nac, muj_no_nac_vera } dato;

typedef int tvecnaciones [MAX_NAC];

typedef struct{
	
	char apellido_nombre[MAX];
	char nacimiento[MAX_FECHA];
	char apellido[MAX];
	char sexo;
	tvecnaciones vecnaciones;
	bool nac_mayor_2000; // dato que devuelve 0 (FALSE) para empleados nacidos antes del 2000 y devuelve 1 (TRUE) para empleados nacidos despues del 2000.
	bool arg_uru_1nac; // dato que retorna 0 (FALSE) para empleados arg o uru con 2 o mas nacionalidades y retorna 1 (TRUE) para otra condicion de nacionalidad.
	bool muj_no_nac_vera;// dato que retorna 0 (FALSE) para empleadas mujeres nacidas en verano y retorna 1 (TRUE) para otra condicion de sexo y estacion del año.
	
}templeado;

typedef templeado tvecempleados[MF];

int pasar_texto_a_entero (char texto[MAX_FECHA], int min, int max){
	
	char texto_carac[2];
	int i, j=0;
	int texto_int;
	
	for (i=min; i<max; i++){
		
		texto_carac[j]=texto[i];
		
		j++;
	}
	
	texto_int=atoi(texto_carac);
	
	return texto_int;
}

void validar_datos (int *num, int max, int min){
	
	while ((*num < min) || (*num > max)){
		
		printf ("\n\t|-Error...");
		printf ("\n\t|-Reingrese datos: ");
		fflush(stdin);
		scanf ("%d", num);
	}
}

void validar_fecha (int *dia, int *mes, int *anio){
	
	validar_datos (anio, 2003, 1949);
	
	validar_datos (mes, 12, 1);	
	
	switch (*mes){
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
			if ((((*anio) % 4 == 0) && ((*anio) % 100 != 0)) || ((*anio) % 400 == 0)){
				
				validar_datos (dia, 29, 1);
			}else{
				
				validar_datos (dia, 28, 1);
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			validar_datos (dia, 30, 1);
			break;
	}
}

void calcular_datos_fecha (char texto[MAX_FECHA], bool *estacion_verano) {
	
	char aux_fecha[MAX_FECHA];
	strcpy(aux_fecha, texto);
	int min_mes=5, max_mes=7, min_dia=8, max_dia=10;
	int anio=atoi(aux_fecha);
	int mes=pasar_texto_a_entero(aux_fecha, min_mes, max_mes);
	int dia=pasar_texto_a_entero(aux_fecha, min_dia, max_dia);
	
	validar_fecha (&dia, &mes, &anio);
	
	if ((dia<10) && (mes<10)){
				
		sprintf(aux_fecha, "%d-0%d-0%d", anio, mes, dia);
	}
			
	else{
				
		if ((dia<10) && (mes>=10)){
					
			sprintf(aux_fecha, "%d-%d-0%d", anio, mes, dia);
		}
				
		else {
					
			if ((dia>=10) && (mes<10)){
						
				sprintf(aux_fecha, "%d-0%d-%d", anio, mes, dia);
			}
					
			else{
						
				sprintf(aux_fecha, "%d-%d-%d", anio, mes, dia);
			}
		}
	}
	
	if (((dia>=21) && (mes==12)) || ((mes>=1) && (mes<=2)) || ((dia<=20) && (mes==3))){
		
		*estacion_verano=true;
	}
	
	strcpy(texto, aux_fecha);
	
}

void validar_sexo (char *letra){
	
	while (( (*letra != 'f') && (*letra != 'F') ) && ( (*letra != 'm') && (*letra != 'M') )){
		
		printf ("\n\tError...");
		printf ("\n\t|-Reingrese sexo (M/F): ");
		fflush (stdin);
		scanf ("%c", letra);
		
			
	}
	printf ("\n");
}

void obtener_nacionalidad(tvecnaciones vecnaciones){
	
	int opc,i;
	
	for (i = 0; i < MAX_NAC; i++)
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
	printf ("\n7. Brasilera");
	printf ("\n0. salir");
		
	printf ("\n|-Elija las nacionalidades o 0 para salir: ");
	fflush (stdin);
	scanf ("%i", &opc);
	
	validar_datos (&opc, MAX_NAC, 0);
	
	while (opc != 0){
		
		printf ("\n|-Elija las nacionalidades o 0 para salir: ");
		vecnaciones[opc] = 1;
        fflush (stdin);
		scanf ("%i", &opc);
		validar_datos (&opc, MAX_NAC, 0);	
	}
	printf ("\n");
}

bool validar_dato_booleano (templeado emp, bool verano_si, dato var) {
	
	int i=2, aux_cant=0;
	char aux_fecha;
	bool aux_bool=false;
	
	switch (var){
		
		case dato_nac_mayor_2000:
			
			if (strcmp(emp.nacimiento, "2000-01-01")>=0){
				
				aux_bool=true;
			}
			break;
		
		case dato_arg_uru_1nac:
			
			if ((emp.vecnaciones[1]==true) || (emp.vecnaciones[2]==true)){
				
				while ((i<MAX_NAC) && (aux_cant==0)){
					
					if (((emp.vecnaciones[1]==true) && (emp.vecnaciones[i]==true)) || 
					((emp.vecnaciones[2]==true) && (emp.vecnaciones[1]==false) && (emp.vecnaciones[i]==true) && (i>2))){
						
						aux_cant++;
					}
					
					i++;
				}
		    }
		    
		    if (aux_cant==0){
		    	
		    	aux_bool=true;
			}
			break;
			
		default:   
		    
			if ((verano_si==false) || ((verano_si==true) && ((emp.sexo=='M') || (emp.sexo=='m')))){
				
				aux_bool=true;
			}
			break;   
	}
	
	return aux_bool;
}

void cargar_datos (int *ml, int *cantidad_nacidos_antes_2000, int *cant_argen, int *cant_2nacio, int *cant_F_verano, tvecempleados vemp){
	
	int i=0, j, cant_mas_jovenes2000=0, cant_argentinos=0, cant_arg_uru=0, cant_muj_verano=0;
	bool es_verano=false;
	char fecha[MAX_FECHA];
	
	do{
		
		printf ("|-Ingrese el/los apellido/s y el/los nombre/s del empleado (coloque 'f' para finalizar la carga):\n");
		
		fflush(stdin);
		fgets (vemp[i].apellido_nombre, MAX, stdin);
		
		if (*vemp[i].apellido_nombre != 'f'){
		
			fflush(stdin);
			
			j=0;
			
			while (vemp[i].apellido_nombre[j]!=','){
				
				vemp[i].apellido[j]=vemp[i].apellido_nombre[j];
				j++;
			}
			
			printf ("\n|-Ingrese fecha de nacimiento (aaaa-mm-dd): \n");
			fgets (fecha, MAX, stdin);
			calcular_datos_fecha(fecha, &es_verano);
			strcpy(vemp[i].nacimiento, fecha);
			printf ("\n");	
			
			vemp[i].nac_mayor_2000=validar_dato_booleano(vemp[i], es_verano, dato_nac_mayor_2000);
			if (vemp[i].nac_mayor_2000==false){
				
				cant_mas_jovenes2000++;
			}
			
			printf ("\n|-Ingrese sexo (M/F): \n");
			fflush (stdin);
			scanf("%c", &vemp[i].sexo);
			
			validar_sexo (&vemp[i].sexo);
			
			vemp[i].muj_no_nac_vera=validar_dato_booleano(vemp[i], es_verano, dato_muj_no_nac_vera);
			if (vemp[i].muj_no_nac_vera==false){
				
				cant_muj_verano++;
			}
			
			obtener_nacionalidad(vemp[i].vecnaciones);
			
			vemp[i].arg_uru_1nac=validar_dato_booleano(vemp[i], es_verano, dato_arg_uru_1nac);
			if (vemp[i].arg_uru_1nac==false){
				
				cant_arg_uru++;
			}
			
			if ((vemp[i].vecnaciones[1])==true){
				
				cant_argentinos++;
			}
			
			i++;
		}
		
	}while ((*vemp[i].apellido_nombre != 'f') && (i != MF));
	
	*ml = i-1;
	*cantidad_nacidos_antes_2000=cant_mas_jovenes2000-1;
	*cant_2nacio=cant_arg_uru-1;
	*cant_F_verano=cant_muj_verano-1;
	*cant_argen=cant_argentinos;
}

void ordenar_vector (tvecempleados emp, int minimo, int maximo, dato dat) {
	
	int i=0, j;
	templeado aux_emp;
	bool cont_ciclo=true;
	
	while ((i<maximo) && (cont_ciclo==true)) {
		
		cont_ciclo=false;
		
		for (j=minimo; j<(maximo-i); j++) {
			
			if (((dat==nac_mayor_2000) && (emp[j].nac_mayor_2000>emp[j+1].nac_mayor_2000)) || 
			((dat==arg_uru_1nac) && (emp[j].arg_uru_1nac>emp[j+1].arg_uru_1nac)) ||
			((dat==apellido) && (strcmp(emp[j].apellido, emp[j+1].apellido)>0)) ||
			((dat==muj_no_nac_vera) && (emp[j].muj_no_nac_vera>emp[j+1].muj_no_nac_vera)) ||
			((dat==fecha) && (strcmp(emp[j].nacimiento, emp[j+1].nacimiento)>0))){
				
				aux_emp=emp[j];
				
				emp[j]=emp[j+1];
				
				emp[j+1]=aux_emp;
				
				cont_ciclo=true;
			}
		}
	    
	    i++;
	}
}

void mostrar_vector (tvecempleados emp, int cant_min, int cant_max){
	
	int i, j;
	
	printf("\n");
	
	if (cant_max>=0) {
		
		for (i=cant_min; i<=cant_max; i++) {
			
			printf("Apellido/s y nombre/s del empleado: %s", emp[i].apellido_nombre);
			
			printf("Fecha de nacimiento: %s\n", emp[i].nacimiento);
		    
		    printf("Sexo: %c\n", emp[i].sexo);
		    
		    printf("Nacionalidad/es: ");
		    
		    for (j=1; j<MAX_NAC; j++){
		    	
		    	if (emp[i].vecnaciones[j]==true){
		    		
		    		printf("%s ", ((j==argentina) ? print_arg : (j==uruguaya) ? print_uru : (j==chilena) ? print_chi :
		            (j==peruana) ? print_per : (j==boliviana) ? print_bol : (j==paraguaya) ? print_par : print_bra));
				}
			}
			
			printf("\n\n");
		}
	}
	
	else {
		
		printf("No hay datos con las caracteristicas solicitadas.\n");
	}
}

void elegir_opcion (int *opcion){
	
	int aux_opcion;
	printf ("\n\t\t\t|----MENU----|\n");
	
	printf ("1. Mostrar nacidos antes del 2000 ordenado por nacimiento.\n");
	printf ("2. Buscar y mostrar datos de apellido de mujer ingresado por usuario, nacidas en verano.\n");
	printf ("3. Mostrar Uruguayos y Argentinos con mas de 1 nacionalidad.\n");
	printf ("4. Mostrar porcentaje de empleados Argentinos.\n");
	printf ("0. salir.\n");
	printf ("\n|-seleccione la opcion a realizar o 0 para salir: ");
	
	scanf ("%i", &aux_opcion);
	validar_datos (&aux_opcion, 4, 0);
	
	*opcion=aux_opcion;
}
	
void buscar_por_apellido (tvecempleados emp, int cant_F_nacidas_ver){
	
	int i=0, j=-1;
	char aux_apellido[MAX];
	bool es_igual=false;
	
	printf("\nIngrese un apellido para buscar coincidencias:\n");
	fflush(stdin);
	fgets(aux_apellido, MAX, stdin);
	
	while ((i<=cant_F_nacidas_ver) && (es_igual==false)){
		
		if (strstr(aux_apellido, emp[i].apellido)!=0){
			
			j=i+1;
			es_igual=true;
			
			while ((j<=cant_F_nacidas_ver) && (es_igual==true)){
				
				if (strstr(aux_apellido, emp[j].apellido)!=0){
					
					j++;
				}
				
				else{
					
					es_igual=false;
				}
			}
			
			es_igual=true;
		}
		
		else{
			
			i++;
		}
	}
	
	mostrar_vector (emp, i, j-1);
}

void opciones_a_ejecutar (int ml, int cant_antes_2000, int cant_arg_uru_2nacio, int cant_F_nacidas_ver, int cant_arg, tvecempleados emp, int opcion) {
	
	float porcentaje;
	int total=ml+1;
	
	switch (opcion) {
		
		case 1:
			
			ordenar_vector (emp, min_pos_vec, ml, dato_nac_mayor_2000);
			ordenar_vector (emp, min_pos_vec, cant_antes_2000, dato_fecha);
			mostrar_vector (emp, min_pos_vec, cant_antes_2000);
			break;
			
		case 2:  
		
		    ordenar_vector (emp, min_pos_vec, ml, dato_muj_no_nac_vera);
	        ordenar_vector (emp, min_pos_vec, cant_F_nacidas_ver, dato_ape);
			buscar_por_apellido(emp, cant_F_nacidas_ver);
			break;
			
		case 3:
			
			ordenar_vector (emp, min_pos_vec, ml, dato_arg_uru_1nac);
			mostrar_vector (emp, min_pos_vec, cant_arg_uru_2nacio);
			break;
			
		case 4:
			
			porcentaje=(((float) cant_arg)/((float)total))*100;
			printf("\nHay un %.2f%% de argentinos sobre el total de empleados.\n", porcentaje);
			break;
			
		default:
			
			printf ("\n\t\tAdios!!...\n");
			break;
	}
}

int main (){
	
	int ml, cant_antes_2000, cant_arg_uru_2nacio, cant_F_nacidas_ver, cant_arg; 
	int opciones;
	tvecempleados vemp;
	
	cargar_datos (&ml, &cant_antes_2000, &cant_arg, &cant_arg_uru_2nacio, &cant_F_nacidas_ver, vemp);
	
	do{
		
		elegir_opcion (&opciones);
		
		opciones_a_ejecutar (ml, cant_antes_2000, cant_arg_uru_2nacio, cant_F_nacidas_ver, cant_arg, vemp, opciones);
		
	}while (opciones!=0);
	
	return 0;
}
