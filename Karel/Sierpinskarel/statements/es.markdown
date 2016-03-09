# Historia

Karel se encuentra dentro de un mundo cuadrado, es decir, el ancho y el alto del mundo son iguales. Ayuda a Karel a pintar el mundo siguiendo las siguientes instrucciones:

* **Paso 1:** Cuenta cuanto mide el cuadrado en el que te encuentras.
* **Paso 2:** Divide el cuadrado en 3 filas y 3 columnas del mismo tamaño de modo que te queden 9 cuadrados. Si no se puede, apágate.
* **Paso 3:** Rellena el cuadro del centro con montones de 1 zumbador.
* **Paso 4:** Para los 8 cuadrados restantes realiza el mismo procedimiento.

Debes dejar de pintar cuando el tamaño del cuadro no se pueda dividir en 3 filas y columnas iguales.
  
# Problema

Escribe un programa que ayude a Karel a dibujar el mundo siguiendo las instrucciones.

# Consideraciones

* Karel tiene infinitos zumbadores en la mochila.
* El tamaño del mundo siempre será múltiplo de 3.
* El mundo inicial no tiene zumbadores en el piso.
* Karel inicia en la casilla (1, 1) viendo al norte.
* No importa la orientación ni la posición final de Karel.

# Ejemplos

### Entrada

![Ejemplo 18x18](/img/7e085f704bdb1db04cf8b480192488cfcf763723.png)

En este mundo de 18x18, Karel primero divide el mundo en 9 cuadros de 6x6 y rellena el del centro. Después, empieza el mismo procedimiento en los 8 cuadros de 6x6 restantes. En cada uno de ellos, divide el cuadro en 9 cuadros de 2x2, rellena el de en medio y se apaga, dado que los cuadros resultantes no pueden dividirse en 3 filas o 2 columnas.

### Salida

![Ejemplo 12x12](/img/062b969cd09b932ce4a3f9c1bd7893663774de3b.png)

En este mundo de 12x12 Karel hace 9 cuadros de 4x4 y rellena el del centro. En ese momento se apaga porque los cuadros de 4x4 no se pueden dividir en 9 cuadros iguales.
