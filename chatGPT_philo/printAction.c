#include "p.h"

void printActionTime(ThreadData* data, int id, const char* action, int current_round) {
    long long current_time = getTime();

    // Use a mutex to ensure synchronized printing
    pthread_mutex_lock(&data->forkMutexes[id]);
    printf("%lld person %d %s (Round %d)\n", current_time - data->start_time, id, action, (int)(data->numRounds - (double)current_round) + 1);
    pthread_mutex_unlock(&data->forkMutexes[id]);
}