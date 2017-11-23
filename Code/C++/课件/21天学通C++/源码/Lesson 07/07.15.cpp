// LISTING 7.15 - Solving the nth Fibonacci Number Using Iteration
#include <iostream>

unsigned int fib(unsigned int position );
int main()
{
    using namespace std;
    unsigned int answer, position;
    cout << "Which position? ";
    cin >> position;
    cout << endl;

    answer = fib(position);
    cout << answer << " is the ";
    cout << position << "th Fibonacci number. " << endl;
    return 0;
}

unsigned int fib(unsigned int n)
{
    unsigned int minusTwo=1, minusOne=1, answer=2;

    if (n < 3)
        return 1;

    for (n -= 3; n != 0; n--)
    {
        minusTwo = minusOne;
        minusOne = answer;
        answer = minusOne + minusTwo;
    }

    return answer;
}