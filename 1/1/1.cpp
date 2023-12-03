#include <iostream>

int pochitatUnikumNumbers(int A[], int m) {
    int kolvoUnikum = 0;

    for (int i = 0; i < m; ++i) {
        bool unikum = true;

        for (int j = 0; j < i; ++j) {
            if (A[i] == A[j]) {
                unikum = false;
                break;
            }
        }

        if (unikum) {
            ++kolvoUnikum;
        }
    }

    return kolvoUnikum;
}

void preobrazMasiv(int A[], int m) {
    int dodatniypokazatel = 0;

    for (int i = 0; i < m; ++i) {
        if (A[i] >= 0) {
            std::swap(A[i], A[dodatniypokazatel]);
            ++dodatniypokazatel;
        }
    }
}

int main() {
    setlocale(0, ".1251");
    int m;
    std::cout << "Введіть розмір масиву: ";
    std::cin >> m;

    int* A = new int[m];

    std::cout << "Введіть елементи масиву: ";
    for (int i = 0; i < m; ++i) {
        std::cin >> A[i];
    }

    int kolvoUnikum = pochitatUnikumNumbers(A, m);
    std::cout << "Кількість різних чисел в масиві: " << kolvoUnikum << std::endl;

    preobrazMasiv(A, m);

    std::cout << "Перетворений масив: ";
    for (int i = 0; i < m; ++i) {
            std::cout << A[i] << " ";
        }
    
    std::cout << std::endl;

    delete[] A;

    return 0;
}