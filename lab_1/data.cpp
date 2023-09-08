#include "data.h"
#include "matrix.h"

void operation() {
    int *minimals;
    Matrix *matrix;
    Matrix *result;
    try {
        matrix = init_matrix(minimals);
        result = perform_task(minimals, matrix);
    }     catch (const std::exception &e) {
        return;
    }

//    for (int i = 0; i < matrix->counter; i++) {
//        std::cout << matrix->height[i] << " " << matrix->length[i] << " " << matrix->value[i] << std::endl;
//    }

    std::cout << "Input matrix:\n";
    print_matrix(*matrix);
    std::cout << "\nResult matrix:\n";
    print_task(minimals, *result);

    delete[] minimals;
    remove_matrix(*matrix);
    delete matrix;
    remove_matrix(*result);
    delete result;
}
