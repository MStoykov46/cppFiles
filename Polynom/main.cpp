#include <iostream>

using namespace std;

template<typename T>
class Polynom{
public:
    Polynom(T* _coefs, int _pow):pow(_pow){
    coefs = new T[n];
    for(int i = 0;i < _pow;i++){
        coefs[i] = _coefs[i]
    }
    }
    T evaluate(T x){
    }
    Polynom derivative(){
    T* coefs_deriv = new T[pow-1];
    for (int i = 0;i < (pow - 1);i++){
        coefs_deriv[i] = (pow-i-1) * coefs[i];
    }
    Polynom polinom_d(coefs_deriv , pow - 1);
    delete[] coefs_deriv;
    return polinom_d;
    }
    friend ostream& operator<<(ostream& out, const Polynom<T>& P){
    out << P.coefs[i] << "*x" << P.pow-i-1 << " + ";
    }
    return out;
    }
private:
    T* coefs;
    int pow;
};

int main()
{
    int p1[] = {1,2,3,4};
    Polynom<int> P(p1,4);
    cout << p << endl;
    Polynom<int> P_d = P.derivative();
    cout << P_d << endl;

    return 0;
}
