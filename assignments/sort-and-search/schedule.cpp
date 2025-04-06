#include <bits/stdc++.h>
using namespace std;

struct Schedule {
    int s, e;
    int d;
};

void input (Schedule &X) {
    cin >> X.s >> X.e;
    X.d = X.e - X.s + 1;
}
void output (Schedule X, int i) {
    cout << i << ": " << X.s << " " << X.e << endl;
}

namespace sort {
    int compare(Schedule X, Schedule Y) {
        /* 
            -1 : X < Y
            0: X=Y
            1: X>Y
        */
        if (X.e < Y.e) {
            return -1;
        } else if (X.e > Y.e) {
            return 1;
        } else {
            if (X.s <= Y.s) {
                return -1;
            } else {
                return 1;
            }
        }
    }
    void assign(Schedule &L, Schedule &R) {
        L.s = R.s;
        L.e = R.e;
        L.d = R.d;
    }
    Schedule * flat(Schedule * s1, Schedule* s2 ,int n1, int n2) {
        Schedule * res = new Schedule [n1 + n2];
        int point1 = 0, point2 = 0;
        int ite = 0;
        while (point1 < n1 && point2 < n2) {
            if (compare(s1[point1], s2[point2]) < 1) {
                // s1 <= s2
                ite++;
                assign(res[ite-1],s1[point1]);
                point1++;
            } else {
                // s1 > s2
                ite++;
                assign(res[ite-1],s2[point2]);
                point2++;
            }
        }
        if (point1==n1) {
            for (int i = point2 ; i<n2; ++i) {
                ite++;
                assign(res[ite-1],s2[i]);
            }
        } else {
            for (int i = point1 ; i<n1; ++i) {
                ite++;
                assign(res[ite-1],s1[i]);
            }
        }
        return res;
    }
    Schedule * merge(Schedule * li, int s, int e) {
        int n = e - s ;
        int mid = s + n/2;
        if (n+1==1) {
            Schedule * R = new Schedule[1];
            assign(R[0], li[s]);
            return R;
        } else if (n+1==2) {
            Schedule * R = new Schedule[2];
            if (compare(li[s], li[e]) < 1) {
                assign(R[0], li[s]);
                assign(R[1], li[e]);
            } else {
                assign(R[0], li[e]);
                assign(R[1], li[s]);
            }
            return R;
        } else {
            Schedule * s1 = merge(li, s, mid);
            Schedule * s2 = merge(li, mid+1, e);

            int N = e - s + 1;
            int n1 = N/2 + N%2;
            int n2 = N - n1;
            return flat(s1, s2, n1, n2);
        }
    }
}

namespace sc {
    int findNum(Schedule * L, int n) {
        int R = 0;
        int CC = -1;

        for (int i=0;i<n;++i) {
            if (CC==-1) {
                CC = L[i].e;
                R++;
            } else {
                if (L[i].s > CC) {
                    CC = L[i].e;
                    R++;
                }
            }
        }

        return R;
    }
}

int main() {
    
    int n; cin >> n;
    Schedule * a = new Schedule [n];
    for (int i=0;i<n;++i) input(a[i]);
    
    Schedule * L = sort::merge(a,0,n-1);
    
    int C = sc::findNum(L, n);
    cout << C;
    
    // ignore the last message
    cin.get();
    cout << endl;
    return 0;
}