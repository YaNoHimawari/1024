// LISTING 13.9 - Implementing <, <=, >, and >= Operators
#include <iostream>

class CDate
{
private:
    int m_nDay; // Range: 1 - 30 (lets assume all months have 30 days!)
    int m_nMonth; // Range: 1 - 12
    int m_nYear;

    void AddDays (int nDaysToAdd);
    void AddMonths (int nMonthsToAdd);
    void AddYears (int m_nYearsToAdd);

public:

    // Constructor that initializes the object to a day, month and year
    CDate (int nDay, int nMonth, int nYear)
        : m_nDay (nDay), m_nMonth (nMonth), m_nYear (nYear) {};

    void DisplayDate ()
    {
        cout << m_nDay << " / " << m_nMonth << " / " << m_nYear;
    }

    bool operator < (const CDate& mDateObj) const;
    bool operator <= (const CDate& mDateObj) const;

    bool operator > (const CDate& mDateObj) const;
    bool operator >= (const CDate& mDateObj) const;
};

CDate::operator int() const
{
    return ((m_nYear * 10000) + (m_nMonth * 100) + m_nDay);
}

bool CDate::operator < (const CDate& mDateObj) const
{
    return (this->operator int () < mDateObj.operator int ());
}

bool CDate::operator > (const CDate& mDateObj) const
{
    return (this->operator int () > mDateObj.operator int ());
}

bool CDate::operator <= (const CDate& mDateObj) const
{
    return (this->operator int () <= mDateObj.operator int ());
}

bool CDate::operator >= (const CDate& mDateObj) const
{
    return (this->operator int () >= mDateObj.operator int ());
}

// Pick the definition of other functions from listing 13.8

int main ()
{
    // Instantiate and initialize a date object to 25 May 2008
    CDate mDate1 (25, 6, 2008);
    CDate mDate2 (23, 5, 2009);
    CDate mDate3 (23, 5, 2009);

    cout << "mDate1 contains: ";
    mDate1.DisplayDate ();
    cout << endl;

    cout << "mDate2 contains: ";
    mDate2.DisplayDate ();
    cout << endl;

    cout << "mDate3 contains: ";
    mDate3.DisplayDate ();
    cout << endl;

    // Use the operator <
    cout << "mDate3 < mDate2 is: ";
    cout << ((mDate3 < mDate2) ? "true" : "false") << endl;

    // Use the operator <=
    cout << "mDate3 <= mDate2 is: ";
    cout << ((mDate3 <= mDate2) ? "true" : "false") << endl;

    // Use operator >=
    cout << "mDate3 >= mDate1 is: ";
    cout << ((mDate3 >= mDate1) ? "true" : "false") << endl;

    // Use operator >
    cout << "mDate1 > mDate3 is: ";
    cout << ((mDate1 > mDate3) ? "true" : "false") << endl;

    return 0;
}