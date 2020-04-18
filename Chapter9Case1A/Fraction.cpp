//Implementation section: Fraction.cpp

#include "Fraction.h"
#include<iostream>
#define FIELD 5
using namespace std;

const char Fraction::SLASH = '/';

//constructor
Fraction::Fraction(int w, int n, int d) {
	wNum = w;
	num = n;
	if (d != 0)
		den = d;
	else
		den = 1;	
}
//constructor
Fraction::Fraction(int n, int d) {
	wNum = 0;
	num = n;
	den = d;
	if (d != 0)
		den = d;
	else
		den = 1;	
}
//getters and setters
char Fraction::getSLASH() {
	return SLASH;
}

void Fraction::setWNum(int w) {
	wNum = w;
}
void Fraction::setNum(int n) {
	num = n;
}
void Fraction::setDen(int d) {
	den = d;
}
int Fraction::getWNum() {
	return wNum;
}
int Fraction::getNum() {
	return num;
}
int Fraction::getDen() {
	return den;
}
//overloading operators starts here
Fraction Fraction::operator+(Fraction const& obj)
{
	Fraction f1;
	f1.num = num + obj.num;
	f1.wNum = wNum + obj.wNum;
	f1.den = den;

	return f1;
}

Fraction Fraction::operator-(Fraction const& obj)
{
	
	Fraction f1;
	f1.num = num - obj.num;
	f1.wNum = wNum - obj.wNum;
	f1.den = den;

	return f1;
}

Fraction Fraction::operator*(Fraction const& obj)
{
	Fraction f1;
	f1.num = num * obj.num;
	wNum = 0;
	f1.den = den * obj.den;

	return f1;
}

Fraction Fraction::operator/(Fraction const& obj)
{
	Fraction f1;
	f1.num = num * obj.den;
	wNum = 0;
	f1.den = den * obj.num;

	return f1;
}

int Fraction::operator==(Fraction const& obj)
{
	int truth;
	if (num == obj.num && den == obj.den && wNum == obj.wNum) {
		truth = 1;
	}
	else {
		truth = 0;
	}
	return truth;
}

int Fraction::operator>(Fraction const& obj)
{
	int truth;
	if (num > obj.num && den > obj.den && wNum > obj.wNum) {
		truth = 1;
	}
	else {
		truth = 0;
	}
	return truth;
}

int Fraction::operator<(Fraction const& obj)
{
	int truth;
	if (num < obj.num && den < obj.den && wNum < obj.wNum) {
		truth = 1;
	}
	else {
		truth = 0;
	}
	return truth;
}

ostream& operator<<(ostream& out, Fraction& f)
{
	if (f.getWNum() != 0 && f.getNum() != 0) {
		out << f.getWNum() << " " << f.getNum() << f.getSLASH() << f.getDen() << endl;
	}
	else if (f.getWNum() != 0 && f.getNum() == 0) {
		out << f.getWNum() << endl;
	}
	else if (f.getWNum() == 0 && f.getNum() >= 1) {
		out << f.getNum() << f.getSLASH() << f.getDen() << endl;
	}
	else {
		out << 0;
	}

	return out;
}

istream& operator>>(istream& in, Fraction& f) {

	cout << "Enter the whole number: ";
	in >> f.wNum;
	cout << "Enter the numerator number: ";
	in >> f.num;
	cout << "Enter the denominator number: ";
	cin >> f.den;

	if (f.den == 0)
		f.den = 1;

	return in;
}
//overloading operators ends here

//reducing fraction to the lower number
void Fraction::reduceFraction() {
	for (int j = this->den * this->num; j > 1; j--) {
		if ((this->num % j) == 0 && (this->den % j) == 0) {
			this->num = this->num / j;
			this->den = this->den / j;
		}
	}
	this->wNum += (this->num / this->den);
	this->num = (this->num % this->den);
}

//transform mixed fraction to improper fractions
void Fraction::mixedToImp()
{
	if (getWNum() != 0) {
		setNum(getWNum() * getDen() + getNum());
		setWNum(0);
	}
}
//mathematical operations start here
Fraction sum(Fraction f1, Fraction f2)
{	
	Fraction* ptr1 = { 0 };
	ptr1 = &f1;
	Fraction* ptr2 = { 0 };
	ptr2 = &f2;
	Fraction cAnswer;

	equalFrac(ptr1, ptr2);
	/*cout << "Problem: ";
	cout << f1 << " + " << f2 << " = " << endl;*/
	cAnswer = f1 + f2;
	cAnswer.reduceFraction();
	//if you want to see result of operations take off the coment next line
	//cout << "sum: " << cAnswer << endl;
	return cAnswer;
}

Fraction subt(Fraction f1, Fraction f2) {
	Fraction* ptr1 = { 0 };
	ptr1 = &f1;
	Fraction* ptr2 = { 0 };
	ptr2 = &f2;
	Fraction cAnswer;
	int greater1, greater2;

	equalFrac(ptr1, ptr2);	
	
		cAnswer = f1 - f2;		
	
	cAnswer.reduceFraction();
	//if you want to see result of operations take off the coment next line
	//cout << "Subt: " << cAnswer << endl;

	return cAnswer;
}

Fraction mult(Fraction f1, Fraction f2) {
	f1.mixedToImp();
	f2.mixedToImp();
	Fraction cAnswer;
	
	cAnswer = f1 * f2;
	cAnswer.reduceFraction();

	//if you want to see result of operations take off the coment next line
	//cout << "mult: " << cAnswer << endl;
	return cAnswer;
}

Fraction div(Fraction f1, Fraction f2) {
	f1.mixedToImp();
	f2.mixedToImp();
	Fraction cAnswer;
	
	cAnswer = f1 / f2;
	cAnswer.reduceFraction();

	//if you want to see result of operations take off the coment next line
	//cout << "div: " << cAnswer << endl;
	return cAnswer;
}
//mathematical operations ends here

//to transform fractions to the same denominator
int equalFrac(Fraction* f1, Fraction* f2) {

	int lcmR;
	lcmR = lcm(f1->getDen(), f2->getDen());
	f1->setNum((lcmR / f1->getDen()) * f1->getNum());
	f1->setDen(lcmR);
	f2->setNum((lcmR / f2->getDen()) * f2->getNum());
	f2->setDen(lcmR);	

	return lcmR;
}
//to discover the lower commom denominator
int lcm(int den1, int den2)
{
	int m = 1;

	while (m % den1 || m % den2) m++;

	return m;
}

