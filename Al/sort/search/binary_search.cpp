#include <bits/stdc++.h>
using namespace std;

int binary_search(int *a, int L, int R, int x)
{
    if(L > R) return -1;
    int M = (R+L)/2;
    if(a[M] == x) return M;
    if(x > a[M]) return binary_search(a, M+1, R, x);
    else return binary_search(a, L, M-1, x);
}
//Danh gia do phuc tap T(n)=T(n/2)+c=T(n/4)+2c=T(n/8)+3c=...=T(n/2^k)+kc 
//= T(1)+clog(n) = O(logn)


int main(){
    int n = 11;
    int a[n] = {1, 2, 3, 5, 6, 7, 8, 9, 10, 11};
    int searched = binary_search(a, 0, 10, 5);
    if(searched == -1)
        cout << "Khong tim thay!!";
    else
        cout << searched << endl;

}