/*
    José Juan Ojeda Granados, 19-01-2022
    POO desde CPP
        * dynamic_cast: se usa cuando sé que una instancia de una clase base es realmente una instancia de una clase derivada. Típicamente en funciones virtuales.

    Convierte el operando expression en un objeto del tipo type-id:
        dynamic_cast < type-id > ( expression )

    type-id debe ser un puntero o una referencia a un tipo de clase definido previamente o un "puntero a void". El tipo de expression debe ser un puntero si type-id es un puntero, o un valor L si type-id es una referencia.

*/
#include <stdio.h>
#include <iostream>

struct A
{
    virtual void test1() { printf("\e[0;34mTest en A\e[0m\n"); }
    virtual void test2() { printf("\e[0;34mTest2 en A\e[0m\n"); }
    void test3() { printf("\e[0;34mTest3 en A\e[0m\n"); }
};

struct B : A
{
    virtual void test1() { printf("\e[0;35mTest en B\e[0m\n"); } // Al ser Virtual se ejecuta la derivada
    void test2() { printf("\e[0;35mTest2 en B\e[0m\n"); }
    void test3() { printf("\e[0;35mTest3 en B\e[0m\n"); }
};

struct C : B
{
    virtual void test1() { printf("\e[0;36mTest en C\e[0m\n"); } // Al ser Virtual ejecuta la derivada
    void test2() { printf("\e[0;36mTest2 en C\e[0m\n"); }
    void test3() { printf("\e[0;36mTest3 en C\e[0m\n"); }
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
    printf("\t\t\t\e[0;33mPolimorfismo - dynamic_cast\e[0m\n");

    A *pObjetoB_ClaseA = new B;
    printf("Dirección de Instancia: A *pObjetoB_ClaseA = new B;\t\e[0;31m%p\e[0m\n", pObjetoB_ClaseA);
    A *pObjetoC_ClaseA = new C;
    printf("Dirección de Instancia: A *pObjetoC_ClaseA = new C;\t\e[0;31m%p\e[0m\n", pObjetoC_ClaseA);

//********************************************************************************
    printf("\nFunción test1 ES virtual en la Clase A\n");
    printf("Llamada función: pObjetoB_ClaseA->test1();\t\t");
    pObjetoB_ClaseA->test1();
    printf("Llamada función: pObjetoC_ClaseA->test1();\t\t");
    pObjetoC_ClaseA->test1();
    printf("\nFunción test2 NO es virtual en la Clase A\n");
    printf("Llamada función: pObjetoB_ClaseA->test2();\t\t");
    pObjetoB_ClaseA->test2();
    printf("Llamada función: pObjetoC_ClaseA->test2();\t\t");
    pObjetoC_ClaseA->test2();
    printf("Llamadas a las funciones test2 no se puede al no existir en la Clase A\n\n");
//********************************************************************************
    
    printf("Conversión dinámica: B *pObjetoB = dynamic_cast<B *>(pObjetoC_ClaseA);\n");
    B *pObjetoB = dynamic_cast<B *>(pObjetoC_ClaseA);

    printf("Dirección pObjetoB\t\t\t\t\t\e[0;31m%p\e[0m\n", pObjetoB);
    if (pObjetoB)
    {
        printf("Llamada función: pObjetoB->test1();\t\t\t");
        pObjetoB->test1();
        printf("Llamada función: pObjetoB->test2();\t\t\t");
        pObjetoB->test2();
    }

    printf("\nConversión dinámica: C *pObjetoC = dynamic_cast<C *>(pObjetoB_ClaseA);\n");
    C *pObjetoC = dynamic_cast<C *>(pObjetoB_ClaseA);

    printf("Dirección pObjetoC\t\t\t\e[0;31m%p\e[0m\n", pObjetoC);
    if (pObjetoC) 
    {
        printf("Llamada función: pObjetoC->test1();\t");
        pObjetoC->test1();
        printf("Llamada función: pObjetoC->test2();\t");
        pObjetoC->test2();
    }
    else 
    {
        printf("El valor de una conversión con errores al tipo de puntero es NULL\n\n");
    }
    
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