// HeadFirstDesignPattern.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "Ducks.h"
#include "AdventureGame.h"

void adventureGame() {
    Knight knight;
    Troll troll;

    knight.fight();
    troll.fight();
    knight.setWeapon(new AxeBehavior);
    knight.fight();
}

void duckSim() {
    CityDuck cduck;
    RubberDuck rduck;
    ModelDuck mduck;

    cduck.display();
    cduck.setFlyBehavior(new DontFly);
    cduck.setQuackBehavior(new Quack);
    cduck.performFly();
    cduck.performQuack();

    rduck.display();
    rduck.setFlyBehavior(new DontFly);
    rduck.setQuackBehavior(new Squeak);
    rduck.performFly();
    rduck.performQuack();

    mduck.display();
    mduck.performFly();
    mduck.setFlyBehavior(new FlyRocketPowered);
    mduck.performFly();

    delete &cduck;
    delete &rduck;
    delete &mduck;
}

int main()
{
    //duckSim();
    adventureGame();

}