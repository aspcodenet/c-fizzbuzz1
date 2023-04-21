#include <stdio.h>
#include "fizzbuzz.h"

int main(){
    while(1){
        int tal;
        scanf(" %d", &tal);
        char result[10];
        calculateFizzBuzz(tal, result);
        printf("%s\n", result);
    }
    return 0;
}