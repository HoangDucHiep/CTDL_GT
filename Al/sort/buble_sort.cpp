#include <bits/stdc++.h>
using namespace std;

template <class T, class K = less<T>>
void bubble_sort(T* L, T* R, K cmp = less<T>())
{
    bool swapped;
    for(T i = 0; i < R-L-1; i++)
    {
        swapped = false;
        for(T* j = L; j < R - i - 1; j++)
        {
            if(cmp(*(j + 1), *(j)))
            {
                swap(*j, *(j + 1));
                swapped = true;
            }
        }

        if(swapped == false)
            break;
    }
}


int main(){
    int n = 11;
    int a[n] = {5, 2, 4, 6, 7, 9, 8, 3, 1, -5, 0};
    bubble_sort(a, a + n);
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

}