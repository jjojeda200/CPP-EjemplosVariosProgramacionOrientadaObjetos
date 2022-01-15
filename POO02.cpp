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
    base() { printf("\e[0;33mConstructor base...\e[0m\n"); } // Constructor
    ~base() { printf("\e[0;33mDestructor base...\e[0m\n"); }

    void set(int a, int b)
    {
        this->variableI = a;
        variableII = b;
    }
    void mostrar()
    {
        printf("Valores/atributos almacenados en el objeto (clase base): %d, %d\n", variableI, variableII);
    }
};

class derivada : public base
{
private:
    int k;

public:
    derivada() { printf("\e[0;33mConstructor derivada...\e[0m\n"); } // Constructor
    derivada(int x) { k = x; } // Constructor que me permite invocar e inicializar el objeto a la vez
    ~derivada() { printf("\e[0;33mDestructor derivada...\e[0m\n"); }


    void mostrarDerivada() { printf("Valores/atributos almacenados en el objeto (clase derivada): %d\n", k); }
};

int main()
{
    system("clear");
    

    // instaciación objeto clase base, comentada para seguimiento de ejecución de constructores
    printf("\e[0;31mEjemplo Uno\e[0m\n");
    printf("\e[0;34mInstaciar objeto de la clase base invocando al metodo constructor:\e[0m\n");
    base Variables0;
    Variables0.set(10, 20);
    Variables0.mostrar();
    printf("\e[0m\n");


    printf("\e[0;31mEjemplo Dos\n");
    // instaciación objeto clase derivada, primero se ejecuta el constructor de la clase más nativa
    // Al instaciar un objeto de la clase derivada, tambien se asignan las variable de la clase base,
    // que contendran valores al azar, los que existan en la zona de memoria que se asigan para guardar
    // las variables (variableI y variableII)
    printf("\e[0;34mInstaciar objeto de la clase derivada sin invocar al metodo constructor:\n");
    printf("\e[0;37mderivada objeto0(30)\e[0m\n");
    derivada objeto0(30);
    printf("\e[0;34mSe llama al método de la clase base: \e[0;37mobjeto0.mostrar();\e[0m\n");
    objeto0.mostrar();
    printf("\e[0;34mSe llama al método de la clase derivada: \e[0;37mobjeto0.mostrarDerivada();\e[0m\n");
    objeto0.mostrarDerivada();
    printf("\e[0m\n");


    printf("\e[0;31mEjemplo Tres\n");
    printf("\e[0;34mInstaciar objeto de la clase derivada invocando al primer método constructor\n");
    printf("sin pasar valor para la variable: \e[0;37mderivada objeto1\e[0m\n");
    derivada objeto1;
    printf("\e[0;34mSe pasan valores al objeto de la clase base invocando al metodo set:\n");
    printf("\e[0;37mobjeto1.set(40, 50);\n");
    objeto1.set(40, 50);
    printf("\e[0;34mSe llama al método de la clase base: \e[0;37mobjeto1.mostrar();\e[0m\n");
    objeto1.mostrar();
    printf("\e[0;34mSe llama al método de la clase derivada: \e[0;37mobjeto1.mostrarDerivada();\e[0m\n");
    objeto1.mostrarDerivada();
    printf("\e[0m\n");

    
    return 0;
}