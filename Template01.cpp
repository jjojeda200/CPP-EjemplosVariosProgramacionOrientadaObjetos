/*
    José Juan Ojeda Granados, 22-01-2022
    Templates

    El formato para declarar plantillas de funciones con parámetros de tipo es:

    template <identificador de clase> function_declaration;
    plantilla <identificador de nombre de tipo> function_declaration;

    La única diferencia entre ambos prototipos es el uso de la palabra clave class o typename de la palabra clave . Su uso es indistinto, ya que ambas expresiones se comportan exactamente de la misma manera.

    https://www-cplusplus-com.translate.goog/doc/oldtutorial/templates/?_x_tr_sl=auto&_x_tr_tl=es&_x_tr_hl=es
*/
#include <iostream>
#include <string.h>
#include <stdio.h>
#define NC "\e[0m"
#define Amarillo "\e[0;33m"
#define Azul "\e[0;34m"
#define Blanco "\e[0;37m"
using std::cin;
using std::cout;
using std::endl;
using std::string;

// ***************************************************************************
// Plantillas de funciones
template <class T>
T GetMax(T a, T b)
{
    T result;
    result = (a > b) ? a : b;
    printf("Multiplicación %d\n", static_cast<int>(a * b));
    printf("Multiplicación %f\n", static_cast<float>(a * b));
    return (result);
}

template <class T, class U>
T GetMin(T a, U b)
{
    return (a < b ? a : b);
}

// ***************************************************************************
// Plantillas de clase
template <class T>
class miPar
{
    T a, b;

public:
    miPar(T primero, T segundo)
    {
        a = primero;
        b = segundo;
    }
    T getmax();
};

template <class T>
T miPar<T>::getmax()
{
    T retval;
    retval = a > b ? a : b;
    return retval;
}

// ***************************************************************************

int main()
{
    system("clear");
    // Plantillas de funciones
    int i = 8, j = 6, k;
    long l = 10, m = 5, n;
    float p = 13.4, q = 6.6, o;
    k = GetMax<int>(i, j);
    n = GetMax<long>(l, m);
    o = GetMax<float>(p, q);
    cout << "Mayor " << k << '\n';
    cout << "Mayor " << n << '\n';
    cout << "Mayor " << o << '\n';

    // int i, j;
    // long l;
    k = GetMin<int, long>(i, l);
    cout << "Menor " << k << '\n';
    o = GetMin<int, float>(i, q);
    cout << "Menor " << o << '\n';

// Plantillas de clase
    miPar<int> miObjeto(100, 75);
    cout << "Mayor " << miObjeto.getmax() << '\n';

    return 0;
}