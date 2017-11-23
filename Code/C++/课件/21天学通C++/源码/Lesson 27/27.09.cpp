// Listing 17.9 - Using peek() and putback()
#include <iostream>
using namespace std;

int main()
{
   char ch;
   cout << "enter a phrase: ";
   while ( cin.get(ch) != 0 )
   {
      if (ch == '!')
         cin.putback('$');
      else
         cout << ch;
      while (cin.peek() == '#')
         cin.ignore(1,'#');
   }
   return 0;
}
