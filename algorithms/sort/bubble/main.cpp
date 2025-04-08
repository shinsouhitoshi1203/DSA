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
    for (int i = 1; i<n; ++i) {
        int pivot = a[i];
        // Find the element thats equal or greater than the pivot
        auto x = lower_bound(a,a+i+1,pivot);

        int found = x - a;
        if (found >= 0) {
            for (int j = i; j>=found+1; --j) {
                a[j] = a[j-1];
            };
            a[found] = pivot;
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