//
// Created by koshachok on 2/27/18.
//

#include <utility>
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
    // In data
    // uno: first - i_step / i; second - j_step
    // dos: first - id of current thread; second - number of threads to create
    auto data = (PMMP *) args;
    if (data->dos.second >= 1) {
        pthread_t tid[PTHREAD_MAX];
        int i_min = data->dos.first * data->uno.first;
        int i_max = (data->dos.first + 1) * data->uno.first;
        for (int i = i_min; i < i_max; i++) {
            for (int t_index = 0; t_index < data->dos.second; t_index++) {
                PMMP temp(*(data->A), *(data->B), *(data->C),
                          std::pair<int, int>(i, data->uno.second),
                          std::pair<int, int>(t_index, 0));
                pthread_create(&tid[t_index], nullptr, parallel_multiply, (void *) &temp);
            }
            for (int j = 0; j < data->dos.second; j++)
                pthread_join(tid[j], nullptr);
        }
    } else {
        int i = data->uno.first;
        int j_min = data->dos.first * data->uno.second;
        int j_max = (data->dos.first + 1) * data->uno.second;
        int k_max = data->A->m;
        LL **A = data->A->table, **B = data->B->table, **C = data->C->table;
        for (int j = j_min; j < j_max; j++) {
            LL rtemp = 0;
            for (int k = 0; k < k_max; k++) {
                //std::cout << "i = " << i << " j = " << j << " k = " << k << std::endl;
                rtemp += A[i][k] * B[k][j];
            }
            C[i][j] = rtemp;
        }
    }

    pthread_exit(nullptr);
}

void Matrix::multiply(Matrix &A, Matrix &B, std::pair<int, int> mode) {
    pthread_t tid[PTHREAD_MAX];
    int thread_num = mode.first * mode.second;
    int i_step = n / mode.first;
    int j_step = m / mode.second;

    for (int i = 0; i < mode.first; i++) {
        PMMP temp(A, B, *this,
                  std::pair<int, int>(i_step, j_step),
                  std::pair<int, int>(i, mode.second));
        pthread_create(&tid[i], nullptr, parallel_multiply, (void *) &temp);
    }

    for (int i = 0; i < thread_num; i++)
        pthread_join(tid[i], nullptr);
}

void Matrix::print(std::ostream &stream) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            stream << table[i][j] << " ";
        stream << "\n";
    }
}

PMMP::PMMP(Matrix &A, Matrix &B, Matrix &C, std::pair<int, int> uno, std::pair<int, int> dos)
        : A(&A), B(&B), C(&C), uno(std::move(uno)), dos(std::move(dos)) {}
