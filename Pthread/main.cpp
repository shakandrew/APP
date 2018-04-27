#include "tests/test_basic_multiplication.hpp"

int main() {
    // sequensial
    run_tests("results.txt", std::pair<int, int>(1,1));
    // p1
    run_tests("results.txt", std::pair<int, int>(2,1));
    run_tests("results.txt", std::pair<int, int>(4,1));
    run_tests("results.txt", std::pair<int, int>(8,1));
    // p2
    run_tests("results.txt", std::pair<int, int>(1,2));
    run_tests("results.txt", std::pair<int, int>(1,4));
    run_tests("results.txt", std::pair<int, int>(1,8));
    // p1-2
    run_tests("results.txt", std::pair<int, int>(2,1));
    run_tests("results.txt", std::pair<int, int>(2,2));
    run_tests("results.txt", std::pair<int, int>(4,2));
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
