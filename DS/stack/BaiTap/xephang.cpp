#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack<pair<int, int>> S;
    S.push(pair(INT_MAX, 0));

    int res = 0;
    int n;
    cin >> n;
    int x;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        while(S.top().first < x)
        {
            res+=S.top().second;
            S.pop();
        }
        if(x == S.top().first)
        {
            if(S.size() > 2) res++;
            res += S.top().second;
            S.top().second++;
        }
        else
        {
            if(S.size() > 1) res++;
            S.push(pair(x, 1));
        }
    }

    cout << res << "\n";
}