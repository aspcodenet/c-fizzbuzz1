#include <gtest/gtest.h>

extern "C" {
#include "password.h"
}

class PasswordTest : public testing::Test {
protected:
	void SetUp() override {
		//game_initialize();	/* Without this the Tests could break*/
	}
};

TEST_F(PasswordTest,WhenLessThanEightCharsShouldReturnError){
    //ARRANGE
    char *password = "abc1234";
    //ACT
    PASSWORD_ERROR error =  checkPassword(password);
    //ASSERT
    ASSERT_EQ(PASSWORD_ERROR_TOO_SHORT, error);
}


TEST_F(PasswordTest,WhenNoUppercaseLetterShouldReturnError){
    //ARRANGE
    char *password = "stefanstefan";
    //ACT
    PASSWORD_ERROR error =  checkPassword(password);
    //ASSERT
    ASSERT_EQ(PASSWORD_ERROR_NO_UPPERCASE_LETTER, error);
}

TEST_F(PasswordTest,WhenNoLowercaseLetterShouldReturnError){
    //ARRANGE
    char *password = "STEFANSTEFAN";
    //ACT
    PASSWORD_ERROR error =  checkPassword(password);
    //ASSERT
    ASSERT_EQ(PASSWORD_ERROR_NO_LOWERCASE_LETTER, error);
}

TEST_F(PasswordTest,WhenNoDigitShouldReturnError){
    //ARRANGE
    char *password = "STEFANstefan";
    //ACT
    PASSWORD_ERROR error =  checkPassword(password);
    //ASSERT
    ASSERT_EQ(PASSWORD_ERROR_NO_NUMBER, error);
}

TEST_F(PasswordTest,WhenNotAllowedWordsShouldReturnError){
    //ARRANGE
    char *password = "STEpasswordFANs123tefan";
    //ACT
    PASSWORD_ERROR error =  checkPassword(password);
    //ASSERT
    ASSERT_EQ(PASSWORD_ERROR_CANT_CONTAIN_CERTAIN_WORDS, error);
}

