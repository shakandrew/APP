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

void *parallel_multiply(void *args) {
    auto data = (PMMP *) args;
    LL **A = data->A->table;
    LL **B = data->B->table;
    LL **C = data->C->table;
    int n = data->C->n, m = data->C->m, k_max = data->A->m, tid = data->id;
    int opl = m / data->mode; // operations per loop

    int j_min = opl * tid, j_max = j_min + opl;
    if (tid+1 == data->mode)
        j_max = m;
    //std::cout << n << std::endl;
    for (int i = 0; i < n; i++)
        for (int j = j_min; j < j_max; j++) {
            LL rtemp = 0;
            for (int k = 0; k < k_max; k++)
                rtemp += A[i][k] * B[k][j];
            C[i][j] = rtemp;
        }
    pthread_exit(NULL);
}

void Matrix::multiply(Matrix &A, Matrix &B, int mode) {
    /*if (A.n != n || B.m != m || A.m != B.n)
        return;*/
    pthread_t tid[PTHREAD_MAX];
    for (int i = 0; i < mode; i++) {
        PMMP temp(A, B, *this, i, mode);
        pthread_create(&tid[i], NULL, parallel_multiply, (void *) &temp);
    }
    for (int i=0;i<mode;i++)
        pthread_join(tid[i], NULL);
}

void Matrix::print(std::ostream &stream) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            stream << table[i][j] << " ";
        stream << "\n";
    }
}

PMMP::PMMP(Matrix &A, Matrix &B, Matrix &C, int id, int mode)
        : A(&A), B(&B), C(&C), id(id), mode(mode) {}
