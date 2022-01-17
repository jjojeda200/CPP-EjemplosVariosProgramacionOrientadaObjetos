/*
    José Juan Ojeda Granados, 16-01-2022
    Programación en C++/Objetos y Clases

    https://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C%2B%2B/Objetos_y_Clases

    https://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C%2B%2B/Herencia

    Compilar con -lstdc++
*/
#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

class Pareja
{
    // atributos
    double a, b;

public:
    // métodos
    double getA();
    double getB();
    void setA(double n);
    void setB(double n);

    Pareja() { printf("Constructor Pareja...\n"); }
    ~Pareja() { printf("Destructor Pareja...\n"); }
};

// implementación de los métodos de la clase Pareja
double Pareja::getA() { return a; }
double Pareja::getB() { return b; }
void Pareja::setA(double n) { a = n; }
void Pareja::setB(double n) { b = n; }


class Suma : public Pareja
{
    // atributos de Suma
    double resultado;

public:
    // métodos de Sumaé realizado por Herencia por extensión
    double calcular();

    // métodos de Sumaé realizado por herencia por composicion
    double calcularP();
    Pareja  p;

    Suma() { printf("Constructor Suma...\n"); }
    ~Suma() { printf("Destructor Suma...\n"); }
};
// implementación de método realizado por Herencia por extensión
double Suma::calcular() { return getA() + getB(); }

// implementación del método realizado por herencia por composicion
double Suma::calcularP() { return p.getA() + p.getB(); }


int main()
{
    // implementación de método realizado por Herencia por extensión
    Suma s;
    s.setA(80);
    s.setB(100);
    cout << s.getA() << " + " << s.getB() << " = " << s.calcular() << endl;
    cin.get();

    // implementación del método realizado por herencia por composicion
    Suma ss;
    s.p.setA(180);
    s.p.setB(100);
    cout << s.p.getA() << " + " << s.p.getB() << " = " << s.calcularP() << endl;
    cin.get();
    return 0;
}