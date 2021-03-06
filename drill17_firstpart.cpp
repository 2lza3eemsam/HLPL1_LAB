#include <iostream>
#include <vector>

void print_arr10 (std::ostream& os, int *a);
void print_array (std::ostream &os, int *arr, int size);
void print_vector (std::ostream& os, const std::vector<int>& v);

int main ()
{
	try
	{
//Question 1 (Allocate an array of 10 ints on free store using new)
		int *arr = new int[10];

//Question 2 (Print the values of the above 10 ints to cout)
		for (size_t i = 0; i < 10; ++i) std::cout << arr[i] << '\n';

//Question 3 (Deallocate the array using delete [])
	    delete [] arr;

//Question 4 (Write a function void print_arr10 (ostream& os, int *a))
		print_arr10(std::cout, arr); //Accessing deallocated memory

//Question 5 (Allocate and array of 10 ints on free store and initialize its values to 100, 101, etc.; Print the result.)
		int * arr1 = new int[10];

		int init = 100; //initialize this part
	    for (size_t i = 0; i < 10; ++i) arr1[i] = init + i;

		print_arr10 (std::cout, arr1); //print

		delete [] arr1;

//Question 6 (Allocate an array of 11 ints on the free store, initialize its values to 100, 101, etc.; and print its values)
		int * arr11 = new int[11];
		int init1 = 100;
		for (size_t i = 0; i < 11; ++i) arr[i] = init1 + i;

		for (size_t i = 0; i < 11; ++i) std::cout << arr[i] << '\n'; //print the array

//Question 7 (write a function void print_array (std::ostream &os, int *arr, int size))
		print_array(std::cout, arr11, 11);

		delete [] arr11;

//Question 8 (Allocate an array of 20 ints on the free store, initialized to 100, 101, etc.)
		int *arr20 = new int[20];
		int init2 = 100; //initialize this part
		for (size_t i = 0; i < 20; ++i) arr20[i] = init2 + i;
		// print
		print_array(std::cout, arr20, 20);
		// free memory
		delete [] arr20;

//Question 9 (Check that all no longer used resources are free)
		// every new is matched with respective delete

//Question 10 (Repeat 5, 6 and 8 with vectors and define: void print_vector(std::ostream& os, const std::vector<int>& v))
		std::cout << "\nDrill 10\n" << '\n';
		std::vector<int> v10;
		size_t vsize = 10;
		int initv = 100;
		for (auto i = 0; i < vsize; ++i) v10.push_back(initv + i);
		print_vector(std::cout, v10);


		std::vector<int> v11;
		vsize = 11;
		for (auto i = 0; i < vsize; ++i) v11.push_back(initv + i);
		print_vector(std::cout, v11);


		std::vector<int> v20;
		vsize = 20;
		for (auto i = 0; i < vsize; ++i) v20.push_back(initv + i);
		print_vector(std::cout, v20);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		getchar();
	}
	getchar();
}
//---------------------------------------------------------------------------

void print_arr10 (std::ostream& os, int *a)
{
	for (size_t i = 0; i < 10; ++i) os << a[i] << '\n';
}

//---------------------------------------------------------------------------

void print_array (std::ostream &os, int *arr, int size)
{
	for (size_t i = 0; i < size; ++i) os << arr[i] <<'\n';
}

//---------------------------------------------------------------------------

void print_vector (std::ostream& os, const std::vector<int>& v)
{
	for (auto it = v.begin(); it != v.end(); ++it) os << *it << '\n';
}
