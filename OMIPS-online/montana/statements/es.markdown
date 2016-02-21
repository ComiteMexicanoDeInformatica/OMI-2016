# Historia

Karel quiere ir a una aventura. No se siente muy confiado en sus habilidades, entonces no va a matar un monstruo, o navegar el mar, porque eso sería muy complicado. En lugar de eso, Karel va a escalar una  montaña. No varias montañas, porque eso le da miedito, y Karel solo esta preparado para escalar una.  

¿Qué es una montaña? Seguramente te estarás preguntando. O no. Te vamos a decir de todos modos. Una montaña tiene las siguientes características: 

* Está pegada a la base del mundo de Karel (La fila 1), porque sino sería una montaña voladora. 
* Es completamente cerrada, porque sino sería una cueva. 
* El lado izquierdo de la montaña sube hasta llegar a la cima, y el lado derecho de la montaña baja hasta llegar a la base. Solamente existe un "pico" en la montaña, porque sino sería mas de una montaña.

Estas cosas son montañas en Karel:

<center>![Ejemplo de salida](montanas_validas.png)</center>

Estas cosas no son montañas en Karel:

<center>![Ejemplo de salida](montanas_invalidas.png)</center>

Karel está extra emocionado por empezar su aventura porque el mundo acaba de llover zumbadores, dejando a las montañas rodeadas por montones de un beeper. (Toma en cuenta que la lluvia del mundo de Karel es rara, entonces los lados de la montaña también son rodeados por zumbadores) 

Una montaña con lluvia se ve así:

<center>![Ejemplo de salida](montana_lluviosa.png)</center>

Como prueba de que escaló la montaña, Karel quiere que la posición (1,1) tenga la misma cantidad de zumbadores que la altura de la montaña. Esto finalmente hará que Karel sea feliz. 

# Problema

Escribe un programa que deje la altura de la montaña representada por zumbadores en la posición (1,1). 

# Consideraciones

* Karel siempre inicia en la posición (1,1) viendo hacia el Norte.
* Todos los montones de zumbadores que están en la montaña son de tamaño 1 y no hay zumbadores que no sean los de la montaña. 
* No importan la orientación ni la posición final de Karel. 
* Solamente importan los zumbadores que están en la posición (1,1), los demás se pueden recoger o no. 
* No importa la cantidad final de zumbadores en la mochila de Karel. 
* La montaña siempre tendrá altura menor a 100. 
* Karel no necesariamente tiene que escalar toda la montaña, solo importa que sepa la altura de la montaña. 
* No hay montañas planas (De altura 0). 
* La altura de una montaña es igual a la cantidad de veces que Karel tiene que moverse al norte para llegar a la cima.

# Subtareas

* **Subtarea 1 [26 puntos]:** Karel no tiene zumbadores en su mochila.

* **Subtarea 2 [74 puntos]:** Karel tiene zumbadores infinitos en su mochila.

# Ejemplo

### Entrada

<center>![Ejemplo de entrada](input_ejemplo.png)</center>

### Salida

<center>![Ejemplo de salida](output_ejemplo.png)</center>
