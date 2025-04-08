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

// Begin Sort

void sort(int n, int * &a) {
    for (int i = 0; i<n-1; ++i) {
        for (int j = i+1; j<n; ++j) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}


// End Sort




int main() {
    int n, * a;
    input(n, a);

    sort(n, a);

    output(n, a);
    
    // ignore the last message
    cin.get();
    cout << endl;
    return 0;
}