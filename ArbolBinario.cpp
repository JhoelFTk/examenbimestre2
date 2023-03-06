#include <iostream>
#include <string>
using namespace std;

struct Coordenada {
    int capacidadBelica;
    string geoLocalizacion;
    string arsenal;
    struct Coordenada *izq, *der;
};

typedef struct Coordenada *ABB;

ABB crearNodo(int capacidadBelica, string geoLocalizacion, string arsenal) {
    ABB nuevoNodo = new(struct Coordenada);
    nuevoNodo->capacidadBelica = capacidadBelica;
    nuevoNodo->geoLocalizacion = geoLocalizacion;
    nuevoNodo->arsenal = arsenal;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;

    return nuevoNodo;
}

void insertarABB(ABB &arbol, int capacidadBelica, string geoLocalizacion, string arsenal) {
    if (arbol == NULL) {
        arbol = crearNodo(capacidadBelica, geoLocalizacion, arsenal);
    }
    else if (capacidadBelica < arbol->capacidadBelica) {
        insertarABB(arbol->izq, capacidadBelica, geoLocalizacion, arsenal);
    }
    else if (capacidadBelica > arbol->capacidadBelica) {
        insertarABB(arbol->der, capacidadBelica, geoLocalizacion, arsenal);
    }
}

void mostrarABB(ABB arbol, int contador) {
    if (arbol == NULL) {
        return;
    }
    else {
        mostrarABB(arbol->der, contador + 1);
        for (int i = 0; i < contador; i++) {
            cout << "    ";
        }
        cout << arbol->capacidadBelica << ", " << arbol->geoLocalizacion << ", " << arbol->arsenal << endl;
        mostrarABB(arbol->izq, contador + 1);
    }
}

int main() {
    ABB arbol = NULL;

    insertarABB(arbol, 5, "GPS5", "bct");
    insertarABB(arbol, 4, "GPS4", "acd");
    insertarABB(arbol, 7, "GPS7", "aaabbct");
    insertarABB(arbol, 1, "GPS1", "bc");
    insertarABB(arbol, 2, "GPS2", "ac");

    mostrarABB(arbol, 0);

    return 0;
}
