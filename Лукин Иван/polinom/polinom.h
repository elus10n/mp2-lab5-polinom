#ifndef __POLINOM_H__
#define __POLINOM_H__

#include <string>
#include "list.h"
#include "monom.h"

class Polinom
{
	List<Monom> monoms;
	void add_monom(const Monom& monom);
	void bring_similar();
public:
	Polinom() = default;
	Polinom(const string& str);
	Polinom(const Polinom& to_copy) = default;

	bool is_empty() { return monoms.is_empty();}
	double polinom_calculation(double x, double y, double z);
	string to_String();

	Polinom operator+(const Polinom& term) const;
	Polinom operator-(const Polinom& term) const;
	Polinom operator*(double constant) const;
};

#endif
