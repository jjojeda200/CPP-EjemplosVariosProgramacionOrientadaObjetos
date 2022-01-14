/*
    José Juan Ojeda Granados, 14-01-2022
    Programación en C++/Herencia

    https://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C%2B%2B/Objetos_y_Clases

    https://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C%2B%2B/Herencia

    Compilar con -lstdc++
*/
#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

class base
{

    int i, j;

public:
    base() { printf("Constructor base...\n"); }
    ~base() { printf("Destructor base...\n"); }

    void set(int a, int b)
    {
        i = a;
        j = b;
    }
    void mostrar() { cout << i << " " << j << "\n"; }
};

class derivada : public base
{

    int k;

public:
    derivada() { printf("Constructor derivada...\n"); }
    ~derivada() { printf("Destructor derivada...\n"); }

    derivada(int x) { k = x; }
    void mostrar_k() { cout << k << "\n"; }
};

int main()
{
    derivada obj(3);

    obj.set(1, 2); // accesar a miembro de base
    obj.mostrar(); // accesar a miembro de base

    obj.mostrar_k(); // usa miembro de la clase derivada

    return 0;
}