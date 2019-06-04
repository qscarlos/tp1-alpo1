#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MF 500
#define MAX 50
#define MAxNAC 8

typedef enum {false, true} bool;
enum  {argentina = 1, uruguaya, chilena, peruana, boliviana, paraguaya, brasilenia}naciones;
typedef int tvecnaciones [MAxNAC];

//typedef tnacion vecnacion[7];
typedef struct{
	
	int dia, mes, anio;
}tfecha;

typedef struct{
	
	char nombre[MAX];
	char apellido [MAX];
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
float porcArgentinos (int ml, tvecempleados vemp);

/////////////////////////////////////////////////////////////////////////////

void main (){
	
	int ml;
	char apellido[MAX];
	tvecempleados vemp;
	
	cargar_datos (&ml, vemp);
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
		
		
		printf ("|-Ingrese nombres o 'f' para finalizar: ");
		
		fflush(stdin);
		fgets (vemp[i].nombre, MAX, stdin);
		
		
		
		if (*vemp[i].nombre != 'f'){
		
			printf ("\n|-Ingrese apellidos: ");
		
			fflush(stdin);
			fgets (vemp[i].apellido, MAX, stdin);
			
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
		
	}while ((*vemp[i].nombre != 'f') && (i != MF));
	
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
