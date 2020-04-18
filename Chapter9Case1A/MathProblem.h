//Class that have attibutes and methods to do mathematical operations with fractions
#ifndef MATHPROBLEM_CPP
#define MATHPROBLEM_CPP
#include "Fraction.h"

class MathProblem
{
private:
	Fraction operand1;
	Fraction operand2;
	Fraction userAnswer;
	Fraction correctAnswer;
	char op;
	bool isAnswerCorrect;
public:
	MathProblem();	
	~MathProblem();
	void setProblem();
	void displayProblem();
	Fraction askUserAnswer();
	bool seekAnswer();
	void setCorrectAnswer(Fraction);
	void createMath();
	char getOp();
	void setOp(char);
};

#endif // !MATHPROBLEM_CPP


