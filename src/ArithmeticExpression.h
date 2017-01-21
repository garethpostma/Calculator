/* Name: Gareth Postma
 * MacID: postmagn
 * Student Number: 001422248
 * Name: Noah Zwiep
 * MacID: zwiepn
 * Student Number: 001424643
 * Name: Mitchell Overbeeke
 * MacID: overbeml
 * Student Number: 001422018
 * Description:
 * */
#include <iostream>
#include <string>
using namespace std;
#include "Expression.h"

#ifndef ARITHMETICEXPRESSION_H_
#define ARITHMETICEXPRESSION_H_

class ArithmeticExpression: public Expression{
public:
	Expression *left;
	Expression *right;
	string *input;
	string *leftStr;
	string *rightStr;
	string *leftExp;
	string *rightExp;
	string *expression;
	string value;
	ArithmeticExpression(){};
	ArithmeticExpression(string *input,string *expression);
	int findBracket(string line);
	virtual string* returnInput();
	virtual string* getExp();
	virtual string evaluate();
	virtual void print();
	string multiply(int i);
	bool checkNeg();
	virtual ~ArithmeticExpression();
};



#endif /* ARITHMETICEXPRESSION_H_ */
