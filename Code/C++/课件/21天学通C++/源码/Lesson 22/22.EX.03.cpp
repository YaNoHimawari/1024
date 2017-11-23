template <typename elementType>
class CSortAscending
{
public:
    bool operator () (const elementType& num1,
        const elementType& num2) const
    {
        return (num1 < num2);
    }
};

int main ()
{
    std::vector <int> vecIntegers;
    // Insert sample numbers: 100, 90... 20, 10
    for (int nSample = 10; nSample > 0; -- nSample)
        vecIntegers.push_back (nSample * 10);
    std::sort ( vecIntegers.begin (), vecIntegers.end (),
        CSortAscending<int> () );
    for ( size_t nElementIndex = 0;
        nElementIndex < vecIntegers.size ();
        ++ nElementIndex )
        cout << vecIntegers [nElementIndex] << ' ';
    return 0;
}