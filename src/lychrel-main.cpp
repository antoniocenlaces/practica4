/******************************************************************************\
 * Programación 1. Práctica 4
 * Autores: Antonio José González Almela
 * Ultima revisión: 
 * Resumen: Solicita un número natural al usuario e predice si puede ser un
 * número de Lychrel o no.
\******************************************************************************/
#include <iostream>
#include "naturales-grandes.hpp"

using namespace std;

int main() {
    unsigned lychrel[3][NUM_DIGITOS] = {0}; // Vector de tres componentes almacena números de cada iteración

    unsigned numero; // Valor de número natural intrioducido por usuario
    cout << "Escriba un número natural: ";
    cin >> numero;

    unsigned iteracion = 0; // Contador de iteraciones en el bucle de búsqueda de capicúa
   
    convertir(numero, lychrel[0]); // Inicializa las dos primeras posiciones del vector
    convertir(numero, lychrel[1]);

    cout << "Iteración " << iteracion << ": "; // Muestra la iteración cero por pantalla
    escribirEnPantalla(lychrel[0]);
    cout << endl;

    unsigned i=0; // Contador circular (0, 1, 2) para alternar las posiciones del vector lychrel[] en cada iteración

    bool parar = false; // Control para parar el bucle cuando se encuentra un capicúa

    unsigned cifras = numCifras(lychrel[0]); // Contador de cifras del número resultante en bucle actual

    while (cifras < NUM_DIGITOS && !parar) { // Bucle hasta encontrar capicúa o llegar al número máximo representable
        iteracion++;
        cout << "Iteración " << iteracion << ": "; // Escribe por pantalla la iteración actual
       
        calcularImagen(lychrel[(i + 1) % 3], lychrel[i  % 3]); // Calcula la imagen del número correspondiente a esta
                                                              // iteración, y almacena en el siguiente vector libre
        if ((cifras >= NUM_DIGITOS - 1) || cifras < 20) { // Si cumple condición muestra número y su imagen
            escribirEnPantalla(lychrel[(i + 1) % 3]);
            cout << " + ";
            escribirEnPantalla(lychrel[i % 3]);
        } else {                                          // De lo contratio muestra "... + ..."
            cout << "... + ..." ;
        }

        
        // cout << " + ";
        
        // if ((cifras >= NUM_DIGITOS - 1) || cifras < 20) {
        //     escribirEnPantalla(lychrel[(i + 1) % 2]);
        // } else {
        //     cout << "...";
        // }

        cout << " = ";

        sumar(lychrel[i % 3], lychrel[(i + 1) % 3], lychrel[(i + 2) % 3]); // Calcula la suma del número de esta iteración
                                                                           // con su imagen especular

        cifras = numCifras(lychrel[(i + 2) % 3]); // Calcula el número de cifras del resultado
        if ((cifras >= NUM_DIGITOS - 1) || cifras < 20) { // Lo muestra si cumple la condición
        escribirEnPantalla(lychrel[(i + 2) % 3]);
        } else {
            cout << "...";
        }

        cout << endl;

        parar = esCapicua(lychrel[(i + 2) % 3]); // Para el bucle si ha encontrado un capicúa
        
        i = (i + 1) % 3; // Aumenta el contador circular
    }
    cout << numero << (parar ? " no es un número de Lychrel." : " podría ser un número de Lychrel") << endl;
    return 0;
}
