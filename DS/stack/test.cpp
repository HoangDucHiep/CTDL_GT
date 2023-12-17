#include <bits/stdc++.h>
#include "list_base.h"
using namespace std;

int main()
{
	Stack<string> S;
	for(auto x:{"ha","noi","mua","khai","giang"}) S.push(x);
	Stack<string> Z;
	Z=S;
	Z.top()="truong";
	while(not Z.empty())
	{
		cout<<Z.top()<<" ";
		Z.pop();
	}
}
