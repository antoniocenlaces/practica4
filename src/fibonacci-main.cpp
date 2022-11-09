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
    int numeroInicial;
    unsigned numeroFinal, contador;
    bool salirDelPrograma;

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
        contador = 2;
        while (!salirDelPrograma && contador < numeroFinal) {
            unsigned i = 0;
            while (i < 3 && contador < numeroFinal) {
                sumar(fibonacci[i % 3], fibonacci[(i + 1) % 3], fibonacci[(i + 2) % 3]);
                if (contador + 2 > unsigned(numeroInicial)) {
                    cout << contador + 1 << ". ";
                    escribirEnPantalla(fibonacci[(i + 2) % 3]);
                    cout << endl;
                } 
                i++;
                contador++;
            }
        }
    } while (!salirDelPrograma);

    return 0;
}
