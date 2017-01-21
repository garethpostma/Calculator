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

#ifndef SUBTRACT_H_
#define SUBTRACT_H_

#include <iostream>
using namespace std;
#include "ArithmeticExpression.h"
#include "Expression.h"

class Subtract : public ArithmeticExpression{
public:
	Expression *left;
	Expression *right;
	string value;
	virtual string evaluate();
	virtual string* returnInput();
	virtual string* getExp();
	Subtract(Expression *left, Expression *right);
	virtual void print();
	virtual~Subtract();

};



#endif /* SUBTRACT_H_ */
