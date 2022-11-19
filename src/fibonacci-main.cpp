/******************************************************************************\
 * Programación 1. Práctica 4
 * Autores: Antonio José González Almela
 * Ultima revisión: 
 * Resumen: Programa que pide al usuario un número incial y otro final y 
 * escribe por pantalla la serie de Fibonacci comprendida entre ellos
\******************************************************************************/

#include <iostream>
#include "naturales-grandes.hpp"

using namespace std;

int main() {
    int numeroInicial; // Primer número solicitado a usuario. Puede ser negativo
    unsigned numeroFinal, contador; // Segundo número solicitado y contador de números
                                    // de la serie generados
    bool salirDelPrograma; // Para controlar cuando salir del bucle de generación de
                           // números de Fibonacci, o salir del programa si introducen un
                           // negativo

    do {    // Bucle que repite la petición de datos al usuario
            // hasta que introduce 0 o negativo en primer lugar
        cout << "Términos inicial y final (0 o negativo para acabar): ";
        cin >> numeroInicial ;
     
        salirDelPrograma = numeroInicial <= 0;
    
        if (!salirDelPrograma) {
            cin >> numeroFinal;
        }

        unsigned fibonacci[3][NUM_DIGITOS] = {0}; // Tres vectores de NUM_DIGITOS componentes
       
        fibonacci[0][0] = 0; // Posición 1 de la serie
        fibonacci[1][0] = 1; // Posición 2 de la serie

        // Si se introducen números incoherentes se sale del programa
        if (unsigned(numeroInicial) > numeroFinal) {
            salirDelPrograma = true;
        } else if (numeroInicial <= 2 && !salirDelPrograma) { // Código que escribe las posiciones 1 y 2 de la serie
            unsigned fin = numeroFinal > 1 ? 2 : 1;
            for (unsigned i = numeroInicial -1; i < fin; i++) {
                cout << i + 1 << ". ";
                escribirEnPantalla(fibonacci[i]);
                cout << endl;
            }
        }
        contador = 2; // Inicia el bucle de generación Fibonacci siendo la tercera posición
                      // la primera a generar
     
        unsigned i = 0; // Contador circular (0, 1, 2) para colocar el resultado de la suma en una
                        // posición de fibonacci[] libre
                        
        while (!salirDelPrograma && contador < numeroFinal) { // Bucle principal para generar números Fibonacci
            sumar(fibonacci[i % 3], fibonacci[(i + 1) % 3], fibonacci[(i + 2) % 3]);
            if (contador + 2 > unsigned(numeroInicial)) {
                cout << contador + 1 << ". ";
                escribirEnPantalla(fibonacci[(i + 2) % 3]);
                cout << endl;
            } 
            i = (i + 1) % 3;
            contador++;
        }

    } while (!salirDelPrograma);

    return 0;
}