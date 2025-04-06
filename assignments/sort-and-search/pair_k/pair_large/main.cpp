#include <bits/stdc++.h>
using namespace std;

void input(int &n, int * &a, int &k) {
    cin >> n >> k;
    a = new int [n];
    for (int i=0;i<n;++i) {
        cin >> a[i];
    }
}
void output(int n, int * a) {
    for (int i = 0; i<n;++i) {
        cout << a[i] << " ";
    }
}
int move_right(int * &a, int s, int limit, int pivot) {
    while (a[s] <= pivot) {
        s++;
        if (s>=limit) return limit;
    }
    return s;
}
int move_left(int * &a, int s, int limit, int pivot) {
    while (a[s] >= pivot) {
        s--;
        if (s<=limit) return limit;
    }
    return s;
}
void sort(int * &a, int s, int e) {
    int pivot = a[s];
    if (s>e) return;

    int mid;

    while (true) {
        int L = move_right(a, s, e, pivot);
        int R = move_left(a, e, s, pivot);
        if (L < R) {
            swap(a[L] , a[R]);
        } else {
            swap(a[s], a[R]);
            mid = R;
            break;
        }
    }

    sort(a, s, mid-1);
    sort(a, mid+1, e);

}

// 2 7 4 5 3
// 2 3 4 5 7
// (3 7) (4 7) (5 7)


int findNext(int * &a, int s, int e, int k) {
    // 0 1 2 3 4
    // 2 3 4 5 7
    // 1 2->4
    int N = e, S = s;
    while (s < e) {
        int n = e - s + 1;
        int mid = s + n / 2;
        if (a[mid]<=k) {
            if (a[mid+1] > k) {
                if (mid+1 <= N) return mid + 1; else return -1;
            } else {
                s = mid + 1;
            }
        } else if (a[mid] > k) { 
            if (a[mid-1] <= k && mid-1 >= S) {
                return mid;
            } else {
                e = mid - 1;
            }
        }
        // } else {
        //     if (a[mid+1] > k) {
        //         if (mid+1 <= N) return mid + 1; else return -1;
        //     } else {
        //         s = mid + 1;
        //     }
        // }
    }

    if (s==e) {
        //hook
        if (a[s] > k) return s;
        if (a[s+1] > k) {
            if (s+1 <= N) return s + 1; else return -1;
        }
    }
    return -1;
}
int count(int * &a, int n, int k) {
    int i = 0; int c = 0;
    // 2 3 4 5 7
    while (i+1 < n) {
        int sd = findNext(a, i+1, n-1, k-a[i]);
        cout << "find " << k-a[i] << " from " <<  i+1 << " " << sd<<endl;
        if (sd!=-1) {
            int r = n-1 - (sd) + 1;
            c+=r;
        } 
        i++;
    }
    return c;
}
int main() {
    int n, *a, k;
    input(n, a, k);


    sort(a, 0, n-1);
    output(n,a); cout << endl;
    int c = count(a, n, k);
    cout << c;
    // ignore the last message
    cin.get();
    cout << endl;
    return 0;
}