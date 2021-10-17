## Análisis de complejidad temporal

***visit***

La funcion *visit* recorre n pasos, ya que solo almacena los datos dentro de un string utilizando las funciones preorder, postorder, inorder y levelbylevel. Cada funcion utiliza llamadas recursivas para recorrer todos los elementos del arbol, por lo que su complejidad temporal es *O(n)* o lineal para el peor de los casos.

***height***

La funcion *height* recorre n pasos, ya que accede a cada una de las ramas del arbol (izquierdas, derechas) usando llamadas recursivas, sumando 1 en cada nivel y cada lado en el que se encuentre del arbol hasta  que se obtiene la altura del arbol. Por lo que su complejidad temporal es *O(n)* o lineal para el peor de los casos.

***ancestors***

La funcion *ancestors* recorre n pasos, ya que recibe como parametro un valor del arbol, valor con el cual accede al arbol para encontrar todos los nodos arribas del valor recibido en línea directa hasta llegar a la raiz y desplega cada uno de ellos dentro de un string, por lo que su comlejidad temporal es O(n) o lineal para el peor de los casos.

***whatlevelamI***

La funcion *whatlevelamI* busca el nivel en el que se encuentra el valor recibido dentro de un arbol recorriendo n pasos, ya que utiliza llamadas recursivas para recorrer el arbol y devolver su nivel, por lo que su complejidad temporal es *O(n)* o lineal para el peor de los casos.
