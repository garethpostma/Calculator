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
#include <iomanip>
#include <string>
using namespace std;
#include "Expression.h"
#include "ArithmeticExpression.h"
bool validExpression(string expression) {
	int x,z;
	int openBracket = 0;
	int closeBracket = 0;
	if(expression==""){return false;}
	for(unsigned int k =0; k < expression.length();k++){
		z = expression.at(k);
		if(z==40){openBracket++;}
		if(z==41){closeBracket++;}}
	for(unsigned int i =0; i< expression.length()-1;i++){
		x= expression.at(i);
		//Checks whether your inputs are 0123456789/*-+()
		if ((x!=48)&&(x!=49)&&(x!=50)&&(x!=51)&&(x!=52)&&(x!=53)&&(x!=54)&&(x!=55)&&(x!=56)&&(x!=57)&&(x!=40)&&(x!=41)&&(x!=42)&&(x!=43)&&(x!=45)&&(x!=47)&&(x!=32)){
			cout << "Expression is not well formed. " << endl;
			return false;}
		//Multiplication operator cannot be placed beside another operator
		else if(expression.at(i)== 42){
			if((expression.at(i+1)==43)||(expression.at(i+1)==47)||(expression.at(i+1)==42)||(expression.at(i+1)==41)){
				cout << "Expression is not well formed. " << endl;
				return false;}}
		//Addition operator cannot be placed beside another operator
		else if(expression.at(i)==43){
			if((expression.at(i+1)==43)||(expression.at(i+1)==47)||(expression.at(i+1)==42)||(expression.at(i+1)==41)){
				cout << "Expression is not well formed. " << endl;
				return false;}}
		//Division operator cannot be placed beside another operator
		else if(expression.at(i)==47){
			if((expression.at(i+1)==43)||(expression.at(i+1)==47)||(expression.at(i+1)==42)||(expression.at(i+1)==41)){
				cout << "Expression is not well formed. " << endl;
				return false;}}
		//Subtraction operator cannot be placed beside another operator
		else if(expression.at(i)==45){
			if((expression.at(i+1)==43)||(expression.at(i+1)==47)||(expression.at(i+1)==42)||(expression.at(i+1)==41)){
				cout << "Expression is not well formed. " << endl;
				return false;}}
		//Cannot have (expression)(expression)
		else if(expression.at(i)==41){
			if(expression.at(i+1)==40){
				cout << "Expression is not well formed. " << endl;
				return false;}}
		// cannot have ( after a number
		else if(expression.at(i)==48 || expression.at(i)==49 ||expression.at(i)==50 || expression.at(i)==51 || expression.at(i)==52 ||expression.at(i)==53 ||expression.at(i)==54|| expression.at(i)==55 ||expression.at(i)==56 ||expression.at(i)==57){
			if(expression.at(i+1)== 40){
				cout << "Expression is not well formed. " << endl;
				return false;}}}
	//Same amount of open brackets as there are close brackets
	if(openBracket != closeBracket){
		cout << "Expression is not well formed. " << endl;
		return false;}
	// Cannot start with /+*)
	else if((expression.at(0)==42)||(expression.at(0)==43)||(expression.at(0)==47)||(expression.at(0)==41)){
		cout << "Expression is not well formed. " << endl;
		return false;}
	// Cannot end with /+-*(
	else if((expression.at(expression.length()-1)==42)||(expression.at(expression.length()-1)==43)||(expression.at(expression.length()-1)==47)||(expression.at(expression.length()-1)==45)||(expression.at(expression.length()-1)==40)){
		cout << "Expression is not well formed. " << endl;
		return false;}
	return true;}
int main() {
	string input;
	while (input != "#"){
		cout << "Please enter an expression:";
		char eq[200];
		cin.getline(eq,200);
		input=eq;
		int i =0;
		if(input==""||(input.at(0)==' ' && input.length()==1)){i=1; input = "";};
		while(i<input.length()){
			if(input.at(i)==' ') input = input.substr(0,i) + input.substr(i+1,input.length()-i-1);
			i++;}
		if(input!="#" && validExpression(input)){
			string *evaluate = &input;
			string printExp = input;
			string *expression =  &printExp;
			Expression *a = new ArithmeticExpression(evaluate,expression);
			a->print();
			cout<<" = "<<fixed<<setprecision(2)<<stod(*(a->returnInput()))<<endl;
			//delete a;
		}}
return 0;};
