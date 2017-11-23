// LISTING 13.6 - Calendar Class Featuring the Binary Addition Operator
#include <iostream>

class CDate
{
private:
    int m_nDay; // Range: 1 - 30 (lets assume all months have 30 days!)
    int m_nMonth; // Range: 1 - 12
    int m_nYear;

    void AddDays (int nDaysToAdd)
    {
        m_nDay += nDaysToAdd;

        if (m_nDay > 30)
        {
            AddMonths (m_nDay / 30);

            m_nDay %= 30; // rollover 30th -> 1st
        }
    }

    void AddMonths (int nMonthsToAdd)
    {
        m_nMonth += nMonthsToAdd;

        if (m_nMonth > 12)
        {
            AddYears (m_nMonth / 12);

            m_nMonth %= 12; // rollover dec -> jan
        }
    }

    void AddYears (int m_nYearsToAdd)
    {
        m_nYear += m_nYearsToAdd;
    }

public:

    // Constructor that initializes the object to a day, month and year
    CDate (int nDay, int nMonth, int nYear)
        : m_nDay (nDay), m_nMonth (nMonth), m_nYear (nYear) {};

    CDate operator + (int nDaysToAdd)
    {
        CDate newDate (m_nDay, m_nMonth, m_nYear);
        newDate.AddDays (nDaysToAdd);

        return newDate;
    }

    void DisplayDate ()
    {
        std::cout << m_nDay << " / " << m_nMonth << " / " << m_nYear;
    }
};

int main ()
{
    // Instantiate and initialize a date object to 25 May 2008
    CDate mDate (25, 6, 2008);

    std::cout << "The date object is initialized to: ";

    // Display initial date
    mDate.DisplayDate ();
    std::cout << std::endl;

    std::cout << "Date after adding 10 days is: ";

    // Adding 10 (days)...
    CDate datePlus10 (mDate + 10);

    datePlus10.DisplayDate ();

    return 0;
}