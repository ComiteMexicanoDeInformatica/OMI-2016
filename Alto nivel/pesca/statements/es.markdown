# Historia

En la ciudad de Alvarado, Veracruz vive un pescador que tiene una pequeña lanchita, una red de pesca de 1 m<sup>2</sup> y, novedosamente, una app llamada iFish para salir a pescar en un mar rectangular de $w \times h$ m<sup>2</sup>, el cual puedes ver como un plano cartesiano.

iFish es muy poderosa, le puede decir al pescador cuántos bancos de peces hay en un área rectángular del mar, sin embargo, como usa la versión gratuita, la app tiene dos restricciones: puede hacer un número de preguntas limitado y cuando no pregunta no puede saber exactamente dónde están los peces en esa área del mar, sólo sabe cuántos hay.

En iFish, el pescador especifica 2 puntos con las coordenadas de las esquinas opuestas de un rectángulo. La app responde diciendo el número de bancos de peces en el área.

El pescador quiere aprovechar al máximo la versión gratuita. Para ello te ha pedido que lo ayudes a diseñar un plan para capturar **a todos** los peces del mar usando la menor cantidad de veces su red.

Recuerda que el pescador puede preguntar cuántos bancos de peces hay en **cualquier tamaño** de área dentro del mar, sin embargo su red mide 1 m<sup>2</sup>, por lo tanto, sólo puede usar su red en un cuadro con área de 1 m<sup>2</sup>.

# Problema

Escribe un programa que, dados $w$ y $h$, el ancho y alto del área del mar, $n$, el número total de bancos de peces en todo el mar, y $k$, el número máximo de consultas que permite la versión gratuita de la app, ayude al pescador a capturar los $n$ bancos de peces tirando su red la menor cantidad posible de veces.

# Entrada y Salida

**Este problema es interactivo**, por lo que no tendrás que leer la entrada ni imprimir la salida, sino implementar en tu código la función `Pescar` y mandar a llamar las funciones del evaluador `UsarApp` y `TirarRed` para completar tu tarea.

Internamente el evaluador llevará el registro de cuantos bancos de peces quedan en el mar, tu programa no necesitará imprimir ni devolver nada, solo asegurarse de que hayas capturado, mediante la función `TirarRed`, todos los bancos de peces del mar.

# Ejemplo

**En el texto del problema que se encuentra en la plataforma de _OmegaUp_ aparecen ejemplos de prueba, así como información sobre cómo crear tus propios casos y corridas de prueba.**

# Implementación

## Tu procedimiento `Pescar()`

C/C++ `void Pescar(int w, int h, int n, int k);`

Pascal `procedure Pescar(var w, h, n, k: LongInt);`

### Descripción

El evaluador buscará en tu código esta función y la llamará con los parámetros `w`, `h`, `n` y `k`. Tu implementación deberá utilizar las funciones `UsarApp` y `TirarRed` para atrapar a todos los peces. En cada caso de prueba **solo se llamará a esta función una vez**.

### Parámetros

+ `w`: El ancho del área que abarca el mar.
+ `h`: La altura del área que abarca el mar.
+ `n`: El número de bancos de peces que hay en el mar.
+ `k`: El número de consultas que puedes hacer con la app.

## Función del evaluador `UsarApp()`

C/C++ `int UsarApp(int x1, int y1, int x2, int y2);`.

Pascal `function UsarApp(var x1, y1, x2, y2: LongInt): LongInt;`.

### Descripción

Esta es la función que deberás llamar cuando quieras consultar cuántos bancos de peces hay en cierta área. Recibe como parámetros dos puntos que describen esquinas opuestas del área rectangular que deseas consultar.

Si las coordenadas se encuentran fuera del área de cobertura o el rectángulo de consulta tiene área igual a cero, la función devolverá `-1`. En caso contrario, devolverá el número de bancos de peces que se encuentran dentro del rectángulo consultado.

Las coordenadas con las que debes preguntar siempre serán enteras. Los bancos de peces **NO** se moverán de su lugar.

### Parámetros

* `x1`: La coordenada $x$ de una esquina del rectángulo.
* `y1`: La coordenada $y$ de una esquina del rectángulo.
* `x2`: La coordenada $x$ de la esquina opuesta del rectángulo.
* `y2`: La coordenada $y$ de la esquina opuesta del rectángulo.

## Función del evaluador `TirarRed()`

C/C++ `int TirarRed(int x1, int y1, int x2, int y2);`.

Pascal `function TirarRed(var x1, y1, x2, y2: LongInt): LongInt;`.

### Descripción

Esta es la función que deberás llamar cuando quieras capturar a los peces que se encuentren en cierta área. Recibe como parámetros dos puntos que describen las esquinas opuestas del área rectangular que deseas consultar.

Esta función tiene una restricción adicional: la red del pescador mide 1 m<sup>2</sup>, por lo tanto, las coordenadas que proporciones no podrán formar un rectángulo de área mayor a 1 m<sup>2</sup>.

Si las coordenadas se encuentran fuera del área de cobertura o el rectángulo de consulta tiene área igual a cero o mayor a 1 m<sup>2</sup>, la función devolverá `-1`. En caso contrario, capturará a todos los peces que se encuentren dentro del área del rectángulo indicado.

**Nota:** Una vez que captures un banco de peces, este ya no volverá a contar en las siguientes consultas de `UsarApp`.

### Parámetros

* `x1`: La coordenada $x$ de una esquina del rectángulo.
* `y1`: La coordenada $y$ de una esquina del rectángulo.
* `x2`: La coordenada $x$ de la esquina opuesta del rectángulo.
* `y2`: La coordenada $y$ de la esquina opuesta del rectángulo.

# Rutina de Ejemplo

|| input

Función llamada

|| output

Valor devuelto

|| description

Descripción

|| input

Pescar(5, 5, 6, 25)

|| output

-

|| description

Esta será la llamada inicial a tu procedimiento `Pescar`.

|| input

UsarApp(0, 0, 5, 5)

|| output

6

|| description

El pescador consulta el número de bancos de peces que hay en todo el mar. Con esta llamada verifica que, en efecto, existen 6 bancos en el mar.

|| input

UsarApp(1, 3, 4, 3)

|| output

-1

|| description

El pescador hace una consulta en un área de 0, es decir, en una línea. La aplicación responderá `-1` dado que es imposible responder esa consulta.

|| input

TirarRed(1, 3, 2, 2)

|| output

0

|| description

El pescador tira la red en un cuadrado de 1 m<sup>2</sup> y no atrapa a ningún banco de peces.

|| input

TirarRed(2, 4, 4, 5)

|| output

-1

|| description

El pescador no puede extender la red más de 1 m<sup>2</sup>, por ello, esta función devuelve `-1`.

|| end

# Experimentación

{{libinteractive:download}}

El evaluador de prueba recibe el archivo `sample.in` con los valores $w$, $h$, $n$ y $k$ en la primer línea. En las siguientes $n$ líneas se encontrarán las coordenadas $x$ y $y$ de cada uno de los bancos de peces que se encuentran en el mar. Las coordenadas de los bancos deben de ser **NO** enteras.

Para el caso de ejemplo anterior, `sample.in` se vería de la siguiente manera:

    5 5 6 25
    0.2 0.8
    2.1 2.5
    4.7 0.9
    2.3 4.6
    1.5 4.2
    1.9 3.4

Donde el tamaño del mar es de $5 \times 5$, existen 6 bancos de peces y puedes tirar la red 25 veces. A partir de la línea 2, se encuentran las coordenadas de los 6 bancos de peces, siendo la primera la posición la $x$ y, la segunda, $y$.

Puedes modificar el contenido de `sample.in` para probar distintos casos con tu solución.

Durante la ejecución, el evaluador de prueba imprimirá algunos mensajes para ayudarte a depurar tu solución. Al finalizar la ejecución de tu función, el evaluador de prueba imprimirá la cantidad de veces que llamaste a las funciones `UsarApp` y `TirarRed`, seguido de un mensaje que te dirá si lograste capturar todos los bancos de peces o no.

**IMPORTANTE:** El evaluador de prueba y el evaluador final que se usará para calificar tu solución son diferentes. El evaluador de prueba tiene la intención de facilitar la depuración de tu solución y puede implementar algunas de sus funciones de manera ineficiente, sin embargo puedes asumir con seguridad que **el tiempo de ejecución del evaluador final no afectará el tiempo total de tu solución**.

# Evaluación

Si durante la ejecución de tu programa excedes el límite de consultas que puedes hacer a la app o tiras la red más de 100,000 veces, recibirás 0 puntos. 
Si al finalizar la ejecución de tu solución no lograste atrapar a todos los peces tu puntaje será de 0 puntos.
Por otro lado, si logras capturar a todos los peces y no excedes el límite de llamadas para ninguna función del evaluador, recibirás un puntaje de al menos 20% de los puntos. El 80% del puntaje restante se otorgará en función del número de veces que llamaste a TirarRed, por lo tanto, entre menos veces uses esta función, mayor será tu puntaje. Nota que cada caso se puntuará de manera independiente.

A continuación se muestran las llamadas para los 20 casos de prueba donde los parámetros de la llamada son:

`Pescar`($w$,$h$,$n$,$k$) las dimensiones del mar, el número de bancos y la cantidad de veces que puedes preguntar al app.

* **Caso 01**: `Pescar(10, 10, 20, 100)`.
* **Caso 02**: `Pescar(18, 12, 50, 200)`.
* **Caso 03**: `Pescar(20, 24, 75, 360)`.
* **Caso 04**: `Pescar(36, 44, 200, 900)`.
* **Caso 05**: `Pescar(60, 80, 330, 2400)`.
* **Caso 06**: `Pescar(100, 150, 365, 5000)`.
* **Caso 07**: `Pescar(130, 120, 240, 3900)`.
* **Caso 08**: `Pescar(350, 350, 2450, 14000)`.
* **Caso 09**: `Pescar(450, 600, 1150, 8000)`.
* **Caso 10**: `Pescar(800, 600, 1800, 15000)`.
* **Caso 11**: `Pescar(800, 800, 2400, 12000)`.
* **Caso 12**: `Pescar(800, 1000, 800, 10000)`.
* **Caso 13**: `Pescar(3000, 2000, 400, 8000)`.
* **Caso 14**: `Pescar(5000, 5000, 850, 10000)`.
* **Caso 15**: `Pescar(7000, 9000, 1200, 17000)`.
* **Caso 16**: `Pescar(10000, 10000, 1250, 17700)`.

Para los últimos 4 casos de prueba se asegura que existe un rectángulo de coordenadas enteras en el mar con un área de **$n$ m<sup>2</sup> que contiene a los $n$ bancos de peces**.

* **Caso 17**: `Pescar(200, 360, 1050, 720)`.
* **Caso 18**: `Pescar(250, 220, 800, 650)`.
* **Caso 19**: `Pescar(280, 320, 1950, 890)`.
* **Caso 20**: `Pescar(280, 400, 800, 700)`.
