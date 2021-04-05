#include "Complex.h"

Complex::Complex()
	: x(0), y(0)
{}

Complex::Complex(double x, double y)
	: x(x), y(y)
{}

Complex::Complex(const Complex& v)
	: x(v.x), y(v.y)
{}

Complex* Complex::operator = (Pair* r)
{
	this->SetX(GetX());
	this->SetY(GetY());
	return this;
}

Complex* Complex::operator + (Pair* Z)
{
	Complex* T = new Complex();
	T->SetX(this->GetX() + ((Complex*)Z)->GetX());
	T->SetY(this->GetY() + ((Complex*)Z)->GetY());
	return T;
}

Complex* Complex::operator - (Pair* Z)
{
	Complex* T = new Complex();
	T->SetX(this->GetX() - ((Complex*)Z)->GetX());
	T->SetY(this->GetY() - ((Complex*)Z)->GetY());
	return T;
}

Complex* Complex::operator * (Pair* Z)
{
	Complex* T = new Complex();
	T->SetX(this->GetX() * ((Complex*)Z)->GetX() - this->GetY() * ((Complex*)Z)->GetY());
	T->SetY(this->GetX() * ((Complex*)Z)->GetY() + ((Complex*)Z)->GetX() * this->GetY());
	return T;
}

Complex* Complex::operator / (Pair* Z)
{
	Complex* T = new Complex();
	T->SetX((this->GetX() * ((Complex*)Z)->GetX() + this->GetY() * ((Complex*)Z)->GetY()) / (((Complex*)Z)->GetX() * ((Complex*)Z)->GetX() + ((Complex*)Z)->GetY() * ((Complex*)Z)->GetY()));
	T->SetY((((Complex*)Z)->GetX() * this->GetY() - this->GetX() * ((Complex*)Z)->GetY()) / (((Complex*)Z)->GetX() * ((Complex*)Z)->GetX() + ((Complex*)Z)->GetY() * ((Complex*)Z)->GetY()));
	return T;
}

bool Complex::operator == (Pair* Z)
{
	Complex* T = new Complex();
	return T->GetX() == ((Complex*)Z)->GetX() && T->GetY() == ((Complex*)Z)->GetY();
}

Complex& Complex::Conj()
{
	this->SetY(-this->GetY());
	return *this;
}

ostream& Complex::Print(ostream& out) const
{
	out << GetX() << " + i * " << GetY() << endl;
	return out;
}

istream& Complex::Insert(istream& in)
{
	double x, y;
	cout << "x = "; in >> x;
	cout << "y = "; in >> y;
	this->SetX(x); this->SetY(y);
	return in;
}