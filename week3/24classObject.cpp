#include<iostream>
using namespace std;

class Hero {

   
    //propeties

    private:
    int health;
   
    public:
    char level;

    void print(){
        cout << level<<endl;
    }

    int getHealth(){
        return health;
    }
    char getLevel(){
        return level;
    }

    void setHealth(int h){
        health = h;
    }
    void setLevel(char ch){
        level = ch;
    }


   
   
};

int main() {

    // //creation of object
    // Hero ramesh;


    // cout <<"ramesh health is :"<<ramesh.getHealth()<<endl;

    // ramesh.setHealth(70);
    // ramesh.level = 'A';

    // //cout <<"size : "<<sizeof(h1)<<endl;

    // cout <<"health is : "<<ramesh.getHealth()<<endl;
    // cout <<"level is : "<<ramesh.level<<endl;




    // //static allocation
    // Hero a; 
    // a.setLevel('B');
    // a.setHealth(80);

    // cout <<"level is : "<<a.level<<endl;
    // cout <<"health is : "<<a.getHealth()<<endl;

    // //dynamic allocatiin
    // Hero *b = new Hero;
    // b->setLevel('A');
    // b->setHealth(70); 

    // cout <<"level is : "<<(*b).level<<endl;
    // cout <<"health is : "<<(*b).getHealth()<<endl;

    // cout <<"level is : "<<b->level<<endl;
    // cout <<"health is : "<<b->getHealth()<<endl;



    Hero ramesh;





    return 0;
}