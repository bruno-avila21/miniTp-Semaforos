# SOR-Semáforos-1S-2021
Trabajo Práctico Semáforos primer semestre año 2021

#### Introduccion:
Para realizar el trabajo practico sobre Threads y Semaforos, tuve en cuenta los videos subidos a repoUNGS y ademas, informarme sobre distintos metodos en el uso de la programacion en C. En primera instancia, decidi plantear el problema en cuestion y realizar un pseudocodigo para luego llevarlo a la implementacion.
****
### Desarrollo:

En primer instancia, como mencione antes, realice el siguiente pseudocodigo. Teniendo en cuenta que p()->wait() y que v()->signal(). 

------------
*Utilizo 9 semaforos. Para cada paso de la receta por lo menos 1 semaforo, gracias a esto puedo tener orden al momento de ejecutar la receta*
- Sem1=0
- Sem2=0
- Sem3=0
- Sem4=0
- Sem5=0
- Sem6=0
- Sem7=0
- Sem8=0
- Sem9=0

*En el caso particular donde solamente uno o dos equipo puede realizar la accion, implemente otros semaforos. En el caso de SemEspera2, se inicializa en 2, dado que 2 equipos pueden ocupar el horno*

- SemEspera=1
- SemEspera1=1
- SemEspera2=2

|   |P(Sem1)   |P(Sem2)   |P(Sem3)   |P(Sem4)   |P(Sem5)   | P(Sem6)  |P(Sem7)   |P(Sem8)   |
| :------------ | :------------ | :------------ | :------------ | :------------ | :------------ | :------------ | :------------ | :------------ |
|  cortar(); |mezclar();   |usar();   |agregar();   |empanar();  |cocinar();   |hornear();   | cortar1();  |armar();   |
|  V(Sem1) |V(Sem2)   |V(Sem3)   |V(Sem4)   |V(Sem5)   |V(Sem6)   |V(Sem7)   |V(Sem8)   |   |

En el momento de la implementacion en C, para poder ver con detalles si realmente los semaforos funcionaban correctamente, utilice la funcion usleep().

Para comenzar a desarrollar el codigo, complente los threads y semaforos que faltaban en el main y en la funcion ejecutarReceta del archivo que se nos entrego.

Una vez codificado y funcionando, me informe de los distintos metodos que se podian utilizar para crear, leer y escribir un archivo de formato .txt. Opte por el metodo que mejor me funciono el cual utiliza las funciones: **fopen("rt"; para leer y "wt"; para escribir), fgets (Almacena cada linea del archivo), fclose(Para cerrar el archivo), puts(Para mostrar lo que se almaceno con fgets), fprintf() y fputs(), las ultimas dos funciones son para escribir el archivo nuevo que se crea**.

#### Conclusion:

En particular, el trabajo practico se me complico mucho, dado que nunca habia programado en C y casi todas las funciones que utilice, las use por primera vez. Sin embargo gracias al tiempo extra que nos otorgaron pude finalizarlo, agregando la lectura y escritura de un archivo de tipo ".txt" y mejorando algunas partes de la implementacion al momento de ejecutarse. Tambien pude investigar sobre el uso de git para desarrollar el informe.
