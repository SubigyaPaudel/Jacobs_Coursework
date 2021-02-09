// simple class for fractions

#ifndef FRACTION_H_
#define FRACTION_H_

using namespace std;

class Fraction {

private:						// internal implementation is hidden
	int num;					// numerator
	int den;					// denominator

	int gcd(int a, int b);		// calculates the gcd of a and b
	int lcm(int a, int b);

public:
	Fraction();					// empty constructor
	Fraction(int, int = 1); 	// constructor taking values for fractions and
                            	// integers. Denominator by default is 1
	int getnum() const;
    int getden() const;
	void print() const;
	friend ostream& operator <<(ostream& out, const Fraction&);
	friend istream& operator >>(istream& in, Fraction&);
	friend Fraction operator *(const Fraction& a, const Fraction& b);
	friend Fraction operator /(const Fraction& a, const Fraction& b);
    Fraction operator+(const Fraction& a);
    Fraction operator-(const Fraction& a);
    bool operator<(const Fraction& a);
    bool operator>(const Fraction& a);
    void operator=(const Fraction& a);
    ~Fraction();
};



#endif /* FRACTION_H_ */
