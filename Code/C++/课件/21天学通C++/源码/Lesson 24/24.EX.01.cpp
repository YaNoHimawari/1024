class CPerson
{
public:
    int m_nAge;
    bool m_bIsFemale;
    bool operator< (const CPerson& anotherPerson) const
    {
        bool bRet = false;
        if (m_nAge > anotherPerson.m_nAge)
            bRet = true;
        else if (m_bIsFemale && anotherPerson.m_bIsFemale)
            bRet = true;
        return bRet;
    }
};