#include <iostream>
#include <string>

using namespace std;
bool is_palindrome(string s)
{
    if(s.length() <= 1){
             return true;
             }

    char first = s[0];
    char last = s[s.length() -1];
    if(first == last)
    {
        string shorter = s.substr(1,s.length() - 2);
        return is_palindrome(shorter);
    }
    else{
    return false;
    }

}
int main()
{
    string test = "rotor";
    cout << is_palindrome(test) << endl;

    return 0;
}
