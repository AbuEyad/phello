#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

void *roll_dice() {
    int value = (rand() % 6) + 1;
    int *result = malloc(sizeof(int));
    *result = value;
    // printf("dice: %d\n", value);
    printf("result address: %p\n", result);
    return (void *) result;
}

int main(int argc, char *argv[]){
    int *res;
    srand(time(NULL));
    pthread_t th[8];
    for(int i = 0; i < 8; i++){
        if(pthread_create(&th[i], NULL, &roll_dice, NULL) != 0){
            return i;
        }
    }
    for (int i = 0; i < 8; i++){
        if(pthread_join(th[i], (void **) &res) != 0){
            return i;
        }
        printf("result: %d\n", *res);
        printf("res address   : %p\n", res);
        free(res);
    }
    return 0;
}
/*
result address: 0x7fa194504080
res address   : 0x7fa194504080

result address: 0x7fa194604090
res address   : 0x7fa194604090

result address: 0x7fa194704080
res address   : 0x7fa194704080

result address: 0x7fa194704090
res address   : 0x7fa194704090

result address: 0x7fa195204080
res address   : 0x7fa195204080

result address: 0x7fa194604080
res address   : 0x7fa194604080

result address: 0x7fa195104080
res address   : 0x7fa195104080

result address: 0x7fa195004080
res address   : 0x7fa195004080


*/