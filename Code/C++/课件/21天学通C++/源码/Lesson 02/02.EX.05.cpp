#include <iostream>
int Add (int first, int second)
{
    std::cout << "Add(), received " << first << " and " <<second<< "\n";
    return (first + second);
}
int Subtract (int first, int second)
{
    std::cout << "Subtract(), received " << first << " and " <<second<<
        "\n";
    return (first - second);
}
int main()
{
    using std::cout;
    using std::cin;
    cout << "I'm in main()!\n";
    int a, b, c;
    cout << "Enter two numbers: ";
    cin >> a;
    cin >> b;
    cout << "\nCalling Add()\n";
    c=Add(a,b);
    cout << "\nBack in main().\n";
    cout << "c was set to " << c;
    Lesson 2, "The Anatomy of a C++ Program" 779
        D
        40_0672329417_appd.qxd 6/6/08 9:46 AM Page 779
        cout << "\n\nCalling Subtract()\n";
    c=Subtract(a,b);
    cout << "\nBack in main().\n";
    cout << "c was set to " << c;
    cout << "\nExiting...\n\n";
    return 0;
}