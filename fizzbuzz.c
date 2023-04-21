#include <string.h>
#include <stdio.h>
#include "fizzbuzz.h"


// Enhetstester VARFÖR?
// - ett bra+snabbt sätt att verifiera att koden är korrekt - under utvecklingen
// - i framtiden -> kunna och våga göra ändringar

/**
 * 
 *   VIKTIG LOGIK
 * 
 *     DET BEROR PÅ !!!!
 *    - för många tester -> svårt att göra ändringar 
 *    
 Hur många ska man göra, om vi tar kalkylatorn, ska man ha ett test för addition med
  positiva tal och ett med negativa tal ett med ett positivt och ett negativt osv?
 *     int c  = 5 + 4;                     c = 5 + -4;


    BUGG -> Hitta felet + skriv enhettest som gör att det inte händer igen
*/

// UNIT TEST -> funktion c - klass i C#,C++
// om talet ät jämt delbart med 7 fast inte med 3 och  större än 14 return "Hej"

//Om tal jämt delbart med 3 och 5 -> "fizzbuzz"
//Om tal jämt delbart med 3 -> "fizz"
//Om tal jämt delbart med 5 -> "buzz"
// annars talet som sträng
void calculateFizzBuzz(int tal, char *szOutBuffer){
    if( tal % 5 == 0 && tal % 3 == 0  ) strcpy(szOutBuffer,"FizzBuzz");
    else if(tal % 3 == 0  ) strcpy(szOutBuffer,"Fizz");
    else if(tal % 5 == 0  ) strcpy(szOutBuffer,"Buzz");
    else sprintf(szOutBuffer,"%d", tal);
}