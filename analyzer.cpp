#include <iostream>
#include <vector>
#include <string>
#include "stringdata.h"
#define ll long long

using namespace std;

int linear_search(const vector<string> container, const string element) //linear search function foes through each element in tuple to check whatever element exists
{
    for (int i = 0; i < container.size(); ++i) //iterator loops through all elements in range 0 to len(container) and checks if element is present, if yes returns index, and if not present returns  -1
    {
        if (container[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int binary_search(const vector<string> container,  string element) // binary search function to find whether an element exists in a dataset
{
    int r = container.size() - 1; // defines right end index of subset being searched on
    int l = 0;  // defines left end index of subset being searched on


    while (l <= r) // makes smaller and smaller subsets finding the element until break case where left end of subset greater than right end(impossible)
    {
        int mid = (l + r) / 2; // defines the middle index of the subset being searched on
        if (container[mid] == element) // checks whether it is the element being searched
        {
            return mid;
        } else if (container[mid] < element) // if element is greater than middle element then the subset should be shifted to the right of middle index i.e left end needs to be shifted to right of mid
        {
            l = mid + 1;
        } else // if element is smaller than middle element then the subset should be shifted to the left of middle index i.e right end needs to be shifted to left of mid
        {
            r = mid - 1;
        }
    }
    return -1; // if break case is reached then element is not found in subset and returns -1
}

int main()
{
    vector<string> strings = getStringData(); // declares a vector of strings each containing a 5 lettered string ordered alphabetically so bin search works

    auto c1 = std::chrono::system_clock::now();
    int lin_algo1 = linear_search(strings, "not_here");
    auto c2=std::chrono::system_clock::now();

    auto timeDif = c2-c1;


    cout << "Time taken for linear search for -not_here- is: " << timeDif.count() << endl;
    cout << "Result on linear search is index: " << lin_algo1 << endl;
    cout << endl;

    c1 = std::chrono::system_clock::now();
    int bin_algo1 = binary_search(strings, "not_here");
    c2 = std::chrono::system_clock::now();
    timeDif = c2-c1;


    cout << "Time taken for binary search for -not_here- is: " << timeDif.count()<< endl;
    cout << "Result on binary search is index: " << bin_algo1 << endl;
    cout << endl;

    c1 = std::chrono::system_clock::now();
    lin_algo1 = linear_search(strings, "mzzzz");
    c2 = std::chrono::system_clock::now();
    timeDif = c2-c1;

    cout << "Time taken for linear search for -mzzzz- is: " << timeDif.count() << endl;
    cout << "Result on linear search is index: " << lin_algo1 << endl;
    cout << endl;

    c1 = std::chrono::system_clock::now();
    bin_algo1 = binary_search(strings, "mzzzz");
    c2 = std::chrono::system_clock::now();
    timeDif = c2-c1;

    cout << "Time taken for binary search for -mzzzz- is: " << timeDif.count() << endl;
    cout << "Result on binary search is index: " << bin_algo1 << endl;
    cout << endl;

    c1 = std::chrono::system_clock::now();
    lin_algo1 = linear_search(strings, "aaaaa");
    c2 = std::chrono::system_clock::now();
    timeDif = c2-c1;

    cout << "Time taken for linear search for -aaaaa- is: " << timeDif.count() << endl;
    cout << "Result on linear search is index: " << lin_algo1 << endl;
    cout << endl;

    c1 = std::chrono::system_clock::now();
    bin_algo1 = binary_search(strings, "aaaaa");
    c2 = std::chrono::system_clock::now();
    timeDif = c2-c1;

    cout << "Time taken for binary search for -aaaaa- is: " << timeDif.count() << endl;
    cout << "Result on binary search is index: " << bin_algo1 << endl;
    cout << endl;





    return 0;
}
