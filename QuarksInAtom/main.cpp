#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Baryon
{
public:
    virtual string get_composition(){}

protected:
    string quarks;
};

class Proton : public Baryon
{
public:
    Proton()
    {
        quarks = "uud";
    };
    string get_composition()
    {
        return quarks;
    }
};

class Neutron : public Baryon
{
public:
    Neutron()
    {
        quarks = "udd";
    };
    string get_composition()
    {
        return quarks;
    }
};

int main()
{
    ifstream in_data;
    in_data.open("input.txt");
    vector<Baryon*> baryons;
    int p, n;
    int u = 0;
    int d = 0;
    char x,y;
    char blank;

    in_data >> x >> blank >> p >> y >> blank >> n;

    for (int i = 0; i < p; i++)
    {
        baryons.push_back(new Proton);
    }
    for (int i = 0; i < n; i++)
    {
        baryons.push_back(new Neutron);
    }

    int z = p + n;
    for (int j = 0; j < z; j++)
    {
        string  nucleon = baryons[j]->get_composition();
        if(nucleon ==  "uud")
        {
            u = u + 2;
            d++;
        }
        else
        {
            u++;
            d = d + 2;
        }
    }
    cout << "u = " << u << endl;
    cout << "d = " << d << endl;

    return 0;
}
