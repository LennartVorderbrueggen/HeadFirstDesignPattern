// FactoryPattern.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "PizzaStore.h"

int main()
{
	PizzaFactory* factory = new PizzaFactory();
	PizzaStore* myStore = new PizzaStore(*factory);

	Pizza myCheesePizza = myStore->orderPizza("CheesePizza");
	myCheesePizza.getDescriptions();

	Pizza myNewPizza = myStore->orderPizza("ClamPizza");
	myNewPizza.getDescriptions();
}