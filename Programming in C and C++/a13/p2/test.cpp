#include <iostream>
#include <fstream>
#include <cstdlib>

class complex{
    private:
        double real;
        double imaginary;
    public:
        complex();
        complex(double, double);
        double getreal() const{return real;}
        double getimaginary() const{return imaginary;}
        void setreal(double real) {this->real = real;}
        void setimaginary(double imaginary){this->imaginary = imaginary;}
        friend complex operator+(complex& a, complex& b);
        friend complex operator-(complex& a, complex& b);
        friend complex operator*(complex& a, complex& b);
        friend std::istream& operator>>(std::istream& in, complex& c);
        friend std::ostream& operator<<(std::ostream& out, const complex& c);
        void operator=(const complex& a); 
};

complex::complex(){
    real = 0;
    imaginary = 0;
}

complex::complex(double a, double b){
    real = a;
    imaginary = b;
}

std::istream& operator>>(std::istream& in, complex& c){
    in >> c.real;
    getchar();
    in >> c.imaginary;
    return in;
}

std::ostream& operator<<(std::ostream& out, const complex& c){
    out << c.real << "+" << c.imaginary << "i";
    return out;
}

complex operator+(complex& a, complex& b){
    double newreal = a.real + b.real;
    double newimaginary = a.imaginary + b.imaginary;
    return complex(newreal, newimaginary);
}

complex operator-(complex& a, complex& b){
    double newreal = a.real - b.real;
    double newimaginary = a.imaginary - b.imaginary;
    return complex(newreal, newimaginary);
}

complex operator*(complex& a, complex& b){
    double newreal = a.real * b.real + a.imaginary * b.imaginary;
    double newimaginary = a.imaginary * b.real + a.real * b.imaginary;
    return complex(newreal, newimaginary); 
}

void complex::operator=(const complex& a){
    this->real = a.getreal();
    this->imaginary = a.getimaginary();
}

using namespace std;

int main(){
    complex c1, c2, result;
    string filename, filename2;
    cout << "Enter the filename" << std::endl;
    cin >> filename;
    ifstream in(filename.c_str());
    if(!in.good()){
        std::cout << "error opening file" << std::endl;
        exit(1);
    }
    cout << "Enter the scond file" << endl;
    cin >> filename2;
    ifstream in2(filename2.c_str());
    in >> c1;
    in2 >> c2;
    string name = "Output.txt";
    ofstream out(name.c_str());
    if(!out.good()){
        std::cout << "error opening the outpur file" << std::endl;
        exit(1);
    }
    out << "The numbers extracted from the file" << c1 << " and "<< endl;
    cout << "The numbers extracted from the file are:" << c1 << " and " << c2 << endl;
    result = c1 + c2;
    cout << "The sum of the two numbers is:" << result << endl;
    out << "The sum of the two numbers is:" << result << endl;
    result = c1 - c2;
    cout << "The difference of the two numbers is:" << result << endl;
    out << "The difference of the two numbers is:" << result << endl;
    result = c1 * c2;
    cout << "The product of the two numbers is:" << result << endl;
    out << "The product of the two numbers is:" << result << endl;
    cout << "The same output has been printed in Output.txt" << endl; 
    out.close();
    in.close();
    in2.close();
    cout << "Process completed" << endl;
    return 0;
}


