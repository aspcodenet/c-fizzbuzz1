#include "stringcalculator.h"
#include <string.h>
#include <stdlib.h>

int  Add(const char *sz){
    if(sz == NULL) return 0;
    if(strlen(sz) == 0) return 0;

    int result = 0;
    char haystack[256];
    strcpy(haystack,sz);
    char *token = strtok(haystack, ",");
    while(token != NULL){
        result += atoi(token);
        token = strtok(NULL, ",");
    }

    return result;
}
