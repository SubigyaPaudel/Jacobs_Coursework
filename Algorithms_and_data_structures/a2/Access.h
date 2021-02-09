#ifndef ACCESS_H
#define ACCESS_H

#include <set>

class Access{
    private:
        std::set<int> codes;
    public:
        void activate(unsigned int code);
        void deactivate(unsigned int code);
        bool isactive(unsigned int code) const;
};

#endif