#include<iostream>
using namespace std;

class Animal{

    public:
    int age;
    int weight;

    public:
    void speak(){
        cout <<"speaking"<<endl;
    }
};

class Dog: public Animal{


};

class GermanShephed: public Dog{

};

int main(){

    GermanShephed g;
    g.speak();

    return 0;
}