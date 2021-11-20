## Análisis de complejidad temporal

***loadGraphList***

La funcion *loadGraphList* toma V+A pasos para cargar los datos de un grafo y almacenarlos en una lista de adyacencia, ya que recibe dos parámetros: los vértices (V) y las arcos (A), por lo que su complejidad temporal es de *O(V+A)* para el peor de los casos.

***DFS***

La función *DFS (Depth First Search o búsqueda de profundidad)* es un algoritmo de búsqueda que se utiliza para buscar un nodo dentro de un grafo, su complejidad temporal es de *O(V+A)* para el peor de los casos, ya que le toma V+A pasos para guardar en un string la lista de nodos visitados y el path del recorrido de un grafo a partir de un nodo inicial y un nodo meta, donde V es el número de vértices y A es el número de arcos del grafo.

***BFS***

La funcion *BFS (Breadth First Search o búsqueda en anchura)* es un algoritmo de búsqueda en un grafo, su complejidad temporal es de *O(V+A)* para el peor de los casos, ya que le toma V+A pasos para guardar en un string la lista de nodos visitados y el path del recorrido de un grafo a partir de un nodo inicial y un nodo meta, donde V es el número de vértices y A es el número de arcos del grafo.
