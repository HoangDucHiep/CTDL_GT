#include <bits/stdc++.h>
using namespace std;

#include "../array_based/queue.h"

void solve(int n)
{
    Queue<pair<string, int>> list;
    for(auto c : {"dangdungcntt", "tienquanutc", "quang123", "maianh", "nguyenminhduc2820"})
    {
        list.push(pair(c, 1));
    }

    while(n > list.front().second)
    { 
        list.push(list.front());
        list.back().second *= 2;
        n-=list.front().second;
        list.pop();
    }
    cout << list.front().first << endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testnum, n;
    cin >> testnum;
    while(testnum--)
    {
        cin >> n;
        solve(n);
    }
    return 0;
}
