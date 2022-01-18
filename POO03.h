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
#pragma once
#include <iostream>
#include <string>

class Numero
{
protected:
    int elNumero; // string elNombre;

public:
    Numero(int elNumero);
    ~Numero();
    int get_Numero();
    void set_Numero(int numero);

    // void Numero::pintar() // Al incluirse dentro de bloque de la clase, ya no hace falta referenciarla
    void pintar() { printf("\e[0;36mEl número %d\e[0m\n", elNumero); }
};

Numero::Numero(int paramNumero) // Constructor 
{
    this->elNumero = paramNumero; // Atributo elNumero = al parámetro paramNumero
    printf("\e[0;37mConstructor ... %d\e[0m\n", elNumero);
}

Numero::~Numero() { printf("\e[0;37mDestructor ...\e[0m\n"); } 

int Numero::get_Numero() // Metodo
{
    return elNumero;
}

void Numero::set_Numero(int numero)
{
    elNumero = numero; // Atributo elNumero = al parámetro numero, sin usar this
}



class DerivadaNumero : public Numero
{
private:
    int elNumeroDerivado;

public:
    DerivadaNumero( int paramNumeroDerivado, int elNumero) : Numero(elNumero)
    {
    elNumero = elNumero; // Atributo elNumero = al parámetro paramNumero
    this->elNumeroDerivado = paramNumeroDerivado; // Atributo paramNumeroDerivado = al parámetro paramNumeroDerivado
    printf("\e[0;37mConstructor Clase Derivada... %d, %d\e[0m\n", elNumeroDerivado, elNumero);
    }
    ~DerivadaNumero() { printf("\e[0;37mDestructor Clase Derivada...\e[0m\n"); }
};
