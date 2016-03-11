# Historia

Estás en una fiesta cool en la piscina donde hay $N$ personas además de ti. Se sabe que en toda fiesta hay un chico demasiado cool que es conocido por todos, pero que no conoce absolutamente a ninguno de los asistentes de la fiesta.

Como eres un ñoñomi y no gustas de los chicos populares, quieres encontrar a ese chico cool y darle una lección (de programación). Por simplicidad, la gente está numerada de $1$ a $N$. Para encontrar a ese chico cool puedes preguntarle a cualquier persona $A$: "¿conoces a la persona $B$ en la fiesta?". Tu tarea es hacer todas las preguntas necesarias para encontrar al chico cool de esa fiesta.

# Problema

Escribe un programa que, dado el número $N$ de personas que están en la fiesta, realice las preguntas adecuadas al programa evaluador para encontrar al chico cool.

Por supuesto, es posible que esta fiesta se haya hecho durante la OMI y no tenga ningún chico cool.

# Entrada y Salida

**Este problema es interactivo**, por lo que no tendrás que leer la entrada ni imprimir la salida, sino implementar en tu código la función `BusquedaCool` y mandar llamar la función del evaluador `Preguntar` para completar tu tarea.

**Para obtener más información sobre los detalles de implementación de este problema debes revisar el texto del problema en la plataforma _OmegaUp_.**

# Restricciones
**$1 \leq N \leq 2,000$** Número de personas en la fiesta además de ti.
Para todos los casos de prueba puedes llamar la función `Preguntar` a lo más **6,000** veces.

# Ejemplo

**En el texto del problema que se encuentra en la plataforma de _OmegaUp_ aparecen ejemplos de prueba, así como información sobre cómo crear tus propios casos y corridas de prueba.**

# Implementación

## Tu función `BusquedaCool()`

C/C++ `int BusquedaCool(int N);`

Pascal `function BusquedaCool(var N: LongInt): LongInt;`

### Descripción

El evaluador buscará en tu código esta función y la llamará con el número $N$ como parámetro. Tu implementación deberá utilizar la función `Preguntar` para encontrar al chico cool de la fiesta y, una vez que lo encuentre, devolver el número que identifica a ese chico.

Si en la fiesta no se encontró a ningún chico cool, tu función deberá devolver `0`.

### Parámetros

* `N`: Un entero indicando la cantidad de personas que hay en la fiesta.

## Función del evaluador `Preguntar()`

C/C++ `int Preguntar(int A, int B);`

Pascal `function Preguntar(var A, B: LongInt): LongInt;`

### Descripción

Llama a esta función para saber si la persona $A$ conoce a la persona $B$. Si la persona $A$ conoce a la persona $B$, la función devolverá `1`; si no la conoce, devolverá `0`.

Dado que todas las personas son complicadas, siempre que preguntes **si una persona se conoce a sí misma** (por ejemplo `Preguntar(1, 1)`), esta función devolverá `0`.

En caso de que realices alguna pregunta a personas que no están presentes en la fiesta ($A, B < 1$ o $A, B > N$), la función `Preguntar` te devolverá `-1`.

Sí, aunque sabemos que duele, lamentablemente tú nunca serás el chico cool.

### Parámetros

* $A$: La persona a la que se le pregunta.
* $B$: La persona por la que preguntas.

# Rutina de Ejemplo

Suponiendo que en la fiesta hubieran 2 personas y que cada uno conoce a:

+ Persona #1: No conoce a nadie.
+ Persona #2: Conoce a la persona 1.

||input

Función llamada

||output

Valor devuelto

||description

Explicación

||input

BusquedaCool(2)

||output

1

||description

Esta es la llamada que el evaluador realiza a la función `BusquedaCool`. En este ejemplo la función devolverá `1` de acuerdo a las llamadas a la función `Preguntar` que se muestran a continuación.

||input

Preguntar(1, 2)

||output

0

||description

La persona `1` no conoce a la persona `2`.

||input

Preguntar(2, 1)

||output

1

||description

La persona `2` sí conoce a la persona `1`.

Como ya preguntaste a todas las personas que podías preguntar y sabes que la persona 1 no conoce a nadie y la persona 2 sí conoce a la persona 1, entonces la persona 1 debe ser el chico cool.

En este momento tu función `BusquedaCool` deberá devolver `1`, indicando que la persona número 1 es el chico cool de la fiesta.

||end

# Experimentación

{{libinteractive:download}}

El evaluador de prueba recibe el archivo `sample.in`, con dos enteros $N$ y $X$ en la primera línea, representando el número de personas en la fiesta y, de antemano, el número del chico cool.

Después seguirán $N$ líneas; la $i$-ésima línea contendrá $N$ números `0` o `1`. Si el $j$-ésimo número de esta línea es `1` significa que la persona con índice $i$ **SÍ** conoce a la persona con índice $j$. Si el número es `0`, significa que $i$ **NO** conoce a $j$.

Para el caso de ejemplo anterior, `sample.in` se vería de la siguiente manera:

    2 1
    0 0
    1 0

Existen 2 personas y la persona 1 es el chico cool. Por lo tanto: 1 no se conoce a sí mismo ni a la persona 2; 2 conoce a la persona 1 y no se conoce a sí mismo.

Durante la ejecución, el evaluador de prueba imprimirá algunos mensajes para ayudarte a depurar tu solución. Al finalizar la ejecución de tu función, el evaluador de prueba imprimirá la cantidad de veces que llamaste a la función `Preguntar` y te dirá si encontraste al chico cool.

# Evaluación

Si durante la ejecución de tu programa execedes el límite de llamadas permitidas a `Preguntar`, recibirás 0 puntos.
Si al finalizar la ejecución de tu solución no encontraste al chico cool, tu puntaje será de 0 puntos.
Por otro lado, si encontrar correctamente al chico cool sin haber excedido el límite de llamadas permitidas y tu función no excede el límite de tiempo obtendrás el 100% de los puntos.

Para un grupo de casos con valor de 28 puntos se cumple que **$N \leq 50$**  
Para otro grupo de casos con valor de 36 puntos se cumple que **$N \leq 1,000$**  
El resto de los casos estará agrupado en un grupo con valor de 36 puntos.
