//Listing 17.1 - character strings and cin

#include <iostream>
using namespace std;

int main()
{
   int myInt;
   long myLong;
   double myDouble;
   float myFloat;
   unsigned int myUnsigned;

   cout << "Int: ";
   cin >> myInt;
   cout << "Long: ";
   cin >> myLong;
   cout << "Double: ";
   cin >> myDouble;
   cout << "Float: ";
   cin >> myFloat;
   cout << "Unsigned: ";
   cin >> myUnsigned;

   cout << "\n\nInt:\t" << myInt << endl;
   cout << "Long:\t" << myLong << endl;
   cout << "Double:\t" << myDouble << endl;
   cout << "Float:\t" << myFloat << endl;
   cout << "Unsigned:\t" << myUnsigned << endl;
   return 0;
}
