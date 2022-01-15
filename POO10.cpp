/*
    José Juan Ojeda Granados, 14-01-2022
    Programación en C++/Objetos y Clases

    https://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C%2B%2B/Objetos_y_Clases

    https://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C%2B%2B/Herencia

    Compilar con -lstdc++
*/
#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

// Esto define la clase CRender
class CRender
{
public:
    char buffer[255];
    void m_Renderizar(const char *cadena);

    CRender() { printf("Constructor...\n"); }
    ~CRender() { printf("Destructor...\n"); }
};

// Implementa m_Renderizar() para la cadena
void CRender::m_Renderizar(const char *cadena)
{
    strcpy(buffer, cadena); // Copia la cadena
    return;
}

int main(int argc, char **argv)
{
    // crear 2 objetos CRender
    CRender render1, render2;

    render1.m_Renderizar("Inicializando la cadena para el objeto render1");
    render2.m_Renderizar("Inicializando la cadena para el objeto render2");

    cout << "buffer en render1: ";
    cout << render1.buffer << endl; // Tenemos acceso a buffer ya que es publico.

    cout << "buffer en render2: ";
    cout << render2.buffer << endl;

    return (0);
}