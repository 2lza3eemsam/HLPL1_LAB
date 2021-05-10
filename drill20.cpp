#include "std_lib_facilities.h"

//Question 6 copying function operation
template<typename Iteration1, typename Iteration2>
Iteration2 my_copy(Iteration1 f1, Iteration1 e1, Iteration2 f2)
{
// f1 is the first
// e1 is the last
// f2 is the result
    while (f1 != e1)
    {
        *f2 = *f1;
        ++f1;
        ++f2;
    }

    return f2;
}

int main()
{

//Question 1 (defining the array with the ten elements that were given in the book)
array<int, 10> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

//Question 2 (defining the vector with the ten elements)
vector<int> v {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

//Question 3 (defining the list with the ten elements)
list<int> l {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };


//Question 4 (Define a second array, vector, and list, each initialized as a copy of the first array, vector, and list, respectively)

    array<int, 10> a2 = a;

    vector<int> v2 = v;

    list<int> l2 = l;


//Question 5 (Increase the value of each element in the array by 2; increase the value of each element in the vector by 3; increase the value of each element in the list by 5.)

    for (int& i : a) //(we increase value of array of each element by 2)
        i += 2;

    for (int& i : v) //(we increase value of vector of each element by 3)
        i += 3;

    for (int& i : l) //we increase value of list of each element by 5)
        i += 5;

// Question 7 (Use your copy() to copy the array into the vector and to copy the list into the array.)

    my_copy(a.begin(), a.end(), v2.begin());                    //we use the copy function to copy from array to vector
    if (a[0] != v2[0])                                          //check if it copies or not so it takes the first element of array and vector and if they are not the same it brings up error
        std::cout << "ERROR: array and vector are not the same!" << endl;

        my_copy(l.begin(), l.end(), a2.begin());                //we use the copy function to copy from list to array
    if(*(l.begin()) != a2[0])                                   //check if it copies or not so it takes the first element of list and array and if they are not the same it brings up error
        std::cout << "ERROR: list and array are not the same!" << endl;


//Question 8 (finding if the element exists in the list and if so where it's position)

    auto v_result = find(begin(v), end(v), 3); //using find in vector
    if (v_result != end(v))
        cout << "Found Element 3 in the vector and it's position is : " << distance(v.begin(), v_result) << endl; // I used distance to find the index of the number
    else
        cout << "Element 3 is Not Found in the vector" << endl;

    auto l_result = find(begin(l), end(l), 27); //using find in list
    if (l_result != end(l))
        cout << "Found Element 27 in the list and it's position is :  " << distance(l.begin(), l_result) << endl; // I used the same distance method to find the index of the number
    else
        cout << "Couldn't Find Element 27 in The List" << endl;
return 0;
}
