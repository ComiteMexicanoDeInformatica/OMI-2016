# Historia

Los amigos de Karel han desafiado a nuestro amigo a encontrar el zumbador perdido en el pasillo donde vive. Karel está cansado de escuchar que es un robot muy desorientado, por ello quiere darles una lección.

**¿No sabes lo que es un pasillo? No hay problema, te explicamos.** Imagina una línea de varias casillas del mundo dibujada con paredes como se muestra en el dibujo de abajo:

<center>![Ejemplo de una línea](linea.png)</center>

Puedes doblar la línea anterior cuantas veces quieras para formar diversos pasillos. Recuerda que la línea de casillas sin doblar también cuenta como un pasillo. Puedes dibujar pasillos de muchas figuras diferentes, a continuación te mostramos solo algunos ejemplos:

<center>![Ejemplos de pasillos](pasillos.png)</center>

Sin embargo, **no puedes doblar la línea de tal forma que se cruce consigo misma**. En seguida te mostramos algunos ejemplos de líneas que se cruzan a si mismas y por lo tanto **NO son pasillos:**

<center>![Ejemplos de cruces](cruces.png)</center>

Karel inicia en uno de los extremos del pasillo; **puedes reconocer un extremo del pasillo por ser una casilla rodeada de 3 o 4 paredes**. Dentro de las casillas del pasillo existe un zumbador perdido. Para mostrarle a sus amigos que no es un robot desorientado, Karel quiere pararse sobre el zumbador perdido y mirar en la misma dirección a la que Karel estaba viendo en la casilla donde comenzó.

Por ejemplo, imagina que Karel se encuentra en un extremo del pasillo mirando al norte. Karel quiere caminar por el pasillo hasta encontrar el zumbador y ahí detenerse. Una vez que Karel esté parado sobre el zumbador, él quiere mirar al norte, justo hacia donde estaba mirando al iniciar su búsqueda.

# Problema

Escribe un programa que mueva a Karel desde su posición inicial en el pasillo hasta el zumbador perdido. **Recuerda que Karel debe terminar su ejecución orientado en la misma dirección con la que inició.**

# Consideraciones

* Karel siempre inicia en un extremo del pasillo.
* Al inicio, Karel no tiene zumbadores en la mochila.
* Siempre existirá **un solo zumbador dentro del pasillo**.
* Karel inicia mirando a la siguiente casilla por la que debe caminar.
* Puede ser que el pasillo donde vive Karel sea una sola casilla.
* **Solo importa la posición y orientación final de Karel**.

# Ejemplo

### Entrada

![Ejemplo de entrada](entrada.png)

### Salida

![Ejemplo de salida](salida.png)

En el ejemplo anterior, Karel inicia mirando al norte. Después de caminar derecho, girar a la derecha y seguir caminando hasta encontrar el zumbador perdido, Karel se detiene y voltea de nuevo al norte para terminar su ejecución orientado en la misma dirección que tenía al iniciar su búsqueda.
