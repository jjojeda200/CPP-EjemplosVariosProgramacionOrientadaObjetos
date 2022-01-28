/*
    José Juan Ojeda Granados, 28-01-2022
    Primera aproximación a POO desde CPP

    Creación básica de una clase llamada cPunto
        * Definición atributos/características
        * Definición de métodos get, set
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

int cPunto::getX() { return varX; }
int cPunto::getY() { return varY; }

void cPunto::MostrarPunto() 
{
    std::cout << "varX= " << varX << "\t";
    std::cout << "varY= " << varY << "\n";
}

//********************************************************************************

class cRalla
{
private:
    int varA, varB;

public:
    cRalla(){ printf("\e[0;33mConstructor cRalla...\e[0m\n"); }
    ~cRalla() { printf("\e[0;33mDestructor cRalla...\e[0m\n"); }
    
    void set(int, int);
    int getA();
    int getB();
    void MostrarRalla();
};

void cRalla::set(int auxA = 0, int auxB = 0)
{
    varA = auxA;
    varB = auxB;
};

int cRalla::getA() { return varA; }
int cRalla::getB() { return varB; }

void cRalla::MostrarRalla() 
{
    std::cout << "varA= " << varA << "\t";
    std::cout << "varB= " << varB << "\n";
}

//********************************************************************************

class cDerivada : public cPunto, public cRalla
{
private:
    friend 
public:
    cDerivada() { printf("\e[0;33mConstructor cDerivada...\e[0m\n"); }
    ~cDerivada() { printf("\e[0;33mDestructor cDerivada...\e[0m\n"); }
};

//********************************************************************************

void MostrarDerivada(cDerivada &auxPunto)
{
    std::cout << "\nFunción Mostrar -->\e[0;36m auxPunto.MostrarPunto();\e[0m\n";
    auxPunto.cPunto::MostrarPunto();
    std::cout << "\nFunción Mostrar -->\e[0;36m auxPunto.MostrarPunto();\e[0m\n";
    auxPunto.cRalla::MostrarRalla();
    std::cout << "\nFunción Mostrar -->\e[0;36m cout << \"varX= \" << auxPunto.getX();\e[0m\n";
    std::cout << "varX= " << auxPunto.getX() << "\t";
    std::cout << "varY= " << auxPunto.getY() << "\n";
    std::cout << "varA= " << auxPunto.getA() << "\t";
    std::cout << "varB= " << auxPunto.getB() << "\n";
}

//********************************************************************************

int main()
{
    system("clear");

    cPunto objPunto;
    objPunto.set(10, 20);
    objPunto.MostrarPunto();

    cRalla objRalla;
    objRalla.set(50, 60);
    objRalla.MostrarRalla();

    cDerivada objDerivado;
    objDerivado.cPunto::set(110,120);
    objDerivado.cRalla::set(150,160);

    MostrarDerivada(objDerivado);


}
