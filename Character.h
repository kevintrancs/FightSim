#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED
#include <iostream>
#include <ctime> // Needed for the true randomization
#include <cstdlib>

using namespace std;

class Character {

protected:

    int health;
    int worth;

public:

    Character(){
        health = (int) (rand()%201) + 1;
        worth = health + ((rand()%501) + 1);
    };

    Character(int life, int value){
        health = life;
        worth = value;
    };

    virtual ~Character(){};

   virtual void attack(Character* &c){
        int damage = (int) rand()%10+1;
        c->addHealth(-damage);

        cout << "You hit it with your fist for " << damage << endl;
   };

   virtual void printDesc(){
        cout << "Some character!" << endl;
   }

   virtual int getHealth(){
        return health;
   }

   virtual int getWorth(){
        return worth;
   }

    virtual void addHealth(int i){
        health += i;
    }

    virtual void addDinero(int i){
        worth += i;
    }

};


#endif // CHARACTER_H_INCLUDED
