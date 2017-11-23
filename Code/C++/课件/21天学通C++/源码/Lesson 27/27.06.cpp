// Listing 17.6 - Using get() with a character array

#include <iostream>
using namespace std;

int main()
{
   char stringOne[256];
   char stringTwo[256];

   cout << "Enter string one: ";
   cin.get(stringOne,256);
   cout << "stringOne: " << stringOne << endl;

   cout << "Enter string two: ";
   cin >> stringTwo;
   cout << "StringTwo: " << stringTwo << endl;
   return 0;
}
