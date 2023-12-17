#include <bits/stdc++.h>
using namespace std;

map<char, int> nguyento = {{'C', 12}, {'H', 1}, {'O', 16}, {'(', 0}};

int khoiluong(string str)
{
    stack<int> temp;
    int sum;
    for(char c : str)
    {
        if('0' <= c && c <= '9')
        {
            temp.top() *= (c-'0');
        }
        else if(c == ')')
        {
            sum = 0;
            while(temp.size() && (temp.top() != 0))
            {
                sum += temp.top();
                temp.pop();
            }
            temp.pop();
            temp.push(sum);
        }
        else
            temp.push(nguyento[c]);
    }
    sum = 0;
    while(temp.size())
    {
        sum += temp.top();
        temp.pop();
    }
    return sum;
}


int main(){
    string phan;
    cin >> phan;
    cout << khoiluong(phan);
}