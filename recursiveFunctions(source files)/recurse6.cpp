#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Time{
public:
    int hour;
    Time(int h){hour = h;}
    Time(){hour = 0;}
    void Print() {cout << hour << ":";}
    friend bool operator<(const Time& t1,const Time& t2){
    return (t1.hour < t2.hour);
    }
};

int main()
{
    vector<Time> vec;
    vec.push_back(Time(1));
    vec.push_back(Time(5));
    vec.push_back(Time(7));
    vec.push_back(Time(4));
    sort(vec.begin(),vec.end());

    for(int i = 0;i < vec.size(); i++)
    {
        vec[i].Print();
    }

    return 0;
}
