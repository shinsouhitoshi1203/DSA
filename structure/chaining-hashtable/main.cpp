#include <bits/stdc++.h>
using namespace std;
// -1 : NULL
// -2 : DELETED


class Hash {
    int T[1000];
    int size;
    int mem_count = 0;

    public:
        Hash() {
            memset(T, -1, sizeof(T));
            size = 1000;
        }

        int fn(int x, int i = 0) {
            if (i == 0) return x%size;
            return ( x%size + i ) % size;
        }

        bool push(int x) {
            int i = 0;
            do {
                int r = fn(x, i);
                if (T[r] == -1 || T[r] == -2) {
                    T[r] = x;
                    mem_count++;
                    return true;
                }
                i++;
            } while (i < size);
            return false;
        }
        bool remove(int x) {
            int i = 0;
            int r;
            do {
                r = fn(x, i);
                i++;
                if (T[r] == x) {
                    T[r] = -2;
                    mem_count--;
                    return true;
                }
            } while (i < size && T[r] != -1);
            return false;
        }
        int find(int x) {
            int i = 0; int r;
            do {
                r = fn(x, i);
                if (T[r] == x) {
                    return r;
                }
                i++;
            } while (i < size && T[r] != -1);
            return -1;
        }
        int count() const {return mem_count;}
};
 
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    Hash H;

    int o;
    while (1) {
        cin >> o;
        if (o==0) break;
        switch (o) {
            case 1: {
                int x; cin >> x;
                bool t = H.push(x);
                cout << (t?"INSERTED: ":"CANNOT INSERT: ") << x << "\n";
                break;
            } case 2: {
                int x; cin >> x;
                bool t = H.remove(x);
                cout << (t ? "DELETED: ":"CANNOT DELETE: ") << x << "\n";
                break;
            } case 3: {
                int x; cin >> x;
                int t = H.find(x);
                cout << (t>=0 ? "FOUND: ":"NOT FOUND: ") << x << "\n";
                break;
            } case 4: {
                cout << H.count() << "\n";
            } 
        }
    }
    
    
    // ignore the last message
    cin.get();
    cout << endl;
    return 0;
}