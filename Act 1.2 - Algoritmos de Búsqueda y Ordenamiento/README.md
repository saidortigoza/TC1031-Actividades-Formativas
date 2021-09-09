## Análisis de complejidad temporal

**Selection Sort**

El algoritmo de ordenamiento de selección recorre n pasos dos veces mediante un ciclo for, por lo que en el peor de los casos su complejidad es O(n^2)

**Bubble Sort**

El algoritmo de ordenamiento burbuja recorre n pasos 2 veces, al igual que el Selection Sort, porque en el peor de los casos tiene que comparar todos los números e intercambiar su posición, por lo que su complejidad es O(n^2).

**Merge Sort**

El algoritmo de ordenamiento Merge divide la búsqueda en mitades cada vez más pequeñas, hasta que queda un sólo elemento (estamos frente a un O(log n)), y al momento de juntar los vectores ordenados recorre n pasos, por lo que su complejidad aumenta O(n), por lo tanto, su complejidad final de O(n log n).

**Búsqueda Secuencial**

El algoritimo de búsqueda secuencial recorre, en el peor de los casos, un arreglo completo utilizando un ciclo for, por lo que su complejidad es O(n).

**Búsqueda Binaria**

El algoritmo de búsqueda binaria funciona dividiendo la búsqueda en mitades utilizando la técnica de recursión, por lo que su complejidad es O(log n) para el peor de los casos.
