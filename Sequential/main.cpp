#include "tests/test_basic_multiplication.hpp"

int main() {
    run_tests("without_rtemp.txt", MODE_BASIC);
    run_tests("with_rtemp.txt", MODE_RTEMP);
}

