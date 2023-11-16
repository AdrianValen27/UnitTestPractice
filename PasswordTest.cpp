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

TEST(PasswordTest, smoke_test) {
    ASSERT_TRUE(1 == 1);
}

/**
 * Test cases for count_leading_characters()
 * Should return the number of repetitions of 
 * the first character in the string, this
 * includes trailing characters.
 */
TEST(PasswordTest, empty_char_phrase) {
    Password my_password;
	int count = my_password.count_leading_characters("");
	ASSERT_EQ(0, count);
}
TEST(PasswordTest, nonempty_char_phrase) {
    Password my_password;
	int count = my_password.count_leading_characters("Zzabc123");
	ASSERT_EQ(0, count);
}
TEST(PasswordTest, single_repitition_phrase) {
    Password my_password;
	int count = my_password.count_leading_characters("aabcAAbc");
	ASSERT_EQ(1, count);
}
TEST(PasswordTest, double_repitition_phrase) {
    Password my_password;
	int count = my_password.count_leading_characters("!!!abcde");
	ASSERT_EQ(2, count);
}
TEST(PasswordTest, triple_repitition_phrase) {
    Password my_password;
	int count = my_password.count_leading_characters("AAAAbbcc");
	ASSERT_EQ(3, count);
}
TEST(PasswordTest, random_symbols_phrase) {
    Password my_password;
	int count = my_password.count_leading_characters("#%@$!*()");
	ASSERT_EQ(0, count);
}
TEST(PasswordTest, excessive_repitition_phrase) {
    Password my_password;
	int count = my_password.count_leading_characters("AAAAAAbbcc");
	ASSERT_EQ(5, count);
}
TEST(PasswordTest, minor_repitition_phrase) {
    Password my_password;
	int count = my_password.count_leading_characters("AABBCC");
	ASSERT_EQ(1, count);
}


/**
 * Test cases for has_mixed_case()
 * Should return true if the phrase has both
 * an uppercase and lowercase character,
 * false otherwise.
 */
TEST(PasswordTest, empty_mixed_case) {
	Password my_password;
	bool result = my_password.has_mixed_case("");
	ASSERT_EQ(false, result);
}
TEST(PasswordTest, single_upper_char_mixed_case) {
	Password my_password;
	bool result = my_password.has_mixed_case("A");
	ASSERT_EQ(false, result);
}
TEST(PasswordTest, single_lower_char_mixed_case) {
	Password my_password;
	bool result = my_password.has_mixed_case("a");
	ASSERT_EQ(false, result);
}
TEST(PasswordTest, double_upper_char_mixed_case) {
	Password my_password;
	bool result = my_password.has_mixed_case("BB");
	ASSERT_EQ(false, result);
}
TEST(PasswordTest, double_lower_char_mixed_case) {
	Password my_password;
	bool result = my_password.has_mixed_case("bb");
	ASSERT_EQ(false, result);
}
TEST(PasswordTest, valid_double_char_mixed_case1) {
	Password my_password;
	bool result = my_password.has_mixed_case("Ab");
	ASSERT_EQ(true, result);
}
TEST(PasswordTest, valid_double_char_mixed_case2) {
	Password my_password;
	bool result = my_password.has_mixed_case("aB");
	ASSERT_EQ(true, result);
}
TEST(PasswordTest, random_char_mixed_case) {
	Password my_password;
	bool result = my_password.has_mixed_case("&!$@%#^)(");
	ASSERT_EQ(false, result);
}
TEST(PasswordTest, no_mixed_repitition_phrase1) {
    Password my_password;
	bool result = my_password.has_mixed_case("AABBCCDD");
	ASSERT_EQ(false, result);
}
TEST(PasswordTest, no_mixed_repitition_phrase2) {
    Password my_password;
	bool result = my_password.has_mixed_case("aabbccdd");
	ASSERT_EQ(false, result);
}


/**
 * Test cases for set()
 * This method returns nothing
 * We must use additional member function
 * authenticate() to validate set()
 */
TEST(PasswordTest, empty_char_set) {
	Password my_password;
	my_password.set("");
	bool result = my_password.authenticate("");
	ASSERT_EQ(false, result);
}
TEST(PasswordTest, invalid_length_char_set) {
	Password my_password;
	my_password.set("ABCD-12");
	bool result = my_password.authenticate("ABCD-12");
	ASSERT_EQ(false, result);
}
TEST(PasswordTest, large_length_char_set) {
	Password my_password;
	my_password.set("abcd-ABCD-1234-5678-_!!_adfafaf");
	bool result = my_password.authenticate("abcd-ABCD-1234-5678-_!!_adfafaf");
	ASSERT_EQ(true, result);
}
TEST(PasswordTest, excessive_leading_char_set) {
	Password my_password;
	my_password.set("AAAAA-bb");
	bool result = my_password.authenticate("AAAAA-bb");
	ASSERT_EQ(false, result);
}
TEST(PasswordTest, single_leading_char_set) {
	Password my_password;
	my_password.set("AAbcd-aabcd");
	bool result = my_password.authenticate("AAbcd-aabcd");
	ASSERT_EQ(true, result);
}
TEST(PasswordTest, no_leading_char_set) {
	Password my_password;
	my_password.set("Abcd-aabcd");
	bool result = my_password.authenticate("Abcd-aabcd");
	ASSERT_EQ(true, result);
}
TEST(PasswordTest, no_mixed_char_set1) {
	Password my_password;
	my_password.set("abcd-abcd");
	bool result = my_password.authenticate("abcd-abcd");
	ASSERT_EQ(false, result);
}
TEST(PasswordTest, no_mixed_char_set2) {
	Password my_password;
	my_password.set("ABCD-ABCD");
	bool result = my_password.authenticate("ABCD-ABCD");
	ASSERT_EQ(false, result);
}
TEST(PasswordTest, valid_char_set) {
	Password my_password;
	my_password.set("ABCD-abcd");
	bool result = my_password.authenticate("ABCD-abcd");
	ASSERT_EQ(true, result);
}
TEST(PasswordTest, duplicate_char_set) {
	Password my_password;
	my_password.set("ChicoCA-95929");
	my_password.set("ChicoCA-95926");
	bool result = my_password.authenticate("ChicoCA-95926");
	ASSERT_EQ(true, result);
}
TEST(PasswordTest, invalid_upper_set_phrase) {
    Password my_password;
	my_password.set("AABBCCDD");
	bool result = my_password.authenticate("AABBCCDD");
	ASSERT_EQ(false, result);
}
TEST(PasswordTest, invalid_lower_set_phrase) {
    Password my_password;
	my_password.set("aabbccdd");
	bool result = my_password.authenticate("aabbccdd");
	ASSERT_EQ(false, result);
}
TEST(PasswordTest, spaces_set_phrase) {
    Password my_password;
	my_password.set("        ");
	bool result = my_password.authenticate("        ");
	ASSERT_EQ(false, result);
}
TEST(PasswordTest, leading_spaces_with_no_mixed_char_set_phrase1) {
    Password my_password;
	my_password.set("     aaa");
	bool result = my_password.authenticate("     aaa");
	ASSERT_EQ(false, result);
}
TEST(PasswordTest, leading_spaces_with_no_mixed_char_set_phrase2) {
    Password my_password;
	my_password.set("     AAA");
	bool result = my_password.authenticate("     AAA");
	ASSERT_EQ(false, result);
}
TEST(PasswordTest, leading_spaces_with_no_mixed_char_set_phrase3) {
    Password my_password;
	my_password.set("     aBc");
	bool result = my_password.authenticate("     aBc");
	ASSERT_EQ(false, result);
}


/**
 * Test cases for authenticate()
 * Returns a bool for authentication
 * If true, then the password matches a 
 * previously used password in history, 
 * false otherwise. 
 */
TEST(PasswordTest, empty_authentication) {
	Password my_password;
	bool result = my_password.authenticate("");
	ASSERT_EQ(false, result);
}
TEST(PasswordTest, valid_authentication) {
	Password my_password;
	bool result = my_password.authenticate("ChicoCA-95929");
	ASSERT_EQ(true, result);
}
TEST(PasswordTest, invalid_authentication) {
	Password my_password;
	bool result = my_password.authenticate("chicoca-95929");
	ASSERT_EQ(false, result);
}