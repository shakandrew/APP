#include "tests/test_basic_multiplication.hpp"

int main() {
    run_tests("with_rtemp.txt", THREAD_2);
    run_tests("with_rtemp.txt", THREAD_4);
    run_tests("with_rtemp.txt", THREAD_8);
}
