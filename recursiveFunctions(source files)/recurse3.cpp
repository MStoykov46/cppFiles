#include <iostream>

using namespace std;
//da se izpechati pravougulen triugulnik
void print_triangle(int n,char ch)
{
    for(int i=0;i<n;i++)
    {
        cout << ch;
    }
        cout << endl;
    if(n>1){print_triangle(n-1,ch);}
    /*for(int i=0;i<n;i++)
    {
        cout << ch;
    }
        cout << endl;*/
}
int main()
{
    print_triangle(10,'A');
    return 0;
}
