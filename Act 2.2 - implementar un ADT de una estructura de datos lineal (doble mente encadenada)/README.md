## Análisis de complejidad temporal

***insertion***

La función *insertion* inserta un elemento en la estructura de datos, recibe el valor a insertar y aumenta el tamaño de la lista. El algoritmo recorre solo un paso, ya que usa el atributo tail de la clase DList para insertar el valor ingresado al final de la lista, por lo que su complejidad es *(O(1))*.

***search***

La función *search* busca la posición de un número dentro de la lista usando un ciclo while, y si el número no está dentro de la lista devuelve un -1. El algoritmo recorre *n* pasos, por lo que en el peor de los casos (que se daría cuando el número que busca está al final de la lista) su complejidad es lineal *(O(n))*.

***update***

La función *update* actualiza el valor de un elemento dentro de la lista a partir del índice recibido por el usuario, recorriendo *n* pasos mediante un ciclo while, una vez que lo encuentra, cambia el valor actual con el valor nuevo. Debido a que en el peor de los casos tendría que recorrer la lista entera, su complejidad es *(O(n))*.

***deleteAt***

La función *deleteAt* elimina un elemento dentro de la lista según su posición y reduce el tamaño de la lista. El algoritmo funciona mediante un ciclo while que recorre *n* pasos hasta llegar al elemento deseado, por lo que su complejidad temporal es *(O(n))* para el peor de los casos.
