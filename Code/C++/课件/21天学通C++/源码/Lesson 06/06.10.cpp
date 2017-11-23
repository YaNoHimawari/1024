// LISTING 6.10 - A Demonstration of Recursion Using the Fibonacci Series
#include <iostream>
int fib (int n);

int main()
{

    int n, answer;
    std::cout << "Enter number to find: ";
    std::cin >> n;

    std::cout << "\n\n";

    answer = fib(n);

    std::cout << answer << " is the " << n;
    std::cout << "th Fibonacci number\n";
    return 0;
}

int fib (int n)
{
    std::cout << "Processing fib(" << n << ")... ";

    if (n < 3 )
    {
        std::cout << "Return 1!\n";
        return (1);
    }
    else
    {
        std::cout << "Call fib(" << n-2 << ") ";
        std::cout << "and fib(" << n-1 << ").\n";
        return( fib(n-2) + fib(n-1));
    }
}