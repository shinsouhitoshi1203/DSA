#include <bits/stdc++.h>
using namespace std;

void generate_binary(int pos, int n, string &str) {
    if (pos>n) {
        cout << str << endl;
        return;
    } 

    // pos = select
    for (int i = '0'; i<='1'; ++i) {
        str.push_back(i);
        generate_binary(pos+1, n, str);
        str.pop_back();
    }
}

int main() {
    int n; cin >> n;
    string str = "";
    generate_binary(1, n, str);
    
    // ignore the last message
    cin.get();
    cout << endl;
    return 0;
}