#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

class Matrix{
public:
    Matrix (int r): rows(r), columns(r), elements(new double[rows * columns])
    {
        for (int i = 0;i < rows * columns;i++)
            elements[i] = 0;
    }
    int get_rows() {return rows;}
    int get_colums() {return columns;}

    double& operator() (int i, int j)
    {
        assert(0 <= i && i < rows && 0 <= j && j < columns);
        return elements[i * columns + j];
    }
    friend Matrix operator*(double left, Matrix& right);
    friend Matrix operator*(Matrix& left, Matrix& right);

    Matrix(const Matrix& other)
    {
        rows = other.rows;
        columns = other.columns;
        elements = new double[rows * columns];
        for (int i = 0; i < rows * columns;i++) elements[i] = other.elements[i];
    }
private:
    int rows;
    int columns;
    double* elements;
};

Matrix operator*(double left, Matrix& right)
{
    Matrix result(right.get_rows());
    for (int i = 0; i < right.rows; i++)
        for (int j = 0; j < right.columns; j++)
        result(i,j) = right(i,j) * left;
    return result;
}

Matrix operator* (Matrix& left, Matrix& right)
{
    Matrix result(left.get_rows() , right.get_colums() );
    for (int i = 0;i < result.get_rows(); i++)
        for (int j = 0; j < result.get_colums() ; j++)
        for (int k = 0; k < left.get_colums(); k++)
        result(i , j) += left(i,k) * right(k,j);
    return result;
}
ostream& operator<< (ostream& left, Matrix& right)
{
    const int WIDTH = 10;
    for (int i = 0;i < right.get_rows();i++)
    {
        for(int j = 0;j < right.get_colums();j++)
        left << setw(WIDTH) << right(i,j);
        left << "\n";
    }
    return left;
}

using namespace std;

int main()
{
    Matrix A(2);
    Matrix B(2);

    Matrix C = A * B;
    cout << C;

    return 0;
}
