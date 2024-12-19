#include "polinom.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(const Monom& left, const Monom& right)
{
	return left.degree < right.degree;
}

void Polinom::add_monom(const Monom& monom)
{
	if (monom.coeff == 0)
		return;
	monoms.push_back(monom);
}

void Polinom::bring_similar()
{
	vector<Monom> tmp;
	while (!monoms.is_empty())
	{
		tmp.push_back(monoms[0]);
		monoms.erase(0);
	}
	sort(tmp.begin(), tmp.end(), compare);
	for (int i = 0; i < tmp.size(); i++)
	{
		if ((i + 1 < tmp.size()) && (tmp[i].degree == tmp[i + 1].degree))
		{
			tmp[i + 1].coeff += tmp[i].coeff;
			tmp[i].coeff = 0;
		}
	}
	for (int i = 0; i < tmp.size(); i++)
		add_monom(tmp[i]);//не позволит добавить мономы с нулевым коэффициентом
}

Polinom::Polinom(const string& str)
{
	if (str.empty())
		throw "incorrect input";
	size_t pos = 0;
	size_t len = str.length();
	while (pos < len)
	{
		size_t startPos = pos;
		if (str[pos] == '-')
			pos++;
		while (pos < len && str[pos] != '+' && str[pos] != '-')
			pos++;
		string monomStr = str.substr(startPos, pos - startPos);
		Monom monom(monomStr);
		if (startPos > 0 && str[startPos - 1] == '-')
			monom.coeff = -monom.coeff;
		add_monom(monom);
		if (pos < len)
			pos++;
	}
	bring_similar();
}

Polinom Polinom::operator+(const Polinom& term) const
{
	Polinom res(*this);
	for (int i = 0; i < term.monoms.get_size(); i++)
		res.add_monom(Monom(term.monoms[i].degree, term.monoms[i].coeff));
	res.bring_similar();
	return res;
}

Polinom Polinom::operator-(const Polinom& term) const
{
	Polinom res(*this);
	for (int i = 0; i < term.monoms.get_size(); i++)
		res.add_monom(Monom(term.monoms[i].degree, -term.monoms[i].coeff));
	res.bring_similar();
	return res;
}

Polinom Polinom::operator*(double constant) const
{
	Polinom res(*this);
	for (int i = 0; i < res.monoms.get_size(); i++)
		res.monoms[i].coeff *= constant;
	res.bring_similar();
	return res;
}

string Polinom::to_String()
{
	if (monoms.is_empty())
		return "0";
	string result;
	for (size_t i = 0; i < monoms.get_size(); i++)
	{
		result += monoms[i].to_string();
		if (i < monoms.get_size() - 1)
		{
			if (monoms[i + 1].coeff >= 0)
				result += "+";
			else
				result += "";
		}
	}
	return result;
}

double Polinom::polinom_calculation(double x, double y, double z)
{
	double res = 0.0;
	for (int i = 0; i < monoms.get_size(); i++)
		res += monoms[i].monom_calculation(x, y, z);
	return res;
}
