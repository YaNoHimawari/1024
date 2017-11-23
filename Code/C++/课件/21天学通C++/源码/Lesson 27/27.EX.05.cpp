#include <iostream>
int main(int argc, char**argv) // returns 1 on error
{
    for (int ctr = argc-1; ctr>0 ; ctr--)
        std::cout << argv[ctr] << " ";
}