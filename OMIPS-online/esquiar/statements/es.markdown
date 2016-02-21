# Historia

Llegó el invierno y ¡a Karel le regalaron unos esquís! La montaña que está
cerca de su casa está cubierta de nieve así que decide aprender a esquiar para
estrenarlos.

Las reglas para esquiar en esa montaña es que siempre debes bajar en diagonal.
Un paso diagonal es un paso hacia abajo seguido de un paso ya sea a la
izquierda o a la derecha. No toda la montaña es segura para esquiar, así que
colocaron zumbadores que marcan la ruta que debe seguir Karel al bajar por la
montaña. Cada vez que Karel encuentre un zumbador, debe cambiar de dirección.

Aquí hay algunos ejemplos de rutas, con la ruta que debes tomar trazada con una
línea azul:

<center>![Ejemplos de rutas](rutas-válidas.png)</center>

Conforme Karel baja por la montaña, quiere ayudar a otras personas que quieren
aprender a esquiar marcando un poco mejor la ruta que deben seguir. Para hacer
esto, deja un montón de dos zumbadores en cada casilla por la que pasa. Esto
quiere decir que si la casilla ya tenía un zumbador, sólo debe dejar un
zumbador más. Karel debe detenerse antes de chocar contra una pared.

No van a haber zumbadores mas que en las casillas por las que pasa Karel, ni
zumbadores a la mitad de un paso en diagonal, así que estas rutas estarían mal:

<center>![Ejemplos de rutas inválidas](rutas-inválidas.png)</center>

La primer ruta está mal porque Karel no pasaría por ahí. La segunda ruta está
mal porque no puede haber un zumbador a la mitad del paso en diagonal.

# Problema

Escribe un programa que mueva a Karel desde su posición inicial, baje por la
montaña usando solo pasos en diagonal y marque cada casilla que visitó con un
montón de dos zumbadores.

# Consideraciones

* Karel siempre inicia en la esquina de arriba a la izquierda viendo hacia el sur.
* Karel tiene infinitos zumbadores en la mochila.
* Karel debe detenerse antes de chocar contra una pared. Si choca, no va a
	obtener puntos.
* La casilla donde inicia Karel está vacía.
* No importa la orientación ni posición final de Karel.
* No pueden quedar zumbadores en el mundo además de los que marcan el camino.
* No habrán zumbadores que te hagan cambiar de dirección a la mitad de un paso
  en diagonal.

# Ejemplos

||input
![Entrada 1](entrada1.png)
||output
![Salida 1](salida1.png)
||input
![Entrada 2](entrada2.png)
||output
![Salida 2](salida2.png)
||end
