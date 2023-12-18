#include <bits/stdc++.h>
using namespace std;


template <class T, class K = less<T>>
void merge_list(T* a, T* b, T *c, T*temp, K cmp = less<T>())
{
    T*i = a, *j = b, *k = temp;

    while(i < b && j < c)
    {
        if(cmp(*i, *j))
        {
            *k = *i;
            k++;
            i++;
        }
        else
        {
            *k = *j;
            k++;
            j++;
        }
    }
    while(i < b)
    {
        *k = *i;
        k++;
        i++;
    }
    while(j < c)
    {
        *k = *j;
        k++;
        j++;
    }

    for(i = a, k = temp; i < c; i++, k++)
    {
        *i = *k;
    }
}

template <class T, class K = less<T>>
void Msort(T* L, T* R, T* B, K cmp = less<T>())
{
    if(L >= R-1)
        return;
    T* M = L + (R-L)/2;
    Msort(L, M, B, cmp);
    Msort(M, R, B, cmp);
    merge_list(L, M, R, B, cmp);
}


template <class T, class K = less<T>>
void merge_sort(T* L, T* R, K cmp = less<T>())
{
    T *B = new T[R - L + 5];
    Msort(L, R, B, cmp);
    delete[] B;
}




int main(){
    int n = 11;
    int a[n] = {5, 2, 4, 6, 7, 9, 8, 3, 1, -5, 0};
    merge_sort(a, a + n, greater<int>());
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

}