#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX;

typedef struct
{
    // Datos de alumno
    char *tiempo_atencion;
    char *Edad;
    char *Gravedad;
    char *Discapacidad;

} paciente;
typedef struct nodo
{
    paciente Paciente;
    struct nodo *siguiente;
    struct nodo *anterior;
} nodo;
typedef struct Lista
{
    nodo *cabecera;
    int tam;
} Lista;

Lista *miLista;
void Insertar(paciente P);
void mostrar();

int main()
{

    FILE *archivo = fopen("datos.txt","r") ; // Abrir archivo
    miLista = (Lista*)malloc(sizeof(Lista));
    if(miLista == NULL)
        printf("Memoria insuficiente.");
    miLista->tam = 0;
    if(archivo == NULL)
    {
        printf("Error! No se pudo abrir el archivo") ;
        exit(-1) ;
    }
    else
    {
        fscanf(archivo,"%d", &MAX) ;
        printf("Cantidad de datos: %d\n\n", MAX) ;
        printf("Valores leidos del archivo:\n\n", MAX) ;
    }

    int tiempo_atencion[MAX], pacientes[MAX], tiempo_espera[MAX], tiempo_total[MAX], prioridad[MAX];

    /*
        Burst time = tiempo de atencion
        Waiting time = el nombre lo dice todo crack
        process = pacientes
        turnaround = tiempo total
        priority = el nombre lo dice todo crack x2
    */

    int i, j, posicion, temp;
    float average_tiempo_espera, average_tiempo_total;

    int gEdad, gGravedad, gDiscapacidad;   //variables para definir el grado de prioridad

    int Edad, Orden;
    char Gravedad[10], Discapacidad[2];   //Variables

    // Datos de paciente
    paciente webo[MAX];
    // Lectura de datos
    for(int i=0; i<MAX; i++)
    {
        int sum = 0;
        //reservamos memoria para las variables
        webo[i].tiempo_atencion = (char*)malloc(sizeof(10));
        webo[i].Edad = (char*)malloc(sizeof(10));
        webo[i].Gravedad = (char*)malloc(sizeof(10));
        webo[i].Discapacidad = (char*)malloc(sizeof(10));
        fscanf(archivo,"%s\t%s\t%s\t%s", webo[i].tiempo_atencion, webo[i].Edad, webo[i].Gravedad, webo[i].Discapacidad) ;
        Edad = atoi(webo[i].Edad);
        if (Edad < 21)
        {
            gEdad = 2;
        }
        else if (Edad < 51)
        {
            gEdad = 3;
        }
        else
        {
            gEdad = 1;
        }
        tiempo_atencion[i] = atoi(webo[i].tiempo_atencion);

        strcpy(Gravedad,webo[i].Gravedad);
        if(Gravedad == "leve")
        {
            gGravedad = 3;
        }
        else if(Gravedad == "medio")
        {
            gGravedad = 2;
        }
        else if(Gravedad == "grave")
        {
            gGravedad = 1;
        }

        strcpy(Discapacidad,webo[i].Discapacidad);

        if(Discapacidad == "si")
        {
            gDiscapacidad = 1;
        }
        else if(Discapacidad == "no")
        {
            gDiscapacidad = 2;
        }
        sum = gEdad + gGravedad + gDiscapacidad;
        prioridad[i] = sum;
        Insertar(webo[i]);
        pacientes[i] = i;
    }
    fclose(archivo) ; // Cierre de archivo
    // Reporte
    mostrar();

    //Determinar prioridad
    for(i = 0; i < MAX; i++)
    {
        posicion = i;
        for(j = i + 1; j < MAX; j++)
        {
            if(prioridad[j] < prioridad[posicion])
            {
                posicion = j;
            }
        }

        //inserta auxiliar temp para a�adir valores en cada bucle
        temp = prioridad[i];
        prioridad[i] = prioridad[posicion];
        prioridad[posicion] = temp;

        temp = tiempo_atencion[i];
        tiempo_atencion[i] = tiempo_atencion[posicion];
        tiempo_atencion[posicion] = temp;

        temp = pacientes[i];
        pacientes[i] = pacientes[posicion];
        pacientes[posicion] = temp;
    }
    int sum = 0;
    tiempo_espera[0] = 0;//inicio de tiempo espera
    for(i = 1; i < MAX; i++) //por cada proceso debajo del limite
    {
        tiempo_espera[i] = 0; //inicializa el valor de tiempo espera[i] en 0
        for(j = 0; j < i; j++)//por cada posicion del array
        {
            tiempo_espera[i] = tiempo_espera[i] + tiempo_atencion[j]; //se suma el tiempo atencion del programa para siguiente proceso
        }
        sum = sum + tiempo_espera[i]; //suma total de todos los tiempos
    }
    average_tiempo_espera = sum / MAX; //promedio de tiempos totales de todos los procesos
    sum = 0;


    //suma de atencion + espera para el  tiempo total
    printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n");
    for(i = 0; i < MAX; i++)
    {
        tiempo_total[i] = tiempo_atencion[i] + tiempo_espera[i];
        sum = sum + tiempo_total[i];
        printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\n", pacientes[i], tiempo_atencion[i], tiempo_espera[i], tiempo_total[i]);
    }
    average_tiempo_total = sum / MAX; //promedio de tiempo total
    printf("\nAverage Waiting Time:\t%f", average_tiempo_espera);
    printf("\nAverage Turnaround Time:\t%f\n", average_tiempo_total);
    return 0;

}

void Insertar(paciente P)
{
    nodo *nuevo;
    nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->Paciente = P;

    if( miLista->tam == 0)
    {
        nuevo->siguiente = NULL;
        nuevo->anterior = nuevo;
        miLista->cabecera = nuevo;
        miLista->tam++;
    }
    else if( miLista->tam == 1)
    {
        nuevo->siguiente = NULL;
        nuevo->anterior = miLista->cabecera;
        miLista->cabecera->siguiente = nuevo;
        miLista->cabecera->anterior = nuevo;
        miLista->tam++;
    }
    else
    {
        nuevo->siguiente = miLista->cabecera->siguiente;
        nuevo->anterior = miLista->cabecera;
        miLista->cabecera->siguiente = nuevo;
        miLista->tam++;
    }
}
void mostrar()
{

    nodo *actual;
    actual = miLista->cabecera;
    printf("Tiempo de atencion\t   Edad\t\tGravedad\t  Discapacidad\n");

    while (actual != NULL)
    {
        printf("%15s %15s %15s %15s\n", actual->Paciente.tiempo_atencion, actual->Paciente.Edad, actual->Paciente.Gravedad, actual->Paciente.Discapacidad) ;

        actual = actual->siguiente;
    }

}
