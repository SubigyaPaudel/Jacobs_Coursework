/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a10_p09.c
*/

class complex{
    private:
        double real;
        double imaginary;
    public:
        complex();
        complex(double a, double b);
        complex(complex&);
        ~complex();
        void setreal(double a);
        void setimaginary(double b);
        void printcomplex();
        double getreal();
        double getimaginary();
        complex add(complex b);
        complex subtract(complex b);
        complex multiply(complex b);
        complex conjugation();
};