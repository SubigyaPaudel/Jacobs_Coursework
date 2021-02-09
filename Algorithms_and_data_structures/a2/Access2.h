#ifndef ACCESS2_H
#define ACCESS2_H

#include <map>

class Access{
    private:
        std::map<unsigned int, unsigned int> codes;
    public:
        void activate(unsigned int code, unsigned int access_level);
        void deactivate(unsigned int code);
        void change_access_level(unsigned int code, unsigned int new_level);
        bool isactive(unsigned int code, unsigned int access_level) const;
};

#endif