#include <bits/stdc++.h>
#include "vector.h"
using namespace std;


int main()
{
    Vector<int> V(3, 1);
	V.resize(7, 6);
	for (int i = 0; i < V.size(); i++)
		V[i] = i + V[i] * 2;
	cout << "\nV: ";
	for (Vector<int>::iterator it = V.begin(); it != V.end(); it++)
		cout << *it << " ";
	cout << "\nV: ";
	for (auto v : V)
		cout << v << " ";
	auto it1 = V.begin() + 4;
	V.insert(it1, 0);
	cout << "\nV: ";
	for (auto v : V)
		cout << v << " ";
	cout << "\nV duyet nguoc : ";
	for (Vector<int>::reverse_iterator it2 = V.r_begin(); it2 != V.r_end(); it2++)
		cout << *it2 << " ";

}
