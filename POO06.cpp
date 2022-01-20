/*
    José Juan Ojeda Granados, 19-01-2022
    POO desde CPP
    * dynamic_cast se usa casi exclusivamente para gestionar polimorfismo. Puedes convertir un puntero o referencia de un tipo polimórfico a cualquier otro tipo de clase (un tipo polimórfico tiene al menos una función virtual, declarada o heredada)

    Convierte:
    *              <Clase Derivada                                        > (Clase Base)
    * dynamic_cast <Tipo de puntero o referencia al que queremos convertir> (puntero o referencia del que queremos convertir)

    dynamic_cast para funcionar necesita:
    * La clase base debe contener como minino un método virtual

*/
#include <stdio.h>
#include <iostream>

struct A
{
    virtual void test1() { printf("\e[0;34mTest1 en A\e[0m Virtual\n"); } // Al ser Virtual ejecuta la derivada
    virtual void test2() { printf("\e[0;34mTest2 en A\e[0m Virtual\n"); }
    void test3() { printf("\e[0;34mTest3 en A\e[0m\n"); }
};

struct B : A
{
    virtual void test1() { printf("\e[0;35mTest1 en B\e[0m Virtual\n"); } // Al ser Virtual se ejecuta la derivada
    void test2() { printf("\e[0;35mTest2 en B\e[0m\n"); }
    void test3() { printf("\e[0;35mTest3 en B\e[0m\n"); }
    virtual void test4() { printf("\e[0;35mTest4 en B\e[0m Virtual\n"); }
    void test5() { printf("\e[0;35mTest5 en B\e[0m\n"); }
};

struct C : B
{
    void test1() { printf("\e[0;36mTest1 en C\e[0m\n"); }
    void test2() { printf("\e[0;36mTest2 en C\e[0m\n"); }
    void test3() { printf("\e[0;36mTest3 en C\e[0m\n"); }
    void test4() { printf("\e[0;36mTest4 en C\e[0m\n"); }
};

void Globaltest(A& a)
{
    try
    {
        C &c = dynamic_cast<C&>(a);
        printf("in GlobalTest\n");
    }
    catch(std::bad_cast) { printf("Can't cast to C\n"); }
}

int main()
{
    system("clear");
    printf("\t\t\e[0;33mPolimorfismo - Método virtual / Clase derivadas\e[0m\n");
    // Instaciando en memoria heap
    A *pObjetoB_ClaseA = new B;
    printf("Dirección de Instancia: A *pObjetoB_ClaseA = new B;\t\e[0;31m%p\e[0m\n", pObjetoB_ClaseA);
    A *pObjetoC_ClaseA = new C;
    printf("Dirección de Instancia: A *pObjetoC_ClaseA = new C;\t\e[0;31m%p\e[0m\n", pObjetoC_ClaseA);
    B *pObjetoC_ClaseB = new C;
    printf("Dirección de Instancia: B *pObjetoC_ClaseB = new C;\t\e[0;31m%p\e[0m\n", pObjetoC_ClaseB);

//********************************************************************************
    /*
    El operador flecha (->) se utiliza cuando se dispone de la dirección de un objeto (en el puntero correspondiente), en lugar del nombre del objeto.
    Es más habitual utilizar el operador flecha que el operador punto.
    La sintaxis (*puntero).miembro es incómoda de leer y escribir, así que usa la sintaxis flecha (->) de manera que puntero->miembro es equivalente a (*puntero).miembro.
    Ambas opciones son validas pero se aconseja usar el operador flecha (->).
    */
    printf("\t\n\e[0;33mFunción test1 ES virtual en A y B, NO en C\e[0m\n");
    printf("Llamada función: pObjetoB_ClaseA->test1();\t\t");
    pObjetoB_ClaseA->test1();
    printf("Llamada función: pObjetoC_ClaseA->test1();\t\t");
    pObjetoC_ClaseA->test1();
    printf("Llamada función: pObjetoC_ClaseB->test1();\t\t");
    pObjetoC_ClaseB->test1();

    printf("\t\n\e[0;33mFunción test2 ES virtual en A, NO en B y C\e[0m\n");
    printf("Llamada función: pObjetoB_ClaseA->test2();\t\t");
    pObjetoB_ClaseA->test2();
    printf("Llamada función: pObjetoC_ClaseA->test2();\t\t");
    pObjetoC_ClaseA->test2();
    printf("Llamada función: pObjetoC_ClaseB->test2();\t\t");
    pObjetoC_ClaseB->test2();

    printf("\t\n\e[0;33mFunción test3 NO es virtual en A, B y C\e[0m\n");
    printf("Llamada función: pObjetoB_ClaseA->test3();\t(*)\t");
    pObjetoB_ClaseA->test3();
    printf("Llamada función: pObjetoC_ClaseA->test3();\t(**)\t");
    pObjetoC_ClaseA->test3();
    printf("Llamada función: pObjetoC_ClaseB->test3();\t(***)\t");
    pObjetoC_ClaseB->test3();
    printf("\n\e[0;33mLlamadas a función test4 no se puede realizar al no existir en la Clase A\e[0m\n");
    printf("\e[0;33mSalvo en el objeto C declarado sobre la Clase B\e[0m\n");
    printf("Llamada función: pObjetoC_ClaseB->test4();\t\t");
    pObjetoC_ClaseB->test4();
    printf("Llamada función: pObjetoC_ClaseB->test5();\t\t");
    pObjetoC_ClaseB->test5();

//********************************************************************************
    printf("\n\t\t\e[0;33mPolimorfismo - dynamic_cast\e[0m\n");
    printf("Conversión dinámica: B *pObjetoBA = dynamic_cast<B*>(pObjetoB_ClaseA);\n");
    B *pObjetoBA = dynamic_cast<B*>(pObjetoB_ClaseA);
    printf("Dirección pObjetoBA\t\t\t\t\t\e[0;31m%p\e[0m\n", pObjetoBA);
    if (pObjetoBA)
    {
        printf("Llamada función: pObjetoBA->test1();\t\t\t");
        pObjetoBA->test1();
        printf("Llamada función: pObjetoBA->test2();\t\t\t");
        pObjetoBA->test2();
        printf("Llamada función: pObjetoBA->test3();\t\t(*)\t");
        pObjetoBA->test3();
    }
    
    printf("\nConversión dinámica: B *pObjetoBCA = dynamic_cast<B*>(pObjetoC_ClaseA);\n");
    B *pObjetoBCA = dynamic_cast<C*>(pObjetoC_ClaseA);
    printf("Dirección pObjetoBCA\t\t\t\t\t\e[0;31m%p\e[0m\n", pObjetoBCA);

    printf("\nConversión dinámica: C *pObjetoCA = dynamic_cast<C*>(pObjetoC_ClaseA);\n");
    C *pObjetoCA = dynamic_cast<C*>(pObjetoC_ClaseA);
    printf("Dirección pObjetoCA\t\t\t\t\t\e[0;31m%p\e[0m\n", pObjetoCA);
    if (pObjetoCA)
    {
        printf("Llamada función: pObjetoCA->test1();\t\t\t");
        pObjetoCA->test1();
        printf("Llamada función: pObjetoCA->test2();\t\t\t");
        pObjetoCA->test2();
        printf("Llamada función: pObjetoCA->test3();\t\t(**)\t");
        pObjetoCA->test3();
    }

    printf("\nConversión dinámica: C *pObjetoCB = dynamic_cast<C*>(pObjetoC_ClaseB);\n");
    C *pObjetoCB = dynamic_cast<C*>(pObjetoC_ClaseB);
    printf("Dirección pObjetoCA\t\t\t\t\t\e[0;31m%p\e[0m\n", pObjetoCB);
    if (pObjetoCB)
    {
        printf("Llamada función: pObjetoCB->test1();\t\t\t");
        pObjetoCB->test1();
        printf("Llamada función: pObjetoCB->test2();\t\t\t");
        pObjetoCB->test2();
        printf("Llamada función: pObjetoCB->test3();\t\t(***)\t");
        pObjetoCB->test3();
    }

    printf("\nConversión dinámica: C *pObjetoCBA = dynamic_cast<C*>(pObjetoB_ClaseA);\n");
    C *pObjetoCBA = dynamic_cast<C*>(pObjetoB_ClaseA);
    printf("Dirección pObjetoC\t\t\t\e[0;31m%p\e[0m\n", pObjetoCBA);

/*
    printf("\nConversión dinámica: C *pObjetoCBA = dynamic_cast<C*>(pObjetoB_ClaseA);\n");
    C *pObjetoCBA = dynamic_cast<C*>(pObjetoB_ClaseA);
    printf("Dirección pObjetoC\t\t\t\e[0;31m%p\e[0m\n", pObjetoCBA);
 
    printf("\nConversión dinámica: C *pObjetoCA = dynamic_cast<C *>(pObjetoC_ClaseB);\n");
    C *pObjetoCA = dynamic_cast<C *>(pObjetoC_ClaseA);

    printf("Dirección pObjetoCA\t\t\t\t\t\e[0;31m%p\e[0m\n", pObjetoCA);
    if (pObjetoCA)
    {
        printf("Llamada función: pObjetoC->test1();\t");
        pObjetoCA->test1();
        printf("Llamada función: pObjetoC->test2();\t");
        pObjetoCA->test2();
    }
    else
    {
        printf("El valor de una conversión con errores al tipo de puntero es NULL\n\n");
    }
 */

    pObjetoB_ClaseA = nullptr;
    delete pObjetoB_ClaseA;
    pObjetoC_ClaseA = nullptr;
    delete pObjetoC_ClaseA;
    pObjetoC_ClaseB = nullptr;
    delete pObjetoC_ClaseB;
    pObjetoBA = nullptr;
    delete pObjetoBA;
    pObjetoCA = nullptr;
    delete pObjetoCA;
    pObjetoCB = nullptr;
    delete pObjetoCB;

    pObjetoCBA = nullptr;
    delete pObjetoCBA;
    /*
        C ConStack;
        Globaltest(ConStack);

       // will fail because B knows nothing about C
        B BonStack;
        Globaltest(BonStack);
    */
}
// #define BLACK   "\033[30m"      /* Black */
// #define RED     "\033[31m"      /* Red */
// #define GREEN   "\033[32m"      /* Green */
// #define YELLOW  "\033[33m"      /* Yellow */
// #define BLUE    "\033[34m"      /* Blue */
// #define MAGENTA "\033[35m"      /* Magenta */
// #define CYAN    "\033[36m"      /* Cyan */
// #define WHITE   "\033[37m"      /* White */
