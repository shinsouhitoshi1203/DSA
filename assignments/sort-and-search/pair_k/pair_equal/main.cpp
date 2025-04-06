#include <bits/stdc++.h>
using namespace std;

void input(int &n, int * &a, int &k) {
    cin >> n >> k;
    a = new int [n];
    for (int i=0;i<n;++i) {
        cin >> a[i];
    }
}


namespace sort {
    // 3 4 0 1 4
    int move_left(int * a, int s, int limit, int pivot) {
        while (a[s] >= pivot) {
            s--;
            if (s <= limit) return limit;
        }
        return s;
    }


    int move_right(int * a, int s, int limit, int pivot) {
        while (a[s] <= pivot) {
            s++;
            if (s >= limit) return limit;
        }
        return s;
    }
    void quick( int * &a, int s, int e) {
        int pivot = a[s];
        int mid;

        if (s >= e) return ;
        while (true) {
            int l_bound = move_right(a, s, e, pivot);
            int r_bound = move_left(a, e, s, pivot);
            if (l_bound < r_bound) {
                swap(a[l_bound], a[r_bound]);
            } else {
                swap(a[s], a[r_bound]);
                mid = r_bound;
                break;
            }
        }

        quick(a, s, mid-1);
        quick(a, mid+1, e);

    }
}

void output(int n, int * a) {
    for (int i = 0; i<n;++i) {
        cout << a[i] << " ";
    }
}

int search(int * a, int s, int e,int k) {
    
    while (s <= e ) {
        int n = e-s+1;
        int mid = s + n / 2; 
        if (a[mid]==k) {
            // cout << "\n Seach for: " << k << " : " << mid;
            return mid;
        } else if (a[mid] > k) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return -1;
}
int findNext (int * a, int s, int e, int k) {
    int E = e;
    while (s<=e) {
        int n = e - s + 1;
        int mid = s + n/2;

        // 1 2 3 4 5 6 7
        // 2 2 2 5 7 8 9
        if (a[mid]==k) {
            if (a[mid+1] > k && mid+1 <= E) {
                return mid+1;
            } else {
                s = mid + 1;
            }
        } else {
            if (a[mid-1] > k && (mid-1) > 0) {
                e = mid - 1;
            } else {
                return mid;
            }
        }
    }
    return -1;
}
namespace count {
    
    int find (int * a, int n, int k) {
        int R = 0;
        int i = 0;
        while (a[i] + a[i+1] < k && i+1 < n) {
            int st = search(a, i+1, n-1, k-a[i]);
            if (st!=-1) {
                int sd = findNext(a, st, n-1, a[st]);
                if (sd == -1) sd = n-1;

                int c = sd - st;
                R+=c;
            }
            i++;
        }
        return R;
    }
}

int main() {
    int n, * a, k;
    input (n, a, k);
    sort::quick(a, 0, n-1);
    int c = count::find(a, n, k);
    
    cout << endl;
    cout << c;
    // ignore the last message
    cin.get();
    cout << endl;
    return 0;
}