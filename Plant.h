#ifndef PLANT_H_INCLUDED
#define PLANT_H_INCLUDED
#include "Character.h"

class Plant : public Character{
    using Character::attack;
public:
    Plant():Character(){

    }

    void attack(Character* &c){
        int damage = (int) rand()%10+1;
        c->addHealth(-damage);

        cout << "Plant branches you for " << damage << " damage."<< endl;
    }

    void printDesc(){
        cout << "Limbs of wood, Leaves of Lashing! King Plant!" << endl;
   }

};

#endif // PLANT_H_INCLUDED
