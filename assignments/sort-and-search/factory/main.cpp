#include <bits/stdc++.h>
#define MAX 1000000000
using namespace std;


void input (int &n, int &k, int * &a) {
    cin >> n >> k;

    a = new int [n];
    for (int i  = 0; i < n ; ++i) {
        cin >> a[i];
    }
}

bool tasks(int t, int * a, int n, int k) {
    int c = 0;
    for (int i = 0 ; i<n;++i) {
        c+=(t/a[i]);
        if (c>=k) return true;
    }
    return c>=k;
} 
int count (int n, int k, int *a) {
    int c = 0;
    
    int s = 1; int e = MAX;
    while (e - s > 1) {
        int mid = s + (e - s) / 2;
        if (tasks(mid, a, n, k)) {
            e = mid;
        } else {
            s = mid + 1;
        }
    }

    if (s > e) {
        return -1;
    } else if (e - s == 0) {
        return s;
    } else {
        /* 
            9 9
            8 9
        */
        if (!tasks(s, a, n, k)) {
            return e;
        } else {
            return s;
        }
    }
}

int main() {
    int n, k, *a;
    input(n,k,a);

    int c = count(n, k, a);

    cout << c;
    delete [] a;
    // ignore the last message
    cin.get();
    cout << endl;
    return 0;
}