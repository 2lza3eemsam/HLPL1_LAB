#include "std_lib_facilities.h"

struct Date {
    int y;      // year
    int m;      // month in year
    int d;      // day of month
};

void init_day(Date& dd, int y, int m, int d)
// checking for error date input
{
    if (d < 1 || d > 31) error("init_day: Invalid day");
    if (m < 1 || m > 12) error("init_day: Invalid month");

    dd.y = y;
    dd.m = m;
    dd.d = d;
}

void add_day(Date& dd, int n)
// Function to add or subtract the date.
{
    dd.d += n;

    //checking for over number and if so it would add or subtract based on if it is day or month
    if (dd.d > 31) { ++dd.m; dd.d -= 31; }     // Day plus = +1 month
    if (dd.d < 1)  { --dd.m; dd.d += 31; }     // Day minus = -1 month
    if (dd.m > 12) { ++dd.y; dd.m -= 12; }     // Month plus = +1 year
    if (dd.m < 1)  { --dd.y; dd.m += 12; }     // Month minus = -1 year
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.y
              << ',' << d.m
              << ',' << d.d << ')';
}

int main()
try
{
    Date today;
    init_day(today, 1978, 6, 25);

    Date tomorrow{today};
    add_day(tomorrow, 1);

    cout << "Today: " << today << '\n';
    cout << "Tomorrow: " << tomorrow << '\n';

                                                            // Check add_day() function concerning the year and month
  //Date test;
                                                            // year add and subtract check
  // init_day(test, 2021, 12, 31);
  // add_day(test, 6);   // 2022 January 6th
  // cout << "January the 6th 2022? " << test << '\n';
  // add_day(test, -6);  // 2021 December 31st again
  // cout << "December the 31st 2021? " << test << '\n';
                                                             // month month add and subtract check
  // init_day(test, 2021, 2, 5);
  // add_day(test, -7);   // 2021 January 29th
  // cout << "January the 29th 2021? " << test << '\n';
  // add_day(test, 7);  // 2021 February 5th again
  // cout << "February the 5th 2021? " << test << '\n';

                                                             // Invalid date check
    // Date today_e;
    // init_day(today_e, 2021, 13, -5);

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
