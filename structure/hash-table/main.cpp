#include <bits/stdc++.h>
using namespace std;
// -1 : NULL
// -2 : DELETED


class Hash {
    vector<int>T [1000];
    int size;
    int mem_count = 0;

    public:
        Hash() {
            size = 1000;
        }

        int fn(int x, int i = 0) {
            if (i == 0) return x%size;
            return ( x%size + i ) % size;
        }

        bool push(int x) {
            int r = fn(x);
            T[r].emplace_back(x);
            mem_count++;
            return true;
        }
        bool remove(int x) {
            int i = 0;
            int r = fn(x);
            if (T[r].size() > 0) {
                auto X = std::find(T[r].begin(), T[r].end(), x);
                if (X!=T[r].end()) {
                    T[r].erase(X);
                    mem_count--;
                    return true;
                }
            }
            return false;
        }
        int find(int x) {
            int r = fn(x);
            if (T[r].size() > 0) {
                auto X = std::find(T[r].begin(), T[r].end(), x);
                if (X!=T[r].end()) {
                    return distance(T[r].begin(),X);
                }
            }
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
