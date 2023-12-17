#include <iostream>
#include "single_linked_list.h"
using namespace std;

void reverse_print(LIST<int>::iterator it)
{
    if (it != NULL)
    {
        reverse_print(it+1);  // Use pre-increment here
        cout << *it << " ";
    }
}


int main()
{
    LIST<int> test;

    for(int i : {1, 2, 3, 4, 5, 6, 6, 7, 7, 4, 634, 345314, 134})
    {
        test.push_back(i);
    }

    cout << "\nLst: ";

    reverse_print(test.begin());


}