#include <bits/stdc++.h>
using namespace std;
 


int main() {
    int n;
    cin >> n;
    
    set <int> numbers;
    // Declare:  set <datatype> name;

    // set.insert();
    // set.find(); --> pointer;
    // set.erase(); --> 
    // for iteration() loop;
    // 

    for (int i = 0; i<n; ++i) {
        int o; cin >> o;
        numbers.insert(o);
    }
    
    /* for (auto x: numbers) {
        cout << x << " ";
    } */

    int x; cin >> x;

    /* auto f = numbers.find(x);
    if ( f != numbers.end()) {
        cout << "Tim thay!";
    } else {
        cout << "Khong tim thay";
    } */

    auto f = numbers.find(x);
    if (f!=numbers.end()) {
        numbers.erase(x);
    }




    
    // ignore the last message
    cin.get();
    cout << endl;
    return 0;
}