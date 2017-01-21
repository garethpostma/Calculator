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
#include "ArithmeticExpression.h"
#include "Expression.h"
#include "Addition.h"
#include "Subtract.h"
#include "Multiplication.h"
#include "Division.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
string the = "the";
string*to = &the;
ArithmeticExpression::ArithmeticExpression(string* a,string *exp):input(a),expression(exp){
	evaluate();};
ArithmeticExpression::~ArithmeticExpression(){
	delete left;
	delete right;
	delete leftStr;
	delete rightStr;
	delete input;
};
void ArithmeticExpression:: print(){
	cout<<*expression;};
string* ArithmeticExpression::returnInput(){
	return input;};
string* ArithmeticExpression::getExp(){
	return expression;};
string ArithmeticExpression::multiply(int i){

	while(i>=0){
		int location = input->find_first_of('*');
		int location1 = input->find_first_of('/');
		int location2 = input->find_first_of('-');
		if(location!=-1 && (*input).at(i)=='*'){
			string subexp1 = (expression->substr(0,i));
			leftExp = &subexp1;
			string subexp2 = expression->substr(i+1,expression->length()-i);
			rightExp = &subexp2;
			bool neg = false;
			bool neg2 = false;
			if(location2==0){neg2=true;
				*input = input->substr(1,input->length()-1);
				i--;}
			string sub = input->substr(0,i);
			leftStr = &sub;
			if((*input).at(i+1)=='-'){
				*input = input->substr(0,i)+"*"+input->substr(i+2,input->length()-2-i);
				neg = true;}
				string sub2 = input->substr(i+1,input->length()-i);
				rightStr = &(sub2);
				left = new ArithmeticExpression(leftStr,leftExp);
				right = new ArithmeticExpression(rightStr,rightExp);
				Multiplication *a = new Multiplication(left,right);
				*expression = *leftExp;
				if(neg && neg2){ neg=false; neg2=false; *input = a->value;}
				else if(neg){*input = "-"+a->value; neg=false;}
				else if(neg2){*input = "-"+a->value; neg2=false;}
				else *input = a->value;
				delete a;

			i--;}
		else if(location1!=-1 && (*input).at(i)=='/'){
			string subexp1 = (expression->substr(0,i));
			leftExp = &subexp1;
			string subexp2 = expression->substr(i+1,expression->length()-i);
			rightExp = &subexp2;
			bool neg = false;
			bool neg2 = false;
			if(location2==0){neg2=true;
				*input = input->substr(1,input->length()-1);
				i--;}
			string sub = input->substr(0,i);
			leftStr = &(sub);
			if((*input).at(i+1)=='-'){
				*input = input->substr(0,i)+"/"+input->substr(i+2,input->length()-2-i);
				neg = true;}
				string sub2 = input->substr(i+1,input->length()-i);
				rightStr = &(sub2);
				left = new ArithmeticExpression(leftStr,leftExp);
				right = new ArithmeticExpression(rightStr,rightExp);
				Division *a = new Division(left,right);
				*expression = *leftExp;
				if(neg && neg2){ neg=false; neg2=false; *input = a->value;}
				else if(neg){*input = "-"+a->value; neg=false;}
				else if(neg2){*input = "-"+a->value; neg2=false;}
				else *input = a->value;
				i--;}
		else if(i==0){i--; value = *input; return *input;}
		else{i--;}
	}
	return *input;};

string ArithmeticExpression::evaluate(){
	int location = 0;
	int location2 = 0;
	while(location != -1){
		location = input->find_last_of("(");
		if(location !=-1){
			string aft = input->substr(location+1,input->length()-location);
			location2 = aft.find_first_of(")");
			string brackets = aft.substr(0,location2);

/////			if(expression->length()>location+1) string brExp = expression->substr(location+1,findBracket(expression->substr(location+1)));
			string brExp = brackets;
			string *pt = &brackets;
			string *inside =  &brExp;
			ArithmeticExpression *a = new ArithmeticExpression(pt,inside);
			*expression = expression->substr(0,location)+*inside;
			if(expression->length()>location+location2+2){*expression += expression->substr(location+location2+2);};
			string cont = a->value;
			*input = input->substr(0,location)+cont+input->substr(location+location2+2,input->length()-location2-location);
			evaluate();
			return "the";
		}}

	int i = input->length()-1;
	while(i>=0){
		if(input->at(0)=='-' && input->at(1)=='-'){*input=input->substr(2,input->length()-2);}
		int location = input->find_first_of('+');
		int location1 = input->find_last_of('-');
		int location2 = input->find_first_of('*');
		int location3 = input->find_first_of('/');
		if(location!=-1 && input->at(i)=='+'){
			string subexp1 = (expression->substr(0,i));
			leftExp = &subexp1;
			string subexp2 = expression->substr(i+1,expression->length()-i);
			rightExp = &subexp2;
			string sub = input->substr(0,i);
			leftStr = &(sub);
			string sub2 = input->substr(i+1,input->length()-i);
			rightStr = &(sub2);
			left = new ArithmeticExpression(leftStr,leftExp);
			right = new ArithmeticExpression(rightStr,rightExp);
			Addition *a = new Addition(left,right);
			*expression = *leftExp;
			*input = a->value;
			i--;}
		else if(location1!=-1 && location1!=0 && input->at(i)=='-' && input->at(i-1)!='*' && input->at(i-1) !='/'){
			string subexp1 = (expression->substr(0,i));
			leftExp = &subexp1;
			string subexp2 = expression->substr(i+1,expression->length()-i);
			rightExp = &subexp2;
			if((*input).at(i-1)=='-'){
				*input = input->substr(0,i-1)+"+"+input->substr(i+1,input->length()-1-i);
				*expression = *input;
				string sub = input->substr(0,i);
				leftStr = &sub;}
			else if((*input).at(i-1)=='+'){
				*input = input->substr(0,i-1)+"-"+input->substr(i+1,input->length()-1-i);
				*expression = *input;
				string sub = input->substr(0,i);
				leftStr = &(sub);}
			else{	string sub = input->substr(0,i);
				leftStr = &(sub);
				string sub2 = input->substr(i+1,input->length()-i);
				rightStr = &(sub2);
				left = new ArithmeticExpression(leftStr,leftExp);
				right = new ArithmeticExpression(rightStr,rightExp);
				Subtract *a = new Subtract(left,right);
				*expression = *leftExp;
				*input = a->value;}

			i--;}
		else if((location2 !=-1 || location3 !=-1)&&((location1==-1||location1==0)|| ((*input).at(location1-1)=='*'||(*input).at(location1-1)=='/'))&&checkNeg() && location==-1){
			multiply(i);}
		else if(i==0){i--;
			value = *input;
			return *input;}
		else{i--;}
	};
	return *input;};
bool ArithmeticExpression::checkNeg(){
	int i = input->length()-1;
	int location = input->find_last_of('-');
	bool store=true;
	while(i>=0){
		if(location!=0 && i !=0 && (*input).at(i)=='-' && (*input).at(i-1)!='/' && (*input).at(i-1)!='*'){
			store = false;}
		i--;}
	return store;
};
int ArithmeticExpression::findBracket(string line){
	int location = line.find_last_of("(");
	if(location==-1){return line.find_first_of(")");}
	string aft = line.substr(location);
	int location2 = aft.find_first_of(")");
	line.at(location)=',';
	line.at(location+location2+1)=',';
	return findBracket(line);
};


