// LISTING 5.4 A Demonstration of Branching Based on Relational Operators
#include <iostream>

int main()
{
    using std::cout;
    using std::cin;

    int MetsScore, YankeesScore;
    cout << "Enter the score for the Mets: ";
    cin >> MetsScore;

    cout << "\nEnter the score for the Yankees: ";
    cin >> YankeesScore;

    cout << "\n";

    if (MetsScore > YankeesScore)
        cout << "Let's Go Mets!\n";

    if (MetsScore < YankeesScore)
    {
        cout << "Go Yankees!\n";
    }

    if (MetsScore == YankeesScore)
    {
        cout << "A tie? Naah, can't be.\n";
        cout << "Give me the real score for the Yanks: ";
        cin >> YankeesScore;

        if (MetsScore > YankeesScore)
            cout << "Knew it! Let's Go Mets!";

        if (YankeesScore > MetsScore)
            cout << "Knew it! Go Yanks!";

        if (YankeesScore == MetsScore)
            cout << "Wow, it really was a tie!";
    }

    cout << "\nThanks for telling me.\n";
    return 0;
}