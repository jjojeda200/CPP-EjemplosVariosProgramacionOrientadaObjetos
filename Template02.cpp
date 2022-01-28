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
using std::string;

// ***************************************************************************
// Plantillas de clase
template <class TipoGenerico>
class Datos
{

public:
    Datos(TipoGenerico varX)
    {
        cout << varX << " es de tipo númerico. \n";
    }
};

template <>
class Datos<string>
{

public:
    Datos(string varX)
    {
        cout << varX << " es de tipo cadena. \n";
    }
};

// ***************************************************************************

int main()
{
    system("clear");
    std::cout << "\e[0;33mMétodo mostrar mayor entre dos números mismo tipo\e[0m\n";
    std::cout << "\e[0;36mTipo de dato, por convenio se usa \e[0;33mT\e[0m\n";

    Datos<int> numeroEntero(10);
    Datos<float> numeroDeciaml(10.5);
    Datos<string> cadena("texto");
    return 0;
}