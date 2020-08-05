#include <iostream>

class Beverage {
public:
	std::string description = "Unknown Beverage";
	double price;

	void setPrice(double price) {
		this->price = price;
	}

	double getPrice() {
		return price;
	}

	virtual std::string getDescription() = 0;

	virtual double cost() = 0;

};

class ConditmentDecorator : public Beverage {
public:
	virtual std::string getDescription() = 0;
};

class HouseBlend : public Beverage {
public:
	HouseBlend() {
		description = "House Blend Coffee";
		price = 0.89;
	}
	double cost() {
		return this->getPrice();
	}
	std::string getDescription() {
		return this->description;
	};
};

class DarkRoast : public Beverage {
public:
	DarkRoast() {
		description = "DarkRoast";
		price = 0.99;
	}
	double cost() {
		return this->getPrice();
	}
	std::string getDescription() {
		return this->description;
	};
};

class Decaf : public Beverage {
public:
	Decaf() {
		description = "Decaf";
		price = 0.99;
	}
	double cost() {
		return this->getPrice();
	}
	std::string getDescription() {
		return this->description;
	};
};


class Espresso : public Beverage {
public:
	Espresso() {
		description = "Espresso";
		price = 1.99;
	}
	double cost() {
		return this->getPrice();
	}
	std::string getDescription() {
		return this->description;
	};
};

class Mocha : public ConditmentDecorator {
	Beverage* beverage;

public:
	Mocha(Beverage* b) {
		price = 0.20;
		beverage = b;
	}
	std::string getDescription() {
		std::string name = ", Mocha";
		return beverage->getDescription() + name;
	}
	double cost() {
		return beverage->cost() + this->getPrice();
	}
};

class Whip : public ConditmentDecorator {
	Beverage* beverage;

public:
	Whip(Beverage* beverage) {
		price = 0.10;
		this->beverage = beverage;
	}
	std::string getDescription() {
		std::string name = ", Whip";
		return beverage->getDescription() + name;
	}
	double cost() {
		return beverage->cost() + this->getPrice();
	}
};

class Soy : public ConditmentDecorator {
	Beverage* beverage;

public:
	Soy(Beverage* beverage) {
		price = 0.15;
		this->beverage = beverage;
	}
	std::string getDescription() {
		std::string name = ", Soy";
		return beverage->getDescription() + name;
	}
	double cost() {
		return beverage->cost() + this->getPrice();
	}
};

class SteamedMilk : public ConditmentDecorator {
	Beverage* beverage;

public:
	SteamedMilk(Beverage* beverage) {
		price = 0.20;
		this->beverage = beverage;
	}
	std::string getDescription() {
		std::string name = ", SteamedMilk";
		return beverage->getDescription() + name;
	}
	double cost() {
		return beverage->cost() + this->getPrice();
	}
};