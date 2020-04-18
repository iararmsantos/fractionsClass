//Implementation section: MathProblem.cpp

#include "MathProblem.h"
#include "Fraction.h"
#include<iostream>
#include<ctime>
using namespace std;

//implementation section

//constructor
MathProblem::MathProblem() : operand1(0, 0, 0), operand2(0, 0, 0), userAnswer(0, 0, 0), correctAnswer(0, 0, 0)
{
	this->op = '+';
	this->isAnswerCorrect = true;	
}
//destructor
MathProblem::~MathProblem()
{
}
//getter and setter
char MathProblem::getOp()
{
	return this->op;
}

void MathProblem::setOp(char op)
{
	this->op = op;
}

//to construct mathematical problems
void MathProblem::setProblem()
{
	userAnswer = 0;
	isAnswerCorrect = false;

	if (op == '+') {
		setCorrectAnswer(sum(this->operand1, this->operand2));
	}

	else if (op == '-') {
		setCorrectAnswer(subt(this->operand1, this->operand2));
	}

	else if (op == '*') {
		setCorrectAnswer(mult(this->operand1, this->operand2));
	}

	else if (op == '/') {
		setCorrectAnswer(div(this->operand1, this->operand2));
	}	
}

//to show a problem
void MathProblem::displayProblem() {
	if (operand1 > operand2) {
		cout << operand1 << " " << op << " " << operand2 << " = " << endl;
	}
	else {
		cout << operand2 << " " << op << " " << operand1 << " = " << endl;
	}	
}

//to user enter possible answers
Fraction MathProblem::askUserAnswer()
{
	int uWhole, uDen, uNum;
	cout << "Enter the answer whole number: ";
	cin >> uWhole;
	userAnswer.setWNum(uWhole);
	cout << "Enter the answer nummerator: ";
	cin >> uNum;
	userAnswer.setNum(uNum);
	cout << "Enter the answer denominator: ";
	cin >> uDen;
	userAnswer.setDen(uDen);

	userAnswer.reduceFraction();

	return userAnswer;
}
//to verify if answer is correct
bool MathProblem::seekAnswer()
{
	double cAnswer = 0;
	double uAnswer = 0;

	//temporary variables
	correctAnswer.mixedToImp();
	userAnswer.mixedToImp();

	cAnswer = (double)correctAnswer.getNum() / correctAnswer.getDen();
	uAnswer = (double)userAnswer.getNum() / userAnswer.getDen();
	cout << endl;
	if (cAnswer == uAnswer) {
		cout << "Congratulations!" << endl;
		isAnswerCorrect = true;
	}
	else {
		cout << "Try again!" << endl;
		isAnswerCorrect = false;
	}
	cout << endl;

	cout << "User Answer: ";
	cout << userAnswer << endl;	
	cout << "Correct Answer: ";
	cout << correctAnswer << endl;
	
	return isAnswerCorrect;
}
//to set correct answer to the attribute correctAnswer
void MathProblem::setCorrectAnswer(Fraction f1)
{
	correctAnswer.setWNum(f1.getWNum());
	correctAnswer.setNum(f1.getNum());
	correctAnswer.setDen(f1.getDen());
}
//method that generate values to the attributes
//needs be improved in the future to generate one attribute at time and should be used in attribute that need this
void MathProblem::createMath() { 
	srand((unsigned)time(NULL));
	operand1.setWNum(1 + (rand() % 9));
	operand1.setNum(1 + (rand() % 9));
	operand1.setDen(1 + (rand() % 9));
	operand2.setWNum(1 + (rand() % 9));
	operand2.setNum(1 + (rand() % 9));
	operand2.setDen(1 + (rand() % 9));
//in the future should be changed to another method to be used independently
	if ((rand() % 4 + 1) == 1) 
		op = '+'; 
	else if((rand() % 4 + 1) == 2)
		op = '-';
	else if ((rand() % 4 + 1) == 3)
		op = '*';
	else if ((rand() % 4 + 1) == 4)
		op = '/';
}




