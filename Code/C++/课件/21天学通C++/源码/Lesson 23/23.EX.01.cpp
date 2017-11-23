struct CaseInsensitiveCompare
{
    bool operator() (const string& str1, const string& str2) const
    {
        string str1Copy (str1), str2Copy (str2);
        transform (str1Copy.begin (),
            str1Copy.end(), str1Copy.begin (), tolower);
        transform (str2Copy.begin (),
            str2Copy.end(), str2Copy.begin (), tolower);
        return (str1Copy < str2Copy);
    }
};