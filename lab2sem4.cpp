#include <iostream>
#include <cstdlib>

class Matrix {
private:
    int **data;
    unsigned int m; // количество строк
    unsigned int n; // количество столбцов

public:
    Matrix(unsigned int rows, unsigned int cols) : m(rows), n(cols) {
        data = new int*[m];
        for (unsigned int i = 0; i < m; ++i) {
            data[i] = new int[n];
        }
    }
    ~Matrix() {
        for (unsigned int i = 0; i < m; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    int* operator[](unsigned int index) {
        return data[index];
    }

    void fillRandom() {
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] = rand() % 10;
            }
        }
    }
    friend std::ostream& operator<<(std::ostream& os, const Matrix& mat) {
        for (unsigned int i = 0; i < mat.m; ++i) {
            for (unsigned int j = 0; j < mat.n; ++j) {
                os << mat.data[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }
    Matrix& operator+=(const Matrix& other) {
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] += other.data[i][j];
            }
        }
        return *this;
    }

    Matrix operator+(const Matrix& other) {
        Matrix result(m, n);
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    bool operator==(const Matrix& other) const {
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                if (data[i][j] != other.data[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool operator!=(const Matrix& other) const {
        return !(*this == other);
    }
};

int main() {
    Matrix mat1(2, 3);
    mat1.fillRandom();
    std::cout << "Matrix 1:" << std::endl << mat1;

    Matrix mat2(2, 3);
    mat2.fillRandom();
    std::cout << "Matrix 2:" << std::endl << mat2;

    Matrix mat3 = mat1 + mat2;
    std::cout << "Matrix 3 (Sum of Matrix 1 and Matrix 2):" << std::endl << mat3;

    if (mat1 == mat2) {
        std::cout << "Matrix 1 is equal to Matrix 2." << std::endl;
    }
    else {
        std::cout << "Matrix 1 is not equal to Matrix 2." << std::endl;
    }

    return 0;
}