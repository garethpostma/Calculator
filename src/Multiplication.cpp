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
#include "Multiplication.h"
#include "ArithmeticExpression.h"
#include "Expression.h"
using namespace std;

Multiplication :: Multiplication(Expression *left, Expression *right){
	this->left = left;
	this->right = right;
	evaluate();
};
string* Multiplication::returnInput(){
	return input;
};
string* Multiplication::getExp(){}
void Multiplication :: print(){
	*left->getExp()="("+*left->getExp()+"*"+*right->getExp()+")";
};

string Multiplication :: evaluate(){
	print();
	value = to_string(stod(*(left->returnInput())) * stod(*(right->returnInput())));
	return to_string(stod(*(left->returnInput())) * stod(*(right->returnInput())));


};


Multiplication :: ~Multiplication(){
	//delete left;delete right;
};




