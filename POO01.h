/*
    José Juan Ojeda Granados, 11-01-2022
    POO desde CPP Clase separada en archivos de encabezado

    Creación básica de una clase llamada Numero
        * Definición atributos/características
        * Definición de métodos
        * Definición de constructor
        * Instanciación de dos objetos "Primer" y por puntero a HEAP

    Compilar con -lstdc++
    gcc POO01.cpp -o POO01 -lstdc++
*/
#pragma once
#include <iostream>
#include <string>

class Numero
{
public:
    Numero(int elNumero);
    ~Numero();
    int obtenerNumero();
    void configurarNumero(int numero);
    void pintar();

private:
    int elNumero;
    //string elNombre;
};

Numero::Numero(int paramNumero) // Constructor
{
    this->elNumero = paramNumero; // Atributo elNumero = al parametro paramNumero
    printf("\e[0;37mConstructor ... %d\e[0m\n", elNumero);
}

Numero::~Numero() // Destructor
{
    printf("\e[0;37mDestructor ...\e[0m\n");
}

int Numero::obtenerNumero() // Metodo
{
    return elNumero;
}

void Numero::configurarNumero(int numero)
{
    elNumero = numero; // Atributo elNumero = al parametro numero, sin usar this
}

void Numero::pintar()
{
    printf("\e[0;36mEl número %d\e[0m\n", elNumero);
}
