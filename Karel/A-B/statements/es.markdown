# Historia

Karel ha estado entrenando para la OMI en omegaUp,
 notó que hay muchos problemas que te piden calcular $A + B$.

Como Karel es muy creativo, decidió cambiar ligeramente el problema
y calcular $A - B$, pero rápidamente descubrió que restar es difícil,
por lo que ahora pide tu ayuda.

En la casilla (1,1) y (1,2) se encuentran dos montones de zumbadores entre 0 y 99 zumbadores cada uno que representan dos números $A$ y $B$ respectivamente.

Karel quiere calcular la diferencia entre estos números.

# Problema

Escribe un programa que ayude a Karel a calcular la diferencia entre $A$ y $B$. La diferencia entre $A$ y $B$ será igual a $A - B$ o $B - A$ dependiendo si $A$ es mayor, menor, o igual que $B$.

* Si $A > B$, tu programa debe dejar $A - B$ zumbadores en la casilla (2,2).
* Si $B \geq A$, tu programa debe dejar $B - A$ zumbadores en la casilla (2,1).

# Consideraciones

* Karel no tiene zumbadores en la mochila.
* Karel inicia en la casilla (1,1) orientado al norte.
* El mundo de Karel es de 100x100 y sólo tiene las paredes que lo delimitan.
* Para obtener los puntos sólo importa cuántos zumbadores hay en la casilla (2,1) y (2,2).
* No importa la orientación ni la posición final de Karel.
* **Si debías dejar zumbadores en la casilla (2,1), la casilla (2,2) debe quedar vacía. Del mismo modo, si debías dejar zumbadores en la casilla (2,2), la casilla (2,1) debe quedar vacía.**

# Ejemplos

En este mundo, $A = 5$ y $B = 2$. Como $A > B$, Karel escribe
$5 - 2 = 3$ en la casilla (2,2).

<center>![A-B.in](/img/6e92920bb572b20d077142597cce19b6b1b5e587.png) ![A-B.out](/img/0dc17f524fe6bec9be0f9acf3158064faf88b05f.png)</center>

En este mundo, $A = 4$ y $B = 10$. Como $B \geq A$, Karel escribe
$10 - 4 = 6$ en la casilla (2,1).

<center>![B-A.in](/img/734e49b5a4eeeb4bb98f51de95da9b6243f4ac1c.png) ![B-A.out](/img/4b057bf37b2510c57ad350f61c33e719ca9321b5.png)</center>
