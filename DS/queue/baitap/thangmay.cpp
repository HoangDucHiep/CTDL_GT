#include <bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, m, s, f;

    cin >> n >> k >> m >> s >> f;

    int went[n + 5] = {};

    queue<int> temp;

    temp.push(s);
    went[s] = 1;

    while(went[f] == 0 && !temp.empty())
    {
        int u = temp.front();
        temp.pop();

        for(auto v : {k, -m})
        {
            if((u+v >= 0 || u+v <= n) && went[u+v] == 0)
            {
                went[u+v] = went[u] + 1;
                temp.push(u+v);
            }
        }
    }

    cout << went[f] - 1;

}