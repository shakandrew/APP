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
    int i_min = data->begin.first;
    int i_max = data->end.first;
    int j_min = data->begin.second;
    int j_max = data->end.second;
    int k_lim = data->A->m;
    LL **A = data->A->table, **B = data->B->table, **C = data->C->table;
    //std::cout << n << std::endl;
    for (int i = i_min; i < i_max; i++)
        for (int j = j_min; j < j_max; j++) {
            LL rtemp = 0;
            for (int k = 0; k < k_lim; k++)
                rtemp += A[i][k] * B[k][j];
            C[i][j] = rtemp;
        }
    pthread_exit(NULL);
}

void Matrix::multiply(Matrix &A, Matrix &B, std::pair<int, int> mode) {
    /*if (A.n != n || B.m != m || A.m != B.n)
        return;*/
    pthread_t tid[PTHREAD_MAX];
    int thread_num = mode.first * mode.second;
    for (int i = 0; i < thread_num; i++) {
        int i_min = (i % mode.first) * (n / mode.first);
        int i_max = (i % mode.first + 1) * (n / mode.first);
        int j_min = (i % mode.second) * (m / mode.second);
        int j_max = (i % mode.second + 1) * (m / mode.second);

        if ((i+1) % mode.first == 0) i_max = n;
        if ((i+1) % mode.second == 0) j_max = m;

        PMMP temp(A, B, *this, std::pair<int,int>(i_min, j_min),
                  std::pair<int, int>(i_max, j_max));
        pthread_create(&tid[i], NULL, parallel_multiply, (void *) &temp);
    }
    for (int i = 0;i < thread_num;i++)
        pthread_join(tid[i], NULL);
}

void Matrix::print(std::ostream &stream) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            stream << table[i][j] << " ";
        stream << "\n";
    }
}

PMMP::PMMP(Matrix &A, Matrix &B, Matrix &C, std::pair<int, int> begin, std::pair<int, int> end)
        : A(&A), B(&B), C(&C), begin(begin), end(end) {}
