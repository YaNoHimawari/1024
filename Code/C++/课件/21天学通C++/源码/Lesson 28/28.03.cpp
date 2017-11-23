// Throwing 
#include <iostream>

using namespace std;

const int DefaultSize = 10;

int main()
{
   int top = 90;
   int bottom = 0;

   try
   {  
      cout << "top / 2 = " << (top/ 2) << endl;
                                                    
      cout << "top divided by bottom = ";
      if ( bottom == 0 )
         throw "Division by zero!";
      else
         cout << (top / bottom) << endl;

      cout << "top / 3 = " << (top/ 3) << endl;
   }
   catch( const char * ex )
   {
      cout << "\n*** " << ex << "***" << endl;
   }
   catch(...)
   {
      cout << "something has gone wrong!" << endl;
   }

   cout << "Done." << endl;
   return 0;
}
