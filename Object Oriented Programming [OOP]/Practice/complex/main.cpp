#include <iostream>
using namespace std;

class complex {
public:
    int a, b;
    complex();

    friend istream &operator>>(istream &in, complex &m);
    friend ostream &operator<<(ostream &out, const complex &m);
    friend complex operator+(const complex &m1, const complex &m2);
};

complex::complex() : a(0), b(0) {}

istream &operator>>(istream &in, complex &m) {
    in >> m.a >> m.b;
    return in;
}

ostream &operator<<(ostream &out, const complex &m) {
    out << m.a << "+j" << m.b;
    return out;
}

complex operator+(const complex &m1, const complex &m2) {
    complex temp;
    temp.a = m1.a + m2.a;
    temp.b = m1.b + m2.b;
    return temp;
}

template <typename T>
istream &operator>>(istream &in, Matrix<T> &M) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            in >> M.mat[i][j];
        }
    }
    return in;
}

template <typename T>
ostream &operator<<(ostream &out, const Matrix<T> &M) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            out << M.mat[i][j] << "  ";
        }
        out << "\n";
    }
    return out;
}

template <typename T>
Matrix<T> operator+(const Matrix<T> &m1, const Matrix<T> &m2) {
    Matrix<T> temp;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            temp.mat[i][j] = m1.mat[i][j] + m2.mat[i][j];
        }
    }
    return temp;
}


template <typename T>
class Matrix {
    T mat[2][2];

public:
    friend istream &operator>><T>(istream &in, Matrix<T> &M);
    friend ostream &operator<< <T>(ostream &out, const Matrix<T> &M);
    friend Matrix<T> operator+ <T>(const Matrix<T> &m1, const Matrix<T> &m2);
};


int main() {
    Matrix<complex> a, b, c;
    cout << "Enter values for Matrix a (4 values for a 2x2 matrix):" << endl;
    cin >> a;
    cout << "Matrix a:" << endl << a << endl;

    cout << "Enter values for Matrix b (4 values for a 2x2 matrix):" << endl;
    cin >> b;
    cout << "Matrix b:" << endl << b << endl;

    c = a + b;
    cout << "Result:" << endl << c;

    return 0;
}
