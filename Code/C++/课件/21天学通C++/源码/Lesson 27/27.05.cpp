// Listing 17.5 - Using get() with parameters

#include <iostream>

int main()
{
   char a, b, c;

   std::cout << "Enter three letters: ";

   std::cin.get(a).get(b).get(c);

   std::cout << "a: " << a << "\nb: ";
   std::cout << b << "\nc: " << c << std::endl;
   return 0;
}
