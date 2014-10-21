#include "Creep.h"
#include <iostream>
#include "Tower.h"

using namespace std;

//create simple creep with health
Creep::Creep(int health) :health(health){}

int Creep::getHealth(){
	return health;
}

//Tower t damages the creeper
void Creep::damage(Tower* t){
	health -= t->getDamage();

	cout << "\nCreep says \"OW!\".\n";
	cout << t->getDamage() << " points of damage dealt.\n";

	if (t->getType() == Tower::ICE || t->getType() == Tower::SUPER)
		cout << "Creep is also slowed down!\n";

	cout << "Creep has " << health << "HP remaining...";
	cout << ((health <= 0) ? "He dead.\n" : "\n");
}

