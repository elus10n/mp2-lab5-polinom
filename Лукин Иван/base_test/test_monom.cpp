#include "gtest.h"
#include "..\polinom\monom.h"

TEST(Monom, can_create_monom)
{
	ASSERT_NO_THROW(Monom test{});
}

TEST(Monom, can_create_from_string)
{
	string tmp = "-x6y2";
	ASSERT_NO_THROW(Monom test(tmp));
}

TEST(Monom, create_from_string_correctly)
{
	string tmp = "8x1y2";
	Monom test(tmp);
	EXPECT_EQ(tmp, test.to_string());
}

TEST(Monom, throws_when_try_to_create_monom_with_negative_degree)
{
	ASSERT_ANY_THROW(Monom test(-1, 1));
}

TEST(Monom, throws_when_try_to_create_monom_with_too_big_degree)
{
	ASSERT_ANY_THROW(Monom test(1000, 1));
}

TEST(Monom, to_string_working_correctly)
{
	Monom test(123, -20);//-20x1y2z3
	EXPECT_EQ("-20x1y2z3", test.to_string());
}

TEST(Monom, can_calculate_in_point)
{
	Monom test(123, 2);

	EXPECT_EQ(test.monom_calculation(4, 3, 2), 576);//4^1 * 3^2 * 2^3 * 2 = 576
}

TEST(Monom, zero_degrees_calculation_give_coefficient_as_result)
{
	double coefficient = 15.16;

	Monom test(0, coefficient);

	EXPECT_EQ(coefficient, test.monom_calculation(100, 100, 100));
}

TEST(Monom, calculation_with_zero_coefficient_give_zero_as_result)
{
	Monom test(999, 0);

	EXPECT_EQ(0, test.monom_calculation(100, 100, 100));
}