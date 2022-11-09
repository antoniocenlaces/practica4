/******************************************************************************\
 * Programación 1. Práctica 4
 * Autores: Antonio José González Almela
 * Ultima revisión: 
 * Resumen: 
\******************************************************************************/
#include <iostream>
#include "naturales-grandes.hpp"

using namespace std;

int main() {
    unsigned lychrel[2][NUM_DIGITOS] = {0};
    unsigned numero;
    cout << "Escriba un número natural: ";
    cin >> numero;

    unsigned iteracion = 0;
   
    convertir(numero, lychrel[0]);
    convertir(numero, lychrel[1]);
    cout << "Iteración " << iteracion << ": ";
    escribirEnPantalla(lychrel[0]);
    cout << endl;

    unsigned i=0;
    bool parar = false;
    unsigned cifrasParo = 0;
    while (cifrasParo < NUM_DIGITOS && !parar) {
        iteracion++;
        cout << "Iteración " << iteracion << ": ";
        unsigned cifras = numCifras(lychrel[i % 2]);
        if ((cifras >= NUM_DIGITOS - 1) || cifras < 20) {
            escribirEnPantalla(lychrel[i % 2]);
        } else {
            cout << "...";
        }

        calcularImagen(lychrel[i % 2], lychrel[(i + 1) % 2]);
        
        cout << " + ";
        cifras = numCifras(lychrel[i % 2]);
        if ((cifras >= NUM_DIGITOS - 1) || cifras < 20) {
            escribirEnPantalla(lychrel[(i + 1) % 2]);
        } else {
            cout << "...";
        }

        cout << " = ";

        sumar(lychrel[i % 2], lychrel[(i + 1) % 2], lychrel[(i + 1) % 2]);

        cifras = numCifras(lychrel[i % 2]);
        if ((cifras >= NUM_DIGITOS - 1) || cifras < 20) {
        escribirEnPantalla(lychrel[(i + 1) % 2]);
        } else {
            cout << "...";
        }

        cout << endl;

        parar = esCapicua(lychrel[(i + 1) % 2]);
        cifrasParo = numCifras(lychrel[(i + 1) % 2]);
        i = (i + 1) % 2;
    }
    cout << numero << (parar ? " no es un número de Lychrel." : " podría ser un número de Lychrel") << endl;
    return 0;
}
