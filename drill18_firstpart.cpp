#include "std_lib_facilities.h"

//Question 1 (Define a global int array of ten ints initialized to 1,2 ,4, 8, etc)
int ga[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

//Question 2 (Define a function f(), taking an int array argument and array size argument.)
void f(int a[], int n)
{
//Question 3
//part a: (local int array of ten ints)
	int la[10];

//part b: (copy the values from ga into la)
	for (int i = 0; i < n; ++i)
		la[i] = ga[i];

//part c: (print out the elements of la)
	for (int i = 0; i < n; ++i)
		cout << la[i] << ", ";
	cout << endl;

//part d: (define a pointer to int and initialized it with an array on free store with size)
	int *p = new int[n];
//part e: (copy the values of the argument array into the free-store array that's why we are using memcpy which is memory capacity)
	memcpy(p, a, n*sizeof(int));
//part f: (print out the elements of the free-store array)
	for (int i = 0; i < n; ++i)
		cout << p[i] << ", ";
	cout << endl;

//part g: (deallocate the free-store array)
	delete[] p;
}
//factorial equation
int fac(int n)
{
	return n > 1 ? n*(fac(n - 1)) : 1;
}


int main()
{
//Question 4
//part a: (Call f() with ga as its argument)
	f(ga, 10);

//part b: (Define an array aa with ten elements, and initialize it with the first ten factorial values)
	int aa[10] {1, fac(2), fac(3), fac(4), fac(5), fac(6), fac(7), fac(8), fac(9), fac(10) };

//part c: (Call f() with aa as its argument)
	f(aa, 10);

	return 0;
}
