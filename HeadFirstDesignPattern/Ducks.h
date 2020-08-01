#pragma once
#include <iostream>

class IFlyBehavior
{
public:
    virtual void fly() = 0;
};

class FlyWithWings : public IFlyBehavior {
public:
    virtual void fly() {
        std::cout << "I fly with wings!\n";
    }
};

class DontFly : public IFlyBehavior {
public:
    virtual void fly() {
        std::cout << "I dont fly!\n";
    }
};

class FlyRocketPowered : public IFlyBehavior {
public:
    virtual void fly() {
        std::cout << "Im flying with a rocket!\n";
    }
};

class IQuackBehavior {
public:
    virtual void quack() = 0;
};

class Quack : public IQuackBehavior {
public:
    virtual void quack() {
        std::cout << "I quack!\n";
    }
};

class Squeak : public IQuackBehavior {
public:
    virtual void quack() {
        std::cout << "I squeak!\n";
    }
};

class Silence : public IQuackBehavior {
public:
    virtual void quack() {
        std::cout << "I dont make noises!\n";
    }
};

class Duck {
public:
    IFlyBehavior* flyBehavior;
    IQuackBehavior* quackBehavior;

    void performFly() {
        flyBehavior->fly();
    }

    void performQuack() {
        quackBehavior->quack();
    }

    void setFlyBehavior(IFlyBehavior* fb) {
        flyBehavior = fb;
    }

    void setQuackBehavior(IQuackBehavior* qb) {
        quackBehavior = qb;
    }

    void swim() {
        std::cout << "Im swimming!\n";
    }

    virtual void display() {
        std::cout << "This duck looks like a normal Duck\n";
    }
};


class CityDuck : public Duck {
public:
    CityDuck() {
        flyBehavior = new FlyWithWings;
        quackBehavior = new Quack;
    }

    void display() {
        std::cout << "This duck looks like a City Duck\n";
    }
};

class MountainDuck : public Duck {
public:
    MountainDuck() {
        flyBehavior = new FlyWithWings();
        quackBehavior = new Quack();
    }
    void display() {
        std::cout << "This duck looks like a Mountain Duck\n";
    }

};
class RubberDuck : public Duck {
public:
    RubberDuck() {
        flyBehavior = new DontFly();
        quackBehavior = new Squeak();
    }

    void display() {
        std::cout << "This duck looks like a Rubber Duck\n";
    }

};

class ModelDuck : public Duck {
public:
    ModelDuck() {
        flyBehavior = new DontFly;
        quackBehavior = new Silence;
    }
    void display() {
        std::cout << "Im a Model Duck!\n";
     }
};