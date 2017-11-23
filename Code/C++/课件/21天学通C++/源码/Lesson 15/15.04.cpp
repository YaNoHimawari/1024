// LISTING 15.4 - Sample Usage of the Template Class
int main ()
{
    using namespace std;

    // Two instantiations of template CHoldsPair -
    CHoldsPair <> mIntFloatPair (300, 10.09);
    CHoldsPair<short,char*>mShortStringPair(25,"Learn templates, love C++");

    // Output values contained in the first object...
    cout << "The first object contains -" << endl;
    cout << "Value 1: " << mIntFloatPair.GetFirstValue () << endl;
    cout << "Value 2: " << mIntFloatPair.GetSecondValue () << endl;

    // Output values contained in the second object...
    cout << "The second object contains -" << endl;
    cout << "Value 1: " << mShortStringPair.GetFirstValue () << endl;
    cout << "Value 2: " << mShortStringPair.GetSecondValue ();

    return 0;
}