#include <bits/stdc++.h>
using namespace std;

template<class T, class K = less<T>>
void insert_sort(T* L, T* R, K cmp = less<T>())
{
    T* i, *j, x;
    for(i = L + 1; i < R; i++)
    {
        x = *i;
        j= i - 1;
        while(j >= L && cmp(x, *j))
        {
            *(j+1) = *j;
            j--;
        }
        *(j+1) = x;
    }
}


int main(){
    int n = 11;
    int a[n] = {5, 2, 4, 6, 7, 9, 8, 3, 1, -5, 0};
    insert_sort(a, a + n, greater<int>());
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }


}