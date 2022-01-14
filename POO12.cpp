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

// Definición de una clase base para vehiculos
class VehiculoRodante
{
public:
    VehiculoRodante() { printf("Constructor VehiculoRodante...\n"); }
    ~VehiculoRodante() { printf("Destructor VehiculoRodante...\n"); }
    /*
     * Función 'set_ruedas'
     * Recibe: num como int
     * Devuelve: void
     * Asigna al dato miembro 'mRuedas' el valor 'num'
     */
    void set_ruedas(int num)
    {
        this->mRuedas = num;
    }

    /*
     * Función 'get_ruedas'
     * Recibe: void
     * Devuelve: int
     * Devuelve el valor que hay dentro del dato miembro 'mRuedas'
     */
    int get_ruedas(void)
    {
        return this->mRuedas;
    }

    /*
     * Función 'set_pasajeros'
     * Recibe: num como int
     * Devuelve: void
     * Asigna al dato miembro 'mPasajeros' el valor 'num'
     */
    void set_pasajeros(int num)
    {
        this->mPasajeros = num;
    }

    /*
     * Función 'get_pasajeros'
     * Recibe: void
     * Devuelve: int
     * Devuelve el valor que hay dentro del dato miembro 'mPasajeros'
     */
    int get_pasajeros(void)
    {
        return this->mPasajeros;
    }

private:
    /* Generalmente en 'private' se sitúan los datos miembros */
    int mRuedas;
    int mPasajeros;
};

// Definición de una clase 'Camion' derivada de la clase base 'VehiculoRodante'.
class Camion : public VehiculoRodante
{
public:
    Camion() { printf("Constructor Camion...\n"); }
    ~Camion() { printf("Destructor Camion...\n"); }
    /*
     * Función 'set_carga'
     * Recibe: size como int
     * Devuelve: void
     * Asigna al dato miembro 'mCarga' el valor 'size'
     */
    void set_carga(int size)
    {
        this->mCarga = size;
    }

    /*
     * Función 'get_carga'
     * Recibe: void
     * Devuelve: int
     * Devuelve el valor que hay dentro del dato miembro 'mCarga'
     */
    int get_carga(void)
    {
        return this->mCarga;
    }

    /*
     * Función 'Mostrar'
     * Recibe: void
     * Devuelve: void
     * Muestra por pantalla las ruedas, pasajeros y la capacidad de carga del objeto 'Camion'
     */
    void Mostrar(void);

private:
    /* Generalmente en 'private' se sitúan los datos miembros */
    int mCarga;
};

void Camion::Mostrar(void)
{
    std::cout << "ruedas: " << this->get_ruedas() << std::endl;
    std::cout << "pasajeros: " << this->get_pasajeros() << std::endl;
    std::cout << "Capacidad de carga en pies cúbicos: " << this->get_carga() << std::endl;
}

/*
 * Este enumerador sirve para definir diferentes tipos de automóvil
 */
enum tipo
{
    deportivo,
    berlina,
    turismo
};

// Definición de una clase 'Automovil' derivada de la clase base 'VehiculoRodante'.
class Automovil : public VehiculoRodante
{
public:
    Automovil() { printf("Constructor Automovil...\n"); }
    ~Automovil() { printf("Destructor Automovil...\n"); }
    /*
     * Función 'set_tipo'
     * Recibe: t como tipo
     * Devuelve: void
     * Asigna al dato miembro 'mTipoDeAutomovil' el valor 't'
     */
    void set_tipo(tipo t)
    {
        this->mTipoDeAutomovil = t;
    }

    /*
     * Función 'get_tipo'
     * Recibe: void
     * Devuelve: tipo
     * Devuelve el valor que hay dentro del dato miembro 'mTipoDeAutomovil'
     */
    enum tipo get_tipo(void)
    {
        return this->mTipoDeAutomovil;
    };

    /*
     * Función 'Mostrar'
     * Recibe: void
     * Devuelve: void
     * Muestra por pantalla las ruedas, pasajeros y la capacidad de carga del objeto 'Camion'
     */
    void Mostrar(void);

private:
    enum tipo mTipoDeAutomovil;
};

void Automovil::Mostrar(void)
{
    std::cout << "ruedas: " << this->get_ruedas() << std::endl;
    std::cout << "pasajeros: " << this->get_pasajeros() << std::endl;
    std::cout << "tipo: ";

    switch (this->get_tipo())
    {
    case deportivo:
        std::cout << "deportivo";
        break;

    case berlina:
        std::cout << "berlina";
        break;

    case turismo:
        std::cout << "turismo";
    }
    std::cout << std::endl;
}

/*
 * Función 'main'
 * Recibe: void
 * Devuelve: int
 * El código es una posible implementación para clarificar el uso efectivo de clases bases y clases derivadas.
 * Muestra por pantalla valores de la clase base y de las clases derivadas.
 */
int main(void)
{
    Camion Camion1;
    Camion Camion2;
    Automovil Automovil1;

    Camion1.set_ruedas(18);
    Camion1.set_pasajeros(2);
    Camion1.set_carga(3200);

    Camion2.set_ruedas(6);
    Camion2.set_pasajeros(3);
    Camion2.set_carga(1200);

    Camion1.Mostrar();
    std::cout << std::endl;
    Camion2.Mostrar();
    std::cout << std::endl;

    Automovil1.set_ruedas(4);
    Automovil1.set_pasajeros(6);
    Automovil1.set_tipo(tipo::deportivo);

    Automovil1.Mostrar();

    return 0;
}