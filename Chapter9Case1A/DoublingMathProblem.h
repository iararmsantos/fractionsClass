//Class to generate another kind of mathematical problem with fractions
#ifndef DOUBLINGMATHPROBLEM_CPP
#define DOUBLINGMATHPROBLEM_CPP
#include "MathProblem.h"
#include "Fraction.h"

class DoublingMathProblem : virtual public MathProblem
{
public: 	
	void setProblem(Fraction *);	
};
#endif // !DOUBLINGMATHPROBLEM_CPP



