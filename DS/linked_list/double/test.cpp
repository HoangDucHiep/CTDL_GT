#include <bits/stdc++.h>
#include "double_linked_list.h"
using namespace std;


int main(){
    List<int> test;

    for(auto num : {1, 4, 5, 6, 2})
    {
        test.push_back(num);
    }

    //test.pop_back();
    //test.pop_front();
    //test.sort();

    for(List<int>::iterator i = test.begin(); i != test.end(); i++)
    {
        cout << *i << " ";
    }

    List<int>::iterator it = test.begin() + 4;
    test.insert(it, 100);

    cout << "\n";
    for(List<int>::iterator i = test.begin(); i != test.end(); i++)
    {
        cout << *i << " ";
    }
    it = test.begin() + 2;
    test.erase(it);
    cout << "\n";
    for(List<int>::iterator i = test.begin(); i != test.end(); i++)
    {
        cout << *i << " ";
    }
}