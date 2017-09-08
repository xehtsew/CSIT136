//************************************************************
// Author: D.S. Malik
// 
// class personType
// This class specifies the members to implement a name.
//************************************************************

#include <string>

using namespace std;

class personType
{
public:
	void print() const;
	//Function to output the first name and last name
	//in the form firstName lastName.

	void setName(string first, string last);
	//Function to set firstName and lastName according to the
	//parameters.
	//Postcondition: firstName = first; lastName = last

	string getFirstName() const;
	//Function to return the first name.
	//Postcondition: The value of firstName is returned.

	string getLastName() const;
	//Function to return the last name.
	//Postcondition: The value of lastName is returned.

	personType();
	//Default constructor
	//Sets firstName and lastName to null strings.
	//Postcondition: firstName = ""; lastName = "";

	personType(string first, string last);
	//Constructor with parameters.
	//Sets firstName and lastName according to the parameters.
	//Postcondition: firstName = first; lastName = last;  


	//HOMEWORK
	//set first name
	void setFirstName(string first);

	//set last name
	void setLastName(string last);

	//set middle name
	void setMiddleName(string middle);

	//get middle name
	string getMiddleName();

	//check if a given first name is the same as this person
	bool checkFirstName(string first);

	//chekc if a given last name is the same as this person
	bool checkLastName(string last);

private:
	string firstName; //variable to store the first name
	string lastName;  //variable to store the last name

	//homework
	string middleName; //variable to store the middle name
};
