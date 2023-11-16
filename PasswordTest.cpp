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
TEST(PasswordTest, single_letter_password1)
{
    Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(0,actual);
}
TEST(PasswordTest, single_letter_password2)
{
    Password my_password;
	int actual = my_password.count_leading_characters("Zzzabc");
	ASSERT_EQ(0,actual);
}
TEST(PasswordTest, single_letter_password3)
{
    Password my_password;
	int actual = my_password.count_leading_characters("aaBBcc");
	ASSERT_EQ(2,actual);
}
TEST(PasswordTest, single_letter_password4)
{
    Password my_password;
	int actual = my_password.count_leading_characters("AAzy");
	ASSERT_EQ(2,actual);
}
TEST(PasswordTest, single_letter_password5)
{
    Password my_password;
	int actual = my_password.count_leading_characters("abcDDD");
	ASSERT_EQ(0,actual);
}
TEST(PasswordTest, single_letter_password6)
{
    Password my_password;
	int actual = my_password.count_leading_characters("AABBCCDD");
	ASSERT_EQ(2,actual);
}
TEST(PasswordTest, single_letter_password7)
{
    Password my_password;
	int actual = my_password.count_leading_characters("!!!!!!!!");
	ASSERT_EQ(8,actual);
}
TEST(PasswordTest, single_letter_password8)
{
    Password my_password;
	int actual = my_password.count_leading_characters("!!!   ");
	ASSERT_EQ(3,actual);
}
TEST(PasswordTest, single_letter_password9)
{
    Password my_password;
	int actual = my_password.count_leading_characters("abc   ");
	ASSERT_EQ(0,actual);
}
TEST(PasswordTest, single_letter_password10)
{
    Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0,actual);
}
TEST(PasswordTest, single_letter_password11)
{
    Password my_password;
	int actual = my_password.count_leading_characters("AAAAbcd-1234");
	ASSERT_EQ(4,actual);
}
TEST(PasswordTest, single_letter_password12)
{
    Password my_password;
	int actual = my_password.count_leading_characters("aabcd1234567");
	ASSERT_EQ(2,actual);
}



TEST(PasswordTest, mixed_case_1)
{
    Password my_password;
	int actual = my_password.has_mixed_case("ABCD");
	ASSERT_EQ(false,actual);
}
TEST(PasswordTest, mixed_case_2)
{
    Password my_password;
	int actual = my_password.has_mixed_case("abcd");
	ASSERT_EQ(false,actual);
}
TEST(PasswordTest, mixed_case_3)
{
    Password my_password;
	int actual = my_password.has_mixed_case("!!!!");
	ASSERT_EQ(false,actual);
}
TEST(PasswordTest, mixed_case_4)
{
    Password my_password;
	int actual = my_password.has_mixed_case("__&&");
	ASSERT_EQ(false,actual);
}
TEST(PasswordTest, mixed_case_5)
{
    Password my_password;
	int actual = my_password.has_mixed_case("!aA!!_");
	ASSERT_EQ(true,actual);
}
TEST(PasswordTest, mixed_case_6)
{
    Password my_password;
	int actual = my_password.has_mixed_case("______");
	ASSERT_EQ(false,actual);
}
TEST(PasswordTest, mixed_case_7)
{
    Password my_password;
	int actual = my_password.has_mixed_case("");
	ASSERT_EQ(false,actual);
}
TEST(PasswordTest, mixed_case_8)
{
    Password my_password;
	int actual = my_password.has_mixed_case("ABCD1234");
	ASSERT_EQ(false,actual);
}
TEST(PasswordTest, mixed_case_9)
{
    Password my_password;
	int actual = my_password.has_mixed_case("abcd1234");
	ASSERT_EQ(false,actual);
}


TEST(PasswordTest, set_1) {
	Password my_password;
	my_password.set("");
	bool actual = my_password.authenticate("");
	ASSERT_EQ(false,actual);
}
TEST(PasswordTest, set_2) {
	Password my_password;
	my_password.set("Tomato95926!");
	bool actual = my_password.authenticate("Tomato95926!");
	ASSERT_EQ(true,actual);
}
TEST(PasswordTest, set_3) {
	Password my_password;
	my_password.set("hello");
	bool actual = my_password.authenticate("hello");
	ASSERT_EQ(false,actual);
}
TEST(PasswordTest, set_4) {
	Password my_password;
	my_password.set("ChicoCA-95926");
	bool actual = my_password.authenticate("ChicoCA-95926");
	ASSERT_EQ(true,actual);
}
TEST(PasswordTest, set_5) {
	Password my_password;
	my_password.set("chicoca-95926");
	bool actual = my_password.authenticate("chicoca-95926");
	ASSERT_EQ(false,actual);
}


TEST(PasswordTest, authenticate_1) {
	Password my_password;
	bool actual = my_password.authenticate("ChicoCA-95929");
	ASSERT_EQ(true,actual);
}
TEST(PasswordTest, authenticate_2) {
	Password my_password;
	bool actual = my_password.authenticate("chicoca-95929");
	ASSERT_EQ(false,actual);
}
TEST(PasswordTest, authenticate_3) {
	Password my_password;
	bool actual = my_password.authenticate("");
	ASSERT_EQ(false,actual);
}
TEST(PasswordTest, authenticate_4) {
	Password my_password;
	bool actual = my_password.authenticate("CHICOCA-95929");
	ASSERT_EQ(false,actual);
}
TEST(PasswordTest, authenticate_5) {
	Password my_password;
	bool actual = my_password.authenticate("AABBCCDD-12345");
	ASSERT_EQ(false,actual);
}