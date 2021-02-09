/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a10_p03.cpp
*/
#include <string>

class city{
    private:
        std::string name;               // the characteristics of the class
        int population;     
        std::string mayor;
        double area;
    public:
        void setname(std::string& newname);        // the setter methods
        void setpopulation(int newpopulation);
        void setmayor(std::string& newmayor);
        void setarea(double newarea);
        std::string getname();                  // the getter methods
        int getpopulation();
        std::string getmayor();
        double getarea();
};