#include <stdio.h>
#include <string.h>
#include "fizzbuzztdd.h"

void calculateFizzBuzzTDD(int tal, char *szOutBuffer){
    if(tal % 3 == 0 && tal % 5 == 0  ) strcpy(szOutBuffer,"FizzBuzz");
    else if(tal % 3 == 0 ) strcpy(szOutBuffer,"Fizz");
    else if(tal % 5 == 0 ) strcpy(szOutBuffer,"Buzz");
    
}