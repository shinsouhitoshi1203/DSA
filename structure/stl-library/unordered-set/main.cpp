#include <bits/stdc++.h>
using namespace std;



int main() {
    unordered_set<int> numbers;
    int n;
    cin >>n;
    for (int i = 0; i<n; ++i) {
        int o; cin >> o;
        numbers.insert(o);
    }

    for (auto x: numbers) {
        cout << x << " ";
    }

    
    // ignore the last message
    cin.get();
    cout << endl;
    return 0;
}
/* 
5
34 2 90 2 9

unordered_set 9 90 2 34
set 2 9 34 90

*/