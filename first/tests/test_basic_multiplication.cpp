//
// Created by koshachok on 3/4/18.
//
#include "test_basic_multiplication.hpp"

void run_tests(std::string file_name, int mode){
    std::ofstream stream(file_name);

/*    multiply_test(stream, MATRIX_MAX_SIZE, MATRIX_MIN_SIZE, MATRIX_MIN_SIZE, MATRIX_MIN_SIZE, mode);
    multiply_test(stream, MATRIX_MIN_SIZE, MATRIX_MAX_SIZE, MATRIX_MAX_SIZE, MATRIX_MIN_SIZE, mode);
    multiply_test(stream, MATRIX_MED_SIZE, MATRIX_MED_SIZE, MATRIX_MED_SIZE, MATRIX_MED_SIZE, mode);
*/
    for (int i = 100; i <= 2000; i += 100)
        multiply_test(stream, i, i, i, i, mode);

    stream.close();
}


void multiply_test(std::ostream &stream, int firstRows, int firstColumns, int secondRows, int secondColumns, int mode) {
    Matrix A(firstRows, firstColumns);
    A.randomizeMatrix(randomFn, RANDOM_MAX_MATRIX_VALUE);

    Matrix B(secondRows, secondColumns);
    B.randomizeMatrix(randomFn, RANDOM_MAX_MATRIX_VALUE);

    double answer = 0;

    for (int i = 0; i < TESTS_AMOUNT; i++) {
        Matrix C(firstRows, secondColumns);
        auto start = std::chrono::high_resolution_clock::now();
        if (mode == MODE_BASIC)
            C.multiply_v1(A, B);
        else
            C.multiply_v2(A, B);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        answer += elapsed.count();
    }

    stream << "[" << A.getRows() << ", " << A.getColumns() << "] * "
           << "[" << B.getRows() << ", " << B.getColumns() << "] : "
           << answer / TESTS_AMOUNT << "\n";

}

int randomFn(int maxValue) {
    std::random_device dev;
    std::default_random_engine eng(dev());
    std::uniform_int_distribution<int> dist(-maxValue, maxValue);
    return dist(eng);
}
// 3,96 3,98 4,046 3,96 3,92