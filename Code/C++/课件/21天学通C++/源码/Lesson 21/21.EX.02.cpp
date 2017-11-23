struct fPredicate
{
    bool operator< (const wordProperty& lsh, const wordProperty& rsh) const
    {
        return (lsh.strWord < rsh. strWord);
    }
};