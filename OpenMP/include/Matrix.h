//
// Created by koshachok on 2/27/18.
//

#ifndef FIRST_MATRIX_H
#define FIRST_MATRIX_H

#include <functional>
#include <fstream>
#include <iostream>
#include <exception>
#include <omp.h>

#define LL long long

class Matrix {
private:
    LL **table;
    int n; // rows
    int m; // columns

    void initMatrix(Matrix &obj);

    void initMatrix(int _n, int _m, LL value);

    void deleteMatrix();
public:
    Matrix();

    Matrix(int _n, int _m);

    Matrix(int _n, int _m, LL value);

    Matrix(Matrix &);

    ~Matrix();

    void randomizeMatrix(std::function<int(int)> fn, int range);

    void setElem(int x, int y, long long elem);

    long long getElem(int x, int y);

    int getRows();

    int getColumns();

    void multiply(Matrix &A, Matrix &B, int mode);

    void print(std::ostream &stream);
};

#endif //FIRST_MATRIX_H
