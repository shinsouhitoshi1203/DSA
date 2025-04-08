#include <bits/stdc++.h>
#define MAX 1000000000
#define ll long long

using namespace std;


void input (int &n, int &k, int * &a) {
    cin >> n >> k;
    a = new int [n];
    for (int i  = 0; i < n ; ++i) {
        cin >> a[i];
    }
}

void prefixSum(int n, int * &a, ll * &S) {
    S = new ll [n];
    for (int i  = 0; i < n ; ++i) {
        if (i > 0) {
            S[i] = (ll)S[i-1] + a[i];
        } else {
            S[i] = (ll)a[i];
        }
    }
}
bool joinL(int n, int l, int H, int * &a, ll * &S) {
    ll L = 0;
    auto x = upper_bound(a, a+n, H);
    int posX = x - a;
    int d = n - posX;
    if (posX!=n) 
        L = S[n-1] - (posX>0 ? S[posX-1] : 0) - d*H;
    else    
        L = 0;
    return L >= l;
}
int getH (int n, int l, int * &a, ll * &S) {
    int s = 0, e = a[n-1]; // n-1 is always the largest number
    int ans = 0;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (joinL(n, l, mid, a, S)) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n, l, *a;
    ll *S;
    input(n,l,a);
    sort(a, a+n);
    prefixSum(n, a, S);
    int c = getH(n, l, a, S);

    cout << c;
    delete [] a;
    // ignore the last message
    cin.get();
    cout << endl;
    return 0;
}