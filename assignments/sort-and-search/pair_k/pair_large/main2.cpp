#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[11] = {1,3,4,4,4,4,5,10,20,30,999};

    int n = 10; int c; cin >> c;
    auto ptU = upper_bound(a, a+n, c); 

    auto ptL = lower_bound(a, a+n, c); 


    /* 

        upper_bound: tra ve con tro LON HON HAN k va la phan tu dau tien
    
        lower_bound: tra ve con tro LON HON HOAC BANG k va la phan tu dau tien

        OTHERWISE ==> 
    */

    if (ptU!=a+n) {
        int k = ptU - a;
        cout << k << " " <<  *ptU;
    }
    cout << endl;

    if (ptL!=a+n) {
        int k = ptL - a;
        cout << k << " " <<  *ptL;
    }
    
    // ignore the last message
    cin.get();
    cout << endl;
    return 0;
}