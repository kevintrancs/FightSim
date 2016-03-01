#ifndef ANIMAL_H_INCLUDED
#define ANIMAL_H_INCLUDED

class Animal : public Character{
    using Character::attack;
public:
    Animal():Character(){
    }

    void attack(Character* &c){
        int damage = (int) rand()%10+1;
        c->addHealth(-damage);
        cout << "Animal claws cause " << damage << " damage."<< endl;
        damage = (int) rand()%10+1;
        cout << "Animal bite cause " << damage << " damage."<< endl;
        c->addHealth(-damage);
    }

    void printDesc(){
        cout << "4 legs, terror to every one and every thing! AN-NI-MAAAAAAAL!!" << endl;
   }


};

#endif // ANIMAL_H_INCLUDED
