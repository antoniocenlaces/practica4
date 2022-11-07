/******************************************************************************\
 * Programación 1. Práctica 4
 * Autores: Antonio José González Almela
 * Ultima revisión: 
 * Resumen: Fichero de implementación «naturales-grandes.cpp» de un módulo
 *          denominado «naturales-grandes» para trabajar con números naturales 
 *          de gran magnitud en la 4ª práctica.
\******************************************************************************/

#include "naturales-grandes.hpp"
#include <iostream>
#include <cmath>

using namespace std; 
const unsigned BASE = 10;
/*
 * Pre:  «original» almacena la representación de un número natural. La
 *       componente original[0] representa   
 *       las unidades de «original», la componente original[1] las decenas de  
 *       «original» y así, sucesivamente. Las componentes de índices
 *       superiores al correspondiente al dígito más significativo
 *       almacenan el valor 0. «original» y «copia» tienen 
 *       «NUM_DIGITOS» componentes.
 * Post: Tras ejecutar este procedimiento, «copia» almacena una representación
 *       idéntica a la del número natural correspondiente a la de «original».
 */
void copiar(const unsigned original[], unsigned copia[]) {
    for (unsigned i = 0; i < NUM_DIGITOS; i++) {
        copia[i] = original[i];
    }
}


/*
 * Pre:  «a» y «b» almacenan las representaciones de sendos números naturales. 
 *       Las componentes a[0] y b[0] representan las unidades del natural «a» y 
 *       «b», respectivamente, las componentes a[1] y b[1], las decenas y así 
 *       sucesivamente. Las componentes de índices
 *       superiores a los correspondientes a los dígitos más significativos
 *       almacenan el valor 0. Las componentes de 
 *       índices superiores almacenan el valor 0. «a» y «b» tienen «NUM_DIGITOS»
 *       componentes.
 * Post: Devuelve el valor booleano true si «a» y «b» representan el mismo
 *       número natural y false en caso contrario.
 */
bool sonIguales(const unsigned a[], const unsigned b[]) {
    bool iguales;
    unsigned i = 0;
    do {
        iguales = a[i] == b[i];
        i++;
    } while (i < NUM_DIGITOS && iguales);
    return iguales;
}


/*
 * Pre:  «natural» almacena la representación de un número natural. La 
 *       componente natural[0] representa las unidades de «natural», la
 *       componente natural[1] las decenas de «natural» y así, sucesivamente. 
 *       Las componentes de índices superiores al correspondiente al dígito más
 *       significativo almacenan el valor 0. «natural» tiene «NUM_DIGITOS»
 *       componentes.
 * Post: Devuelve el número de cifras de «natural» cuando se escribe en base 10
 *       sin ceros a la izquierda.
 */
unsigned numCifras(const unsigned natural[]) {

    unsigned i = NUM_DIGITOS - 1;

    while (i > 0 && natural[i] == 0) {
        i--;
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

/*
 * Pre:  «natural» almacena la representación de un número natural grande. Sea 
 *       «n» el número de dígitos de «natural». La componente natural[0] 
 *       representa las unidades de «natural», la componente natural[1] las
 *       decenas de «natural» y así, sucesivamente. Las componentes de índices
 *       superiores al correspondiente al dígito más significativo
 *       almacenan el valor 0. «natural» tiene «NUM_DIGITOS» componentes.
 * Post: Tras ejecutar este procedimiento, se ha escrito en la pantalla el
 *       número natural representado por «natural» (sin ceros a la izquierda).
 */
void escribirEnPantalla(const unsigned natural[]) {
    unsigned cifras = numCifras(natural);
        for (unsigned i = cifras - 1; i > 0; i--) {
            cout << natural[i];
        }
        cout << natural[0] << endl;
}

/*
 * Pre:  «naturalGrande» tiene «NUM_DIGITOS» componentes.
 * Post: Tras ejecutar este procedimiento, «naturalGrande» contiene la secuencia
 *       de dígitos equivalente a «numero». 
 *       La componente naturalGrande[0] almacena las unidades de «numero», la
 *       componente naturalGrande[1], las decenas de «numero» y así 
 *       sucesivamente. Las componentes de índices superiores al correspondiente
 *       al dígito más significativo almacenan el valor 0.
 */
void convertir(const unsigned numero, unsigned naturalGrande[]) {
    unsigned n = numero; // copio el numero recibido en una variable
    unsigned posicion = 0; // para almacenar la posición de naturalGrande por la que voy
    naturalGrande[posicion] = n % BASE; // dígito menos significativo
    n = n / BASE; // elimino de n el dígito menos significativo
    while (n != 0) {
        posicion++; // voy a la siguiente posición
        naturalGrande[posicion] = n % BASE;
        n = n / BASE;
    }
    for (posicion++; posicion < NUM_DIGITOS; posicion++) {
        naturalGrande[posicion] = 0;
    }
}


/*
 * Pre:  «naturalGrande» almacena los dígitos de un número natural lo 
 *       suficientemente pequeño como para ser representado por un dato de tipo
 *       «unsigned». En la componente naturalGrande[0] se almacena el dígito
 *       que representa las unidades de ese número, en la componente 
 *       naturalGrande[1], las decenas y así sucesivamente. Las componentes de
 *       índices superiores al correspondiente al dígito más significativo
 *       almacenan el valor 0. «naturalGrande» tiene «NUM_DIGITOS» componentes.
 * Post: Devuelve el valor numérico del natural almacenado en «naturalGrande».
 */
unsigned valor(const unsigned naturalGrande[]) {
    unsigned resultado = 0;
    for (unsigned i = 0; i < numCifras(naturalGrande); i++) {
        resultado += naturalGrande[i] * unsigned(pow(BASE,i));
    }
    return resultado;
}


/*
 * Pre:  «a» y «b» almacenan las representaciones de sendos números naturales. 
 *       Las componentes a[0] y b[0] representan las unidades del natural «a» y 
 *       «b», respectivamente, las componentes a[1] y b[1], las decenas y así 
 *       sucesivamente. Las componentes de índices superiores a los
 *       correspondientes a los dígitos más significativos almacenan el valor 0.
 *       La suma de los números representados por «a» y «b» tiene menos de
 *       «NUM_DIGITOS» dígitos.
 *       Los vectores «a», «b» y «suma» tienen «NUM_DIGITOS» componentes.
 * Post: Tras ejecutar este procedimiento, «suma» almacena la representación de
 *       un número natural equivalente a la suma de los naturales representados
 *       por «a» y «b». Sea «s» el número de dígitos de suma. La componente
 *       suma[0] representa las unidades de la suma, la componente suma[1]
 *       representa las decenas y así sucesivamente.
 */
void sumar(const unsigned a[], const unsigned b[], unsigned suma[]) {
    const unsigned TALLA_A = numCifras(a);
    const unsigned TALLA_B = numCifras(b);

    const unsigned TALLA_SUMA = TALLA_A > TALLA_B ? TALLA_A : TALLA_B;

    unsigned acarreo = 0;

    for (unsigned i = 0; i < TALLA_SUMA; i++) {
        unsigned digitoSuma = a[i] + b[i] + acarreo;
        suma[i] = digitoSuma % BASE;
        acarreo = digitoSuma > 9 ? 1 : 0;
    }
    suma[TALLA_SUMA] = acarreo;
    for (unsigned i = TALLA_SUMA + 1; i < NUM_DIGITOS; i++)  {
        suma[i]=0;
    }
}


/*
 * Pre:  «natural» almacena la representación de un número natural. La
 *       componente natural[0] representa las unidades de «natural», la
 *       componente natural[1] las decenas de «natural» y así sucesivamente. Las
 *       componentes de índices superiores al correspondiente al dígito más
 *       significativo almacenan el valor 0. «natural» e «imagen» tienen
 *       «NUM_DIGITOS» componentes.
 * Post: Tras ejecutar este procedimiento, «imagen» almacena la representación
 *        del número natural correspondiente a la imagen especular de «natural».
 */
void calcularImagen(const unsigned natural[], unsigned imagen[]) {
    const unsigned TALLA = numCifras(natural);

    unsigned j = TALLA - 1; // índice para recorrer imagen del final al principio

    for (unsigned i = 0; i < TALLA - 1; i++) {
        imagen[j] = natural[i];
        j--; 
    }
    imagen[0] = natural[TALLA - 1];
    for (unsigned i = TALLA; i < NUM_DIGITOS; i++)  {
        imagen[i]=0;
    }
}


/*
 * Pre:  «natural» almacena la representación de un número natural. La
 *       componente natural[0] representa las unidades de «natural», la
 *       componente natural[1] las decenas de «natural» y así sucesivamente. Las
 *       componentes de índices superiores al correspondiente al dígito más
 *       significativo almacenan el valor 0. «natural» tiene «NUM_DIGITOS»
 *       componentes.
 * Post: Devuelve «true» si y solo si «natural» es un número capicúa.
 */
bool esCapicua(const unsigned natural[]) {
    unsigned imagen[NUM_DIGITOS] = {0};
    calcularImagen(natural, imagen);

    if (sonIguales(natural, imagen)) {
        return true;
    } else {
        return false;
    }
}

