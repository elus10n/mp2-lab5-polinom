#ifndef __MONOM_H__
#define __MONOM_H__

#include <cmath>
#include <sstream>
#include <iostream>

using namespace std;

class Monom
{
public:
	int degree;
	double coeff;
public:
	Monom(int degr = 0, double cfnt = 0): degree(degr), coeff(cfnt)
	{
		if (degr < 0 || degr > 999)
			throw "Incorrect monom degree!";
	}

	Monom(const Monom& to_copy) = default;

	Monom(const string& str)
	{
		int xDeg = 0, yDeg = 0, zDeg = 0;
		istringstream iss(str);
		bool is_negative = false;
		if (!iss.eof() && iss.peek() == '-')
		{
			is_negative = true;
			iss.ignore();
		}
		if (!(iss >> coeff))
		{
			coeff = 1.0;
			iss.clear();
		}
		if (is_negative)
		{
			coeff *= -1.0;
		}
		char var;
		int pwr;
		while (iss >> var)
		{
			if (var == 'x' || var == 'y' || var == 'z')
			{
					if (iss >> pwr && pwr >= 0)
					{
					switch (var) {
					case 'x':
						xDeg = pwr;
						break;
					case 'y':
						yDeg = pwr;
						break;
					case 'z':
						zDeg = pwr;
						break;
					}
				}
				else
				{
					switch (var)
					{
					case 'x':
						xDeg = 1;
						break;
					case 'y':
						yDeg = 1;
						break;
					case 'z':
						zDeg = 1;
						break;
					}
				}
			}
			else
				throw "incorrect input";
		}
		if (xDeg > 9 || yDeg > 9 || zDeg > 9)
			throw "incorrect input";
		degree = xDeg * 100 + yDeg * 10 + zDeg;
	}

	double monom_calculation(double x, double y, double z)
	{
		double res = coeff;
		int var_degrees[3]{};//|x|y|z|
		var_degrees[0] = degree / 100;
		var_degrees[1] = (degree / 10) % 10;
		var_degrees[2] = degree % 10;
		for (int i = 0; i < 3; i++)
		{
			res *= pow((i == 0 ? x : (i == 1 ? y : z)), var_degrees[i]);
		}
		return res;
	}

	string to_string()
	{
		ostringstream oss;
		if (coeff < 0)
			oss << "-";
		if (abs(coeff) != 1)
			oss << abs(coeff);
		int xDeg = degree / 100;
		int yDeg = (degree / 10) % 10;
		int zDeg = degree % 10; 
		if (xDeg > 0) oss << "x" << xDeg;
		if (yDeg > 0) oss << "y" << yDeg;
		if (zDeg > 0) oss << "z" << zDeg;
		return oss.str();
	}

	bool operator==(const Monom& compare) const
	{
		return(degree == compare.degree && coeff == compare.coeff);
	}

	bool operator!=(const Monom& compare) const
	{
		return!(operator==(compare));
	}
};

#endif
