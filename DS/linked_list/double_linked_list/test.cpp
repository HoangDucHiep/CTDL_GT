#include <iostream>
#include "double_linked_list.h"
using namespace std;

int main()
{
    LIST<int> test;

    for(int i : {1, 2, 3, 4, 5, 6, 6, 7, 7, 4, 634, 345314, 134})
    {
        test.push_back(i);
    }

    LIST<int> sec(test.begin(), test.end());

    cout << "\nLst: ";
    for(auto i = sec.begin(); i != sec.end(); ++i)
    {
        cout << *i << " ";
    }

    auto insertIt = sec.begin();
    sec.insert(insertIt, 5);
    cout << "\nLst: ";
    for(auto i = sec.begin(); i != sec.end(); ++i)
    {
        cout << *i << " ";
    }

    sec.erase(sec.begin()+1);
    cout << "\nLst: ";
    for(auto i = sec.begin(); i != sec.end(); ++i)
    {
        cout << *i << " ";
    }
}