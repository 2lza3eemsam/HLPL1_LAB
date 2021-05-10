#include "std_lib_facilities.h"

//Question 1 (Defining a global vector<int> gv and initialize it with ten ints, 1, 2, 4, 8, 16, etc.)
vector<int> gv = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

//Question 2 (Defining a function f() taking a vector<int> argument)
void f(vector<int>& v)
{
//Question 3
//part a: (Define a local vector<int> lv with the same number of elements as the argument vector.)
	vector<int> lv(10);

//part b: (Copy the values from gv into lv.)
	lv = v;

//part c: (Print out the elements of lv.)
	for (int i : lv)
		cout << i << ", ";
	cout << endl;

//part d: (Define a local vector<int> lv2; initialize it to be a copy of the argument vector.)
	vector<int> lv2 = v;

//part e: (Print out the elements of lv2.)
	for(int i : lv2)
		cout << i << ", ";
	cout << endl;
}
//factorial equation
int fac(int n)
{
	return n > 1 ? n*(fac(n - 1)) : 1;
}

//Question 4
int main()
{
//part a: (Call f() with gv as its argument.)
	f(gv);

//part b: (Define a vector<int> vv, and initialize it with the first ten factorial values (1, 2*1, 3*2*1, 4*3*2*1, etc.))
	vector<int> vv = { 1, fac(2), fac(3), fac(4), fac(5), fac(6), fac(7), fac(8), fac(9), fac(10) };

//part c: (Call f() with vv as its argument.)
	f(vv);

	return 0;
}
