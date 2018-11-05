#include <iostream>

using namespace std;
void rec2(int );
void rec1(int a)
{
    /*if(a>0){rec2(a-2);}
    cout << "a=" << a << " ";*/
    cout << "a=" << a << " ";
    if(a>0){rec2(a-2);}
}
void rec2(int b)
{
    /*if(b>0){rec1(b-2);}
    cout << "b=" << b << " ";*/
    cout << "b=" << b << " ";
    if(b>0){rec1(b-2);}
}
int main()
{
    rec1(10);
    return 0;
}
