#include "password.h"
#include <string.h>
#include <ctype.h>

PASSWORD_ERROR checkPassword(const char *password){
    if(strlen(password) < 8) return PASSWORD_ERROR_TOO_SHORT;

    int uppercaseCount = 0;
    int lowercaseCount = 0;
    int digitCount = 0;
    for(int i = 0; i < strlen(password); i++){
        if(isupper(password[i]))
            uppercaseCount++;
        if(islower(password[i]))
            lowercaseCount++;
        if(isdigit(password[i]))
            digitCount++;
    }
    if(uppercaseCount == 0) return PASSWORD_ERROR_NO_UPPERCASE_LETTER;
    if(lowercaseCount == 0) return PASSWORD_ERROR_NO_LOWERCASE_LETTER;
    if(digitCount == 0) return PASSWORD_ERROR_NO_NUMBER;


    if(!strstr(password,"password")) return PASSWORD_ERROR_CANT_CONTAIN_CERTAIN_WORDS;
    if(!strstr(password,"secret")) return PASSWORD_ERROR_CANT_CONTAIN_CERTAIN_WORDS;
    if(!strstr(password,"summer")) return PASSWORD_ERROR_CANT_CONTAIN_CERTAIN_WORDS;
    if(!strstr(password,"winter")) return PASSWORD_ERROR_CANT_CONTAIN_CERTAIN_WORDS;


    return  PASSWORD_ERROR_OK;
}   