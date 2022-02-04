/*
    José Juan Ojeda Granados, 02-02-2022
    Primera aproximación a POO desde CPP

    Creación básica de una clase llamada cPunto
        * Definición atributos/características
        * Definición de métodos get, set
        * Definición de constructor
        * Herencias Multiples
        * Vectores

    Compilar con -lstdc++
*/
#include <iostream>
#include <vector>

class cPunto
{
private:
    int varX, varY;

public:
    // cPunto() { printf("\e[0;33mConstructor cPunto...\e[0m\n"); }
    // ~cPunto() { printf("\e[0;33mDestructor cPunto...\e[0m\n"); }

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
    // cRalla() { printf("\e[0;33mConstructor cRalla...\e[0m\n"); }
    // ~cRalla() { printf("\e[0;33mDestructor cRalla...\e[0m\n"); }

    void set(int, int);
    int getA() const;
    int getB() const;
    void MostrarRalla();
};

void cRalla::set(int auxA = 0, int auxB = 0)
{
    varA = auxA;
    varB = auxB;
};

int cRalla::getA() const { return varA; }
int cRalla::getB() const
{
    //varB = 300; // <-- const no permite modificaciones
    return varB;
}

void cRalla::MostrarRalla()
{
    std::cout << "varA= " << varA << "\t";
    std::cout << "varB= " << varB << "\n";
}

//********************************************************************************

class cDerivada : public cPunto, public cRalla
{
private:
public:
    // cDerivada() { printf("\e[0;33mConstructor cDerivada...\e[0m\n"); }
    // ~cDerivada() { printf("\e[0;33mDestructor cDerivada...\e[0m\n"); }
};

//********************************************************************************

void MostrarDerivada(cDerivada &auxPunto)
{
    std::cout << "\nFunción Mostrar -->\e[0;36m auxPunto.MostrarPunto();\e[0m\n";
    auxPunto.cPunto::MostrarPunto();
    std::cout << "\nFunción Mostrar -->\e[0;36m auxPunto.MostrarPunto();\e[0m\n";
    auxPunto.cRalla::MostrarRalla();
    std::cout << "\nFunción Mostrar -->\e[0;36m cout << \"varX= \" << auxPunto.get...();\e[0m\n";
    std::cout << "varX= " << auxPunto.getX() << "\t";
    std::cout << "varY= " << auxPunto.getY() << "\n";
    std::cout << "varA= " << auxPunto.getA() << "\t";
    std::cout << "varB= " << auxPunto.getB() << "\n";
}

void SetDerivada(cDerivada &auxPunto, int x, int y, int a, int b)
{
    std::cout << "\nFunción SetDerivada\n";
    auxPunto.cPunto::set(x, y);
    auxPunto.cRalla::set(a, b);
    auxPunto.cPunto::MostrarPunto();
    auxPunto.cRalla::MostrarRalla();
}

//********************************************************************************

int main()
{
    system("clear");
    std::cout << "\e[0;33mCreación objPunto -->\e[0m\n";
    cPunto objPunto;
    objPunto.set(10, 20);
    objPunto.MostrarPunto();

    std::cout << "\n\e[0;33mCreación objRalla -->\e[0m\n";
    cRalla objRalla;
    objRalla.set(50, 60);
    objRalla.MostrarRalla();

    std::cout << "\n\e[0;33mCreación objDeri0 -->\e[0m";
    cDerivada objDeri0;
    objDeri0.cPunto::set(110, 120);
    objDeri0.cRalla::set(150, 160);

    MostrarDerivada(objDeri0);
    SetDerivada(objDeri0, 210, 220, 250, 260);

    cDerivada objDeri1;
    cDerivada objDeri2;

//********************************************************************************

    std::cout << "\n\e[0;33mCreación vector vDerivada -->\e[0m\n";
    std::cout << "\e[0;36mLlamada a métodos por vector -->\e[0m\n";
    std::vector<cDerivada> vDerivada;
    vDerivada.push_back(objDeri0);
    vDerivada.push_back(objDeri1);
    vDerivada.push_back(objDeri2);
    
    vDerivada[1].cPunto::set(310, 320);
    vDerivada[1].cRalla::set(350, 360);
    vDerivada[2].cPunto::set(410, 420);
    vDerivada[2].cRalla::set(450, 460);
/*
    vDerivada[0].MostrarPunto();
    vDerivada[0].MostrarRalla();
    vDerivada[1].MostrarPunto();
    vDerivada[1].MostrarRalla();
*/    
    for (int i = 0; i < 3; i++)
    {
        std::cout << "\nPosición: " << i << " en el vector\n";
        std::cout << "varX\tvarY\tvarA\tvarB\n";
        std::cout << vDerivada[i].getX() << "\t"  << vDerivada[i].getY() << "\t"
                  << vDerivada[i].getA() << "\t"  << vDerivada[i].getB() << "\n";
    }

    std::cout << "\n\e[0;33mPosición: en memoria de los elementos del vector\e[0m\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Elemento: " << i << "\t" << &vDerivada[i]<< "\n";
    }
    // 
    
    return 0;
}