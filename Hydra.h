#ifndef HYDRA_H_INCLUDED
#define HYDRA_H_INCLUDED

class Hydra : public Character{

public:
    Hydra():Character(){
        health = 10000;
        worth = 10000;
    };

    void attack(Character* &c){
        int damage = 0;

        for(int i = 0; i < 10; i++){
            damage = (int) rand()%10+1;
            c->addHealth(-damage);
            cout << "Head #" << i << " causes " << damage << " damage."<< endl;
        }
    };

    void printDesc(){
        cout << " A beast with no comparison.. Hyd... (*Announcer gets head bitten off)" << endl;
   };
};
#endif // HYDRA_H_INCLUDED
