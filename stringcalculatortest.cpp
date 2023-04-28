#include <gtest/gtest.h>

extern "C" {
#include "stringcalculator.h"
}

class StringCalculatorTddTest : public testing::Test {
protected:
	void SetUp() override {
		//game_initialize();	/* Without this the Tests could break*/
	}
};

TEST_F(StringCalculatorTddTest,WhenEmptyStringShouldReturn0){
    //ARRANGE
    char *string = "";
    //ACT
    int result = Add(string);
    //ASSERT
    ASSERT_EQ(0, result);
}

TEST_F(StringCalculatorTddTest,WhenNullStringShouldReturn0){
    //ARRANGE
    char *string = NULL;
    //ACT
    int result = Add(string);
    //ASSERT
    ASSERT_EQ(0, result);
}

TEST_F(StringCalculatorTddTest,WhenMultipleNumbersShouldReturnSum){
    //ARRANGE
    char *string = "4,99,10,5,2";
    //ACT
    int result = Add(string);
    //ASSERT
    ASSERT_EQ(120, result);
}


TEST_F(StringCalculatorTddTest,WhenSingleNumberShouldReturnNumber){
    //ARRANGE
    char *string = "162";
    //ACT
    int result = Add(string);
    //ASSERT
    ASSERT_EQ(162, result);
}






