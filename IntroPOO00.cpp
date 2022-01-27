/*
    José Juan Ojeda Granados, 27-01-2022
    Primera aproximación a POO desde CPP

    Creación básica de una clase llamada Numero
        * Definición atributos/características
        * Definición de métodos
        * Definición de constructor
        * Instanciación de dos objetos "Primer" y por puntero a HEAP

    Compilar con -lstdc++
    gcc POO00.cpp -o POO00 -lstdc++
*/
#include <iostream>

class cPunto
{
private:
    
public:
    int varX, varY;
    cPunto(int auxX = 0, int auxY = 0)
    {
        varX = auxX;
        varY = auxY;
    };
};

void MostrarPunto(cPunto auxPunto)
{
    std::cout << "varX= " << auxPunto.varX << "\t";
    std::cout << "varY= " << auxPunto.varY << "\n";
}

int main()
{

    cPunto oPunto0(10, 20);
    MostrarPunto(oPunto0);

    MostrarPunto(cPunto(100, 200));

    MostrarPunto(cPunto(20));
}
