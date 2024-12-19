#include "gtest.h"
#include "..\\polinom\polinom.h"

TEST(Polinom, can_create_polinom)
{
	ASSERT_NO_THROW(Polinom test{});
}

TEST(Polinom, can_convert_polynomial_from_string)
{
	string tmp = "-20x6y7+z7-20y6z8";
	ASSERT_NO_THROW(Polinom test(tmp));
}

TEST(Polinom, can_convert_if_polinom_has_one_monom_correctly)
{
	string monom = "6x1z2";

	ASSERT_NO_THROW(Polinom test(monom));

	Polinom test(monom);

	EXPECT_EQ(monom, test.to_String());
}

TEST(Polinom, throws_when_try_convert_from_empty_string)
{
	ASSERT_ANY_THROW(Polinom test(""));
}

TEST(Polinom, can_convert_from_string_correctly)
{
	string tmp = "10z5-y9+8x1y2";
	Polinom test(tmp);
	EXPECT_EQ(tmp, test.to_String());
}

TEST(Polinom, when_convert_from_string_brings_similar)
{
	string tmp = "x1y1z1+x1y1z1+x1y1z1+x1y1z1+x1y1z1";
	string expected = "5x1y1z1";

	Polinom test(tmp);

	EXPECT_EQ(expected, test.to_String());
}

TEST(Polinom, addition_working_correctly_and_brings_similar)
{
	Polinom term1("x1y1z1+2x1y1z2-5z4");
	Polinom term2("3x1y1z1+2x2y1z1+6z4");
	Polinom result("4x1y1z1+2x1y1z2+2x2y1z1+z4");

	Polinom result_test = term1 + term2;

	EXPECT_EQ(result.to_String(), result_test.to_String());
}

TEST(Polinom, subtraction_working_correctly_and_brings_similar)
{
	Polinom term1("x1y1z1+2x1y1z2-5z4");
	Polinom term2("3x1y1z1+2x2y1z1+6z4");
	Polinom result("-2x1y1z1+2x1y1z2-2x2y1z1-11z4");

	Polinom result_test = term1 - term2;

	EXPECT_EQ(result.to_String(), result_test.to_String());
}

TEST(Polinom, multiply_on_constant_working_correctly)
{
	Polinom test("10x1y2-x1");
	Polinom res("20x1y2-2x1");

	Polinom res_test = test * 2;

	EXPECT_EQ(res.to_String(), res_test.to_String());
}

TEST(Polinom, multiply_on_zero_give_zero)
{
	Polinom test("10x1y2-x1");

	Polinom res = test * 0;

	EXPECT_EQ(res.to_String(), "0");
}

TEST(Polinom, can_calculate_in_point)
{
	Polinom test("x2y1-4z3+10x2");

	EXPECT_EQ(test.polinom_calculation(2, 6, 1), 60);//2^2*6^1 - 4*1^3 + 10*2^2 = 24 - 4 + 40 = 60
}