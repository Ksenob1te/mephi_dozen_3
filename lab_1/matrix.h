#ifndef MEPHI_DOZEN_3_MATRIX_H
#define MEPHI_DOZEN_3_MATRIX_H

#include <iostream>
#include <limits>
#include <cstring>

typedef struct Matrix {
    int *height;
    int *length;
    int *value;
    int current_size;
    int counter;
    int matrix_height, matrix_width;
} Matrix;

template <class T>
T getNum(T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max()) {
    T a;
    while (true) {
        std::cin >> a;
        if (std::cin.eof())
            throw std::runtime_error("Failed to read number: EOF");
        else if (std::cin.bad())
            throw std::runtime_error(std::string("Failed to read number: ") + strerror(errno));
        else if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "You are wrong; repeat please!" << std::endl;
        }
        else if (a >= min && a <= max)
            return a;
    }
}

Matrix * init_matrix(int * &minimals);
Matrix *perform_task(const int *minimals, const Matrix *matrix);
void print_task(const int *minimals, const Matrix *matrix);
void print_matrix(const Matrix *matrix);
void remove_matrix(Matrix *matrix);

#endif //MEPHI_DOZEN_3_MATRIX_H
