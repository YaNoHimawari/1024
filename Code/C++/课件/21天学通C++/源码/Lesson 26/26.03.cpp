// LISTING 26.3 - A Sample Destructive-Copy Type Smart Pointer
template <typename T>
class destructivecopy_pointer
{
private:
    T* m_pObject;
public:
    // other members, constructors, destructors, operators* and ->, etc...

    // copy constructor
    destructivecopy_pointer(destructivecopy_pointer& source)
    {
        // Take ownership on copy
        m_pObject = source.m_pObject;

        // destroy source
        source.m_pObject = 0;
    }

    // assignment operator
    destructivecopy_pointer& operator= (destructivecopy_pointer& rhs)
    {
        if (m_pObject != source.m_pObject)
        {
            delete m_pObject;
            m_pObject = source.m_pObject;
            source.m_pObject = 0;
        }
    }
};