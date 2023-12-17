#include <iostream>
#include "vector.h"

using namespace std;


int main()
{

    long long n, carry;
    cin >> n;

    VECTOR<int> LNum(1, 1);   //vector co 1 so 1


    for(int i = 2; i <= n; i++)
    {
        carry = 0;
        for(auto it = LNum.begin(); it != LNum.end(); it++)
        {
            *it *= i;
            *it += carry;
            if(*it >= 10)
            {
                carry = *it/10;
                *it %= 10;
            }
            else{
                carry = 0;
            }
        }
        if(carry != 0) LNum.push_back(carry);
    }

    for(auto it = LNum.rbegin(); it != LNum.rend(); it++)
    {
        cout << *it;
    }
}