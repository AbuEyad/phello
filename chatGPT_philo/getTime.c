#include "p.h"

long long getTime() {
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    return current_time.tv_sec * 1000LL + current_time.tv_usec / 1000LL;
}