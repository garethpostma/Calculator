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
#include "Subtract.h"
#include "ArithmeticExpression.h"
#include "Expression.h"
using namespace std;

Subtract :: Subtract(Expression *left, Expression *right){
	this->left = left;
	this->right = right;
	evaluate();
};
string* Subtract::returnInput(){
	return input;
};
string* Subtract::getExp(){}
void Subtract :: print(){
	*left->getExp()="("+*left->getExp()+"-"+*right->getExp()+")";
};

string Subtract :: evaluate(){
	print();
	value = to_string(stod(*(left->returnInput())) - stod(*(right->returnInput())));
	return to_string(stod(*(left->returnInput())) - stod(*(right->returnInput())));
};


Subtract :: ~Subtract(){
	//delete left;delete right;
};


