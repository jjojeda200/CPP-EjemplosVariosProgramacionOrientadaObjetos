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
#pragma once
#include <iostream>
#include <string>

class Numero
{
protected:
    int elNumero;

public:
    // Numero(); // <-- Esto es solo una declaración que no es utilizable 
    Numero() { printf("\e[0;37mConstructor predeterminado clase base... %d\e[0m\n", elNumero); } // Constructor predeterminado
    Numero(int elNumero);
    ~Numero();
    int get_Numero(); // <-- Es solo una declaración que no es utilizable si el desarrollo del método/función
    void set_Numero(int paramNumero); // <-- Es solo una declaración que no es utilizable si el desarrollo del método

    // void Numero::pintar() // <-- Al incluirse dentro de bloque de la clase, ya no hace falta referenciarla
    void pintar() { printf("\e[0;36mEl objeto almacena el número %d\e[0m\n", elNumero); }
};

// Metodos
Numero::Numero(int paramNumero) // Desarrollo del segundo Constructor
{
    this->elNumero = paramNumero; // Atributo elNumero = al parámetro paramNumero
    printf("\e[0;37mConstructor segundo clase base... %d\e[0m\n", elNumero);
}
Numero::~Numero() { printf("\e[0;37mDestructor clase base... %d\e[0m\n", elNumero); } 

int Numero::get_Numero() { return elNumero; }

// Atributo elNumero = al parámetro paramNumero, sin usar this
void Numero::set_Numero(int paramNumero) { elNumero = paramNumero; }


class DerivadaNumero : public Numero
{
private:
    int elNumeroDerivado;

public:
    // Utiliza el constructor predeterminado de la clase base (class Numero)
    // solo para crear objetos 
    DerivadaNumero() { printf("\e[0;33mConstructor predeterminado clase derivada... %d\e[0m\n\n", elNumeroDerivado); }
    
    DerivadaNumero( int paramNumeroDerivado )
    {
        elNumero = 0;
        this->elNumeroDerivado = paramNumeroDerivado;
        printf("\e[0;33mConstructor segundo clase derivada... %d, %d\e[0m\n", elNumeroDerivado, elNumero);
    }

    DerivadaNumero( int paramNumero, int paramNumeroDerivado) : Numero(elNumero)
    {
    this->elNumero = paramNumero; // Atributo elNumero = al parámetro paramNumero
    this->elNumeroDerivado = paramNumeroDerivado; // Atributo paramNumeroDerivado = al parámetro paramNumeroDerivado
    printf("\e[0;33mConstructor tercero clase derivada... %d, %d\e[0m\n", elNumero, elNumeroDerivado);
    }
    ~DerivadaNumero() { printf("\e[0;33mDestructor Clase Derivada... %d\e[0m\n", elNumeroDerivado); }

    int get_DerivadaNumero() { return elNumeroDerivado; }
    void set_DerivadaNumero(int paramNumero) { elNumeroDerivado = paramNumero; }
    void pintartodo() { printf("\e[0;35mEl objeto almacena los números %d, %d\e[0m\n\n", elNumero, elNumeroDerivado); }
};
