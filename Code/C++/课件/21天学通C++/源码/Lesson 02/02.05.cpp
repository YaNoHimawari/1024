// LISTING 2.5 - Demonstrates Comments
#include <iostream>

int main()
{
    using std::cout;

    /* this is a comment
    and it extends until the closing
    star-slash comment mark */
    cout << "Hello World!\n";
    // this comment ends at the end of the line
    cout << "That comment ended!\n";

    // double-slash comments can be alone on a line
    /* as can slash-star comments */
    return 0;
}