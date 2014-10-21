#include <iostream>
#include <ctime>
#include <string>
#include "Tower.h"
#include "Map.h"

using namespace std;

void printTowerStats(Tower* t);
void demonstrateAttack(Tower* t, Map* m);
void changeTower(Tower* &t, Map* m);

int main(){

	//create dummy map
	Map* m = new Map();


	int choice = -1;
	Tower* t;

	//create tower
	cout << "Select the type of tower you'd like\n";
	cout << "-1\tRegular\n" << "-2\tIce\n" << "-3\tCannon\n" << "-4\tSuper\n";
	cout << ": ";
	cin >> choice;

	switch (choice){
	case 1:
		t = new Tower(Tower::TOWER_TYPE::REGULAR, 1, 2, 5, m);
		break;
	case 2:
		t = new Tower(Tower::TOWER_TYPE::ICE, 1, 2, 5, m);
		break;
	case 3:
		t = new Tower(Tower::TOWER_TYPE::CANNON, 1, 2, 5, m);
		break;
	case 4:
		t = new Tower(Tower::TOWER_TYPE::SUPER, 1, 2, 5, m);
		break;
	default:
		cout << "Let's just pretend you entered 1...\n";
		t = new Tower(Tower::TOWER_TYPE::REGULAR, 1, 2, 5, m);
		break;
	}

	choice = -1;
	//main menu
	while (choice != 5){
		cout << "\n========================================================\n";
		cout << "What would you like to do?\n";
		cout << "1-\tDisplay info on tower\n";
		cout << "2-\tUpgrade tower\n";
		cout << "3-\tFight creepers\n";
		cout << "4-\tCreate new tower\n";
		cout << "5-\tExit\n";
		cout << ": ";
		cin >> choice;

		cout << "\n========================================================\n";

		switch (choice){
		case 1:
			printTowerStats(t);
			break;
		case 2:
			cout << "Upgraded one level. This cost: " << t->getUpgradeCost();
			t->setUpgradeLevel(t->getUpgradeLevel() + 1);
			break;
		case 3:
			demonstrateAttack(t, m);
			break;
		case 4:
			changeTower(t,m);
			break;
		case 5:
			//it will break out of the while loop
			break;
		default:
			cout << "Please enter a valid choice.\n";
			break;
		}
	}

	//clean up
	delete t;
	delete m;
	t = NULL;
	m = NULL;

	cin.get();

}

void printTowerStats(Tower* t){
	//display stats on tower
	string s;
	switch (t->getType()){
	case Tower::TOWER_TYPE::REGULAR:
		s = "Regular";
		break;
	case Tower::TOWER_TYPE::ICE:
		s = "Ice";
		break;
	case Tower::TOWER_TYPE::CANNON:
		s = "Cannon";
		break;
	case Tower::TOWER_TYPE::SUPER:
		s = "Super";
		break;
	}

	int* position = t->getPosition();

	cout << "Tower type: " << s << endl;
	cout << "Tower upgrade level: " << t->getUpgradeLevel() << endl;
	cout << "Tower cost: " << t->getCost() << endl;
	cout << "Tower refund: " << t->getRefund() << endl;
	cout << "Tower upgrade cost: " << t->getUpgradeCost() << endl;
	cout << "Tower damage: " << t->getDamage() << endl;
	cout << "Tower range: " << t->getRange() << endl;
	cout << "Tower cooldown: " << t->getCooldownTime() << " seconds" << endl;
	cout << "Tower position: " << position[0] << "," << position[1] << "\n\n";
	cout << "========================================================" << endl;
}

void demonstrateAttack(Tower* t, Map* m){
	
	//variables for handling "gameplay loop"
	double elapsedTime = 0;
	double timePerFrame = 1 / 60; //60 frames per second
	std::clock_t startTime = std::clock();

	//reset creeps on map
	m->resetCreeps();

	cout << "Attacking creeps in range\n";
	cout << "========================================================\n";

	//keep shooting until all creeps are dead
	while (m->getNumCreepsInRange(t) != 0){
		
		//keep adding to elapsed time until it reaches timePerFrame
		if (elapsedTime <= timePerFrame)
			elapsedTime = (std::clock() - startTime) / (double)CLOCKS_PER_SEC;
		else{
			//update logic

			t->Update(elapsedTime);


			//reset clock
			elapsedTime = 0;
			startTime = std::clock();
		}
	}

	cout << "\nAll creeps are dead!\n\n";
}

void changeTower(Tower* &t, Map* m){
	delete t;
	int choice = -1;
	//create tower
	cout << "Select the type of tower you'd like\n";
	cout << "-1\tRegular\n" << "-2\tIce\n" << "-3\tCannon\n" << "-4\tSuper\n";
	cout << ": ";
	cin >> choice;

	switch (choice){
	case 1:
		t = new Tower(Tower::TOWER_TYPE::REGULAR, 1, 2, 5, m);
		break;
	case 2:
		t = new Tower(Tower::TOWER_TYPE::ICE, 1, 2, 5, m);
		break;
	case 3:
		t = new Tower(Tower::TOWER_TYPE::CANNON, 1, 2, 5, m);
		break;
	case 4:
		t = new Tower(Tower::TOWER_TYPE::SUPER, 1, 2, 5, m);
		break;
	default:
		cout << "Let's just pretend you entered 1...\n";
		t = new Tower(Tower::TOWER_TYPE::REGULAR, 1, 2, 5, m);
		break;
	}
	
}