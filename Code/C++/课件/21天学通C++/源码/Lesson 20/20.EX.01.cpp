struct FindContactGivenNumber
{
    bool operator () (const CContactItem& lsh, const CContactItem& rsh)
        const
    {
        return (lsh.strPhoneNumber < rsh.strPhoneNumber);
    }
};