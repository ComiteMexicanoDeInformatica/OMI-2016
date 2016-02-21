# Historia

En su nuevo trabajo como electricista, Karel tiene la importante tarea de cambiar todos los focos que hay en la oficina. La oficina donde trabaja Karel es un rectángulo dibujado con paredes (puedes ver el ejemplo de abajo para entender mejor). Para los trabajadores es importante poder caminar libremente por la oficina, es por eso que, además de las paredes que dibujan el rectángulo, no existirá ninguna otra pared que te estorbe para recorrer la oficina como tu quieras.

Cada casilla dentro de la oficina tiene un foco. Si una casilla del rectángulo tiene **un zumbador** entonces el foco de esa casilla se encuentra **encendido**. Por otro lado, si la casilla no tiene **ningún zumbador** entonces el foco se encuentra **apagado**. Por cada foco en la oficina, nuestro amigo electricista tiene la tarea de: si el foco está encendido, apagarlo; si el foco está apagado, encenderlo.

Karel sabe entonces que debe recorrer toda la oficina y cambiar los focos en cada una de las casillas, si hace bien su trabajo, al final **todas las casillas deben quedar al revés de como estaban al inicio**.

# Problema

Escribe un programa que ayude a Karel a recorrer todas las casillas de la oficina y utilizar los zumbadores en su mochila para encender los focos apagados colocando un zumbador y apagar los focos encendidos recogiendo el zumbador de las casillas necesarias.

# Consideraciones

* La oficina de Karel siempre es un rectángulo.
* Todas las casillas en la oficina tienen **0 o 1 zumbador**.
* No habrá paredes dentro de la oficina que estorben a Karel.
* Karel inicia en la posición (1, 1) del mundo orientado al norte.
* Al inicio, Karel tiene infinitos zumbadores en la mochila.
* No importa la posición ni la orientación final de Karel.

# Ejemplos

### Entrada

![Ejemplo de entrada](entrada.png)

La oficina es un rectángulo de 4 filas cada una con 5 columnas. Hay 10 focos encendidos (representados con montones de 1 zumbador) y 10 focos apagados (montones de 0 zumbadores).

### Salida

![Ejemplo de salida](salida.png)

Después de que Karel apagó los focos encendidos y encendió los focos apagados la oficina se ve así.
