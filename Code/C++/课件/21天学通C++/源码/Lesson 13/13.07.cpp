// LISTING 13.7 - Using the Addition Assignment Operator to Increment Days in the Calendar Given an Integer Input
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

    // The addition-assignment operator    void operator += (int nDaysToAdd)
    {
        AddDays (nDaysToAdd);
    }

    void DisplayDate ();
};