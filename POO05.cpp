/*
    José Juan Ojeda Granados, 17-01-2022
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
    gcc POO05.cpp -o POO05 -lstdc++
*/
#include <iostream>
#include <unistd.h> // sleep()
#include "POO05.h"

void BloquePrimero()
{
    system("clear");
    printf("\t\e[0;33mBloque 1ª Clase Base (Instaciación Stack, Heap, +++)\e[0m\n");
    
    printf("Se crean el primer objeto, sin inicializar y se muestran en el constructor\n");
    // Crea el objeto primero y lanza el constructor, se cierra con el destructor automático
    // Se almacena un valor inicial para el primer objeto: 1
    Numero Primero;
    printf("Al no inicializar el objeto, contendrá cualquier valor que se encuentre en\n");
    printf("la memoria asignada :\t ");
    Primero.pintar();
    printf("Se almacena el valor 1 con el método set y se muestra con el método pintar()\n");
    Primero.set_Numero(1);
    Primero.pintar();

    printf("Se crea el segundo objeto por puntero en heap, se muestra la dirección\n");
    printf("Se les asigna un dato inicial: 20, y se muestran en el constructor\n");
    // Crea el objeto por puntero y lanza el constructor, se cierra con el delete
    
    // NombreClaseDelObjeto *NombreVariablePuntero = new NombreClaseDelObjeto
    Numero *pNumero = new Numero(20); // (20) <-- Se almacena un valor inicial 
    printf("pNumero\t\t\e[0;33m%p\e[0m\n", pNumero);
    printf("Se llama al método set_Numero por puntero, se modifica el contenido\n");
    printf("con un 2 y se muestra\n");
    (*pNumero).set_Numero(2);
    pNumero->pintar(); // Otra forma --> (*pNumero).pintar();

    // destructor del constructor lanzado al crear *pNumero
    // pNumero = nullptr; no lanza el destructor al des comentarlo
    printf("Se elimina el puntero al segundo objeto y se dispara el destructor\n");
    delete pNumero;

    return;
}
//********************************************************************************
void BloqueSegundo()
{
    system("clear");
    printf("\t\e[0;33mBloque 2º Clase Derivada (Constructores, Destructores, Métodos)\e[0m\n");
    printf("Se crean el primer objeto, sin inicializar y se muestra en los constructores\n");
    printf("Nota, se recorren todos los constructores de las clases en que se base\n");
    printf("Al no inicializar el objeto, contendrá cualquier valor que exista\n");
    printf("en la memoria asignada\n");
    DerivadaNumero Segundo;
    Segundo.set_Numero(2);
    Segundo.set_DerivadaNumero(3);
    printf("Se almacenan los valores 2 y 3 con los métodos set y se muestran con pintartodo\n");
    Segundo.pintartodo();

    printf("Se inicializa con 5 en la clase derivada y almacena 4 con el método set\n");
    DerivadaNumero Tercero(5);
    Tercero.set_Numero(4);
    Tercero.pintartodo();

    printf("Se inicializan el objeto con valores 6 y 7, y y se muestra con el método pintartodo\n");
    DerivadaNumero Cuarto(6,7);
    Cuarto.pintartodo();

    // ultimo destructor automático
    return;
}
//********************************************************************************
void BloqueTercero()
{
    system("clear");
    printf("\t\e[0;33mBloque 3º Clase Derivada (Punteros, Funciones)\e[0m\n");
    printf("Se crean un objeto de clase derivada por puntero a clase derivada:\n");
    printf("\t\t\t\e[0;31m-->\e[0;36mDerivadaNumero *pObjeto = new DerivadaNumero;\e[0m\n");
    printf("Se muestran los constructores\n");
    // NombreClaseDelObjeto *NombreVariablePuntero = new NombreClaseDelObjeto
    DerivadaNumero *pObjeto = new DerivadaNumero;
    printf("Al no inicializar el objeto, contendrá cualquier valor que exista\n");
    printf("en la memoria asignada\n");
    printf("pObjeto = \t\t\e[0;33m%p\e[0m\n", pObjeto);
    printf("Se llama a los métodos:\t\e[0;36m(*pObjeto).set_Numero(1)\e[0m;\n");
    printf("y:\t\t\t\e[0;36m(*pObjeto).set_DerivadaNumero(2);\e[0m\n");
    (*pObjeto).set_Numero(1);    
    (*pObjeto).set_DerivadaNumero(2);
    pObjeto->pintartodo(); // Otra forma --> (*pObjeto).pintartodo();
    printf("Llamada a función calculo(), se ejecuta en clase derivada:\n\t\e[0;36mint Resultado = pObjeto->calculo();\e[0m = ");
    int Resultado = pObjeto->calculo();
    printf("%d\n", Resultado);
    printf("Llamada a función calculo1(), se ejecuta en clase derivada:\n\t\e[0;36mint Resultado = pObjeto->calculo1();\e[0m = ");
    Resultado = pObjeto->calculo1();
    printf("%d\n", Resultado);

    printf("Se elimina el puntero al objeto y se disparan los destructores\n");
    delete pObjeto;
    return;
}
//********************************************************************************
void BloqueCuarto()
{
    system("clear");
    printf("\t\e[0;33mBloque 4º Clase Derivada (Polimorfismo, Funciones Virtuales)\e[0m\n");
    printf("Se crean un objeto de clase base por puntero a clase derivada:\n");
    printf("\t\t\t\e[0;31m-->\e[0;36mNumero *pObjeto = new DerivadaNumero;\e[0m\n");
    printf("Se muestran los constructores\n");
    // NombreClaseDelObjeto *NombreVariablePuntero = new NombreClaseDelObjeto
    Numero *pObjeto = new DerivadaNumero;
    printf("Al no inicializar el objeto, contendrá cualquier valor que exista\n");
    printf("en la memoria asignada\n");
    printf("pObjeto = \t\t\e[0;33m%p\e[0m\n", pObjeto);
    printf("Se llama al método:\t\e[0;36m(*pObjeto).set_Numero(1)\e[0m;\n");
    printf("\e[0;31mError compilador-->\e[0m:\t\e[0;36m(*pObjeto).set_DerivadaNumero(2);\e[0m\n");
    (*pObjeto).set_Numero(1);    
//    (*pObjeto).set_DerivadaNumero(2);
    pObjeto->pintar(); // Otra forma --> (*pObjeto).pintar();
    printf("Llamada a función calculo(), se ejecuta en clase base:\n\t\e[0;36mint Resultado = pObjeto->calculo();\e[0m = ");
    int Resultado = pObjeto->calculo();
    printf("%d\n", Resultado);
    printf("Llamada a función calculo1(), se ejecuta en clase derivada:\n\t\e[0;36mint Resultado = pObjeto->calculo1();\e[0m = ");
    Resultado = pObjeto->calculo1();
    printf("%d\n", Resultado);

    printf("Se elimina el puntero al objeto y se disparan los destructores\n");
    delete pObjeto;
    return;
}
//********************************************************************************

void Menu()
{
    system("clear");
    int opcion;
    do
    {
        printf("\t\e[0;33mProgramación Orientada a Objetos desde CPP\n\n");
        printf("Clase Base, Clases Derivadas, Herencias, Constructores, Destructores, Métodos\n");
        printf("Instanciación por valor y por punteros....\e[0m\n");
        printf("\t1 - Bloque 1ª Clase Base (Instaciación Stack, Heap, +++).\n");
        printf("\t2 - Bloque 2º Clase Derivada (Constructores, Destructores, Métodos).\n");
        printf("\t3 - Bloque 3º Clase Derivada (Punteros, Funciones).\n");
        printf("\t4 - Bloque 4º Clase Derivada (Polimorfismo, Funciones Virtuales).\n\n");

        printf("\t  - Comparar las salidas de los bloques 3 y 4.\n\n");     
        printf("Teclea opción: ");
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            BloquePrimero();
            break;
        case 2:
            BloqueSegundo();
            break;
        case 3:
            BloqueTercero();
            break;
        case 4:
            BloqueCuarto();
            break;
        default:
            printf("\e[0;33mLa opción no es válida.\n\e[0m");
            sleep(2);
            system("clear");
        }
    } while (opcion < 1 || opcion > 4);
}

int main(int argc, char *argv[])
{
    system("clear");
    Menu();

    return 0;
}