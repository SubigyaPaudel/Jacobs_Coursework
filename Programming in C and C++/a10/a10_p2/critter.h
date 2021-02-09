/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a10_p02.c
*/

#include <string> // defines standard C++ string class

/* First C++ class */
class Critter
{
private:  // data members are private
	std::string name;
	int hunger;
	int boredom;
	double height;
    std::string gender;
    int age;

public: // business logic methods are public
	// setter methods
	void setName(std::string& newname);
	void setHunger(int newhunger);
	void setBoredom(int newboredom);
	// getter method
	int getHunger();
	// service method
	void print();
    void setgender(std::string& gender);
	std::string getgender();
	int getage();
    void setage(int newage);
};