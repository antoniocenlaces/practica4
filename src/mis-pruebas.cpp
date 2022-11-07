#include <iostream>
// #include "naturales-grandes.hpp"
using namespace std;
const unsigned NUM_DIGITOS = 1000;
unsigned numCifras(const unsigned natural[]) {
    unsigned i = NUM_DIGITOS -1;
    cout << "El vector al final: " << natural[i] << endl;
    cout << "En numCifras, i: " << i;
    while (i > 0 && natural[i] == 0) {
        i--;
        cout << " " << i;
    }
    // suponiendo que cuando natural[] sea todo ceros, se cuenta como 1 cifra (el cero)
    // este bucle no necesita inspeccionar la posición natural[0]
    return i+1;
    // Bucle acabado: i <= 0 o bien natural[i] !=0 
    // if (i > 0) {
    //     return i+1;
    // } else if (natural[i] == 0) { 
    //     return 0;
    // } else {
    //     return 1;
    // }
}

int main() {
    unsigned prueba[NUM_DIGITOS] = {0};

    unsigned tam = numCifras(prueba);

}