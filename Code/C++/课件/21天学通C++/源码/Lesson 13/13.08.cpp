// LISTING 13.8 Overloading Equality and Inequality Operators
#include <iostream>
using namespace std;

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

    // integer conversion operator
    operator int();

    // equality operator that helps with: if (mDate1 == mDate2)...
    bool operator == (const CDate& mDateObj);

    // overloaded equality operator that helps with: if (mDate == nInteger)
    bool operator == (int nDateNumber);

    // inequality operator
    bool operator != (const CDate& mDateObj);

    // overloaded inequality operator for integer types
    bool operator != (int nDateNumber);
};

CDate::operator int()
{
    return ((m_nYear * 10000) + (m_nMonth * 100) + m_nDay);
}

// equality operator that helps with if (mDate1 == mDate2)...
bool CDate::operator == (const CDate& mDateObj)
{
    return ( (mDateObj.m_nYear == m_nYear)
        && (mDateObj.m_nMonth == m_nMonth)
        && (mDateObj.m_nDay == m_nDay) );
}

bool CDate::operator == (int nDateNumber)
{
    return nDateNumber == (int)*this;
}

// inequality operator
bool CDate::operator != (const CDate& mDateObj)
{
    return !(this->operator== (mDateObj));
}

bool CDate::operator != (int nDateNumber)
{
    return !(this->operator == (nDateNumber));
}

void CDate::AddDays (int nDaysToAdd)
{
    m_nDay += nDaysToAdd;

    if (m_nDay > 30)
    {
        AddMonths (m_nDay / 30);

        m_nDay %= 30; // rollover 30th -> 1st
    }
}
void CDate::AddMonths (int nMonthsToAdd)
{
    m_nMonth += nMonthsToAdd;

    if (m_nMonth > 12)
    {
        AddYears (m_nMonth / 12);

        m_nMonth %= 12; // rollover dec -> jan
    }
}
void CDate::AddYears (int m_nYearsToAdd)
{
    m_nYear += m_nYearsToAdd;
}

int main ()
{
    // Instantiate and initialize a date object to 25 May 2008
    CDate mDate1 (25, 6, 2008);

    cout << "mDate1 contains: ";

    // Display initial date
    mDate1.DisplayDate ();
    cout << endl;

    CDate mDate2 (23, 5, 2009);
    cout << "mDate2 contains: ";
    mDate2.DisplayDate ();
    cout << endl;

    // Use the inequality operator
    if (mDate2 != mDate1)
        cout << "The two dates are not equal... As expected!" << endl;

    CDate mDate3 (23, 5, 2009);
    cout << "mDate3 contains: ";
    mDate3.DisplayDate ();
    cout << endl;

    // Use the inequality operator
    if (mDate3 == mDate2)
        cout << "mDate3 and mDate2 are evaluated as equals" << endl;

    // Get the integer equivalent of mDate3 using operator int()
    int nIntegerDate3 = mDate3;

    cout<< "The integer equivalent of mDate3 is:"<< nIntegerDate3<< endl;

    // Use the overloaded version of operator== (for int comparison)
    if (mDate3 == nIntegerDate3)
        cout << "The integer and mDate3 are equivalent" << endl;

    // Use the overloaded version of operator != that accepts integers
    if (mDate1 != nIntegerDate3)
        cout << "The mDate1 is inequal to mDate3";

    return 0;
}