//Listing 17.2 - character strings and cin

#include <iostream>

int main()
{
   char YourName[50];
   std::cout << "Your first name: ";
   std::cin >> YourName;
   std::cout << "Here it is: " << YourName << std::endl;
   std::cout << "Your entire name: ";
   std::cin >> YourName;
   std::cout << "Here it is: " << YourName << std::endl;
   return 0;
}
