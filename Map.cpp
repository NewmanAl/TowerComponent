#include "Map.h"
#include <iostream>
#include "Tower.h"
#include "Creep.h"

using namespace std;

Map::Map(){
	//for the sake of this demonstration, the map will always have three creepers on it
	//which are then targeted and attacked

	creep1 = new Creep(15);
	creep2 = new Creep(25);
	creep3 = new Creep(20);
}

Map::~Map(){
	delete creep1;
	delete creep2;
	delete creep3;
	creep1 = creep2 = creep3 = NULL;
}

int Map::getNumCreepsInRange(const Tower* t){
	//For purposes of this demo, AoE towers(Cannon, Super) get creepers 2 and 3 in range
	//Others get creeper 1
	if (t->getType() == Tower::CANNON || t->getType() == Tower::SUPER){
		int i = (creep2->getHealth() > 0) ? 1 : 0;
		i += (creep3->getHealth() > 0) ? 1 : 0;
		return i;
	}
	else{
		return (creep1->getHealth() > 0) ? 1 : 0;
	}
}

Creep** Map::getCreepsInRange(Tower* t){
	//For purposes of this demo, AoE towers(Cannon, Super) get creepers 2 and 3 in range
	//Others get creeper 1
	

	if (t->getType() == Tower::CANNON || t->getType() == Tower::SUPER){
		Creep** c = new Creep*[2];

		//return the creeps that arent dead
		if (creep2->getHealth() > 0){
			c[0] = creep2;
			if (creep3->getHealth() > 0){
				c[1] = creep3;
			}
		}
		else
			c[0] = creep3;

		return c;
	}
	else{
		//this can only be called if creep1 is alive, so no need to check health
		Creep** c = new Creep*[1]{creep1};
		return c;
	}
}

void Map::resetCreeps(){
	delete creep1;
	delete creep2;
	delete creep3;
	creep1 = creep2 = creep3 = NULL;

	creep1 = new Creep(15);
	creep2 = new Creep(25);
	creep3 = new Creep(20);
}

