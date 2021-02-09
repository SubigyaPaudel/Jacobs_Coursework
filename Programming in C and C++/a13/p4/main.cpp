#include<iostream>
using namespace std;
 
class A
{
  int x;
public:
  void setX(int i) {x = i;}
  void print() { cout << x; }
};
 
class B:  public virtual A // virtual added
{
public:
  B()  { setX(10); }
};
 
class C:  public virtual A  // virtual added
{
public:
  C()  { setX(20); }
};
 
class D: public B, public C {  
};
 
int main()
{
    D d;
    d.print();
    return 0;
}

// we get errors in this original version of the program because the
// some attributes of the class D were too ambiguous. Since class D was
// inherited from both B and C, the compiler cannot decide which 
// common interfaces within B and C to choose from. So, adding the keyword
// virtual in front of the public in lines 18 and 12, ensures that the class A 
// is not inherited twice so that no confusion arises.