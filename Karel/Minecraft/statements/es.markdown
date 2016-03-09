# Historia

En uno de sus tantos viajes, Karel logró llegar al (aparentemente) infinito mundo de Minecraft. Allí conoció a Steve, un tipo bastante popular por esos rumbos, quien le pidió ayuda para cavar un nuevo camino en su mapa. Para ello, Steve le dio a Karel una serie de instrucciones representadas por montones de zumbadores empezando en la primer casilla de la primer fila del mundo. Dependiendo del número de zumbadores que se encuentren en cada casilla, la instrucción significa que Karel debe realizar alguna de las siguientes acciones:


+ 1 zumbador: avanzar una casilla al norte y cavar.
+ 2 zumbadores: avanzar una casilla al oeste y cavar.
+ 3 zumbadores: avanzar una casilla al sur y cavar.
+ 4 zumbadores: avanzar una casilla al este y cavar.

Las instrucciones se deben seguir de izquierda a derecha. Karel empezará el recorrido desde la casilla (1, 1). Al iniciar, el mundo empieza con una profundidad de 0 en todas las casillas.


Karel se dio cuenta que al seguir las instrucciones de Steve el camino puede terminar con distintas profundidades. Esto sucede porque cada que Karel pasa por una casilla, la profundidad de ésta aumenta en 1; si pasa por una casilla más de una vez, la profundidad será mayor a 1. Como a Karel no le gusta tener distintas profundidades en su mapa, ha decidido rellenar las desigualdades del camino para que todas las casillas del camino tengan estrictamente una profundidad de 1.


# Problema

Escribe un programa que, dadas las instrucciones de Steve, ayude a Karel a determinar el número de bloques de tierra que necesita de relleno para que al final todas las casillas del camino tengan profundidad 1. Tu programa deberá escribir este número en la posición (1,1).

# Consideraciones

+ Karel tiene infinitos zumbadores en la mochila.
+ Karel puede iniciar en cualquier lugar del mapa, con orientación desconocida.
+ Siguiendo las instrucciones, Karel jamás chocará contra una pared.
+ El mundo de Karel siempre será un cuadrado de 100x100 sin paredes en el interior.
+ Para obtener los puntos de este problema, no importan la posición ni orientación final de Karel, sólo los zumbadores en la posición (1, 1).

******

# Ejemplo Minecraft

![Ejemplo](/img/e7a5fd421b8ddad1e8abde21fa998328a2edb1ee.png)

La respuesta de este ejemplo es 1 porque hay una casilla por la que Karel pasó 2 veces, de modo que necesita un bloque de relleno para que todo el camino quede con profundidad 1.

![Ejemplo](/img/cbc77d7e8c2d366480d90a369693bccaa1d6d53d.png)
