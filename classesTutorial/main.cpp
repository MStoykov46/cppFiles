#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Person{
public:
    virtual void read(ifstream&) = 0;
    virtual string get_info() = 0;
    virtual void write(ofstream&) = 0;
    virtual string get_name() = 0;

protected:
    string name;
    string surname;
};

class Student:public Person{
public:
    virtual void read(ifstream& in) {
        in >> name >> surname >> fnum;
    }
    virtual string get_info(){return name + " " + surname + " " + fnum;}
    virtual void write(ofstream& out) {
    out << name << surname << fnum;
    }
    virtual string get_name() {return name;}
private:
    string fnum;
};

class Teacher:public Person{
public:
    virtual string get_name() {return name;}
    virtual void read(ifstream& in) {
        in >> name >> surname >> course;
    }
    virtual string get_info(){return name + " " + surname + " " + course;}
    virtual void write(ofstream& out) {
    out << name << surname << course;
    }
private:
    string course;

};


int main()
{
    vector<Person*> persons;

    ifstream in_data;
    in_data.open("teachers.txt");
    int n;
    in_data >> n;
    for(int i = 0; i < n;i++){
        Teacher* teacher = new Teacher();
        teacher->read(in_data);
        cout << teacher->get_info() << endl;
        persons.push_back(teacher);
        }
    in_data.close();

    in_data.open("students.txt");
    int m;
    in_data >> m;
    for(unsigned int i = 0;i < m;i++){
        Student* student = new Student();
        student->read(in_data);
        cout << student->get_info() << endl;
        persons.push_back(student);
    }
    in_data.close();

    for (unsigned int i = 0; i < persons.size(); i++){
        Person* person = persons[i];
        cout << persons[i]->get_info() << endl;
    }

    ofstream out_data;
    out_data.open("persons.txt");

    for (unsigned int i = 0; i < persons.size(); i++){
        Person* person = persons[i];
        if(person->get_name()[0] == 'J' )
        person->write(out_data);
    }

    out_data.close();



    return 0;
}
