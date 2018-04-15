//
// Created by koshachok on 3/4/18.
//

#ifndef FIRST_TEST_BASIC_MULTIPLICATION_H
#define FIRST_TEST_BASIC_MULTIPLICATION_H

#include <iostream>
#include <fstream>
#include <chrono>
#include <random>
#include "../include/Matrix.h"

#define MATRIX_MAX_SIZE 8000000
#define MATRIX_MED_SIZE 800
#define MATRIX_MIN_SIZE 8


#define RANDOM_MAX_MATRIX_VALUE 1000000

#define THREAD_2 2
#define THREAD_4 4
#define THREAD_8 8
#define TESTS_AMOUNT 3

void multiply_test(std::ostream &stream, int firstRows, int firstColumns, int secondRows, int secondColumns, int mode);
void run_tests(std::string file_name, int mode);
int randomFn(int maxValue);

#endif //FIRST_TEST_BASIC_MULTIPLICATION_H
