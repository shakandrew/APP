#include "tests/test_basic_multiplication.hpp"

int main() {
    // p1
    run_tests("results.txt", std::pair<int, int>(1,0));
    run_tests("results.txt", std::pair<int, int>(2,0));
    run_tests("results.txt", std::pair<int, int>(4,0));
    run_tests("results.txt", std::pair<int, int>(8,0));
    // p2
    //run_tests("results.txt", std::pair<int, int>(0,2));
    //run_tests("results.txt", std::pair<int, int>(0,4));
    //run_tests("results.txt", std::pair<int, int>(0,8));

    // p1-2
    //run_tests("results.txt", std::pair<int, int>(2,1));
    //run_tests("results.txt", std::pair<int, int>(2,2));
    //run_tests("results.txt", std::pair<int, int>(4,2));
/*
    Matrix A(4, 4);
    Matrix B(4, 4);
    Matrix C(4, 4);

    A.randomizeMatrix(randomFn, 5);
    B.randomizeMatrix(randomFn, 5);
    C.multiply(A, B, std::pair<int, int>(2, 1));

    C.print(std::cout);
    return 0;*/
}
