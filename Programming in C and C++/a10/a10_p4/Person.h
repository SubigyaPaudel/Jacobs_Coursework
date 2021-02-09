#include <string>

class person{
    private:
        std::string name;
        int age;
        double height;
        person *relative;
    public:
        void setname(std::string newname);
        void setage(int newage);
        void setheight(double newheight);
        void setrelative(person* arelative);
        std::string getname();
        int getage();
        int getheight();
        person getrelative();        
};