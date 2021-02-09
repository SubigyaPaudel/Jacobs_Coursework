#define _POSIX_C_SOURCE 200809L

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <getopt.h>
#include <string.h>

//shared variables
static int status;
static char coins[20] = "0000000000XXXXXXXXXX";
static int people;
static int flips;
#define number_of_coins 20
static pthread_mutex_t global_lock;
static pthread_mutex_t collection_lock;
static pthread_mutex_t coinlocks[number_of_coins];

void run_threads(int people, void* (*proc)(void*)){
    pthread_t threads[people];
    int failure;
    for(int i = 0; i < people; i++){
        failure = pthread_create(&threads[i], NULL, proc, NULL);
        if(failure){
            perror("Failed to create a thread");
            status = EXIT_FAILURE;
        }
    }
    for(int i = 0; i < people; i++){
        failure = pthread_join(threads[i], NULL);
        if(failure){
            perror("Unable to join a thread");
            status = EXIT_FAILURE;
        }
    }
}

static double timeit(int n, void* (*proc)(void *)){
    clock_t t1, t2;
    t1 = clock();
    run_threads(n, proc);
    t2 = clock();
    return ((double) t2 - (double) t1) / CLOCKS_PER_SEC * 1000;
}

void* one_person_once(void* sth){
    int failure;
    failure = pthread_mutex_lock(&global_lock);
    if(failure){
        perror("Unable to obtain a lock");
        pthread_exit(NULL);
    }
    for(int i = 0; i < flips; i++){
        for(int j = 0; j < number_of_coins; j++){
            if(coins[j] == '0')
                coins[j] = 'X';
            else
                coins[j] = '0';
        }
    }
    failure = pthread_mutex_unlock(&global_lock);
    if(failure){
        perror("Unable to perform an unlock");
        pthread_exit(NULL);
    }
    return NULL;
}

void* one_set_of_flips_once(void* sth){
    int failure;
    for(int i = 0; i < flips; i++){
        failure = pthread_mutex_lock(&collection_lock);
        if(failure){
            perror("Unable to obtain a lock");
            pthread_exit(NULL);
        }
        for(int j = 0; j < number_of_coins; j++){
            if(coins[j] == '0')
                coins[j] = 'X';
            else
                coins[j] = '0';
        }
        failure = pthread_mutex_unlock(&collection_lock);
        if(failure){
            perror("Unable to perform an unlock");
            pthread_exit(NULL);
        }
    }
    return NULL;
}

void* one_coin_once(void* sth){
    int failure;
    for(int i = 0; i < flips; i++){
        for(int j = 0; j < number_of_coins; j++){
            failure = pthread_mutex_lock(&coinlocks[j]);
            if(failure){
                perror("Unable to obtain a lock");
                pthread_exit(NULL);
            }
            if(coins[j] == '0')
                coins[j] = 'X';
            else
                coins[j] = '0';
            failure = pthread_mutex_unlock(&coinlocks[j]);
            if(failure){
                perror("Unable to perform an unlock");
                pthread_exit(NULL);
            }
        }
    }
    return NULL;
}

int main(int argc, char** argv){
    char option;
    flips = 10000;
    people = 100;
    printf("Atleast the program got started\n");
    while((option = getopt(argc, argv, "n:p:")) != -1){
        printf("Inside the while loop\n");
        switch(option){
            case 'n':
                if(atoi(optarg))
                    flips = atoi(optarg);
                break;
            case 'p':
                if(atoi(optarg))
                    people = atoi(optarg);
                break;
        }  
    }
    printf("Arguments taken\n");
    static double timetaken;
    printf("coins: %s (start-global-lock)\n", coins);
    timetaken = timeit(people, one_person_once);
    printf("coins: %s (end-global-lock)\n", coins);
    printf("%d threads X %d flips: %lf ms\n", people, flips, timetaken);
    printf("coins: %s (start-iteration-lock)\n", coins);
    timetaken = timeit(people, one_set_of_flips_once);
    printf("coins: %s (end-iteration-lock)\n", coins);
    printf("%d threads X %d flips: %lf ms\n", people, flips, timetaken);
    printf("coins: %s (start-coin-lock)\n", coins);
    timetaken = timeit(people, one_coin_once);
    printf("coins: %s (end-coin-lock)\n", coins);
    printf("%d threads X %d flips: %lf ms\n", people, flips, timetaken);
}