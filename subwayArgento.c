#include <stdio.h>      // libreria estandar
#include <stdlib.h>     // para usar exit y funciones de la libreria standard
#include <string.h>
#include <pthread.h>    // para usar threads
#include <semaphore.h>  // para usar semaforos
#include <unistd.h>


#define LIMITE 100


//Puntero al archivo para escribir

FILE* fichero1;

//Pasos de la receta
	char cadena1 [LIMITE];     
	char cadena2 [LIMITE];
	char cadena3 [LIMITE];
	char cadena4 [LIMITE];
	char cadena5 [LIMITE];
	char cadena6 [LIMITE];
	char cadena7 [LIMITE];
	char cadena8 [LIMITE];
	char cadena9 [LIMITE];
	char cadena10 [LIMITE];
	char cadena11 [LIMITE];
	char cadena12 [LIMITE];


//Semaforos Compartidos
sem_t sem1;
sem_t sem2;
sem_t sem3;


//creo estructura de semaforos 
struct semaforos {
	sem_t sem_mezclar;
	sem_t sem_usar;
	sem_t sem_cocinar;
	sem_t sem_hornear;
	sem_t sem_agregar;
	sem_t sem_empanar;
	sem_t sem_cortar;
	sem_t sem_armar;

};

//creo los pasos con los ingredientes

struct paso {
   char accion [LIMITE];
   char ingredientes[4][LIMITE];
   
};

//creo los parametros de los hilos 
struct parametro {
 int equipo_param;
 struct semaforos semaforos_param;
 struct paso pasos_param[8];
};



void* cortar(void *data) {


	//creo el puntero para pasarle la referencia de memoria (data) del struct pasado por parametro (la cual es un puntero). 
	struct parametro *mydata = data;

	//llamo a la funcion imprimir le paso el struct y la accion de la funcion

	printf("\tEquipo %d -",mydata->equipo_param);
	puts (cadena1);

	//Escribo el archivo "resultado.txt"

	fprintf(fichero1,"\tEquipo %d -",mydata->equipo_param);
	fputs(cadena1,fichero1);

	//uso sleep para simular que que pasa tiempo
	usleep( 1000000 );

	//doy la señal a la siguiente accion (cortar me habilita mezclar)
	sem_post(&mydata->semaforos_param.sem_mezclar);
	

}


void* mezclar(void *data){
	char *accion="mezclar";

	struct parametro *mydata=data;

	sem_wait(&mydata->semaforos_param.sem_mezclar);

	usleep(80000);
//	imprimirAccion (mydata,accion);
	printf("\tEquipo %d -",mydata->equipo_param);
	
	puts(cadena2);

	//Escribo el archivo "resultado.txt"

	fprintf(fichero1,"\tEquipo %d -",mydata->equipo_param);
	fputs(cadena2,fichero1);


	usleep(50000);

	sem_post(&mydata->semaforos_param.sem_usar);

}

void* usar(void *data){
//	char *accion="usar";

	struct parametro *mydata=data;

	sem_wait(&mydata->semaforos_param.sem_usar);

	sem_wait(&sem1);

	printf("\tEquipo %d -",mydata->equipo_param);
	puts(cadena3);

	//Escribo el archivo "resultado.txt"

	fprintf(fichero1,"\tEquipo %d -",mydata->equipo_param);
	fputs(cadena3,fichero1);

	usleep(2000000);
	printf("\tEquipo %d -",mydata->equipo_param);
	puts(cadena4);

	//Escribo el archivo "resultado.txt"

	fprintf(fichero1,"\tEquipo %d -",mydata->equipo_param);
	fputs(cadena4,fichero1);


	sem_post(&sem1);
	sem_post(&mydata->semaforos_param.sem_agregar);

}


void* agregar(void *data){
	char *accion="agregar";

	struct parametro *mydata=data;

	sem_wait(&mydata->semaforos_param.sem_agregar);

	usleep(80000);
	printf("\tEquipo %d -",mydata->equipo_param);
	puts(cadena5);	

	//Escribo el archivo "resultado.txt"

	fprintf(fichero1,"\tEquipo %d -",mydata->equipo_param);
	fputs(cadena5,fichero1);

	usleep(50000);

	sem_post(&mydata->semaforos_param.sem_empanar);


}


void* empanar(void *data){
	char *accion="empanar";

	struct parametro *mydata=data;

	sem_wait(&mydata->semaforos_param.sem_empanar);

	usleep(80000);
	printf("\tEquipo %d -",mydata->equipo_param);
	puts(cadena6);

	//Escribo el archivo "resultado.txt"

	fprintf(fichero1,"\tEquipo %d -",mydata->equipo_param);
	fputs(cadena6,fichero1);


	usleep(50000);

	sem_post(&mydata->semaforos_param.sem_cocinar);


}


void* cocinar(void *data){
//	char *accion="cocinar";

	struct parametro *mydata=data;

	sem_wait(&mydata->semaforos_param.sem_cocinar);
	sem_wait(&sem2);


	printf("\tEquipo %d -",mydata->equipo_param);
	puts(cadena7);

	//Escribo el archivo "resultado.txt"

	fprintf(fichero1,"\tEquipo %d -",mydata->equipo_param);
	fputs(cadena7,fichero1);	

	usleep(5000000);

	printf("\tEquipo %d -",mydata->equipo_param);
	puts(cadena8);

	//Escribo el archivo "resultado.txt"

	fprintf(fichero1,"\tEquipo %d -",mydata->equipo_param);
	fputs(cadena8,fichero1);



	sem_post(&sem2);
	sem_post(&mydata->semaforos_param.sem_hornear);


}

void* hornear(void *data){
	char *accion="hornear";

	struct parametro *mydata=data;

	sem_wait(&mydata->semaforos_param.sem_hornear);
	sem_wait(&sem3);

	printf("\tEquipo %d -", mydata->equipo_param);
	puts(cadena9);

	//Escribo el archivo "resultado.txt"

	fprintf(fichero1,"\tEquipo %d -",mydata->equipo_param);
	fputs(cadena9,fichero1);


	usleep(1000000);
	printf("\tEquipo %d -",mydata->equipo_param);
	puts(cadena10);

	//Escribo el archivo "resultado.txt"

	fprintf(fichero1,"\tEquipo %d -",mydata->equipo_param);
	fputs(cadena10,fichero1);

	sem_post(&sem3);
	sem_post(&sem3);

	sem_post(&mydata->semaforos_param.sem_cortar);

	
}

void* cortar1(void *data){
	char *accion="empanar";

	struct parametro *mydata=data;

	sem_wait(&mydata->semaforos_param.sem_cortar);

	usleep(80000);
	printf("\tEquipo %d -",mydata->equipo_param);
	puts(cadena11);

	//Escribo el archivo "resultado.txt"

	fprintf(fichero1,"\tEquipo %d -",mydata->equipo_param);
	fputs(cadena11,fichero1);

	usleep(50000);

	sem_post(&mydata->semaforos_param.sem_armar);


}

void* armar(void *data){
	char *accion="empanar";

	struct parametro *mydata=data;

	sem_wait(&mydata->semaforos_param.sem_armar);

	usleep(80000);
	printf("\tEquipo %d -",mydata->equipo_param);
	puts(cadena12);

	//Escribo el archivo "resultado.txt"

	fprintf(fichero1,"\tEquipo %d -",mydata->equipo_param);
	fputs(cadena12,fichero1);

	usleep(50000);


	pthread_exit(NULL);
}



void* ejecutarReceta(void *i) {

	// Leo la receta
	
    	FILE* fichero;
    	fichero = fopen("receta.txt", "rt");
    	fgets (cadena1, LIMITE, fichero);
    	fgets (cadena2, LIMITE, fichero);
    	fgets (cadena3, LIMITE, fichero);
	fgets (cadena4, LIMITE, fichero);
	fgets (cadena5, LIMITE, fichero);
	fgets (cadena6, LIMITE, fichero);
	fgets (cadena7, LIMITE, fichero);
	fgets (cadena8, LIMITE, fichero);
	fgets (cadena9, LIMITE, fichero);
	fgets (cadena10, LIMITE, fichero);
	fgets (cadena11, LIMITE, fichero);
	fgets (cadena12, LIMITE, fichero);


    	fclose(fichero);

	//Para escribir

	fichero1= fopen("resultado.txt","wt");

	
	//variables semaforos

	sem_t sem_mezclar;
	sem_t sem_usar;

	sem_t sem_agregar;
	sem_t sem_empanar;

	sem_t sem_cocinar;
	sem_t sem_hornear;

	sem_t sem_cortar;
	sem_t sem_armar;


	
	//variables hilos
	pthread_t p1; 
	pthread_t p2;
	pthread_t p3; 
	pthread_t p4;
	pthread_t p5; 
	pthread_t p6;
	pthread_t p7; 
	pthread_t p8; 
	pthread_t p9; 

	
	//numero del equipo (casteo el puntero a un int)

	int p = *((int *) i);
	
	printf("Ejecutando equipo %d \n", p);

	//reservo memoria para el struct

	struct parametro *pthread_data = malloc(sizeof(struct parametro));

	//seteo los valores al struct
	
	//seteo numero de grupo
	pthread_data->equipo_param = p;

	//seteo semaforos
	pthread_data->semaforos_param.sem_mezclar = sem_mezclar;

	pthread_data->semaforos_param.sem_usar= sem_usar;

	pthread_data->semaforos_param.sem_agregar= sem_agregar;
	pthread_data->semaforos_param.sem_empanar= sem_empanar;

	pthread_data->semaforos_param.sem_cocinar= sem_cocinar;
	pthread_data->semaforos_param.sem_hornear= sem_hornear;

	pthread_data->semaforos_param.sem_cortar= sem_cortar;
	pthread_data->semaforos_param.sem_armar= sem_armar;

	
	//inicializo los semaforos

	sem_init(&(pthread_data->semaforos_param.sem_mezclar),0,0);
	sem_init(&(pthread_data->semaforos_param.sem_usar),0,0);

	sem_init(&(pthread_data->semaforos_param.sem_agregar),0,0);
	sem_init(&(pthread_data->semaforos_param.sem_empanar),0,0);

	sem_init(&(pthread_data->semaforos_param.sem_cocinar),0,0);
	sem_init(&(pthread_data->semaforos_param.sem_hornear),0,0);

	sem_init(&(pthread_data->semaforos_param.sem_cortar),0,0);
	sem_init(&(pthread_data->semaforos_param.sem_armar),0,0);



	//creo los hilos a todos les paso el struct creado (el mismo a todos los hilos) ya que todos comparten los semaforos 
    int rc;
    rc = pthread_create(&p1,                           //identificador unico
                           NULL,                          //atributos del thread
                                cortar,             //funcion a ejecutar
                                pthread_data);                     //parametros de la funcion a ejecutar, pasado por referencia
	
	//crear demas hilos aqui

	rc= pthread_create(&p2,NULL,mezclar,pthread_data);
	rc= pthread_create(&p3,NULL,usar,pthread_data);

	rc= pthread_create(&p4,NULL,agregar,pthread_data);
	rc= pthread_create(&p5,NULL,empanar,pthread_data);

	rc= pthread_create(&p6,NULL,cocinar,pthread_data);
	rc= pthread_create(&p7,NULL,hornear,pthread_data);

	rc= pthread_create(&p8,NULL,cortar1,pthread_data);
	rc= pthread_create(&p9,NULL,armar,pthread_data);


	//join de todos los hilos
	pthread_join (p1,NULL);
	pthread_join (p2,NULL);
	pthread_join (p3,NULL);
	pthread_join (p4,NULL);
	pthread_join (p5,NULL);
	pthread_join (p6,NULL);
	pthread_join (p7,NULL);
	pthread_join (p8,NULL);
	pthread_join (p9,NULL);


	//valido que el hilo se alla creado bien 
    if (rc){
       printf("Error:unable to create thread, %d \n", rc);
       exit(-1);
     }

	 
	//destruccion de los semaforos 
	sem_destroy(&sem_mezclar);
	sem_destroy(&sem_usar);
	sem_destroy(&sem_cocinar);
	sem_destroy(&sem_hornear);

	sem_destroy(&sem_agregar);
	sem_destroy(&sem_empanar);

	sem_destroy(&sem_cortar);
	sem_destroy(&sem_agregar);


	//destruir demas semaforos 



	//salida del hilo
	 pthread_exit(NULL);
}


int main ()
{

	sem_init(&sem1,0,1);

	sem_init(&sem2,0,1);

	sem_init(&sem3,0,2);


	//creo los nombres de los equipos 
	int rc;
	int *equipoNombre1 =malloc(sizeof(*equipoNombre1));
	int *equipoNombre2 =malloc(sizeof(*equipoNombre2));
	int *equipoNombre3 =malloc(sizeof(*equipoNombre3));
	int *equipoNombre4 =malloc(sizeof(*equipoNombre4));

  	//Equipos
	*equipoNombre1 = 1;
	*equipoNombre2 = 2;
	*equipoNombre3 = 3;
	*equipoNombre4 = 4;

	//creo las variables los hilos de los equipos
	pthread_t equipo1; 
	pthread_t equipo2;
	pthread_t equipo3; 
	pthread_t equipo4;

  
	//inicializo los hilos de los equipos
    rc = pthread_create(&equipo1,                           //identificador unico
                            NULL,                          //atributos del thread
                                ejecutarReceta,             //funcion a ejecutar
                                equipoNombre1); 

    rc = pthread_create(&equipo2,                           //identificador unico
                            NULL,                          //atributos del thread
                                ejecutarReceta,             //funcion a ejecutar
                                equipoNombre2);
	 rc = pthread_create(&equipo3,                           //identificador unico
                            NULL,                          //atributos del thread
                                ejecutarReceta,             //funcion a ejecutar
                                equipoNombre3);
	 rc = pthread_create(&equipo4,                           //identificador unico
                            NULL,                          //atributos del thread
                                ejecutarReceta,             //funcion a ejecutar
                                equipoNombre4);


   if (rc){
       printf("Error:unable to create thread, %d \n", rc);
       exit(-1);
     } 

	//join de todos los hilos
	pthread_join (equipo1,NULL);
	pthread_join (equipo2,NULL);
	pthread_join (equipo3,NULL);
	pthread_join (equipo4,NULL);

	fclose(fichero1);


    pthread_exit(NULL);
}



//Para compilar:   gcc subwayArgento.c -o ejecutable -lpthread
//Para ejecutar:   ./ejecutable
