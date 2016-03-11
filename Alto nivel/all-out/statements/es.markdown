# Historia

Practicar para la OMI es muy estresante, así que te pones a jugar un juego de video para relajarte. En dicho juego tienes un equipo de 4 personajes. Cada personaje cuenta con un número entero de puntos de energía que pueden usar para hacer ataques. En este juego realizar cualquier ataque cuesta $K$ puntos de energía.

Como en los mejores juegos de este tipo, cada personaje puede atacar sólo con cierto tipo de ataques. En este juego existen 7 tipos: Normal, Fuego, Hielo, Aire, Electricidad, Luz y Oscuridad. Cada personaje puede realizar ataques de un subconjunto de estos tipos. Por ejemplo, un personaje de tu equipo podría solamente realizar ataques de tipo Normal y de Fuego, mientras otro personaje podría realizar ataques de tipo Aire y Electricidad, y así para los demás miembros.

El siguiente nivel que jugarás tiene $N$ enemigos, numerados del $1$ al $N$, cada enemigo es vulnerable a **sólo un tipo de ataque**. Para terminar el calabozo debes vencer a todos y cada uno de los enemigos. Lleno de determinación, has decidido terminar este juego de una vez por todas.

# Problema

Dada la descripción de los tipos de ataque que pueden realizar de los personajes de tu equipo, los puntos de energía que tiene cada uno, la cantidad de enemigos en el siguiente nivel y las vulnerabilidades de cada uno, determine la estrategia para finalizar el nivel. **Se asegura que siempre habrá una forma de finalizar el calabozo.**

# Entrada

Tu programa debe leer del teclado la siguiente información.

* Una línea con los números $N$ y $K$, la cantidad de enemigos y el costo en energía de realizar un ataque.
* En las siguientes 4 líneas recibirás una cadena de caracteres $P_i$ y un entero $E_i$. Cada línea representa a un personaje de tu equipo, la cadena $P_i$ puede contener cualquier subconjungo de los caracteres `N`, `F`, `H`, `A`, `E`, `L`, `O`, que representan los tipos de ataque que puede realizar el $i$-ésimo personaje de tu equipo. El entero $E_i$ representa la cantidad de energía del personaje al inciar el nivel.
* Finalmente habrá $N$ líneas, cada una con un único carácter $V_j$ que puede ser `N`, `F`, `H`, `A`, `E`, `L` o `O` y que representa la vulnerabilidad del enemigo $j$-ésimo.

# Salida

Para cada uno de los miembros de tu equipo (en el mismo orden en el que se presentan en la entrada) debes imprimir dos líneas.

En la primera de estas líneas, para el miembro $i$, debes imprimir un entero $M_i$ representando la cantidad de enemigos que el $i$-ésimo personaje debe vencer. En la siguiente línea, imprime $M_i$ enteros; cada entero representa el índice de uno de los monstruos que ese personaje debe vencer.

Para obtener puntos en este problema es necesario que imprimas una estrategia válida para vencer a los $N$ enemigos sin rebasar los puntos de energía de cada personaje ni sus restricciones en el tipo de ataques que pueden realizar. En caso de haber múltiples soluciones cualquiera de ellas será considerada correcta.

# Restricciones

$1 \leq K \leq 10$&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;El costo de realizar un ataque.
$1 \leq E_i \leq 5,000,000$&nbsp;&nbsp;La cantidad de energía inicial del personaje $i$.
$1 \leq N \leq 50,000$&nbsp;&nbsp;&nbsp;El número de enemigos.


# Ejemplo

|| input
5 1
NAE 3
A 1
EH 2
A 3
N
E
A
E
A
|| output
1
1
0

2
4 2
2
3 5
|| description
El miembro 1 del equipo ataca al enemigo 1 con un ataque Normal.

El miembro 2 de tu equipo no ataca a ningún enemigo.

El miembro 3 del equipo vence al enemigo 2 y 4 con un ataque Electrico.

Finalmente, el miembro 4 ataca a los enemigos 3 y 5 con ataques de Aire.
|| end


Para un grupo de casos de prueba con valor de $23$ puntos, $N \leq 10$  
Para un grupo de casos de prueba con valor de $26$ puntos, $N \leq 50$  
Para un grupo de casos de prueba con valor de $22$ puntos, $N \leq 100$
