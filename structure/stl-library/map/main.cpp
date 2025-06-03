#include <bits/stdc++.h>
using namespace std;
 


int main() {
    int n;
    cin >> n;
    
    map <string, int> numbers;
    // Declare:  map <datatype> name;

    // map.insert();
    // map.find(); --> pointer;
    // map.erase();
    // for iteration() loop;
    // map.empty(); --> bool

    for (int i = 0; i<n; ++i) {
        string k; cin >> k;
        int o; cin >> o;
        numbers.insert({k, o});
    }
    
    for (auto x: numbers) {
        cout << x.first << ", " << x.second << endl;
    }

    /* int x; cin >> x; */

    /* auto f = numbers.find(x);
    if ( f != numbers.end()) {
        cout << "Tim thay!";
    } else {
        cout << "Khong tim thay";
    } */

    /* auto f = numbers.find(x);
    if (f!=numbers.end()) {
        numbers.erase(x);
    } */

    if (!numbers.empty()) numbers.clear();
    

    
    // ignore the last message
    cin.get();
    cout << endl;
    return 0;
}