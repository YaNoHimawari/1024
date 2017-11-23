// LISTING 3.2 - A Demonstration of the Use of Variables
#include <iostream>

int main()
{
    using std::cout;
    using std::endl;

    unsigned short int Width = 5, Length;
    Length = 10;

    // create an unsigned short and initialize with result
    // of multiplying Width by Length
    unsigned short int Area = (Width * Length);

    cout << "Width:" << Width << endl;
    cout << "Length: " << Length << endl;
    cout << "Area: " << Area << endl;
    return 0;
}