## Análisis de complejidad temporal

***push***

La funcion *push* inserta un elemento en el siguiente valor disponible dentro de la fila, y reordena la estructura utilizando la funcion *heapify*. Utilizando un ciclo while cada valor que se quiera insertar sera por niveles en el arbol, comparando que el hijo siempre sean mas chico que su padre, por lo que su complejidad temporal es *O(log n)* o logaritmica para el peor de los casos.

***pop***

La funcion *pop* elimina el dato que tiene mayor prioridad en la fila (la raiz del arbol) y reordena el arbol usando la funcion *heapify*, por lo que su complejidad temporal es O(log n) o logaritmica para el peor de los casos dado que usa *heapify*, pero si solo se removiera el elemento sin reorganizar la estructura entonces su complejidad seria *O(1)* o constante para el peor de los casos.

***top***

La funcion *top* unicamente devuelve el valor del elemento con mayor prioridad (la raiz del arbol), esta funcion es la misma para todos los casos por lo que su complejidad siempre es *O(1)* o constante para el peor de los casos.

***empty***

La funcion *empty* es una funcion booleana que devuelve verdadero si no existen elementos dentro de la fila, y devuelve falso en caso de que existan elementos, al ser una funcion sencilla que no utiliza ningun ciclo o llamada recursiva, su complejidad es *O(1)* o constante para el peor de los casos.

***size***

La funcion *size* devuelve el numero de elementos almacenados en la fila, que es el valor del atributo count, dado que no utiliza ningun ciclo, su complejidad es *O(1)* o constante para el peor de los casos.
