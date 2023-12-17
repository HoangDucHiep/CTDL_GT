#include <bits/stdc++.h>
using namespace std;
#include "./list_based/queue.h"

int main(){
    Queue<int> test(10, 4);

    cout << "Size: " << test.size() << endl;
    cout << "Elements: ";
    while(!test.empty())
    {
        cout << test.front() << " ";
        test.pop();
    }
    cout << "\n";

    for(int c : {1, 2, 3, 4, 5, 6, 7, 8})
    {
        test.push(c);
    }

    test.front() = 100;
    test.back() = 99;

    cout << "After changed: ";
    while(!test.empty())
    {
        cout << test.front() << " ";
        test.pop();
    }






}
