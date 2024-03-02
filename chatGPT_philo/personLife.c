#include "p.h"

void* personLife(void* arg) {
    ThreadArg* threadArg = (ThreadArg*)arg;
    ThreadData* data = threadArg->data;
    int id = threadArg->id;

    for (int current_round = 0; data->numRounds == 0 || current_round < data->numRounds; current_round++) {
        pthread_mutex_lock(&data->forkMutexes[id]);
        pthread_mutex_lock(&data->forkMutexes[(id + 1) % data->numPersons]);

        printActionTime(data, id, "is eating", current_round);
        data->last_meal_time = getTime();  // Update last meal time

        // Simulate eating time
        usleep(data->eatTime * 1000);

        pthread_mutex_unlock(&data->forkMutexes[id]);
        pthread_mutex_unlock(&data->forkMutexes[(id + 1) % data->numPersons]);

        printActionTime(data, id, "is sleeping", current_round);

        // Simulate sleeping time
        usleep(data->sleepTime * 1000);

        // Check if the person is starving
        long long current_time = getTime();
        long long time_since_last_meal = current_time - data->last_meal_time;

        pthread_mutex_lock(&data->isStarvingMutex);
        if (time_since_last_meal > data->maxStarvationTime && !data->isStarving) {
            // Set the starving flag and exit the thread
            data->isStarving = 1;
        }
        pthread_mutex_unlock(&data->isStarvingMutex);

        // If a person is starving, exit the thread
        if (data->isStarving) {
            break;
        }
    }

    pthread_exit(NULL);
}