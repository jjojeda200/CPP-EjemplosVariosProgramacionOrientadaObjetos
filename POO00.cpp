/*
    José Juan Ojeda Granados, 10-01-2022
    Aproximación a POO desde CPP

    Creación básica de una clase llamada Numero
        * Definición atributos/características
        * Definición de métodos
        * Definición de constructor
        * Instanciación de dos objetos "Primer" y por puntero a HEAP

    Compilar con -lstdc++
    gcc POO00.cpp -o POO00 -lstdc++
*/
#include <iostream>

class Numero
{
public:
    Numero(); // Constructor
    ~Numero(); // Destructor
    // Métodos
    int obtenerNumero() const; // <-- impide la realización de modificaciones en el método
    void configurarNumero(int numero);
    void pintar();

private:
    int elNumero;
};

Numero::Numero()
{
    printf("\e[0;37mConstructor ...\e[0m\n");
}

Numero::~Numero()
{
    printf("\e[0;37mDestructor ...\e[0m\n");
}

int Numero::obtenerNumero() const // <-- impide la realización de modificaciones en el método 
{
    // elNumero = 80; // Error al compilar: assignment of member ‘Numero::elNumero’ in read-only object
    return elNumero;
}

void Numero::configurarNumero(int numero)
{
    elNumero = numero;
}

void Numero::pintar()
{
    printf("\e[0;36mEl número %d\e[0m\n", elNumero);
}

int main(int argc, char *argv[])
{
    system("clear");
    printf("\n\t\e[0;33mBloque main\e[0m\n");

    // Crea el objeto Primer y lanza el constructor, se cierra con el destructor automático
    Numero Primer;
    printf("Se crea el objeto Primer, se almacena el número 10 y se muestra\n");
    Primer.configurarNumero(10);
    Primer.pintar();
    // int varA = Primer.obtenerNumero(); // Para comprobar al desactivar const en el método
    // printf("varA = %d", varA);

    printf("\nSe crea el objeto por puntero en heap, y se muestra la dirección\n");
    // Crea el objeto por puntero y lanza el constructor, se cierra con el delete
    Numero *pNumero = new Numero;
    printf("pNumero\t\t\e[0;33m%p\e[0m\n", pNumero);

    printf("Se llama al método guardar numero por puntero y se almacena el 20, se muestra\n");
    (*pNumero).configurarNumero(20);
    (*pNumero).pintar();
    /*
    El operador flecha (->) se utiliza cuando se dispone de la dirección de un
    objeto (en el puntero correspondiente), en lugar del nombre del objeto.
    Es más habitual utilizar el operador flecha que el operador punto.
    La sintaxis (*puntero).miembro es incómoda de leer y escribir, así que usa la
    sintaxis flecha (->) de manera que puntero->miembro es equivalente a (*puntero).miembro.
    Ambas opciones son validas pero se aconseja usar el operador flecha (->).
    */
    printf("Se llama al método guardar numero por puntero y se modifica a 40, se muestra\n");
    pNumero->configurarNumero(40);
    pNumero->pintar();

    // destructor del constructor lanzado al crear *pNumero
    // pNumero = nullptr; no lanza el destructor al descomentarlo
    delete pNumero;

    // ultimo destructor automático
    return 0;
}