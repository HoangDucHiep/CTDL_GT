#include <bits/stdc++.h>
using namespace std;

#include "../array_based/queue.h"



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, *arr;
    cin >> n;
    arr = new int[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr+n, greater<int>());
    int res = 0;

    Queue<int> trian;

    for(int i = 0; i < n; i++)
    {
        while(trian.size() > 1 && arr[i]+trian.back() <= trian.front())
        {
            trian.pop();
        }
        trian.push(arr[i]);

        if(res < trian.size())
        {
            res = trian.size();
        }
    }

    if(res >= 3)
        cout << res;
    else
        cout << "Khong the tao ra day thoa man";
    return 0;
}



