#include "p.h"

void printUsage(const char* program_name) {
    printf("Usage: %s <number_of_persons> <max_starvation_time> <eat_time> <sleep_time> [number_of_rounds]\n", program_name);
    printf("  - number_of_persons: The number of persons (threads)\n");
    printf("  - max_starvation_time: Maximum time (in milliseconds) without eating before considered starving\n");
    printf("  - eat_time: Time (in milliseconds) for each person to eat\n");
    printf("  - sleep_time: Time (in milliseconds) for each person to sleep\n");
    printf("  - number_of_rounds (optional): The number of rounds (meals) each person will eat (default is infinite)\n");
}