// LISTING 13.2 - Postfix Increment Operator
// postfix operator: differs from prefix in return-type and input param
CDate operator ++ (int)
{
    // Store a copy of the current state, before incrementing day
    CDate mReturnDate (m_nDay, m_nMonth, m_nYear);

    IncrementDay ();

    // Return the state before increment was performed
    return mReturnDate;
}