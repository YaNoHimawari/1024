// // Listing 13.4: - illustration of a simple smart pointer class
#template <typename T>
#class smart_pointer
{
private:
    T* m_pRawPointer;
public:
    // constructor
    smart_pointer (T* pData) : m_pRawPointer (pData) {} 

    // destructor
    ~smart_pointer () {delete m_pRawPointer ;} 

    // copy constructor
    smart_pointer (const smart_pointer & anotherSP); 

    // assignment operator
    smart_pointer& operator= (const smart_pointer& anotherSP); 

    // dereferencing operator
    T& operator* () const 
    {
        return *(m_pRawPointer);
    }

    // member selection operator
    T* operator-> () const 
    {
        return m_pRawPointer;
    }
};