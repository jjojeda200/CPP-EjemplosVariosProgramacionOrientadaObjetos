/*
    José Juan Ojeda Granados, 10-01-2022
    Repaso pasando parámetros a funciones por medio de punteros memoria

    Manejo básico de punteros a zonas de memoria
     * Para declarar variable apuntadora.
     * Para desreferenciar, acceder directamente al contenido de una ubicación de memoria 
       almacenada en una variable puntero.
     & Para mostrar la dirección de memoria de cualquier variable.

    Compilar con -lstdc++
    gcc Repa02.cpp -o Repa02 -lstdc++
*/
#include <iostream>

class Numero
{
public:
    int obtenerNumero();
    void configurarNumero(int numero);
    void pintar();

private:
    int elNumero;
};

int Numero::obtenerNumero()
{
    return elNumero;
}

void Numero::configurarNumero(int numero)
{
    elNumero = numero;
}

void Numero::pintar()
{
    std::cout << elNumero + elNumero << std::endl;
}

int main()
{
    Numero Primer;
    Primer.configurarNumero(10);
    Primer.pintar();

    std::cout << Primer.obtenerNumero() << std::endl;
    return 0;
}
