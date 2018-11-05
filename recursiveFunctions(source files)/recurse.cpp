#include <iostream>

using namespace std;

double fib(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    return fib(n-2) + fib(n-1);
}
int main()
{
    cout << fib(8) << endl;
    return 0;
}
