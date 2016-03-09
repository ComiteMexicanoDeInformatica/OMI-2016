# Historia

Karel llegó a la OMI, dejó su maleta en su cuarto y ahora quiere encontrarse con su amigo, pero desconoce el piso dónde está su amigo. Su amigo le dejó zumbadores en la mochila para que sepa cuántos pisos bajar. Por ejemplo, si Karel tiene un zumbador en su mochila, tiene que bajar un piso, si tiene dos zumbadores en su mochila, tiene que bajar dos pisos, y así sucesivamente.

Para bajar, Karel tiene que usar las escaleras del hotel. En el mundo de Karel, cada fila es un piso del hotel y una escalera se representa por un espacio, sin pared, por el cual Karel puede llegar al piso de abajo. Las escaleras de este hotel no están alineadas, así que puede ser que las escaleras estén en medio o en las orillas de cada piso. 

# Problema

Escribe un programa que ayude a Karel a bajar al piso dónde está su amigo, para lo cual debe bajar usando las escaleras una cantidad de pisos igual a la cantidad de zumbadores que su amigo le dejó en la mochila.

Al llegar al piso dónde está su amigo, Karel debe apagarse.

# Consideraciones

* El hotel es un rectángulo delimitado por paredes.
* Todos los pisos tienen al menos una escalera por donde Karel puede bajar.
* Karel empieza en el último piso del hotel, es decir, el piso más alto con una orientación desconocida.
* Karel inicia con una cantidad de zumbadores en la mochila igual a la cantidad de pisos que tiene que bajar.
* El número de zumbadores que tiene Karel siempre es menor que el número de pisos que tiene el hotel.
* Para obtener los puntos Karel debe apagarse en cualquier casilla del piso donde está su amigo.
* No importa la orientación final de Karel ni los zumbadores que queden en el mundo.

# Ejemplos

### Entrada

![Ejemplo de entrada](/img/aed2fb035d0bb78bbd03b97fd1be620fdff94415.jpg)

Karel empieza en el piso 8. Karel empieza con 7 zumbadores en su mochila, tiene que bajar 7 pisos para encontrar a su amigo.

### Salida

![Ejemplo de salida](/img/79bc5e368e0756ab0b6082cf985e6c7d1e18f69c.jpg)

Tras bajar 7 pisos, llegó al piso 1 y debe apagarse en cualquier lugar de ese piso.
