template <typename elementType=int>
struct Double
{
    void operator () (const elementType element) const
    {
        cout << element * 2 << ' ';
    }
};

int main ()
{
    vector <int> vecIntegers;
    for (int nCount = 0; nCount < 10; ++ nCount)
        vecIntegers.push_back (nCount);
    cout << "Displaying the vector of integers: " << endl;
    // Display the array of integers
    for_each ( vecIntegers.begin () // Start of range
        , vecIntegers.end () // End of range
        , Double <> () ); // Unary function object
    return 0;
}