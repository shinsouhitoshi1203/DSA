#include <bits/stdc++.h>
using namespace std;


void input(int &n, int * &a, int &k) {
    cin >> n >> k;
    a = new int [n];
    for (int i=0;i<n;++i) {
        cin >> a[i];
    }
}
void output(int n, int * a) {
    for (int i = 0; i<n;++i) {
        cout << a[i] << " ";
    }
}


/* 

5 9
2 7 4 5 3
2 3 4 5 7
3+2 = 5
*/

int count (int * &a, int n, int k) {
    int C = 0;
    int i = 0;
    while (a[i] + a[i+1] < k && i+1 < n) {
        auto pos = lower_bound(a+(i+1),a+(n),k-a[i]); // a[f] = k-a[i] ==> f-1; 
        int posL = pos - a - 1;
        // cout << i << " " << posL ;
        C = C + (posL - (i+1)  + 1);
        i++ ;
    }
    return C;
}


int main() {
    int n, * a, k;
    input(n, a, k);
    sort(a, a+n);
    output(n,a);
    cout << endl;
    int c = count (a, n, k);
    cout << c;

    delete [] a;
    // ignore the last message
    cin.get();
    cout << endl;
    return 0;
}