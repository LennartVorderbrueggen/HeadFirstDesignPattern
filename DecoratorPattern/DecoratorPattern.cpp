// DecoratorPattern.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "StarbuzzOrderSystem.h"

int main()
{
    Beverage* beverage1 = new Espresso();
    beverage1 = new Mocha(beverage1);
    std::cout << beverage1->getDescription() << " : " << beverage1->cost() << "\n";

    Beverage* beverage2 = new HouseBlend();
    beverage2 = new Mocha(beverage2);
    beverage2 = new Mocha(beverage2);
    beverage2 = new Whip(beverage2);
    std::cout << beverage2->getDescription() << " : " << beverage2->cost() << "\n";


    Beverage* beverage3 = new DarkRoast();
    beverage3 = new Mocha(beverage3);
    beverage3 = new Whip(beverage3);
    beverage3 = new Soy(beverage3);
    std::cout << beverage3->getDescription() << " : " << beverage3->cost() << "\n";
}