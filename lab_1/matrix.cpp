#include "matrix.h"
#include <iomanip>
#include "climits"


void print_matrix(const Matrix &matrix) {
    int count = 0;
    for (int i = 0; i < matrix.matrix_height; ++i) {
        for (int j = 0; j < matrix.matrix_width; ++j) {
            if (matrix.height[count] == i && matrix.length[count] == j) {
                std::cout << std::right << std::setw(3) << matrix.value[count];
                if (count + 1 != matrix.counter) count++;
            } else {
                std::cout << std::right << std::setw(3) << 0;
            }
        }
        std::cout << std::endl;
    }
}

void print_task(const int *minimals, const Matrix &matrix) {
    int count = 0;
    for (int i = 0; i < matrix.matrix_height; ++i) {
        int current_minimal = minimals[i];
        bool fount_minimal = false;
        for (int j = 0; j < matrix.matrix_width; ++j) {
            if (matrix.height[count] == i && matrix.length[count] == j) {
                if (current_minimal == matrix.value[count]) fount_minimal = true;
                if (fount_minimal) std::cout << std::right << std::setw(3) << matrix.value[count];
                if (count + 1 != matrix.counter) count++;
            } else {
                if (current_minimal == 0) fount_minimal = true;
                if (fount_minimal) std::cout << std::right << std::setw(3) << 0;
            }
        }
        std::cout << std::endl;
    }
}

int * resize(const int *array, int old_size, int new_size) {
    int *expanded_array = new int[new_size];
    for (int i = 0; i < old_size; ++i)
        expanded_array[i] = array[i];
    delete[] array;
    return expanded_array;
}

void add_element(Matrix &matrix, int height, int length, int value) {
    if (matrix.counter >= matrix.current_size) {
        matrix.height = resize(matrix.height, matrix.current_size, matrix.current_size + 10);
        matrix.length = resize(matrix.length, matrix.current_size, matrix.current_size + 10);
        matrix.value = resize(matrix.value, matrix.current_size, matrix.current_size + 10);
        matrix.current_size += 10;
    }
    matrix.height[matrix.counter] = height;
    matrix.length[matrix.counter] = length;
    matrix.value[matrix.counter] = value;
    ++(matrix.counter);
}

Matrix * init_matrix(int * &minimals) {
    auto *matrix = new Matrix;
    matrix->height = new int[0];
    matrix->length = new int[0];
    matrix->value = new int[0];
    matrix->current_size = 0;
    matrix->counter = 0;
    try {
        std::cout << "Type in row count -->";
        matrix->matrix_height = getNum<int>(0, INT_MAX);
        std::cout << "Type in columns count -->";
        matrix->matrix_width = getNum<int>(0, INT_MAX);
    }
    catch (const std::exception &e) {
        remove_matrix(matrix);
        std::cerr << e.what() << std::endl;
        throw;
    }

    minimals = new int[matrix->matrix_height];
    matrix->counter = 0;
    for (int i = 0; i < matrix->matrix_height; ++i) {
        minimals[i] = INT_MAX;
        for (int j = 0; j < matrix->matrix_width; ++j) {
            int x;
            try {
                x = getNum<int>(INT_MIN, INT_MAX);
            } catch (const std::exception &e) {
                remove_matrix(matrix);
                delete[] minimals;
                std::cerr << e.what() << std::endl;
                throw;
            }
            if (minimals[i] > x) minimals[i] = x;
            if (x != 0) add_element(*matrix, i, j, x);
        }
    }
    return matrix;
}

Matrix *perform_task(const int *minimals, const Matrix *matrix) {
    auto *result = new Matrix;
    result->height = new int[0];
    result->length = new int[0];
    result->value = new int[0];
    result->current_size = 0;
    result->counter = 0;
    result->matrix_height = matrix->matrix_height;
    result->matrix_width = matrix->matrix_width;

    for (int i = 0; i < matrix->counter; i++) {
        if (minimals[matrix->height[i]] <= matrix->value[i])
            add_element(*result, matrix->height[i], matrix->length[i], matrix->value[i]);
    }
    return result;
}

void remove_matrix(Matrix *matrix) {
    delete[] matrix->height;
    delete[] matrix->length;
    delete[] matrix->value;
    delete matrix;
}
