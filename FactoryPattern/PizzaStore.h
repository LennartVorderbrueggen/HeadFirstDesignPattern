#include <iostream>

class Pizza {
public:
	void getDescriptions() {
		std::cout << "This is a Pizza.\n";
	}

	void prepare() {
		std::cout << "Pizza is prepared!\n";
	}
	void bake() {
		std::cout << "Pizza is baked!\n";
	}
	void cut() {
		std::cout << "Pizza is cutted!\n";
	}
	void box() {
		std::cout << "Pizza is boxed!\n";
	}
};

class CheesePizza : public Pizza {
public:
	void getDescriptions() {
		std::cout << "This is a cheese Pizza.\n";
	}
};

class VeggiePizza : public Pizza {
public:
	void getDescriptions() {
		std::cout << "This is a veggie Pizza.\n";
	}
};

class ClamPizza : public Pizza {
public:
	void getDescriptions() {
		std::cout << "This is a clam Pizza.\n";
	}
};

class PepperoniePizza : public Pizza {
public:
	void getDescriptions() {
		std::cout << "This is a pepperonie Pizza.\n";
	}
};

class PizzaFactory {
public:
	static Pizza* createPizza(std::string type){
		Pizza *pizza = NULL;
		if (type == "CheesePizza") {
			pizza = new CheesePizza;
		}
		else if (type == "VeggiePizza") {
			pizza = new VeggiePizza;
		}
		else if (type == "ClamPizza") {
			pizza = new ClamPizza;
		}
		else if (type == "PepperoniePizza") {
			pizza = new PepperoniePizza;
		}
		return pizza;
	}
};

class PizzaStore {
public:
	PizzaFactory factory;

	PizzaStore(PizzaFactory fac) {
		this->factory = fac;
	}

	static Pizza* orderPizza(std::string type) {
		Pizza *pizza;
		pizza = factory.createPizza(type);

		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();

		return pizza;
	}
};