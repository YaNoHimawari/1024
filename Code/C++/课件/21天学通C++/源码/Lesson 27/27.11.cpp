// Listing 17.11 - Using write()
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
   char One[] = "One if by land";

   int fullLength = strlen(One);
   int tooShort = fullLength -4;
   int tooLong = fullLength + 6;

   cout.write(One,fullLength) << endl;
   cout.write(One,tooShort) << endl;
   cout.write(One,tooLong) << endl;
   return 0;
}
