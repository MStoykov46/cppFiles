#include <iostream>
#include <string>
using namespace std;
class Car {
public:
Car(string hd){make = hd;}
string get_make() const {return make;}
private:
    string make;
};

class Student{
public:
    Student(string nm){
        name = nm;
        pCar = NULL;
        };
    Student(string nm, Car* pC){
    name = nm;
    pCar = pC;
    };
    string get_info() const{
    return name + " " + (( pCar ) ? pCar ->get_make() : "");
}
private:
    string name , fn;
Car* pCar;
};

int main(){

Car car("honda");
Student student("Ivan");
Student petya("Petya", &car);
cout << petya.get_info() << endl;
cout << student.get_info() << endl;

return 0;
}
