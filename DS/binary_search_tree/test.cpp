#include <bits/stdc++.h>
using namespace std;

#include "binary_search_tree.h"

int main(){
    binary_search_tree<int> test;

    for(int i : {3, 5, 1, 6, 8, 9})
    {
        test.insert(i);
    }

    test.inorder();

    cout << "\nAfter remove 6: ";
    test.remove(6);
    test.inorder();

    cout << "\nnew tree: ";
    binary_search_tree<int> test2; //(test);  //dung thu constructor
    test2 = test;
    test2.inorder();

    cout << "\nNumber of nodes: " << test2.nodes();
    cout << "\nNumber of leave: " << test2.leaves();
    cout << "\nNumber of height: " << test2.height();
    cout << "\nSum: " << test2.sum();


    cout << "\ninorder: "; test.inorder();
    cout << "\npreorder: "; test.preorder();
    cout << "\npostorder: "; test.postorder();
    
}