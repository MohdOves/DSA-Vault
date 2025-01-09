#include<iostream>
#include<cstring>
using namespace std;

class Hero {

   
    //propeties

    private:
    int health;
   
    public:
    char *name;
    char level;
    static int timeToComplete;

    Hero(){
        cout <<" default constructor Called "<<endl;
        name = new char[100];
    }


    //parameterised constructor
    Hero(int health) {
        cout << "this ->"<<this <<endl;
        this -> health = health;
    }

    Hero(int health,char level) {
        this -> level = level;
        this -> health = health;
    }


    //copy constructor
    Hero(Hero& temp){

        char *ch = new char[strlen(temp.name) +1];
        strcpy(ch,temp.name);
        this->name = ch;

        cout <<"copy constructor called"<<endl;
        this-> health = temp.health;
        this-> level = temp.level;
    }


    void print(){
        cout <<endl;
        cout <<"[ Name : "<<this->name<<" ,";
        cout << "health : " <<this->health<<",";
        cout <<"level : "<< this->level<<"]";
        cout <<endl;
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


    void setName(char name[]){
        strcpy(this->name,name);
    }

    static int  random(){
        cout <<timeToComplete <<endl;
    }


    ~Hero(){
        cout <<"destructor bhai called "<<endl;
    }



};


int Hero::timeToComplete = 5;


int main() {

    // //object created statically
   
    // Hero ramesh(10);
    // // cout <<"adress of ramesh "<<&ramesh<<endl;
    
    
    // //dynamically
    // Hero *h = new Hero(11);
    // h->print();


    // Hero temp(22,'B');
    // temp.print();




    // Hero S(70,'C');
    // S.print();


    // //copy constructor
    // Hero R(S);
    // R.print();



    // Hero hero1;
    // hero1.setHealth(12);
    // hero1.setLevel('D');
    // char name[7] = "Babbar";
    // hero1.setName(name);

    // // hero1.print();

    // //use deault copy constructor

    // Hero hero2(hero1);
    // // hero2.print();

    // hero1.name[0] = 'G';
    // hero1.print();

    // hero2.print();

    // //copy assignment operator
    // hero1 = hero2;
    // hero1.print();
    // hero2.print();



    //destructor

    //static
    // Hero a;

    // //dynamically
    // Hero *b = new Hero();

    // //manually called
    // delete b;


    //static keyword
    cout <<Hero::timeToComplete<<endl;

    cout <<Hero::random<<endl;

    return 0;
}
