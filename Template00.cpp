/*
    José Juan Ojeda Granados, 22-01-2022
    Templates

    El formato para declarar plantillas de funciones con parámetros de tipo es:

    template <identificador de clase> function_declaration;
    plantilla <identificador de nombre de tipo> function_declaration;

    La única diferencia entre ambos prototipos es el uso de la palabra clave class o typename de la palabra clave . Su uso es indistinto, ya que ambas expresiones se comportan exactamente de la misma manera.

*/
#include <iostream>
#include <string.h>
#include <stdio.h>
#define NC "\e[0m"
#define Amarillo "\e[0;33m"
#define Azul "\e[0;34m"
#define Blanco "\e[0;37m"
using std::cout;
using std::string;

// ***************************************************************************
// Plantillas de funciones
template <class Ttipodato>
Ttipodato GetMax(Ttipodato a, Ttipodato b)
{
    Ttipodato result;
    cout << "Mayor entre " << a << " y " << b << "\t";
    result = (a > b) ? a : b; // Si a es > devuelve a : si no devuelve b
    return (result);
}

template <class T, class U>
T GetMin(T a, U b) // OJO Devuelve del tipo indicado 
{
    cout << "Mayor entre " << a << " y " << b << "\t";
    return (a < b ? a : b);
}


// ***************************************************************************

int main()
{
    system("clear");
    std::cout << "\e[0;33mFunción mostrar mayor entre dos números mismo tipo\e[0m\n";
    std::cout << "\e[0;36mTtipodato, por convenio se usa \e[0;33mT\e[0m\n";
    // Plantillas de funciones
    int i = 8, j = 6, k;
    long l = 10, m = 5, n;
    float p = 13.4, q = 6.6, o;
    k = GetMax<int>(i, j);
    cout << "Mayor: " << k << '\n';
    n = GetMax<long>(l, m);
    cout << "Mayor: " << n << '\n';
    o = GetMax<float>(p, q);
    cout << "Mayor: " << o << '\n';

    std::cout << "\e[0;33mFunción mostrar menor entre dos números distintos tipos\e[0m\n";
    // int i, j;
    // long l;
    k = GetMin<int, long>(i, l);
    cout << "Menor: " << k << '\n';
    o = GetMin<int, float>(i, q);
    cout << "Menor: " << o << '\n';

    return 0;
}