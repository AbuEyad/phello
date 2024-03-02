
#include "p.h"

int main(int argc, char *argv[]) {
    if (argc < 5 || argc > 6) {
        fprintf(stderr, "Error: Invalid number of arguments.\n");
        printUsage(argv[0]);
        return 1;
    }

    int numPersons = atoi(argv[1]);
    int maxStarvationTime = atoi(argv[2]);
    int eatTime = atoi(argv[3]);
    int sleepTime = atoi(argv[4]);
    int numRounds = (argc == 6) ? atoi(argv[5]) : 0; // Number of rounds is optional

    if (numPersons <= 0 || maxStarvationTime <= 0 || eatTime <= 0 || sleepTime <= 0 || (numRounds < 0 && numRounds != 0)) {
        fprintf(stderr, "Error: Invalid input. Please provide positive integers for parameters.\n");
        printUsage(argv[0]);
        return 1;
    }

    pthread_mutex_t* forkMutexes = malloc(numPersons * sizeof(pthread_mutex_t));
    ThreadData* data = malloc(numPersons * sizeof(ThreadData));
    ThreadArg* threadArgs = malloc(numPersons * sizeof(ThreadArg));

    for (int i = 0; i < numPersons; i++) {
        pthread_mutex_init(&forkMutexes[i], NULL);  // Initialize mutex at runtime
        data[i].start_time = getTime();
        data[i].last_meal_time = data[i].start_time;  // Initialize last meal time
        data[i].forkMutexes = forkMutexes;
        data[i].numPersons = numPersons;
        data[i].maxStarvationTime = maxStarvationTime;
        data[i].eatTime = eatTime;
        data[i].sleepTime = sleepTime;
        data[i].numRounds = numRounds;
        data[i].isStarving = 0; // Initialize the flag
        pthread_mutex_init(&data[i].isStarvingMutex, NULL);
        data[i].persons = malloc(numPersons * sizeof(pthread_t)); // Allocate memory for person threads
    }

    for (int i = 0; i < numPersons; i++) {
        threadArgs[i].data = &data[i];
        threadArgs[i].id = i;
    }

    // Create threads for persons
    for (int i = 0; i < numPersons; i++) {
        if (pthread_create(&data[i].persons[i], NULL, personLife, &threadArgs[i]) != 0) {
            fprintf(stderr, "Error creating thread for Person %d\n", i);
            return 2;
        }
    }

    // Create thread for checking starvation
    pthread_t starvationThread;
    if (pthread_create(&starvationThread, NULL, checkForStarvation, data) != 0) {
        fprintf(stderr, "Error creating thread for checking starvation\n");
        return 2;
    }

    // Join thread for checking starvation
    if (pthread_join(starvationThread, NULL) != 0) {
        fprintf(stderr, "Error joining thread for checking starvation\n");
        return 3;
    }

    printf("All persons have finished their lives.\n");

    // Destroy mutexes
    for (int i = 0; i < numPersons; i++) {
        pthread_mutex_destroy(&forkMutexes[i]);
        pthread_mutex_destroy(&data[i].isStarvingMutex);
        free(data[i].persons); // Free memory for person threads
    }

    free(forkMutexes);
    free(data);
    free(threadArgs);

    return 0;
}
