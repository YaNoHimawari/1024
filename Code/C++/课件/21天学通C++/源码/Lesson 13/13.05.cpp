// LISTING 13.5 - Using Conversion Operators to Convert a CDate into an Integer
#include <iostream>

class CDate
{
private:
    int m_nDay; // Range: 1 - 30 (lets assume all months have 30 days!)
    int m_nMonth; // Range: 1 - 12
    int m_nYear;

public:

    // Constructor that initializes the object to a day, month and year
    CDate (int nDay, int nMonth, int nYear)
        : m_nDay (nDay), m_nMonth (nMonth), m_nYear (nYear) {};

    // Convert date object into an integer.
    operator int()
    {
        return ((m_nYear * 10000) + (m_nMonth * 100) + m_nDay);
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

    // Get the integer equivalent of the date
    int nDate = mDate;

    std::cout << "The integer equivalent of the date is: " << nDate;

    return 0;
}