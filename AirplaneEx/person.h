/*
 * person.h
 *
 *  Created on: Jul 23, 2018
 *      Author: oscarmaldonado
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <string>

using namespace std;

class person
{

public:
	person();
	person(string name,float balance,int age);
 void set_name(string namee);
	void set_balance(float balancee);
	void set_age(int agee);
	string get_name();
	float get_balance();
	void increY(int a);
	{
		y++
	}

	int get_age();
private:
	string name;
	float balance;
	int age;
	int y;
};







#endif /* PERSON_H_ */
