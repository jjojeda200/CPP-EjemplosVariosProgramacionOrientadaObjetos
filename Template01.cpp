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
// Plantillas de clase
    miPar<int> miObjeto(100, 75);
    cout << "Mayor " << miObjeto.getmax() << '\n';

    return 0;
}