// Listing 17.12 - Adjusting the width of output
#include <iostream>
using namespace std;

int main()
{
   cout << "Start >";
   cout.width(25);
   cout << 123 << "< End\n";

   cout << "Start >";
   cout.width(25);
   cout << 123<< "< Next >";
   cout << 456 << "< End\n";

   cout << "Start >";
   cout.width(4);
   cout << 123456 << "< End\n";

   return 0;
}
