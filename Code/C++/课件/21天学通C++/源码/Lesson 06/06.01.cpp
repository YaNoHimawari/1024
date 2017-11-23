// LISTING 6.1 - A Function Declaration and the Definition and Use of That Function
#include <iostream>

int Area(int length, int width); //function prototype

int main()
{
    using std::cout;
    using std::cin;

    int lengthOfYard = 0;
    int widthOfYard = 0;
    int areaOfYard = 0;

    cout << "\nHow wide is your yard? ";
    cin >> widthOfYard;
    cout << "\nHow long is your yard? ";
    cin >> lengthOfYard;

    areaOfYard= Area(lengthOfYard, widthOfYard);

    cout << "\nYour yard is ";
    cout << areaOfYard;
    cout << " square feet\n\n";
    return 0;
}

int Area(int len, int wid)
{
    return len * wid;
}