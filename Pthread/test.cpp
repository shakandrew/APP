#include <pthread.h>
#include <iostream>
using namespace std;

void * tp(void * some) {
    cout << "Inside " << (long) some <<endl;
    pthread_exit(NULL);
}

void * tmp(void * some) {
    pthread_t tid[2];
    for (long i=0;i<2;i++)
        pthread_create(&tid[i], NULL, tp, some);

    cout << (long) some << endl;

    for (int i=0;i<2;i++)
        pthread_join(tid[i], NULL);
    pthread_exit(NULL);
}

int main() {
    pthread_t tid[4];
    for (long i=0;i<4;i++){
        pthread_create(&tid[i], NULL, tmp, (void *) i);
        cout << "This is thread " << i <<endl;
    }
    for (int i=0;i<8;i++)
        pthread_join(tid[i], NULL);
    cout << "One thread left" << endl;

    pthread_exit(NULL);
}
