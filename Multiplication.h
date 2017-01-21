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

#ifndef MULTIPLICATION_H_
#define MULTIPLICATION_H_

#include <iostream>
using namespace std;
#include "ArithmeticExpression.h"
#include "Expression.h"

class Multiplication : public ArithmeticExpression{
public:
	Expression *left;
	Expression *right;
	string value;
	virtual string evaluate();
	virtual string* returnInput();
	virtual string* getExp();
	Multiplication(Expression *left, Expression *right);
	virtual void print();
	virtual~Multiplication();

};




#endif /* MULTIPLICATION_H_ */
