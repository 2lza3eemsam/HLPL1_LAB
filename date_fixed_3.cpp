#include "std_lib_facilities.h"

class Date {
    int y, m, d;                    // year, month, day
public:
    Date(int yy, int mm, int dd);   // check for valid date and initialize
    void add_day(int n);            // increase the Date by n days
    int month() const { return m; }
    int day() const { return d; }
    int year() const { return y; }
};

Date::Date(int yy, int mm, int dd)
// checking for error date input
{
    if (dd < 1 || dd > 31) error("init_day: Invalid day");
    if (mm < 1 || mm > 12) error("init_day: Invalid month");

    y = yy;
    m = mm;
    d = dd;
}

void Date::add_day(int n)
// Function to add or subtract the date.
{

    d += n;

    //checking for over number and if so it would add or subtract based on if it is day or month
    if (d > 31) { ++m; d -= 31; }     // Day plus = +1 month
    if (d < 1)  { --m; d += 31; }     // Day minus = -1 month
    if (m > 12) { ++y; m -= 12; }     // Month plus = +1 year
    if (m < 1)  { --y; m += 12; }     // Month minus = -1 year
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.year()
              << ',' << d.month()
              << ',' << d.day() << ')';
}

int main()
try
{
    Date today{1978, 6, 25};

    Date tomorrow{today};
    tomorrow.add_day(1);

    cout << "Today: " << today << '\n';
    cout << "Tomorrow: " << tomorrow << '\n';

                                                            // Check add_day() function concerning the year and month
   // Date test{2021, 12, 31};
                                                            // year add and subtract check
   // test.add_day(6);   // 2022 January 6th
   // cout << "January the 6th 2022? " << test << '\n';
   // test.add_day(-6);  // 2021 December 31st again
   // cout << "December the 31st 2021? " << test << '\n';
                                                             // month add and subtract check
   // test = Date{2021, 2, 5};
   // test.add_day(-7);   // 2021 January 29th
   // cout << "January the 29th 2021? " << test << '\n';
   // test.add_day(7);    // 2021 February 5th again
   // cout << "February the 5th 2021? " << test << '\n';
                                                             // Invalid date check
    // Invalid date
   // Date today_e{2021, 13, -5};

    return 0;
}
catch(exception& e)
{
    cerr << e.what() << '\n';
    return 1;
}
catch(...)
{
    cerr << "Unknown exception!!\n";
    return 2;
}
