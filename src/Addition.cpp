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
#include "Addition.h"
#include "ArithmeticExpression.h"
#include "Expression.h"
using namespace std;

Addition :: Addition(Expression *left, Expression *right){
	this->left = left;
	this->right = right;
	evaluate();
}
string* Addition::returnInput(){
	return input;
};
string* Addition::getExp(){}
void Addition :: print(){
	*left->getExp()="("+*left->getExp()+"+"+*right->getExp()+")";
}

string Addition :: evaluate(){
	print();
	value = to_string(stod(*(left->returnInput())) + stod(*(right->returnInput())));
	return to_string(stod(*(left->returnInput())) + stod(*(right->returnInput())));
};


Addition :: ~Addition(){
	//delete left;delete right;
}



