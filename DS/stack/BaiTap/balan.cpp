#include <bits/stdc++.h>
using namespace std;

#include "../array_base.h"

map<char, int> OP = {{'+', 1}, {'-', 1}, {'/', 2}, {'*', 2}};
//su dung cho do uu tien cua phep toan

string polish_notation(string exp)
{
    Stack<char> op; // stack chua toan tu
    string res = "";    //bieu thuc hau to

    for(char c : exp)
    {
        if('0' <= c && c <= '9')       //neu c la chu so, cho vao chuoi
        {
            res += c;
        }
        else if(c == '(')   //neu c la (, push vao stack
        {
            op.push(c);
        }
        else if(c == ')') //neu c la ), pop tu stack vao res den khi gap (
        {
            while(op.top() != '(')
            {
                res += op.top();
                op.pop();
            }
            op.pop();   //pop ki tu (
        }
        else        //cac th con lai
        {
            while(op.size() && OP[c] <= OP[op.top()])   //pop cho den khi op van con toan tu
            {   //                                      //va c co do uu tien nho hon hoac bang top().            
                res += op.top();
                op.pop();
            }
            op.push(c);
        }
    }

    while(op.size())
    {
        res += op.top();
        op.pop();
    }

    return res;
}

int buff(int a, int b, char op)
{
    if(op == '+') return a + b;
    else if(op == '-') return a - b;
    else if(op == '*') return a * b;
    else return a / b;
}

int calcu(string polish_notation)
{
    Stack<int> temp;
    int a;
    for(char c : polish_notation)
    {
        if('0' <= c && c <= '9')
        {
            temp.push(c - '0');
        }
        else
        {
            a = temp.top();
            temp.pop();
            temp.top() = buff(temp.top(), a, c);  
        }
    }
    return temp.top();
}


int main(){
    string exp;
    cin >> exp;
    string polish = polish_notation(exp);
    cout << polish << "\n";
    cout << calcu(polish);
}