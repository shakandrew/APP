#include "tests/test_basic_multiplication.hpp"

int main() {
/*    // sequensial
    run_tests("results.txt", std::pair<int, int>(1,1));*
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
/*/
    Matrix A(3, 3);
    Matrix B(3, 3);
    Matrix C(3, 3);

    A.randomizeMatrix(randomFn, 10);
    B.randomizeMatrix(randomFn, 10);
    C.multiply(A, B, std::pair<int, int>(1, 1));

    C.print(std::cout);
}
