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

#ifndef ADDITION_H_
#define ADDITION_H_

#include <iostream>
using namespace std;
#include "ArithmeticExpression.h"
#include "Expression.h"

class Addition : public ArithmeticExpression{
public:
	Expression *left;
	Expression *right;
	string value;
	virtual string evaluate();
	virtual string* returnInput();
	virtual string* getExp();
	Addition(Expression *left, Expression *right);
	virtual void print();
	virtual ~Addition();

};



#endif /* ADDITION_H_ */
