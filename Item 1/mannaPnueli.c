#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 2//numero de threads
int soma;
int req = 0;
int resp = 0;

void secao_critica(int n) {//procedimento de acesso a seção critica
    int local = soma;
    sleep(rand()%2);
    soma = local + 1;

    printf("(thread %d) SOMA: %d\n", n, soma);
}

void *client(int *n) {

    printf("client \n");
    while (1 == 1) {

        while (resp != n)
                req = n;

        //secao_critica(n);

        resp = 0;
    }
}

void *server() {
    printf("server \n");
    while (1 == 1) {
        while (req == 0);
        resp = req;

        while (resp != 0);
        req = 0;
    }
}

int main(){

    int i,j;
    pthread_t threads_s[NUM_THREADS],threads_c[NUM_THREADS];

    for(i=0; i<NUM_THREADS; i++){
        pthread_create(&threads_s[i], NULL, &server, NULL);
    }

    for(i=0; i<NUM_THREADS; i++){
        j = i+1;
        pthread_create(&threads_c[i], NULL, &client, j);
    }

    for(i=0; i<NUM_THREADS; i++){
        pthread_join(threads_s[i], NULL);
    }

    for(i=0; i<NUM_THREADS; i++){
        pthread_join(threads_c[i], NULL);
    }

 return 0;
}