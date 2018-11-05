#include <iostream>
#include <vector>
#include <string>

using namespace std;

int partition(vector<int>& a, int from , int to)
{
    int pivot = a[from];
    int i = from - 1;
    int j = to + 1;
    while(i < j)
    {
        i++; while (a[i] < pivot) i++;
        j--; while (a[j] > pivot) j--;
        if (i < j) swap(a[i], a[j]);
    }
    return j;
}

void sort(vector<int>& a, int from , int to)
{
    if (from >= to) return;
    int p = partition(a, from, to);
    sort(a, from,p);
    sort(a, p+1, to);
}

int main()
{
    vector<int> test(7);
    test[0] = 3;
    test[1] = 7;
    test[2] = 9;
    test[3] = 2;
    test[4] = 4;
    test[5] = 1;
    test[6] = 8;

    sort(test,0,6);
    for(int i = 0;i < test.size();i++)
    {
        cout << test[i];
    }


    return 0;
}
