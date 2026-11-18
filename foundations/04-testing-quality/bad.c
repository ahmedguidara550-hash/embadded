#include <stdio.h>
#include <stdlib.h>

int main(void){
    int values[5];
    int uninitialised;
    char *leak = malloc(10);

    for(int i = 0;i <= 5;i++){
        values[i] = i;
    }

    printf("%d\n",uninitialised);
    (void)leak;
    return 0;
}