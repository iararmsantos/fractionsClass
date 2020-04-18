//Implementation section
#include "DoublingMathProblem.h"
#include "Fraction.h"
#include<iostream>
using namespace std;

//overload method to generate problems doubling the fractions
void DoublingMathProblem::setProblem(Fraction *f1)
{
	this->setOp('+');	
	cout << "Problem: " << *f1 << " " << this->getOp() << " " << *f1 << " = " << endl;
		
}

