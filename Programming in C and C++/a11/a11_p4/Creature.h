/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a11_p04.c
*/

class Creature {
	public:
		Creature(int = 10);  
		void run() const;
        ~Creature();
	protected:
		int distance;
};

class Wizard : public Creature {
	public:
		Wizard(int = 3, int = 5);
        ~Wizard();
		void hover() const;
	private:
		int distFactor;
};

class Golem : public Creature{
    private:
        float radius;
    public:
        Golem(int  = 9, float = 100);
        ~Golem();
        void roll();
};

class Giant : public Creature{
    private:
        float height;
    public:
        Giant(int = 2, float = 100);
        ~Giant();
        void leap() const;
};