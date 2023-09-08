#include "data.h"
#include <iomanip>


void print_matrix(const int *height, const int *length, const int *value, int elements_count,
                  int matrix_height, int matrix_width) {
    int count = 0;
    for (int i = 0; i < matrix_height; ++i) {
        for (int j = 0; j < matrix_width; ++j) {
            if (height[count] == i && length[count] == j) {
                std::cout << std::right << std::setw(3) << value[count];
                if (count + 1 != elements_count) count++;
            } else {
                std::cout << std::right << std::setw(3) << 0;
            }
        }
        std::cout << std::endl;
    }
}

void print_task(const int *minimals, const int *height, const int *length, const int *value, int elements_count,
                int matrix_height, int matrix_width) {
    int count = 0;
    for (int i = 0; i < matrix_height; ++i) {
        int current_minimal = minimals[i];
        bool fount_minimal = false;
        for (int j = 0; j < matrix_width; ++j) {
            if (height[count] == i && length[count] == j) {
                if (current_minimal == value[count]) fount_minimal = true;
                if (fount_minimal) std::cout << std::right << std::setw(3) << value[count];
                if (count + 1 != elements_count) count++;
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

void operation() {
    int *height = new int[0];
    int *length = new int[0];
    int *value = new int[0];
    int current_size = 0;
    int matrix_height = 0, matrix_width = 0;
    try {
        std::cout << "Type in row count -->";
        matrix_height = getNum<int>(0, INT_MAX);
        std::cout << "Type in columns count -->";
        matrix_width = getNum<int>(0, INT_MAX);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        throw;
    }
    int *minimals = new int[matrix_height];

    int counter = 0;
    for (int i = 0; i < matrix_height; ++i) {
        minimals[i] = INT_MAX;
        for (int j = 0; j < matrix_width; ++j) {
            int x;
            try {
                x = getNum<int>(INT_MIN, INT_MAX);
            } catch (const std::exception &e) {
                std::cerr << e.what() << std::endl;
                throw;
            }
            if (minimals[i] > x) minimals[i] = x;
            if (x != 0) {
                if (counter >= current_size) {
                    height = resize(height, current_size, current_size + 10);
                    length = resize(length, current_size, current_size + 10);
                    value = resize(value, current_size, current_size + 10);
                    current_size += 10;
                }
                height[counter] = i;
                length[counter] = j;
                value[counter] = x;
                ++counter;
            }
        }
    }
//    for (int i = 0; i < counter; i++) {
//        std::cout << height[i] << " " << length[i] << " " << value[i] << std::endl;
//    }

    std::cout << "Input matrix:\n";
    print_matrix(height, length, value, current_size, matrix_height, matrix_width);
    std::cout << "\nResult matrix:\n";
    print_task(minimals, height, length, value, current_size, matrix_height, matrix_width);

    delete[] minimals;
    delete[] height;
    delete[] length;
    delete[] value;
}
