#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    int sum = 0;

    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a+n, greater<int>());

    queue<int> temp;

    for(int i = 0; i < n; i++)
    {
        temp.push(a[i]);
        if(temp.front() >= k+a[i])
            temp.pop();
        else sum += a[i];
    }

    cout << temp.size() << " " << sum;



}