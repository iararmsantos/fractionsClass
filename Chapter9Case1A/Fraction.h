/*First Class: Fraction.h
Fraction attributes and methods to operate with fractions*/

#ifndef FRACTION8_CPP
#define FRACTION8_CPP
#include <iostream>
using namespace std;

class Fraction {
private:
	int wNum;
	int num;
	int den;
	const static char SLASH;
public:
	Fraction(int, int, int);
	Fraction(int = 0, int = 1);
	//Fraction();
	void setWNum(int n);
	void setNum(int n);
	void setDen(int n);
	int getWNum();
	int getNum();
	int getDen();
	static char getSLASH();
	void reduceFraction();
	Fraction operator+(Fraction const& obj);
	Fraction operator-(Fraction const& obj);
	Fraction operator*(Fraction const& obj);
	Fraction operator/(Fraction const& obj);
	int operator==(Fraction const& obj);
	int operator>(Fraction const& obj);
	int operator<(Fraction const& obj);
	void mixedToImp();
	friend ostream& operator<<(ostream& out, Fraction& f);
	friend istream& operator>>(istream& in, Fraction& f);	
};
#endif // !FRACTION8_CPP

int lcm(int a, int b);
int equalFrac(Fraction* f1, Fraction* f2);
Fraction sum(Fraction f1, Fraction f2);
Fraction subt(Fraction f1, Fraction f2);
Fraction mult(Fraction f1, Fraction f2);
Fraction div(Fraction f1, Fraction f2);