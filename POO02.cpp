/*
    José Juan Ojeda Granados, 14-01-2022
    Programación en C++/Herencia

    Compilar con -lstdc++
*/
#include <iostream>
#include <cstring>

class base
{
private:
    int variableI, variableII;

public:
    base() { printf("\e[0;33mConstructor base...\e[0m\n"); }
    ~base() { printf("\e[0;33mDestructor base...\e[0m\n"); }

    void set(int a, int b)
    {
        this->variableI = a;
        variableII = b;
    }
    void mostrar()
    {
        printf("Valores pasados al método set (clase base): %d, %d\n", variableI, variableII);
    }
};

class derivada : public base
{
private:
    int k;

public:
    derivada() { printf("\e[0;34mConstructor derivada...\e[0m\n\n"); }
    ~derivada() { printf("\e[0;34mDestructor derivada...\e[0m\n\n"); }

    derivada(int x) { k = x; }
    void mostrarDerivada() { printf("Valores pasados al método set (clase derivada): %d\n", k); }
};

int main()
{
    system("clear");
    

    // instaciación objeto clase base, comentada para seguimiento de ejecución de constructores
    printf("\e[0;31mEjemlo Uno\n");
    printf("\e[0;34mInstaciar objeto de la clase base invocando al metodo constructor:\n");
    base Variables0;
    Variables0.set(10, 20);
    Variables0.mostrar();
    Variables0.~base();
    printf("\e[0;34mLlamando explícitamente al destructor\n\n");


    printf("\e[0;31mEjemlo Dos\n");
    // instaciación objeto clase derivada, primero se ejecuta el constructor de la clase más nativa
    // Al instaciar un objeto de la clase derivada, tambien se asignan las variable de la clase base,
    // que contendran valores al azar, los que existan en la zona de memoria que se asigan para guardar
    // las variables (variableI y variableII)
    printf("\e[0;34mInstaciar objeto de la clase derivada sin invocar al metodo constructor:\n");
    printf("\e[0;37mderivada objeto0(30)\e[0m\n");
    derivada objeto0(30);
    printf("\n\e[0;34mSe llama al método de la clase base: \e[0;37mobjeto0.mostrar();\e[0m\n");
    objeto0.mostrar();
    printf("\n\e[0;34mSe llama al método de la clase derivada: \e[0;37mobjeto0.mostrarDerivada();\e[0m\n");
    objeto0.mostrarDerivada(); // acceder miembro de la clase derivada

/*
    derivada objeto1; // Instacia objeto de la clase derivada invoca al metodo constructor
    objeto1.set(40, 50);
    objeto1.mostrar();

    //derivada objeto1(30);

    objeto1.set(10, 20); // acceder a miembro de base modificando los valores asignados anteriormente

    objeto1.mostrar(); // acceder a miembro de la clase base
    objeto1.mostrarDerivada(); // acceder miembro de la clase derivada
*/
    return 0;
}