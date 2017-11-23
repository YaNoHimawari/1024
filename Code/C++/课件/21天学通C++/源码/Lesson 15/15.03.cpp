// LISTING 15.3 - A Template Class with a Pair of Member Attributes
// Template class with default parameters
template <typename T1=int, typename T2=double>

class CHoldsPair
{
private:
    T1 m_Value1;
    T2 m_Value2;
public:
    // Constructor that initializes member variables
    CHoldsPair (const T1& value1, const T2& value2)
    {
        m_Value1 = value1;
        m_Value2 = value2;
    };

    // Accessor functions
    const T1 & GetFirstValue ()
    {
        return m_Value1;
    };

    const T2& GetSecondValue ()
    {
        return m_Value2;
    };
};