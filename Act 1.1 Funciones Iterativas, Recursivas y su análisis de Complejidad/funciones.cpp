#include "funciones.h"

long Funciones::sumaIterativa (int n) {
    long acum = 0;
	for (int i = 1 ; i <= n ; i++) {
		acum += i;
	}
	return acum;
}

long Funciones::sumaRecursiva (int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n + sumaRecursiva(n - 1);
    }
}

long Funciones::sumaDirecta (int n) {
    return (n*(n + 1))/2;
}