#include "std_lib_facilities.h"

void swap_v(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_r(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}


int main()
{
    int x = 7;
    int y = 9;

    cout << "x is now " << x << " and y is now " << y << '\n';

    const int cx = 7;
    const int cy = 9;

    cout << "cx is now " << cx << " and cy is now " << cy << '\n';

    double dx = 7;
    double dy = 9;

    cout << "dx is now " << dx << " and dy is now " << dy << '\n';

    return 0;
}
