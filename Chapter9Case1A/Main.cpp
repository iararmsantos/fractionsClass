/*
This program uses classes to calculate fractions using overloading operators, friends and inheritance.
By: Iara Santos
Data: 02/22/2020
*/

#include<iostream>
#include<string>
#include<ctime>
#include "Fraction.h"
#include "MathProblem.h"
#include "DoublingMathProblem.h"

using namespace std;

int main() {
	//*variables
	int const SIZE = 5;
	Fraction f1[SIZE];
	DoublingMathProblem math;
	srand((unsigned)time(NULL));
	Fraction* ptr = f1;
	int i;
	int count = 0;
	
	//to set values to the fractions
	for (i = 0; i < SIZE; i++) {		
		f1[i].setWNum(1 + (rand() % 9));
		f1[i].setNum(1 + (rand() % 9));
		f1[i].setDen(1 + (rand() % 9));		
	}
	//to start verify correctAnswer, to show a new problem to the user, to receive the userAnswer, and count if user match the answer
	for (i = 0; i < SIZE; i++) {
		ptr = &f1[i];
		math.setCorrectAnswer(sum(*f1, *f1));
		math.setProblem(ptr);
		math.askUserAnswer();
		if (math.seekAnswer()) {
			count++;
		}
	}
	
	cout << "***********************************" << endl;
	cout << "*      Fraction Game              *" << endl;
	cout << "*         Results                 *" << endl;
	cout << "***********************************" << endl;
	cout << "   You got " << (count * 100) / SIZE << "% questions right!" << endl; 

	return 0;
}