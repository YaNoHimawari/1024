bool CMyArray::operator== (const CMyArray& dest) const
{
    bool bRet = false;
    if (dest.m_nNumElements == this->m_nNumElements)
    {
        for (int nIndex = 0; nIndex < m_nNumElements; ++ nIndex)
        {
            bRet = dest [nIndex] == m_pnInternalArray [nIndex];
            if (!bRet)
                break;
        }
    }
    return bRet;
}
bool CMyArray::operator< (const CMyArray& dest) const
{
    bool bRet = false;
    if (m_nNumElements < dest.m_nNumElements)
        bRet = true;
    else if (m_nNumElements > dest.m_nNumElements)
        bRet = false;
    else // equal lengths
    {
        int nSumArrayContents = 0;
        int nSumDestArrayContents = 0;
        for (int nIndex = 0; nIndex < m_nNumElements; ++ nIndex)
        {
            nSumArrayContents += m_pnInternalArray [nIndex];
            nSumDestArrayContents += dest.m_pnInternalArray [nIndex];
        }
        bRet = (nSumArrayContents < nSumDestArrayContents);
    }
    return bRet;
}