#include <bits/stdc++.h>
using namespace std;
 
int main() {
    stack <int> L;
    int n; cin >> n;
    for (int i=0; i<n; ++i) {
        int o; cin >> o;
        L.push(o);
    }

    while (!L.empty()) {
        cout << L.top() << " ";
        L.pop();
    }

    cout << L.empty();
    
    // ignore the last message
    cin.get();
    cout << endl;
    return 0;
}