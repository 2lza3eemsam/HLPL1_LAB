#include "std_lib_facilities.h"
int main ()
{
	try
	{
//Question 1 (Allocate an int, initialize it to 7 and assign its addres to a variable p1.)
		int var = 7;
		int* p1 = &var;

//Question 2 (Print out the value of p1 and the int it points to)
		std::cout <<"p1 (address of var) = " << p1
			      <<"\nvar (value of var) = "<< *p1 <<'\n';

//Question 3 (Allocate an array of seven ints, initialized to 1, 2, 4, 8, etc. Assign its address to p2.)
		const int arr_size =7;
		int arr[arr_size];

		for (size_t i = 0; i < arr_size; ++i) arr[i] = std::pow(2., (double)i);

		int *p2 = arr;

//Question 4 (Print out the value of p2 and the array it points to)
		std::cout << "p2 (address of array's first element) " << p2 <<'\n';
		std::cout << "arr (address of array's first element) " << arr <<'\n';

//Question 5 (Declare an int *p3 and initialize it to p2)
		int *p3 = p2;

//Question 6 (Assign p1 to p2 // p2 points to: var)
		p2 = p1;

//Question 7 (Assign p3 to p2 // p2 points to: arr (as p3 was initialized to point to: arr via: p2 earlier value))
		p2 = p3;

//Question 8 (Print the values of p1 and p2 and the values of what they point to.)
		std::cout <<"p1 "<< p1 <<" *p1 "<< *p1 <<'\n'; // var = 7
		std::cout <<"p2 "<< p2 <<" *p2 "<< *p2 <<'\n'; // first elements of arr[0] = 2^0 = 1

//Question 9 (Deallocate all the memory on the free store: nothing)

//Question 10 (Allocate an array of 10 ints, initialize them to 1, 2, 4, 8, etc, and assign its address to a variable p1)
		const int arr_size1 = 10;
		int arr10[arr_size1];
		for (size_t i = 0; i < arr_size1; ++i) arr10[i] = std::pow(2., (double) i);

		p1 = arr10;

//Question 11 (Allocate an array of 20 ints, initialize them to 1, 2, 4, 8, etc, and assign its address to a variable p2)
		const int arr_size2 = 20;
		int arr20[arr_size2];
		for (size_t i = 0; i < arr_size2; ++i) arr20[i] = std::pow(2., (double) i);

		p2 = arr20;

//Question 12 (Copy the values pointed to by p1 into the array pointer to by p2.)
		for (size_t i = 0; i < arr_size1; ++i) p2[i] = p1[i];

		for (size_t i = 0; i < arr_size2; ++i) std::cout << p2[i] <<'\n'; //print

//Question 13 ( Repeat part 10 to 12 using vectors)
		std::cout <<"\nVector drill\n" <<'\n';
		vector<int>v10;
		for (auto i = 0; i < 10; ++i) v10.push_back(std::pow(2., (double)i));
		vector<int>* vptr = &v10;

		vector<int>v10b;
		vector<int>* vptrb = &v10b;

		for (auto i = 0; i < v10.size(); ++i) *vptrb = *vptr;

		for (auto i = 0; i < v10b.size(); ++i) std::cout << v10b[i] <<'\n';//print
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		getchar();
	}
	getchar();
}
