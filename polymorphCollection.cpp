#include <iostream>
#include <string>
#include <vector>
using namespace std;

class People{
public:
    People(){
        name = n;
        age = a;
        status = s;
    }
    void get_info(){
    cout << "Person with name " << name << " and age " << age << " has a status - " << status << endl;
    }
    string name;
    int age;
    string status;
};

int main(){
    vector<People*> peopleContainer();
    People a;
    People b;
    People c;

    peopleContainer.push_back(a);
    peopleContainer.push_back(b);
    peopleContainer.push_back(c);
    get_info(a);
    get_info(b);
    get_info(c);
return 0;
}
