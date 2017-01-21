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

#ifndef DIVISION_H_
#define DIVISION_H_

#include <iostream>
using namespace std;
#include "ArithmeticExpression.h"
#include "Expression.h"

class Division : public ArithmeticExpression{
public:
	Expression *left;
	Expression *right;
	string value;
	virtual string evaluate();
	virtual string* returnInput();
	virtual string* getExp();
	Division(Expression *left, Expression *right);
	virtual void print();
	virtual ~Division();

};




#endif /* DIVISION_H_ */
