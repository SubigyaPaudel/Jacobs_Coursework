/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a11_p03.c
*/


#include <iostream>

using namespace std;


// Creature starts
class Creature {
	public:
		Creature(int = 10);  
		void run() const;
        ~Creature();
	protected:
		int distance;
};

Creature::Creature(int a): distance(a){
    cout << "Creature created" << endl;
}    

void Creature::run() const
{ 
    cout << "running " << distance << " meters!\n";
}  

Creature::~Creature(){
    cout << "Now the creature is gone" << endl;
}

//class wizard starts

class Wizard : public Creature {
	public:
		Wizard(int = 3, int = 5);
        ~Wizard();
		void hover() const;
	private:
		int distFactor;
};

Wizard::Wizard(int a, int b) : Creature(a)
{
    distFactor = b;
    cout << "Wizard created" << endl;
}  

void Wizard::hover() const
{
    cout << "hovering " << (distFactor * distance) << " meters!\n";
}

Wizard::~Wizard(){
    cout << "Now the wizard is gone" << endl;
}

// class golem starts

class Golem : public Creature{
    private:
        float radius;
    public:
        Golem(int  = 9, float = 100);
        ~Golem();
        void roll();
};

Golem::Golem(int a, float b) : Creature(a) {
    radius = b;
    cout << "Golem created" << endl;
}

Golem::~Golem(){ 
    cout << "Now the Golem is gone" << endl;
}

void Golem::roll(){
    float dist = 2 * radius;
    cout << "Rolling " << dist << "meters" <<  endl;
}

//Class Giant begins

class Giant : public Creature{
    private:
        float height;
    public:
        Giant(int = 2, float = 100);
        ~Giant();
        void leap() const;
};

Giant::Giant(int a, float b) : Creature(a){
    height = a;
    cout << "Giant created" << endl;
}

Giant::~Giant(){
    cout << "Now the Giant is gone" << endl;
}

void Giant::leap() const{
    cout << "Leaping " << 2.0 * height << " meters" << endl; 
}

int main()
{ 
    cout << "Creating an Creature.\n";
    Creature c;
    c.run();

    cout << "\nCreating a Wizard.\n";
    Wizard w;
    w.run();
    w.hover();
    Golem g;
    g.roll();
    g.run();
    Giant h;
    h.leap();
    h.run();
    return 0;
} 
