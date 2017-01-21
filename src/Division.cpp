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
#include "Division.h"
#include "ArithmeticExpression.h"
#include "Expression.h"
using namespace std;

Division :: Division(Expression *left, Expression *right){
	this->left = left;
	this->right = right;
	evaluate();
};
string* Division::returnInput(){
	return input;
};
string* Division::getExp(){}
void Division :: print(){
	*left->getExp()="("+*left->getExp()+"/"+*right->getExp()+")";
	//cout<<"/"+*right+")";
};

string Division :: evaluate(){
	print();
	value = to_string(stod(*(left->returnInput())) / stod(*(right->returnInput())));
	return to_string(stod(*(left->returnInput())) / stod(*(right->returnInput())));
};


Division :: ~Division(){
	//delete left;delete right;
	}



