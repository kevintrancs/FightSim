#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include "Character.h"
#include "Hero.h"
#include "Plant.h"
#include "Animal.h"
#include "Hydra.h"

using namespace std;

bool compByHealth(Character *a, Character *b);

int main()
{
    srand(time(NULL));

    bool isRetired = false;
    int week = 1;
    int currentEnemy = -1;
    Character* you = new Hero(500, 0);
    vector<Character *> enemyList;
    Character* ptr;

    for(int i = 0; i < 9; i++){
        int choice = (int) (rand()%2)+1;
        switch(choice){
            case 1: // Animal
                ptr = new Animal();
                break;
            case 2: // plant
                ptr = new Plant();
                break;
            default:
                break;
        }
        enemyList.push_back(ptr);
    }

    ptr = new Hydra();
    enemyList.push_back(ptr);

    sort(enemyList.begin(), enemyList.end(), compByHealth);

    /**
    *Start loop here
    *
    */
    cout << "Welcome to the Alien Fight Simulator!" << endl;

    while(!isRetired){
    int turn = 0;
    bool inputValid = false;
    int choiceNum = 0;

    cout << "----------" << endl;
    cout << "Week " << week << endl;
    cout << "----------" << endl;
    cout << "You currently have: " << you->getWorth() << " space bucks." << endl;
    cout << "You currently have: " << you->getHealth() << " health." << endl;
    cout << "Would you like to: " << endl;
    cout << "1) Fight your next opp." << endl;
    cout << "2) Rest" << endl;
    cout << "3) Retire" << endl;

        while(!inputValid){
            cin >> choiceNum;
            switch(choiceNum){
            case 1:
                inputValid = true;
                currentEnemy++;

                cout << "IN THIS CORNER!! " ; you->printDesc();
                cout << "IN THIS CORNER!!" ; enemyList[currentEnemy]->printDesc();

                while(you->getHealth() > 0 && enemyList[currentEnemy]->getHealth() > 0){
                    if(turn%2 == 0)
                        you->attack(enemyList[currentEnemy]);
                    else
                        enemyList[currentEnemy]->attack(you);
                    turn++;
                }

                if(you->getHealth() > 0)
                    you->addDinero(enemyList[currentEnemy]->getWorth());
                else{
                    cout << "You die. Woops." << endl;
                    isRetired = true;
                }

                break;
            case 2:
                inputValid = true;

                cout << "You feel stronger, but you lose 500 space bucks on expenses." << endl;
                you->addDinero(-500);
                you->addHealth(200);

                if(you->getWorth() < 0){
                    cout << "You have run out of money. You die, cold and alone." << endl;
                    isRetired = true;
                }

                break;
            case 3:
                inputValid = true;
                cout << "You retired in peace... with " << you->getWorth() << " space bucks." << endl;
                isRetired = true;
                break;
            default:
                cout << "That is not a valid choice. Please enter a number between 1 and 3" << endl;
                cin.clear();
                break;
            }
        }
        week++;
    }
    return 0;
}

bool compByHealth(Character *a, Character *b)
{
    return a->getHealth() < b->getHealth();
}
