//
// Created by koshachok on 2/27/18.
//

#include "../include/Matrix.h"

/*
 * Private methods
 */

void Matrix::initMatrix(int _n, int _m, LL value) {
    n = _n;
    m = _m;
    table = new LL *[n];
    for (int i = 0; i < n; i++) {
        table[i] = new LL[m];
        for (int j = 0; j < m; j++)
            table[i][j] = value;
    }
}

void Matrix::initMatrix(Matrix &obj) {
    n = obj.n;
    m = obj.m;
    table = new LL *[n];
    for (int i = 0; i < n; i++) {
        table[i] = new LL[m];
        for (int j = 0; j < m; j++)
            table[i][j] = obj.table[i][j];
    }
}

void Matrix::deleteMatrix() {
    for (int i = 0; i < n; i++)
        delete[] table[i];
    delete[] table;
}

/*
 * Public methods
 */
Matrix::Matrix() {
    initMatrix(0, 0, 0);
}

Matrix::Matrix(int n, int m) {
    initMatrix(n, m, 0);
}

Matrix::Matrix(int _n, int _m, LL value) {
    initMatrix(_n, _m, value);
}

Matrix::Matrix(Matrix &obj) {
    initMatrix(obj);
}

Matrix::~Matrix() {
    deleteMatrix();
}

void Matrix::randomizeMatrix(std::function<int(int)> fn, int range) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            table[i][j] = fn(range);
}

void Matrix::setElem(int x, int y, long long elem) {
    table[x][y] = elem;
}

LL Matrix::getElem(int x, int y) {
    return table[x][y];
}

int Matrix::getRows() {
    return n;
}

int Matrix::getColumns() {
    return m;
}

void Matrix::multiply_v1(Matrix &A, Matrix &B) {
    /*if (A.n != n || B.m != m || A.m != B.n)
        return;*/
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < A.m; k++)
                table[i][j] = table[i][j] +
                              A.table[i][k] * B.table[k][j];
}

void Matrix::multiply_v2(Matrix &A, Matrix &B) {
    /*if (A.n != n || B.m != m || A.m != B.n)
        return;*/

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            LL rtemp = 0;
            for (int k = 0; k < A.m; k++)
                rtemp += A.table[i][k] * B.table[k][j];
            table[i][j] = rtemp;
        }
}

void Matrix::print(std::ostream &stream) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            stream << table[i][j] << " ";
        stream << "\n";
    }
}
