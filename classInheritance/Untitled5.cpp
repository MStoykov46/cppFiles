#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Person{
public:
    Person(string nm){name = nm;}
    string get_name() const {return name;}
protected:
    string name;
};

class Student:public Person{
public:
    Student(string nm, int fn):Person(nm){
    fnum = fn;
    }
    string get_info() const {
        char buffer[10];
        itoa(fnum, buffer, 9);
    return name + " " + buffer;
    }
private:
    int fnum;
};


int main()
{
    Student ivan("Ivan", 85988);
    cout << ivan.get_info();


    return 0;
}
