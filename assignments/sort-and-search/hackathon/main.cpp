#include <bits/stdc++.h>
using namespace std;

void input (int &n, int &h, int * &a) {
    cin >> n >> h;
    a = new int [n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}

int calc(int n, int x, int *a) {
    int c = 0;
    for (int i = 0; i < n; ++i) {
        int k = ceil(a[i] / (x * 1.0));
        c+=k;
    }
    return c;
}

bool check(int n, int x, int H, int * a) {
    int currS = calc(n, x, a);
    return currS <= H;
}

int findAvg(int n, int h, int * a) {
    int s = 1; 
    int e = max_element(a, a+n) - a;
    if (e==n) return 0;
    e = a[e];
    int ans = 1;
    while (s <= e) {
        int sel = s + (e - s) / 2;
        if (check(n, sel, h, a)) {
            ans = sel;
            e = sel - 1;
        } else {
            s = sel + 1;
        }
    }
    return ans;
}

int main() {
    int N, H, * a;

    input(N, H, a);
    int avg = findAvg(N, H, a);

    cout << avg;
    // ignore the last message
    cin.get();
    cout << endl;
    return 0;
}