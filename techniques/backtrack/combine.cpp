#include <bits/stdc++.h>
using namespace std;

void input (int &n, int * &a) {
    cin >> n;
    a = new int [n];
    for (int i=0; i<n; ++i) cin >> a[i];
}

void output(int n, int *a) {
    for (int i = 0;i<n;++i) cout << a[i] << " "; cout << endl;
}
// 
namespace select {
    vector<int> list;
    int * map_list;
    void output() {
        for (auto x: list) {
            cout << x << " ";
        }
        cout << endl;
    }
    void run(int * &a, int n, int k) {
        if (k==0) {
            output();
            return;
        }
        // for (int i=s; i<=(n-1)-(k-1); ++i) {
        //     list.push_back(a[i]);
        //     run(a, n, k-1, i+1);
        //     list.pop_back();
        // }
        for (int i=0; i<n; ++i) {
            if (map_list[i]==0) {
                map_list[i] = 1;
                list.push_back(a[i]);
                run(a, n, k-1);
                list.pop_back();
                map_list[i] = 0;
            }
        }
    }
    void fill_array(int n) {
        map_list = new int[n];
        for (int i=0; i<n; ++i) map_list[i] = 0;
    }
    void tohop(int * &a, int n, int k) {
        fill_array(n);
        run(a,n,k);
    }
}
int main() {
    int n, * a;
    input (n, a);
    int k; cin >> k;
    select::tohop(a, n, k);   
    
    // ignore the last message
    cin.get();
    cout << endl;
    return 0;
}

// 10000

