#include <bits/stdc++.h>
#include "io.h"

#include "sort_heap.h"
using namespace std;

int main() {
    int * a, n;
    input(n , a);
    sort(a, n);
    output(n, a);
    // ignore the last message
    cin.get();
    cin.get();
    cout << endl;
    return 0;
}