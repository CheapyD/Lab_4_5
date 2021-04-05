#pragma once
#include "Pair.h"

class Complex : public Pair
{
private:
	double x, y;

public:
	Complex();
	Complex(double x, double y);
	Complex(const Complex& v);

	double GetX() const { return x; }
	double GetY() const { return y; }

	void SetX(double value) { x = value; }
	void SetY(double value) { y = value; }

	virtual Complex* operator = (Pair* r);

	virtual Complex* operator + (Pair* Z);
	virtual Complex* operator - (Pair* Z);
	virtual Complex* operator * (Pair* Z);
	virtual Complex* operator / (Pair* Z);
	virtual bool operator == (Pair* Z);
	Complex& Conj();

	virtual ostream& Print(ostream& out) const;
	virtual istream& Insert(istream& in);
};