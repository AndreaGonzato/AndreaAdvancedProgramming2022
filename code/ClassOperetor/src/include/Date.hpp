#pragma once
#include <iostream>

class Date{
    int mo, da, yr;
public:
    Date(int m, int d, int y)
    {
        mo = m; da = d; yr = y;
    }
    friend std::ostream& operator<<(std::ostream& os, const Date& dt);
};

std::ostream& operator<<(std::ostream& os, const Date& dt){
    os << dt.mo << '/' << dt.da << '/' << dt.yr;
    return os;
}
