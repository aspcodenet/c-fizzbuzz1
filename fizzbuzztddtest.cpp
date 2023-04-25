#include <gtest/gtest.h>

extern "C" {
#include "fizzbuzztdd.h"
}

class FizzbuzzTddTest : public testing::Test {
protected:
	void SetUp() override {
		//game_initialize();	/* Without this the Tests could break*/
	}
};

TEST_F(FizzbuzzTddTest,WhenTalIsDivisibleBy3ThenFizzShouldBeReturned){
    //ARRANGE
    int tal = 6;
    char buffer[10];
    //ACT
    calculateFizzBuzzTDD(tal, buffer);
    //ASSERT
    ASSERT_STREQ("Fizz", buffer);
}


TEST_F(FizzbuzzTddTest,WhenTalIsDivisibleBy5ThenBuzzShouldBeReturned){
    //ARRANGE
    int tal = 20;
    char buffer[10];
    //ACT
    calculateFizzBuzzTDD(tal, buffer);
    //ASSERT
    ASSERT_STREQ("Buzz", buffer);
}

TEST_F(FizzbuzzTddTest,WhenTalIsDivisibleBy5And3ThenFizzBuzzShouldBeReturned){
    //ARRANGE
    int tal = 30;
    char buffer[10];
    //ACT
    calculateFizzBuzzTDD(tal, buffer);
    //ASSERT
    ASSERT_STREQ("FizzBuzz", buffer);
}







