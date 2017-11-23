// Listing 17.13 - fill()

#include <iostream>
using namespace std;

int main()
{
   cout << "Start >";
   cout.width(25);
   cout << 123 << "< End\n";

   cout << "Start >";
   cout.width(25);
   cout.fill('*');
   cout << 123 << "< End\n";
   cout << "Start >";
   cout.width(25);
   cout << 456 << "< End\n";
  
   return 0;
}
