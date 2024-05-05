#include <iostream>

using namespace std;

class Matrix {
    int** values ;
    int row, column ;
public:
    Matrix (const int a, const int b): row(a), column(b) {
        values = new int*[row];
        for (int i = 0; i < row; i++){
            values[i] = new int[column];
        }
    }

    Matrix(const Matrix& another) : row(another.row), column(another.column) {
        values = new int*[row];
        for(int i = 0; i<row; i++){
            values[i] = new int[column];
            for (int j = 0; j < column; j++){
                values[i][j] = another.values[i][j];
            }
        }
    }
    ~Matrix(){
        for(int i =0; i< row; i++){
            delete [] values [i];
        }
        delete [] values;
    }
    friend ostream& operator << (ostream& os, const Matrix& another);
    friend istream& operator >> (istream& is, const Matrix& another);

    Matrix operator + (const Matrix& another){
        for(int i =0; i< another.row; i++){
            for(int j =0; j<another.column; j++){
                values[i][j] += another.values[i][j];
            }
        }
        return *this;
    }
    Matrix& operator = (const Matrix& another){
        if(this == &another) // self-assignment check
            return *this;

        // Deallocate existing memory
        for (int i = 0; i < row; ++i) {
            delete [] values[i];
        }
        delete [] values;

        // Allocate new memory
        row = another.row;
        column = another.column;
        values = new int*[row];

        for(int i = 0; i < row; i++){
            values[i] = new int[column];
            for(int j = 0; j < column; j++){
                values[i][j] = another.values[i][j];
            }
        }
        return *this;
    }

    Matrix operator * (const int num){
        Matrix temp(row, column);
        for(int i =0; i< row; i++){
            for(int j =0; j<column; j++){
                temp.values[i][j]  = values[i][j] * num;
            }
        }
        return temp;
    }
};

ostream& operator << (ostream& os, const Matrix& another){
    for(int i =0; i<another.row;i++){
        for(int j =0; j< another.column; j++){
            os << another.values[i][j] <<"\t";
        }
        os << endl;
    }
    return os;
}

istream& operator >> (istream& is, const Matrix& another){
    for(int i = 0; i< another.row; i++){
        for(int j =0; j< another.column; j++){
            is >> another.values[i][j];
        }
    }
    return is;
}

int main() {
    Matrix m1(2, 2), m2(2, 2) ;
    cin >> m1 ;
    cin >> m2 ;

    Matrix m3(m1 + m2);
    Matrix m4(2, 2);

    m4 = m3 * 10 ;

    cout << m3 << endl << m4 << endl ;
}
