## Análisis de complejidad temporal

***add***

La funcion *add* inserta un elemento en el splay tree como un BST normal, y después utiliza la función *splay* para ordenar el árbol con el nuevo valor como raíz. Dado que el algoritmo emplea condicionales y llamadas recursivas para sólo modificar una parte del árbol, su complejidad temporal es *O(log n)* o logaritmica para el peor de los casos.

***remove***

La funcion *remove* elimina un valor ingresado por el usuario en el splay tree. Utiliza una serie de condicionales para posicionar el valor en la raíz y posteriormente eliminarlo, dejando como nueva raíz a su sucesor, por lo que su comlejidad temporal es *O(log n)* o logaritmica para el peor de los casos.

***find***

La funcion *find* recorre n pasos para encomtrar un valor ingresado en la función, y devuelve un valor booleano que indica si se encontró o no, utiliza condicionales y llamadas recursivas para mover el valor ingresado a la raíz mediante la función *splay* y reordenar el árbol, por lo que su comlejidad temporal es *O(log n)* o logaritmica para el peor de los casos.

***size***

La funcion *size* es una funcion que devuelve un valor entero que es equivalente al número de elementos dentro del árbol, dado que solamente le toma un paso, su complejidad temporal es *O(1)* o constante para el peor de los casos.
