//
// Said Ortigoza
// A01707430
//

#ifndef FUNCIONES_H
#define FUNCIONES_H

class Funciones {
public:
    Funciones(){};
    
    int sumaIterativa(int);
    int sumaRecursiva(int);
    int sumaDirecta(int);
};

int Funciones::sumaIterativa(int n) {
    int sum = 0, i;
    for(i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}
  
int Funciones::sumaRecursiva(int n) {
    if(n == 0) {
        return 0;
    }
    return n + sumaRecursiva(n - 1);
}

int Funciones::sumaDirecta(int n) {
    return (n * (n + 1) / 2);
}

#endif
