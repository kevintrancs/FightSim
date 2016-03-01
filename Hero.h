#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED
#include "Character.h"
class Hero : public Character{

public:

    Hero(int life, int value):Character(life, value){

    }

   virtual void printDesc(){
        cout << "Some guy off the street... I guess" << endl;
    }

};


#endif // HERO_H_INCLUDED
