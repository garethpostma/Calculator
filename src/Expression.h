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
using namespace std;
#ifndef EXPRESSION_H_
#define EXPRESSION_H_

class Expression{
public:
	virtual string evaluate()=0;
	virtual void print()=0;
	virtual string* returnInput()=0;
	virtual string* getExp()=0;
	string *input;
	virtual ~Expression(){//delete input;
		};
};



#endif /* EXPRESSION_H_ */
