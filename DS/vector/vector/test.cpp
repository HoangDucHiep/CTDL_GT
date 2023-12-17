#include <iostream>
#include "vector.h"
using namespace std;


int main()
{
    VECTOR<int> test(10, 6);
    VECTOR<int> sec(test.begin()+1, test.end());
    VECTOR<int>::iterator it = sec.begin();
    while(it != sec.end())
    {
        cout << *it << "";
        it++;
    }
}