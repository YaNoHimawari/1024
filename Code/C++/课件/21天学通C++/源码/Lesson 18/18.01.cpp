// LISTING 18.1 - Instantiating a std::vector
#include <vector>

int main ()
{
    std::vector <int> vecDynamicIntegerArray;

    // Instantiate a vector with 10 elements (it can grow larger)
    std::vector <int> vecArrayWithTenElements (10);

    // Instantiate a vector with 10 elements, each initialized to 90
    std::vector <int> vecArrayWithTenInitializedElements (10, 90);

    // Instantiate one vector and initialize it to the contents of another
    std::vector <int> vecArrayCopy (vecArrayWithTenInitializedElements);

    // Instantiate a vector to 5 elements taken from another
    std::vector<int> vecSomeElementsCopied(vecArrayWithTenElements.begin()
        , vecArrayWithTenElements.begin () + 5);

    return 0;
}