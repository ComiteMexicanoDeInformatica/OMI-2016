# Historia

Mientras estabas practicando arduamente para la OMI 2016, el estafador William Zabka se ha robado tu piña de la suerte. Bien sabes que sin tu piña de la suerte no vas a conseguir ninguna medalla en la olimpiada, así que le pides al detective/arquitecto Ted Mosby que, junto a los famosos chicos Mosby, te ayude a encontrar a Zabka.

Zabka se escondió en una cuadrícula rectangular de $N \times M$. Por suerte Ted y sus chicos desarrollaron un dron que les permite buscar a Zabka dentro de un cuadrado, sin importar su tamaño, en tan solo un minuto.

Con su dron, los chicos Mosby piensan ubicar a Zabka con el siguiente método:

* Primero encuentran el cuadrado más grande que quepa en el área de la cuadrícula que aún no han revisado.
* Ubicar ese cuadrado pegado a uno de los extremos del área de la cuadrícula que aún no se ha revisado.
* Revisar el área cuadrada en 1 minuto.
* Volver al paso 1 hasta que el área rectangular haya sido revisada completamente.

# Problema

Escribe un programa que dadas las dimensiones de $N$ y $M$ de la cuadrícula donde se escondió Zabka, calcule cuál será la cantidad máxima de minutos que tardarán en encontrarlo.  Es decir, la cantidad de cuadrados que tendrán que revisar.

# Entrada

Tu programa debe leer del teclado la siguiente información:

* Una línea con dos números enteros: $N$ y $M$.

# Salida

Tu programa debe escribir en la pantalla un único número que representa el tiempo que tomará revisar toda la cuadrícula.

# Ejemplo

|| input
3 2
|| output
3
|| description
La cuadrícula es de $3 \times 2$. Mosby inicia buscando en un cuadrado de $2 \times 2$. Después de realizar la búsqueda, queda una línea sin buscar de $1 \times 2$ en la cuadrícula. Mosby checa un cuadrado de $1 \times 1$ y finalmente busca en el cuadrado de $1 \times 1$ restante. En total Se requirió de $3$ minutos para revisar la cuadrícula completa.
|| input
5 7
|| output
5
|| description
La forma de búsqueda se muestra en la siguiente imagen.
||end

<center>![Explicación del segundo caso de ejemplo](explicacion_ejemplo.png)</center>

# Límites

Para un conjunto de casos **NO** agrupados con un valor de 60 puntos, se cumple que $1 \leq N, M \leq 10^6$.

Para otro conjunto de casos agrupados con un valor de 40 puntos, se cumple que $1 \leq N, M < 2^{31}$.
