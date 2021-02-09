#include<iostream>
using namespace std;
 
class A{
    private:        // private was not written here
        int x;
    public:
        A(int i) { x = i; }
        void print() { cout << x; }
};
 
class B: public virtual A{ // it should be public virtual instead of virtual public
    public:
        B():A(10) {  }
};
 
class C: public virtual A{ // same as the above correction
    public:
        C():A(10) {  }
};
 
class D: public B, public C {
    public:
        D() : A(10), B(), C(){
        }//since this class has multiple inheritance, a constructor must be provided
};
 
int main()
{
    D d;
    d.print();
    return 0;
}