/*
    José Juan Ojeda Granados, 28-01-2022
    Primera aproximación a POO desde CPP

    Creación básica de una clase llamada cPunto
        * Definición atributos/características
        * Definición de métodos
        * Definición de constructor
        * Herencias Multimples

    Compilar con -lstdc++
*/
#include <iostream>

class cPunto
{
private:
    int varX, varY;

public:
    cPunto() { printf("\e[0;33mConstructor cPunto...\e[0m\n"); }
    ~cPunto() { printf("\e[0;33mDestructor cPunto...\e[0m\n"); }

    void set(int, int);
    int getX();
    int getY();
    void MostrarPunto();
};

void cPunto::set(int auxX = 0, int auxY = 0)
{
    varX = auxX;
    varY = auxY;
};

int cPunto::getX()
{
    return varX;
}
int cPunto::getY()
{
    return varY;
}

void cPunto::MostrarPunto()
{
    std::cout << "varX= " << varX << "\t";
    std::cout << "varY= " << varY << "\n";
}

//********************************************************************************

class cPuntoDerivada : public cPunto
{
private:
public:
    cPuntoDerivada() { printf("\e[0;33mConstructor cPuntoDerivada...\e[0m\n"); }
    ~cPuntoDerivada() { printf("\e[0;33mDestructor cPuntoDerivada...\e[0m\n"); }
    int getX();
};

//********************************************************************************

void MostrarPuntoDerivada(cPunto &auxPunto)
{
    std::cout << "\nFunción Mostrar -->\e[0;36m auxPunto.MostrarPunto();\e[0m\n";
    auxPunto.MostrarPunto();
    std::cout << "\nFunción Mostrar -->\e[0;36m cout << \"varX= \" << auxPunto.getX();\e[0m\n";
    std::cout << "varX= " << auxPunto.getX() << "\t";
    std::cout << "varY= " << auxPunto.getY() << "\n";
}

//********************************************************************************

int main()
{
    system("clear");

    cPunto objPunto0;
    objPunto0.set(10, 20);
    objPunto0.MostrarPunto();

    cPuntoDerivada objPunto1;
    objPunto1.set(100);
    objPunto1.MostrarPunto();

    MostrarPuntoDerivada(objPunto0);
    MostrarPuntoDerivada(objPunto1);

    std::cout << "Objeto0 varX * varY = " << objPunto0.getX() * objPunto0.getY() << "\n";
    std::cout << "Objeto1 varX * varY = " << objPunto0.getX() * objPunto1.getY() << "\n";
}
