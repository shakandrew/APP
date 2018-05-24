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

void pll_multiply_processing(void *args) {
    auto data = (PMMP *) args;
    int j_min = data->arg1;
    int j_max = data->arg2;
    int i = data->arg3;
    int k_max = data->A->m;
    LL **A = data->A->table, **B = data->B->table, **C = data->C->table;
    for (int j = j_min; j < j_max; j++) {
        LL rtemp = 0;
        for (int k = 0; k < k_max; k++)
            rtemp += A[i][k] * B[k][j];
        C[i][j] = rtemp;
    }
}

void *pll_multiply_1(void *args) {
    pll_multiply_processing(args);
    // delete data allocated on heap
    delete (PMMP*) args;
    pthread_exit(nullptr);
}

void *pll_multiply_2(void *args) {
    auto data = (PMMP *) args;
    int i_min = data->arg1;
    int i_max = data->arg2;
    // set j_min, j_max
    data->arg1 = 0;
    data->arg2 = data->C->m;
    for (int i = i_min; i < i_max; i++) {
        data->arg3 = i;
        pll_multiply_processing((void *) data);
    }
    pthread_exit(nullptr);
}

void *pll_multiply_3(void *args) {
    auto data = (PMMP *) args;
    pthread_t tid[PTHREAD_MAX];

    for (int i = data->arg1; i < data->arg2; i++) {
        for (int index = 0; index < data->arg3; index++) {

            int j_min = index * (data->arg4 / data->arg3);
            int j_max = (index + 1) * (data->arg4 / data->arg3);
            auto temp = new PMMP(data->A, data->B, data->C, j_min, j_max, i, data->A->m);

            pthread_create(&tid[index], nullptr, pll_multiply_1, (void *) temp);
        }
        for (int index = 0; index < data->arg3; index++)
            pthread_join(tid[index], nullptr);
    }

    delete data;
    pthread_exit(nullptr);
}

void Matrix::multiply(Matrix &A, Matrix &B, std::pair<int, int> mode) {
    pthread_t tid[PTHREAD_MAX];

    if (mode.first != 0) {
        for (int index = 0; index < mode.first; index++) {

            int i_min = index * (n / mode.first);
            int i_max = (index + 1) * (n / mode.first);
            auto args = new PMMP(&A, &B, this, i_min, i_max, mode.second, m);

            if (mode.second == 0)
                pthread_create(&tid[index], nullptr, pll_multiply_2, (void *) args);
            else
                pthread_create(&tid[index], nullptr, pll_multiply_3, (void *) args);
        }
        for (int index = 0; index < mode.first; index++) {
            pthread_join(tid[index], nullptr);
        }
    }

    if (mode.first == 0 && mode.second != 0) {
        for (int i = 0; i < n; i++) {
            for (int index = 0; index < mode.second; index++) {

                int j_min = index * (m / mode.second);
                int j_max = (index + 1) * (m / mode.second);
                auto args = new PMMP(&A, &B, this, j_min, j_max, i, A.m);

                pthread_create(&tid[index], nullptr, pll_multiply_1, (void *) args);
            }
            for (int index = 0; index < mode.second; index++) {
                pthread_join(tid[index], nullptr);
            }
        }
    }

}

void Matrix::print(std::ostream &stream) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            stream << table[i][j] << " ";
        stream << "\n";
    }
}

PMMP::PMMP(Matrix *A, Matrix *B, Matrix *C, int arg1, int arg2, int arg3, int arg4)
        : A(A), B(B), C(C), arg1(arg1), arg2(arg2), arg3(arg3), arg4(arg4) {}