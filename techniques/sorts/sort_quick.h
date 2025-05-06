#include <bits/stdc++.h>
using namespace std;

int partition_1(int * &a, int s, int e) {
    int pivot = a[e];
    int l = s - 1;
    for (int i = 0; i<e; ++i) {
        if (a[i] <= pivot) {
            l++;
            swap(a[l], a[i]);
        }
    }
    l++;
    swap(a[l], a[e]);
    return l;
}

int partition_2(int * &a, int s, int e) {
    int i = s - 1;
    int j = e + 1;

    int pivot = a[s];

    while (true) {
        
        do {
            i++;
        } while (a[i] < pivot);

        do {
            j--;
        } while (a[j] > pivot);

        if (i<j) {
            swap(a[i], a[j]);
        } else {
            return j;
        }
        
    }
}

/* void sort (int * &a, int s, int e) {
    if (s >= e) return;
    int mid = partition(a, s, e);
    sort(a, s, mid);
    sort(a, mid + 1, e);    
} */

void sort (int * &a, int s, int e) {
    if (s >= e) return;
    int mid = partition_1(a, s, e);
    sort(a, s, mid - 1);
    sort(a, mid + 1, e);    
}