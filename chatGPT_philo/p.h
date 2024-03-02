#ifndef P_H 
# define P_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct {
    long long           start_time;
    long long           last_meal_time;
    pthread_mutex_t*    forkMutexes;  // Array of mutexes representing forks
    int                 numPersons;
    int                 maxStarvationTime;  // Maximum time (in milliseconds) without eating before considered starving
    int                 eatTime;    // Time (in milliseconds) to eat
    int                 sleepTime;  // Time (in milliseconds) to sleep
    int                 numRounds;  // Number of rounds (meals)
    int                 isStarving; // Flag to indicate if a person is starving
    pthread_mutex_t     isStarvingMutex; // Mutex for accessing the isStarving flag
    pthread_t*          persons; // Array to store person threads
} ThreadData;

typedef struct {
    ThreadData* data;
    int         id;
} ThreadArg;

void* personLife(void* arg);
void* checkForStarvation(void* arg);
void printUsage(const char* program_name);
void printActionTime(ThreadData* data, int id, const char* action, int current_round);
long long getTime();
#endif