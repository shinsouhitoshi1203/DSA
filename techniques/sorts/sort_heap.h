#include <bits/stdc++.h>
using namespace std;


void sort(int * a, int n);
void heapify(int * a, int limit, int i);

void sort(int * a, int n) {
    for (int i = n/2 - 1; i>=0; --i) {
        heapify(a, n, i);
    }

    for (int i = n-1; i>=0; --i) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

void heapify(int * a, int limit, int i) {
    int l = 2*i + 1;
    int r = 2*i + 2;
    int p = i;

    // max-node binary tree
    if (l < limit && a[l] > a[p]) {
        p = l;
    }
    if (r < limit && a[r] > a[p]) {
        p = r;
    }

    if (p!=i) {
        swap(a[i], a[p]);
        heapify(a, limit, p);
    }
}