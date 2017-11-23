// LISTING 13.11 - A Function Object implemented Using operator()
#include <string>
#include <iostream>

class CDisplay
{
public:
    void operator () (std::string strIn) const
    {
        std::cout << strIn << std::endl;
    }
};

int main ()
{
    CDisplay mDisplayFuncObject;

    // equivalent to mDisplayFuncObject.operator () ("Display this string!");
    mDisplayFuncObject ("Display this string!");

    return 0;
}