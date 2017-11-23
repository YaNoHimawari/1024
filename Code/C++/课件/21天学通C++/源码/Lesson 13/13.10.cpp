// LISTING 13.10 - Using the Subscript Operator in Programming a Dynamic Array
#include <iostream>

class CMyArray
{
private:
    int* m_pnInternalArray;
    int m_nNumElements;
public:
    CMyArray (int nNumElements);
    ~CMyArray ();

    // declare a subscript operator
    int& operator [] (int nIndex);
};

// subscript operator: allows direct access to an element given an index
int& CMyArray::operator [] (int nIndex)
{
    return m_pnInternalArray [nIndex];
}

CMyArray::CMyArray (int nNumElements)
{
    m_pnInternalArray = new int [nNumElements];
    m_nNumElements = nNumElements;
}
CMyArray::~CMyArray ()
{
    delete [] m_pnInternalArray;
}

int main ()
{
    // instantiate a dynamic array with 5 elements
    CMyArray mArray (5);

    // write into the array using the subscript operator []
    mArray [0] = 25;
    mArray [1] = 20;
    mArray [2] = 15;
    mArray [3] = 10;
    mArray [4] = 5;

    cout << "The contents of the array are: " << std::endl << "{";

    // read from the dynamic array using the same subscript operator
    for (int nIndex = 0; nIndex < 5; ++ nIndex)
        std::cout << mArray [nIndex] << " ";

    std::cout << "}";

    return 0;
}