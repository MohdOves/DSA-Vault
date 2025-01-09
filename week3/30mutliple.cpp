#include<iostream>
using namespace std;

class Animal{

    public:
    int age;
    int weight;

    public:
    void bark(){
        cout <<"Bark"<<endl;
    }
};

class Human{

    public:
    string color;

    public:
    void speak(){
        cout <<"Speaking"<<endl;
    }
};

class Multiple: public Animal, public Human{

};

int main(){

    Multiple obj1;
    obj1.speak();
    obj1.bark();
    
    return 0;
}