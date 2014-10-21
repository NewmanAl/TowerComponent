#ifndef MAP_H
#define MAP_H

class Tower;
class Creep;

class Map{

public:

	Map();
	~Map();

	Creep** getCreepsInRange(Tower*);
	int getNumCreepsInRange(const Tower*);

	void resetCreeps();

private:
	//Ideally, these should be in an array, but for the
	//sake of simplicity and headache avoidance, they wont be.
	//I'm still new to c++, and this assignment is about the Towers
	
	//Pay attention to the Towers ._.
	Creep* creep1;
	Creep* creep2;
	Creep* creep3;


};



#endif