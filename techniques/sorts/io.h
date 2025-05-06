#include <bits/stdc++.h>
using namespace std;
void input(int &n, int * &a) {
    cin >> n;
    a = new int [n];
    for (int i = 0; i<n; ++i) {
        cin >> a[i];
    }
}

void output(int n, int * a) {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}