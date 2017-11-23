template <typename elementType=int>
struct Double
{
    int m_nUsageCount;
    // Constructor
    Double () : m_nUsageCount (0) {};
    void operator () (const elementType element) const
    {
        ++ m_nUsageCount;
        cout << element * 2 << ' ';
    }
};