#include <gtest/gtest.h>

extern "C" {
#include "fizzbuzz.h"
}

class FizzbuzzTest : public testing::Test {
protected:
	void SetUp() override {
		//game_initialize();	/* Without this the Tests could break*/
	}
};

// Funktionen behöver inte ha en return för att vara testbar?
// TIPS: Dela upp er kod! Testbar funktion -> bara beräkningar, inga scanf/printf
TEST_F(FizzbuzzTest,WhenTalIsDivisibleBy3and5ThenFizzBuzzShouldBeReturned){
    //ARRANGE
    int tal = 30;
    char buffer[10];
    //ACT
    calculateFizzBuzz(tal, buffer);
    //ASSERT
    ASSERT_STREQ("FizzBuzz", buffer);
}

//Om tal jämt delbart med 3 och 5 -> "fizzbuzz"
//Om tal jämt delbart med 3 -> "fizz"
TEST_F(FizzbuzzTest,WhenTalIsDivisibleBy3ThenFizzShouldBeReturned){
    //ARRANGE
    int tal = 6;
    char buffer[10];
    //ACT
    calculateFizzBuzz(tal, buffer);
    //ASSERT
    ASSERT_STREQ("Fizz", buffer);
}

//Om tal jämt delbart med 5 -> "buzz"
TEST_F(FizzbuzzTest,WhenTalIsDivisibleBy10ThenBuzzShouldBeReturned){
    //ARRANGE
    int tal = 10;
    char buffer[10];
    //ACT
    calculateFizzBuzz(tal, buffer);
    //ASSERT
    ASSERT_STREQ("Buzz", buffer);
}


// annars talet som sträng
TEST_F(FizzbuzzTest,WhenTalIsNotDivisableBy3or5ThenNumberShouldBeReturned){
    //ARRANGE
    int tal = 8;
    char buffer[10];
    //ACT
    calculateFizzBuzz(tal, buffer);
    //ASSERT
    ASSERT_STREQ("8", buffer);
}









