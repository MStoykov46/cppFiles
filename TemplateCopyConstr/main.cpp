#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Set {
public:
    Set():elements( nullptr ), size(0) {}
    ~Set(){
    delete[] elements;
    }
    Set& operator=(const Set& other){
    size = other.size;
    elements = new T[size];
    for (int i = 0;i < size;i++) elements[i] = other.elements[i];
    };
    Set(const Set& other){
    size = other.size;
    elements = new T[size];
    for (int i = 0;i < size;i++) elements[i] = other.elements[i];
    }
    void add(T n){
        if(elements == nullptr) elements = new T[1];
        if(contains(n)) return;
        size++;
        T* elements1 = new T[size];
        for(int x = 0 ;x < (size-1);x++) elements1[x] = elements[x];
        elements1[size-1] = n;
        delete[] elements;
        elements = elements1;
        }
    bool contains(T n) const {
    for(int x = 0;x < size;x++)
        if (elements[x] == n) return true;
    return false;
    }
    int get_size() const {
    return size;
    }
private:
    T* elements;
    int size;
};



int main()
{
    Set<float> s;
    s.add(43.);
    s.add(40.5);
    cout << s.get_size() << endl;
    cout << s.contains(43.) << endl;
    cout << s.contains(40.5) << endl;
    Set<string> a;
    a.add("edno");
    cout << a.get_size() << endl;
    cout << a.contains("edno") << endl;

    return 0;
}
