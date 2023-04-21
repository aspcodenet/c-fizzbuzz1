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
TEST_F(FizzbuzzTest,WhenTalIsDivisibleBy3and5ThenFizzBuzzShouldBeReturned){
    //ARRANGE
    int tal = 30;
    char buffer[10];
    //ACT
    calculateFizzBuzz(tal, buffer);
    //ASSERT
    ASSERT_STREQ("FizzBuzz", buffer);
}








