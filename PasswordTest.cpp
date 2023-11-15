/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, smoke_test)
{
    ASSERT_TRUE( 1 == 1 );
}
TEST(PasswordTest1, single_letter_password)
{
    Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1,actual);
}
TEST(PasswordTest2, single_letter_password)
{
    Password my_password;
	int actual = my_password.count_leading_characters("ZZzabc");
	ASSERT_EQ(2,actual);
}
TEST(PasswordTest3, single_letter_password)
{
    Password my_password;
	int actual = my_password.count_leading_characters("aaBBcc");
	ASSERT_EQ(2,actual);
}
TEST(PasswordTest4, single_letter_password)
{
    Password my_password;
	int actual = my_password.count_leading_characters("AAzy");
	ASSERT_EQ(2,actual);
}
TEST(PasswordTest5, single_letter_password)
{
    Password my_password;
	int actual = my_password.count_leading_characters("abcDDD");
	ASSERT_EQ(1,actual);
}
TEST(PasswordTest6, single_letter_password)
{
    Password my_password;
	int actual = my_password.count_leading_characters("AABBCCDD");
	ASSERT_EQ(2,actual);
}
TEST(PasswordTest7, single_letter_password)
{
    Password my_password;
	int actual = my_password.count_leading_characters("!!!!!!!!");
	ASSERT_EQ(8,actual);
}



TEST(PasswordTest_1, single_letter_password)
{
    Password my_password;
	int actual = my_password.has_mixed_case("ABCD");
	ASSERT_EQ(false,actual);
}
TEST(PasswordTest_2, single_letter_password)
{
    Password my_password;
	int actual = my_password.has_mixed_case("abcd");
	ASSERT_EQ(false,actual);
}
TEST(PasswordTest_3, single_letter_password)
{
    Password my_password;
	int actual = my_password.has_mixed_case("!!!!");
	ASSERT_EQ(false,actual);
}
TEST(PasswordTest_4, single_letter_password)
{
    Password my_password;
	int actual = my_password.has_mixed_case("__&&");
	ASSERT_EQ(false,actual);
}
TEST(PasswordTest_5, single_letter_password)
{
    Password my_password;
	int actual = my_password.has_mixed_case("!aA!!_");
	ASSERT_EQ(true,actual);
}
TEST(PasswordTest_6, single_letter_password)
{
    Password my_password;
	int actual = my_password.has_mixed_case("______");
	ASSERT_EQ(false,actual);
}