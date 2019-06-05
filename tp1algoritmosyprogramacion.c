#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MF 500
#define MAX 50
#define MAX_NAC 8
#define MAX_FECHA 11
#define mayor_2000 "2000-01-01"
#define dato_ape_nomb 0
#define dato_fecha 1
#define dato_sexo 2
#define dato_nac 3
#define dato_nac_mayor_2000 4
#define dato_arg_uru_1nac 5
#define dato_muj_no_nac_vera 6
#define print_arg "argentina"
#define print_uru "uruguaya"
#define print_chi "chilena"
#define print_per "peruana"
#define print_bol "boliviana"
#define print_par "paraguaya"
#define print_bra "brasilera"
#define min_pos_vec 0

typedef enum {false, true} bool;
enum  {argentina = 1, uruguaya, chilena, peruana, boliviana, paraguaya, brasilenia}naciones;
typedef enum { apellido_nombre, fecha, sexo, ciudadania, nac_mayor_2000, arg_uru_1nac, muj_no_nac_vera } dato;
typedef int tvecnaciones [MAxNAC];

//typedef tnacion vecnacion[7];

typedef struct{
	
	char apellido_nombre[MAX];
	char nacimiento[MAX_FECHA];
	char sexo;
	tvecnaciones vecnaciones;
	bool nac_mayor_2000; // dato que devuelve 0 (FALSE) para empleados nacidos antes del 2000 y devuelve 1 (TRUE) para empleados nacidos despues del 2000.
	bool arg_uru_1nac; // dato que retorna 0 (FALSE) para empleados arg o uru con 2 o mas nacionalidades y retorna 1 (TRUE) para otra condicion de nacionalidad.
	bool muj_no_nac_vera;    
	//vecnacion naciones;
	
}templeado;

typedef templeado tvecempleados[MF];

/////////////////////////////////////////////////////////////////////////////

void cargar_datos (int *ml, tvecempleados vemp);

	void validar_fecha (int *dia, int *mes, int *anio);
	void validar_sexo (char *sexo);
	void obtener_nacionalidad (tvecnaciones vecnaciones);
	void validar_datos (int *num, int max, int min);
        int pasar_texto_a_entero (char texto[MAX_FECHA], int min, int max);
        void pasar_enteros_a_validar (char texto[MAX_FECHA], bool *estacion_verano);
        bool validar_dato_booleano (templeado emp, bool verano_si, dato var);
float porcArgentinos (int ml, tvecempleados vemp);
void ordenar_vector (tvecempleados emp, int minimo, int maximo, dato dat);
void mostrar_vector (tvecempleados emp, int cant_min, int cant_max);

/////////////////////////////////////////////////////////////////////////////

void main (){
	
	int ml, cant_antes_2000, cant_arg_uru_2nacio, cant_F_nacidas_ver, cant_arg;
	tvecempleados vemp;
	
	//Punto A
	cargar_datos (&ml, &cant_antes_2000, &cant_arg, &cant_arg_uru_2nacio, &cant_F_nacidas_ver, vemp);
	
	//Punto B
	ordenar_vector (vemp, min_pos_vec, ml, dato_nac_mayor_2000);
	ordenar_vector (vemp, min_pos_vec, cant_antes_2000, dato_fecha);
	mostrar_vector (vemp, min_pos_vec, cant_antes_2000);
	
	//Punto C
	mostrar_vector (vemp, min_pos_vec, ml, dato_muj_no_nac_vera);
	
	//Punto D
	
	ordenar_vector (vemp, min_pos_vec, ml, dato_arg_uru_1nac);
	mostrar_vector (vemp, min_pos_vec, cant_arg_uru_2nacio);
	
	//Punto E
	
	indicar_porcentaje_empleados_arg (cant_arg, ml);
	printf("\n");
	system("pause");
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
		printf ("\n\tValidando opcion...\n");	
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
	
			mujeresmismoapellido (ml, vemp, apellido);
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

void pasar_enteros_a_validar (char texto[MAX_FECHA], bool *estacion_verano) {
	
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
	
	if ((dia>=21) && (mes==12) || ((mes>=1) && (mes<=2)) || ((dia<=20) && (mes==3))){
		
		*estacion_verano=true;
	}
	
	strcpy(texto, aux_fecha);
	
}

bool validar_dato_booleano (templeado emp, bool verano_si, dato var) {
	
	int i=1, aux_cant=0;
	char aux_fecha;
	bool aux_bool=false;
	
	switch (var){
		
		case dato_nac_mayor_2000:
			
			if (strcmp(emp.nacimiento, mayor_2000)>=0){
				
				aux_bool=true;
			}
			break;
		
		case dato_arg_uru_1nac:
			
			if ((emp.vecnaciones[1]==true) || (emp.vecnaciones[2]==true)){
				
				while ((i<MAX_NAC) && (aux_cant==0)){
					
					if (((emp.vecnaciones[1]==true) && (emp.vecnaciones[i+1]==true)) || 
					((emp.vecnaciones[2]==true) && (emp.vecnaciones[1]==false) && (emp.vecnaciones[i+1]==true))){
						
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
		    
			if ((verano_si==false) || ((emp.sexo=='M') || (emp.sexo=='m'))){
				
				aux_bool=true;
			}
			break;   
	}
	
	return aux_bool;
}
void cargar_datos (int *ml, int *cantidad_nacidos_antes_2000, int *cant_argen, int *cant_2nacio, int *cant_F_verano, tvecempleados vemp){
	
	int i=0,cant_mas_jovenes2000=0, cant_argentinos=0, cant_arg_uru=0, cant_muj_verano=0;
	bool es_verano=false;
	char fecha[MAX_FECHA];
	
	do{
		
		
		printf ("|-Ingrese el/los apellido/s y el/los nombre/s del empleado (coloque 'f' para finalizar la carga): ");
		
		fflush(stdin);
		fgets (vemp[i].apellido_nombre, MAX, stdin);
		
		
		
		if (*vemp[i].nombre != 'f'){
		
			printf ("\n|-Ingrese fecha de nacimiento (aaaa-mm-dd): ");
			fgets (fecha, MAX_FECHA, stdin);
			pasar_enteros_a_validar(fecha, &es_verano);
			strcpy(vemp[i].nacimiento, fecha);
			printf ("\n");	
			
			vemp[i].nac_mayor_2000=validar_dato_booleano(vemp[i], es_verano, dato_nac_mayor_2000);
			if (vemp[i].nac_mayor_2000==false){
				
				cant_mas_jovenes2000++;
			}
			printf ("\n");	
			system("pause");
			
			printf ("\n|-Ingrese sexo (M/F): ");
			fflush (stdin);
			scanf("%c", &vemp[i].sexo);
			
			printf ("\n|-Validando sexo...\n");
			validar_sexo (&vemp[i].sexo);
			
			vemp[i].muj_no_nac_vera=validar_dato_booleano(vemp[i], es_verano, dato_muj_no_nac_vera);
			if (vemp[i].muj_no_nac_vera==false){
				
				cant_muj_verano++;
			}
			
			system ("pause");
			
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
		
	}while ((*vemp[i].nombre != 'f') && (i != MF));
	
        *ml = i-1;
	*cantidad_nacidos_antes_2000=cant_mas_jovenes2000-1;
	*cant_2nacio=cant_arg_uru-1;
	*cant_F_verano=cant_muj_verano-1;
	*cant_argen=cant_argentinos;
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

void validar_sexo (char *letra){
	
	while (( (*letra != 'f') && (*letra != 'F') ) && ( (*letra != 'm') && (*letra != 'M') )){
		
		printf ("\n\tError...");
		printf ("\n\t|-Reingrese sexo (M/F): ");
		fflush (stdin);
		scanf ("%c", letra);
		
			
	}
	printf ("\n\t->sexo validado!\n");
	printf ("\n");
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

void ordenar_vector (tvecempleados emp, int minimo, int maximo, dato dat) {
	
	int i=0, j;
	templeado aux_emp;
	bool cont_ciclo=true;
	
	while ((i<maximo) && (cont_ciclo==true)) {
		
		for (j=minimo; j<(maximo-i); j++) {
			
			cont_ciclo=false;
			
			if (((dat==nac_mayor_2000) && (emp[j].nac_mayor_2000>emp[j+1].nac_mayor_2000)) || 
			((dat==arg_uru_1nac) && (emp[j].arg_uru_1nac>emp[j+1].arg_uru_1nac)) ||
			((dat==apellido_nombre) && (strcmp(emp[j].apellido_nombre, emp[j+1].apellido_nombre)>0)) ||
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
	
	int i, j, k=0, l;
	tvecnaciones aux_nac;
	
	if (cant_max>=0) {
		
		for (i=cant_min; i<=cant_max; i++) {
			
			printf("Apellido/s y nombre/s del empleado: %s", emp[i].apellido_nombre);
		
		    printf("Fecha de nacimiento: %s\n", emp[i].nacimiento);
		
		    printf("Sexo: %c\n", emp[i].sexo);
		
		    for (j=1; j<MAX_NAC; j++){
		    	
		    	if (emp[i].vecnaciones[j]==true){
		    		
		    		aux_nac[k]=j;
		    		k++;
				}
			}
			
			printf("Nacionalidad/es: ");
			
			for (l=0; l<k; l++){
				
				printf("%s ", ((aux_nac[l]==argentina) ? print_arg : (aux_nac[l]==uruguaya) ? print_uru : (aux_nac[l]==chilena) ? print_chi : 
				(aux_nac[l]==peruana) ? print_per : (aux_nac[l]==boliviana) ? print_bol : (aux_nac==paraguaya) ? print_par : print_bra));
			}
			
			printf("\n");
		}
	}
	
	else {
		
		printf("No hay datos con las caracteristicas solicitadas.\n");
	}
}

void indicar_porcentaje_empleados_arg (int cantidad_arg, int max_logic){
	
	float porcentaje;
	int total=max_logic+1;
	
	porcentaje=(((float) cantidad_arg)/((float)total))*100;
	
	printf("Hay un %.2f%% de argentinos sobre el total de empleados\n", porcentaje);
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

const char* DameNacionalidad(int i)
{
    const char* Nacionalidades[] = {"Argentina","Bolivia","Brasilenia","Chilena","Paraguaya","Peruana","Uruguaya"};
    return Nacionalidades[i];
}

void NumANacionalidad(int nac[], char* Nacs)
{
    int i;
    int index = 0;
    for (i = 0; i < 7; i++)
    {
        if(nac[i] == 1)
        {
            if(index > 0)
            {
                Nacs[index] = ',';
                index++;
                Nacs[index] = ' ';
                index++;
            }
            const char* nacstr = DameNacionalidad(i);
            strcpy(Nacs + index, nacstr);
            index += strlen(nacstr);
        }
    }
    Nacs[index] = '\0';
}

void MostrarEmpleado(templeado Emp)
{
    char* sexostr[] = {"masculino","femenino"};
    int sexoIndex = (Emp.sexo == 'm') ? 0 : 1;
    char Nacs[100];
    NumANacionalidad(Emp.vecnaciones, Nacs);

    printf("El empleado es: %s %s, ", Emp.apellido, Emp.nombre);
    printf("nacio en la fecha %d - %d - %d, ", Emp.fnacimiento.dia, Emp.fnacimiento.mes, Emp.fnacimiento.anio);
    printf("es de sexo %s ", sexostr[sexoIndex]);
    printf("y es de nacionalidad %s.\n", Nacs);
}

int MultUruOArg(int nac[])
{
    int i;
    int cant = 0;
    for(i = 0; i < MAxNAC; i++)
    {
        if(nac[i] == 1)
        {
            cant++;
        }
        if((nac[0] == 1 || nac[6] == 1) && cant >= 2)
        {
            return 1;
        }
    }

    return 0;

}

void MostrarEmpAU(tvecempleados Emps,int ML)
{
    int i;
    for(i = 0; i < ML; i++)
    {
        if(MultUruOArg(Emps[i].vecnaciones) == 1)
        {
            MostrarEmpleado(Emps[i]);
        }
    }
}

void mujeresmismoapellido (tvecempleados emp, int ml, apellidoaux)
{
	int i;
	char busqueda;
	
	for(i=0; i<=ml; i++)
	{
	busqueda = strstr (emp[i].apellido, apellidoaux);
	if (bool muj_no_nac_vera == false)
		{	
			mostrar_vector (emp, 0, ml, dato_muj_no_nac_vera);	
		}
	}
}

