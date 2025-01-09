#include<iostream>
using namespace std;

// class A{

//     public:
//     void sayHello(){
//         cout <<"Hello Love Babbar"<<endl;
//     }

//     void sayHello(string name){
//         cout <<"Hello"<<name<<endl;
//     }
// };


// int main() {

    
//     A obj;
//     obj.sayHello();


//       return 0;
// }


class A{

    public:
    void sayHello(string name,int x){
        cout <<"Hello Love Babbar"<<endl;
    }

    int sayHello(string name){
        cout <<"Hello"<<name<<endl;
        return 1;
    }

    
};


int main() {

    string babbar = "babbar";
    A obj;
    obj.sayHello(babbar);


    return 0;
}