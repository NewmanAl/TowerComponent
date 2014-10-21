#ifndef TOWER_H
#define TOWER_H


class Map;
class Creep;

class Tower{

public:
	/*
	Ice Tower slows down creeps
	Cannon causes AoE damage
	Regular is boring
	Super is a combination of Cannon and Ice
	*/
	enum TOWER_TYPE{ ICE, CANNON, REGULAR, SUPER };

	Tower(TOWER_TYPE type, int level, int xpos, int ypos, Map* map);
	~Tower();

	//getters
	//----------------------------------------
	int getCost() const;
	int getRefund() const;
	int getRange() const;
	int getDamage() const;
	int getUpgradeLevel() const;
	bool isCoolingDown() const;
	int* getPosition() const;
	TOWER_TYPE getType() const;
	double getCooldownTime() const;
	int getUpgradeCost() const;

	//setters
	//----------------------------------------
	void setUpgradeLevel(int level);

	//other functions
	//----------------------------------------
	void Update(double elapsedTime); //elapsedTime being the time passed since last update


private:
	//members
	//----------------------------------------
	int cost;
	int refund;
	int range;
	int baseDamage;
	int upgradeLevel;
	const TOWER_TYPE type;

	double cooldownTime;
	double cooldownElapsed;
	bool coolingDown;

	const int xpos;
	const int ypos;

	Map* map;

	//functions
	//----------------------------------------

	void shootAvailableCreeps(Map*);

};
#endif