#include <bits/stdc++.h>
using namespace std;

template <class T, class K = less<T>>
T* Partition(T *L, T *R, K cmp = less<T>())
{
    T* pivot = L;

    T* i = L;

    for(T* j = L+1; j < R; j++)
    {
        if(cmp(*j, *pivot))
        {
            i++;
            swap(*i, *j);
        }
    }
    swap(*L, *i);
    return i;
}

template <class T, class K = less<T>>
void quick_sort(T *L, T *R, K cmp = less<T>())
{
    if(L >= R-1)
        return;
    swap(*L, *(L + (R-L)/2));
    T* par = Partition(L, R, cmp);
    quick_sort(L, par, cmp);
    quick_sort(par, R, cmp);
}


int main(){
    int n = 11;
    int a[n] = {5, 2, 4, 6, 7, 9, 8, 3, 1, -5, 0};
    quick_sort(a, a + n);
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

}