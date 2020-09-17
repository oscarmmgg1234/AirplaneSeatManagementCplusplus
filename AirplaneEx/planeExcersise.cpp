/*
 * planeExcersise.cpp
 *
 *  Created on: Jul 23, 2018
 *      Author: oscarmaldonado
 */
#include <iostream>
#include <string>
#include <iomanip>
#include "person.h"
#include <fstream>

using namespace std;

#define Log(x) std :: cout << x << endl;

person :: person()
{
	string name = "";
	float balance = 0.0;
	int age = 0;
}

person::person(string namee,float balancee, int agee)
{
	name = namee;
	balance = balancee;
	age = agee;

}
void person :: increY(int yy);


void person :: set_name(string pname)
{
	name = pname;
}
 void person :: set_age(int page)
{
	age = page;
}
void person :: set_balance(float pbalance)
{
	balance = pbalance;
}

string person :: get_name()
{
	return name;
}
int person :: get_age()
{
	return age;
}
float person::get_balance()
{
	return balance;
}
typedef char arraySeat[13][6];
arraySeat airSeat;

void initSeats(int a)
{

	cout << setw(10) << "A" <<right << setw(6) << 'B' << right << setw(6)  << 'C' << right <<
			setw(6)  << 'D' << right << setw(6) << 'E' << right << setw(6)  <<'F' << endl;
	cout << endl;
	for (int row = 0;row <13;row++)
	{
		for(int column = 0;column <6;column++)
		{
			if(row > a)
			{
			airSeat[row][column] = '*';
			}
			if(column == 5)
				{break;
				}
		}
	}//end of init loop

}
void printSeats(arraySeat airSeat)
{

	int rowNu = 0;

	for(int row = 0 ; row < 12;row++)
	{


		if(row < 10)
		{
		cout << "row " << rowNu << setw(5)  << airSeat[row][0] << setw(6)  << airSeat[row][1]<< setw(6) << airSeat[row][2] <<
				 setw(6)  << airSeat[row][3] << setw(6)  << airSeat[row][4] << setw(6)  << airSeat[row][5] << endl;
		cout << endl;
		}
	else
	{
		cout << "row " << rowNu << setw(4)  << airSeat[row][0] << setw(6)  << airSeat[row][1]<< setw(6)  << airSeat[row][2] <<
				 setw(6)  << airSeat[row][3] << setw(6)  << airSeat[row][4] << setw(6) << airSeat[row][5] << endl;
		cout << endl;
	}
	rowNu++;

}
}

int main()//////////////////////////////////////////
{


//to change or pick the seat you want
int x,y;
char z;

//define the class your boarding with
string airClass;
int classType;
//Person object
string Pname;
float Pbalance;
int Page;

Log("Enter your name, balance, and age in the input file and then press any key to continue:");

std::cin.get();

ifstream inData;

inData.open("inpt.txt");

inData >> Pname >> Pbalance >> Page;


inData.close();

person Person(Pname,Pbalance,Page);

enum airpClass{ECONOMY,BUSINESS,FIRST};

if(Person.get_balance() >= 100)
{
	Log("Based on your balance you can choose between economy, business, or first class type boarding")
			cout << endl;
}
else if(Person.get_balance() < 100 && Person.get_balance() >= 50)
{
	Log("based on your balance you can choose between economy and business");
	cout << endl;

}
else if(Person.get_balance() < 50)
{
	Log("Based on your balance you can choose economy");
	cout << endl;
}

Log("What luxury level would you like to board on the plane: economy,business, or first?");
cout << endl;



while(airClass != "quit")
{

	cin >> airClass;



if(airClass == "economy")
{
	if(Person.get_balance() >= 20)
	{
	classType = ECONOMY;
	Log("You have chosen economy class")
	cout << endl;
	break;
	}else {Log("You cant afford this class")
		cout << endl;}
}

else if (airClass == "business")
{
	if(Person.get_balance() >= 50)
	{
	classType = BUSINESS;
	Log("You have chosen business class")
	cout << endl;
	break;
	}else{Log("you cant afford this class")
		cout << endl;}
}
else if (airClass == "first" )
{
	if(Person.get_balance() >= 100){
	classType = FIRST;
	Log("You have chosen first class")
	cout << endl;
	break;
	}
	else
	{Log("You cant afford this class")
		cout << endl;}
}
}//end of whie loop



Log("Now which seat would you like to reserve in your class bording");
cout << endl;

switch (classType)
{
case ECONOMY:
{
	initSeats(3);
	printSeats(airSeat);
	cout << setw(10) << "A" <<right << setw(6) << 'B' << right << setw(6)  << 'C' << right <<
			setw(6)  << 'D' << right << setw(6) << 'E' << right << setw(6)  <<'F' << endl;
	break;
}
case BUSINESS:
{
	initSeats(1);
	printSeats(airSeat);
	cout << setw(10) << "A" <<right << setw(6) << 'B' << right << setw(6)  << 'C' << right <<
			setw(6)  << 'D' << right << setw(6) << 'E' << right << setw(6)  <<'F' << endl;
	break;
}
case FIRST:
{
		initSeats(-1);
		printSeats(airSeat);
		cout << setw(10) << "A" <<right << setw(6) << 'B' << right << setw(6)  << 'C' << right <<
				setw(6)  << 'D' << right << setw(6) << 'E' << right << setw(6)  <<'F' << endl;
		break;
}
}//end of switch
cout << endl;
Log("Enter the row # and column letter of your desired seat if available");
cin >> x >> z;

switch(z)
{
case 'a':
{
	y = 0;
	break;
}
case 'b':
{
	y = 1;
	break;
}
case 'c':
{
	y = 2;
	break;
}
case 'd':
{
	y = 3;
	break;
}
case 'e':
{
	y = 4;
	break;
}
case 'f':
{
	y = 5;
	break;
}
}

airSeat[x][y] = 'X';
cout << endl;
cout << Person.get_name() << " you have chosen row: " << x << " in column: " << z << endl;
cout << endl;
cout << setw(10) << "A" <<right << setw(6) << 'B' << right << setw(6)  << 'C' << right <<
				setw(6)  << 'D' << right << setw(6) << 'E' << right << setw(6)  <<'F' << endl;
printSeats(airSeat);

ofstream outData;

outData.open("outpt.txt");


outData << "Thank you for shopping with us today " << Person.get_name() << endl;

outData << endl;

outData << Person.get_name() << " you have chosen row: " << x << " in column: " << z << endl;





outData.close();
}



