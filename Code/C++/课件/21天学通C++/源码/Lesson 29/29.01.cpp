// LISTING 29.1 Using #define
#define DemoVersion
#define SW_VERSION 5
#include <iostream>

using std::endl;
using std::cout;

int main()
{
    cout << "Checking on the definitions of DemoVersion,";
    cout << "SW_VERSION, and WINDOWS_VERSION..." << endl;

#ifdef DemoVersion
    cout << "DemoVersion defined." << endl;
#else
    cout << "DemoVersion not defined." << endl;
#endif

#ifndef SW_VERSION
    cout << "SW_VERSION not defined!" << endl;
#else
    cout << "SW_VERSION defined as: "
        << SW_VERSION << endl;
#endif

#ifdef WINDOWS_VERSION
    cout << "WINDOWS_VERSION defined!" << endl;
#else
    cout << "WINDOWS_VERSION was not defined." << endl;
#endif

    cout << "Done." << endl;
    return 0;
}