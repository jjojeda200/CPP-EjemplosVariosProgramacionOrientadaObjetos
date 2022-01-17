/*
    José Juan Ojeda Granados, 15-01-2022
    POO desde CPP
        * Clase separada en archivos de encabezado
        * Clase derivada con constructores y destructores
        * Creación de objetos pro referencia y por punteros

    Creación básica de una clase llamada Numero
        * Definición atributos/características
        * Definición de métodos
        * Definición de constructor
        * Instanciación de objetos por valor y por puntero a HEAP

    Nota constructores y destructores:
    Algunas clases derivadas necesitan constructores. Si la clase base tiene un constructor hay que invocarlo y si, dicho constructor necesita argumentos, hay que proporcionarlos. Aunque los constructores de la clase base no se heredan, son usados para crear la parte heredada de la clase base, de un objeto de la clase derivada y, esta tarea es responsabilidad del constructor de la clase base.

    Compilar con -lstdc++
    gcc POO03.cpp -o POO03 -lstdc++
*/
#include <iostream>
#include "POO03.h"

int main(int argc, char *argv[])
{
    system("clear");

    printf("Se crean objetos Primer y Según, se almacena 1 y 2 respectivamente\n");
    printf("Y se muestran en el constructor\n");
    // Crea el objeto Primer y lanza el constructor, se cierra con el destructor automático
    // Se almacena un valor inicial para Primer de 1
    Numero Primer(1);
    Primer.pintar();
    // Se almacena un valor inicial para Según de 2
    Numero Segun(2);
    Segun.pintar();
    printf("Se modifica el dato de Primer y Según, a 10 y 20 respectivamente\n");
    printf("Y se muestra con el método pintar()\n");
    Primer.set_Numero(10);
    Primer.pintar();
    Segun.set_Numero(20);
    Segun.pintar();

    printf("\nSe crea el objeto por puntero en heap, se muestra la dirección\n");
    printf("Se les asigna un dato inicial y se muestran en el constructor\n");
    // Crea el objeto por puntero y lanza el constructor, se cierra con el delete
    // Se almacena un valor inicial 
    Numero *pNumero0 = new Numero(4);
    printf("pNumero0\t\t\e[0;33m%p\e[0m\n", pNumero0);

    Numero *pNumero1 = new Numero(5);
    printf("pNumero1\t\t\e[0;33m%p\e[0m\n", pNumero1);

    printf("Se llama al método set_Numero por puntero, se almacena el 40, se muestra\n");
    (*pNumero0).set_Numero(40);
    (*pNumero0).pintar();

    printf("Se muestra el ultimo objeto creado sin modificar su dato\n");
    // pNumero1->set_Numero(50);
    pNumero1->pintar();

    // destructor del constructor lanzado al crear *pNumero
    // pNumero0 = nullptr; no lanza el destructor al des comentarlo
    delete pNumero0;
    delete pNumero1;

    // Utilización clase derivada
    DerivadaNumero valor(100, 110);
    valor.pintar();

    // ultimo destructor automático
    return 0;
}