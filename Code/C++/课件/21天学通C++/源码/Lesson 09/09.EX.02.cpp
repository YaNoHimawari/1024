int main()
{
    int varOne;
    const int * const pVar = &varOne;
    varOne = 6;
    *pVar = 7;
    int varTwo;
    pVar = &varTwo;
    return 0;
}