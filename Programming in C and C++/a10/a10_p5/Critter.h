/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a10_p05.c
*/

#include <string> // defines standard C++ string class

class Critter
{
private:  // data members are private
	std::string name;
	int hunger;
	int boredom;
	double height;

public: // business logic methods are public
	// setter methods
	void setName(std::string& newname);
	void setHunger(int newhunger);
	void setBoredom(int newboredom);
	void setheight(double newheight);
	double getheight();
	// getter method
	int getHunger();
	// service method
	void print();
	Critter();
	Critter(std::string s);
	Critter(std::string newname, int newhunger, int newboredom, double newheight=10.0);
};