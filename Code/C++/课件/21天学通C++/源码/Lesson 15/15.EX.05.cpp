template <typename Array1Type, typename Array2Type>
class CTwoArrays
{
private:
    Array1Type m_Array1 [10];
    Array2Type m_Array2 [10];
public:
    Array1Type& GetArray1Element(int nIndex){return m_Array1[nIndex];}
    Array2Type& GetArray2Element(int nIndex){return m_Array2[nIndex];}
};