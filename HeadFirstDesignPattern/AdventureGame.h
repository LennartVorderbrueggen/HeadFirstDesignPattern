#pragma once
#include <iostream>

class IWeaponBehavior {
public:
	virtual void useWeapon() = 0;
};

class KnifeBehavior : public IWeaponBehavior{
public:
	void useWeapon() {
		std::cout << "Cutting with knife\n";
	}
};

class BowAndArrowBehavior : public IWeaponBehavior {
public:
	void useWeapon() {
		std::cout << "Shot an A<rrow with a bow\n";
	}
};

class AxeBehavior : public IWeaponBehavior {
public:
	void useWeapon() {
		std::cout << "Chopping with an axe\n";
	}
};

class SwordBehavior : public IWeaponBehavior {
public:
	void useWeapon() {
		std::cout << "Swinging a sword\n";
	}
};


class Character {
public:
	IWeaponBehavior* weapon;

	void fight() {
		weapon->useWeapon();
	};
	virtual void setWeapon(IWeaponBehavior* w) {
		weapon = w;
	}
};

class Queen : public Character {
public:
	Queen() {
		weapon = new KnifeBehavior;
	}
};

class King : public Character {
public:
	King() {
		weapon = new BowAndArrowBehavior();
	}
};

class Knight : public Character {
public:
	Knight() {
		weapon = new SwordBehavior;
	}
};

class Troll : public Character {
public:
	Troll() {
		weapon = new AxeBehavior();
	}
};