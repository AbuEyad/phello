#include "p.h"

void* checkForStarvation(void* arg) {
    ThreadData* data = (ThreadData*)arg;

    for (int i = 0; i < data->numPersons; i++) {
        pthread_join(data->persons[i], NULL); // Wait for all person threads to finish
    }

    pthread_mutex_lock(&data->isStarvingMutex);
    // If a person is starving, stop the simulation
    if (data->isStarving) {
        printf("Simulation stopped.\n");
    }
    pthread_mutex_unlock(&data->isStarvingMutex);

    pthread_exit(NULL);
}