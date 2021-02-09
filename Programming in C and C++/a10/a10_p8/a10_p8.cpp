/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a10_p08.c
*/

#include <iostream>
#include <cstring>  // standard C string.h header file

using namespace std;

/*
	Naive string: the goal is to illustrate how copy constructors 
	should be handled. See also charbuffer.cpp
*/

class NaiveString {
private:
	char *str;
public:
	NaiveString(const char*);
	NaiveString(const NaiveString&);
    void clearmemory();
	void update(char, char);
	void print();
};

NaiveString::NaiveString(const char* t) {
	str = new char[strlen(t) + 1];
	strcpy(str, t);
    cout << "NaiveString(const char* t) is being called" << endl;
}

/* 
	Copy constructor: creates a new instance of 
	naive string starting from an existing one 
*/


NaiveString::NaiveString(const NaiveString& src) {
	str = new char[strlen(src.str) + 1];
	strcpy(str, src.str);
	// please note that we can access src.str even if it is private
	// as we are inside the NaiveString class
    cout << "NaiveString::NaiveString(const NaiveString& src) is being called" << endl;
}

/* replaces occurrences of oldchar by newchar */
void NaiveString::update(char oldchar, char newchar) {
	unsigned int i;
	for (i = 0; i < strlen(str); i++) 
		if (str[i] == oldchar)
			str[i] = newchar;
}

void NaiveString::print() {
	cout << str << endl;
}

void NaiveString::clearmemory(){
    delete [] str;
}

void funcByVal(NaiveString s) {
	cout << "funcbyval() being called" << endl;
	s.update('B', 'C');
	s.print();
}

void funcByref(NaiveString& stringref){
    cout << "funcbyref() being called" << endl;
    stringref.update('B','C');
    stringref.print();
}

int main(int argc, char** argv)
{
    NaiveString a("aBcBdB");
    NaiveString b(a);
  	a.print();
	cout << "About to call funcbyval()" << endl;
	funcByVal(a);
    cout<< "About to call funcbyval()" << endl;
    funcByref(a);
	a.print();
    b.clearmemory();
    return 0;
}