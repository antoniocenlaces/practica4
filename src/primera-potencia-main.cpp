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
    
    unsigned numero;

    do 
    {   
        unsigned sumando[NUM_DIGITOS] = {0}; // vector para guardar el valor a sumar consigo mismo
        unsigned suma[NUM_DIGITOS] = {0}; // resultado de la suma

        sumando[0] = 1; // inicialización de valores para el caso de potencia 0
        suma[0] = 1;
        unsigned potencia = 0;

        cout << "Número de dígitos (0 o negativo para acabar): ";
        cin >> numero;

        while (numCifras(suma) < numero && numero > 0) {
            potencia++;
            sumar(sumando, sumando, suma);
            copiar(suma, sumando);
        }
        escribirEnPantalla(suma);
        cout << " es 2 elevado a la " << potencia << "ª potencia" << endl;
        cout << "y es la primera potencia de 2 de " << numero << " dígito" 
             << (numero > 1 ? "s." : ".") << endl;        
    } while (numero > 0);

    return 0;
}
