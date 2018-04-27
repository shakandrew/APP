#include "tests/test_basic_multiplication.hpp"

int main() {

    run_tests("results.txt", THREAD_2);
    run_tests("results.txt", THREAD_4);
    run_tests("results.txt", THREAD_8);
/*
    Matrix A(8000000,8);
    Matrix B(8,8);
    Matrix C(8000000,8);

    A.randomizeMatrix(randomFn, 10);
    B.randomizeMatrix(randomFn, 10);
    C.multiply(A, B, 4);

    Matrix A1(8,8000000);
    Matrix B1(8000000,8);
    Matrix C1(8,8);

    A1.randomizeMatrix(randomFn, 10);
    B1.randomizeMatrix(randomFn, 10);
    C1.multiply(A, B, 8);
*/
}
