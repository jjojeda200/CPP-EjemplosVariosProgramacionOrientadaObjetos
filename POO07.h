/*
    José Juan Ojeda Granados, 17-01-2022
    POO desde CPP
        * Clase separada en archivos de encabezado
        * Clase derivada con constructores y destructores
        * Creación de objetos pro referencia y por punteros

    Creación básica de una clase llamada ClaseNumero
        * Definición atributos/características
        * Definición de métodos
        * Definición de constructor
        * Instanciación de objetos por valor y por puntero a HEAP

    Nota constructores y destructores:
    Algunas clases derivadas necesitan constructores. Si la clase base tiene un constructor hay que invocarlo y si, dicho constructor necesita argumentos, hay que proporcionarlos. Aunque los constructores de la clase base no se heredan, son usados para crear la parte heredada de la clase base, de un objeto de la clase derivada y, esta tarea es responsabilidad del constructor de la clase base.

    Compilar con -lstdc++
    gcc POO05.cpp -o POO05 -lstdc++
*/
#pragma once
#include <iostream>
#include <string>

class ClaseNumero
{
protected:
    int elNumero;

public:
    // ClaseNumero(); // <-- Esto es solo una declaración que no es utilizable 
    ClaseNumero() { printf("\e[0;37mConstructor predeterminado clase base... %d\e[0m\n", elNumero); } // Constructor predeterminado
    ClaseNumero(int elNumero);
    

    virtual ~ClaseNumero(); // <-- Si existe algún método virtual el destructor debe serlo también
    
    int get_ClaseNumero(); // <-- Es solo una declaración que no es utilizable si el desarrollo del método/función
    void set_ClaseNumero(int paramNumero); // <-- Es solo una declaración que no es utilizable si el desarrollo del método

    // void ClaseNumero::pintar() // <-- Al incluirse dentro de bloque de la clase, ya no hace falta referenciarla
    void pintar() { printf("\e[0;36mEl objeto almacena el número %d\e[0m\n\n", elNumero); }
    int calculo() { return elNumero * 10; }
    virtual int calculo1() { return elNumero * 10; }
};

// Metodos
ClaseNumero::ClaseNumero(int paramNumero) // Desarrollo del segundo Constructor
{
    this->elNumero = paramNumero; // Atributo elNumero = al parámetro paramNumero
    printf("\e[0;37mConstructor segundo clase base... %d\e[0m\n", elNumero);
}
ClaseNumero::~ClaseNumero() { printf("\e[0;37mDestructor clase base... %d\e[0m\n", elNumero); } 

int ClaseNumero::get_ClaseNumero() { return elNumero; }

// Atributo elNumero = al parámetro paramNumero, sin usar this
void ClaseNumero::set_ClaseNumero(int paramNumero) { elNumero = paramNumero; }


class ClaseDerivadaNumero : public ClaseNumero
{
private:
    int elNumeroDerivado;

public:
    // Utiliza el constructor predeterminado de la clase base (class ClaseNumero)
    // solo para crear objetos 
    ClaseDerivadaNumero() { printf("\e[0;33mConstructor predeterminado clase derivada... %d\e[0m\n\n", elNumeroDerivado); }
    
    ClaseDerivadaNumero( int paramNumeroDerivado )
    {
        elNumero = 0;
        this->elNumeroDerivado = paramNumeroDerivado;
        printf("\e[0;33mConstructor segundo clase derivada... %d, %d\e[0m\n", elNumeroDerivado, elNumero);
    }

    ClaseDerivadaNumero( int paramNumero, int paramNumeroDerivado) : ClaseNumero(elNumero)
    {
    this->elNumero = paramNumero; // Atributo elNumero = al parámetro paramNumero
    this->elNumeroDerivado = paramNumeroDerivado; // Atributo paramNumeroDerivado = al parámetro paramNumeroDerivado
    printf("\e[0;33mConstructor tercero clase derivada... %d, %d\e[0m\n", elNumero, elNumeroDerivado);
    }
    ~ClaseDerivadaNumero() { printf("\e[0;33mDestructor Clase Derivada... %d\e[0m\n", elNumeroDerivado); }

    int get_ClaseDerivadaNumero() { return elNumeroDerivado; }
    void set_ClaseDerivadaNumero(int paramNumero) { elNumeroDerivado = paramNumero; }
    void pintartodo() { printf("\e[0;35mEl objeto almacena los números %d, %d\e[0m\n\n", elNumero, elNumeroDerivado); }
    int calculo() { return elNumero * 20; }
    int calculo1() { return elNumero * 20; }
};
