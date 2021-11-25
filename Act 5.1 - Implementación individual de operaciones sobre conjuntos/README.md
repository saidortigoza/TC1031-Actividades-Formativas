## Análisis de complejidad temporal

***put***

La funcion *put* hace uso de la función *indexOf* para saber el indice de la llave ingresada. Después utiliza este indice para agregar la llave y el valor ingresado como parametro de la funcion, y en caso de que exista alguna colision se moverá a la siguiente posición. Por lo que para el peor de los casos su complejidad temporal es *O(n)* o lineal, en caso de que la tabla hash esté llena, pero para su mejor caso su complejidad temporal es *O(1)* o constante, debido a que solo toma un paso agregar el valor y el indice a la tabla.

***get***

La funcion *get* hace uso de la función *indexOf* para saber el indice de la llave ingresada. Después utiliza este indice para buscar el valor ingresado en esa posición, si existe un valor almacenado en este índice, la función lo devuelve, de lo contrario, la función despliega el mensaje "La llave ingresada es incorrecta.". Dado que no utiliza ciclos, la complejidad de la función es de *O(1)* o constante.
