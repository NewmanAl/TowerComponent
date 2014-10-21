#ifndef CREEP_H
#define CREEP_H

class Tower;

class Creep{

public:

	Creep();
	Creep(int health);

	int getHealth();
	void damage(Tower*);

private:
	int health;

};


#endif