#include <bits/stdc++.h>
using namespace std;

class Tree {
    private: 
        struct node {
            int value;
            node * left = nullptr;
            node * right = nullptr;

            node * parent  = nullptr;
        };
        int length = 0;
        node * head = nullptr;

        node * create_node(int x, node * parent) {
            node * new_node = new node();
            new_node->value = x;
            new_node->parent = parent;
            length++;
            return new_node;
        }

        void add_traverse(node * &head, int x, node * parent = nullptr) {
            if (head==nullptr) {
                head = create_node(x, parent);
            } else {
                if (x < head->value) {
                    add_traverse(head->left, x, head);
                } else if (x > head->value) {
                    add_traverse(head->right, x, head);
                }
            }
        }

        void dfs_traverse(node * head) {
            // The order is L, N, R:
            if (head!=nullptr) {
                dfs_traverse(head->left);
                cout << head->value << " ";
                dfs_traverse(head->right);
            } 
        }

        node * &traverse(node * &head, int x) {
            // The order is L, N, R:
            if (head!=nullptr) {
                if (x == head->value) return head;
                if (x < head->value) return traverse(head->left, x);
                if (x > head->value) return traverse(head->right, x);
            } 
            return this->head->parent;
        };

        node * &replacement(node * &head, node * &prev) {
            if (head != nullptr) {
                return replacement(head->right, head);
            } else {
                return prev;
            }
        }

        void remove_force(node * &head) {
            if (head!=nullptr) {
                if (head->left == nullptr && head->right == nullptr) {
                    delete head;
                    head = nullptr;
                } else {
                    if (head->left != nullptr) {
                        head = head->left;
                    } else {
                        head = head->right;
                    }
                }
            }
        }
        
        void remove_traverse(node * &head, int x) {
            if (head!=nullptr) {
                if (head->value == x) {
                    length--;
                    if (head->left == nullptr && head->right == nullptr) {
                        delete head;
                        head = nullptr;
                    } else if (head->left != nullptr && head->right != nullptr) {
                        auto &R = replacement(head->left, head);
                        head->value = R->value;
                        remove_force(R);
                    } else {
                        if (head->left != nullptr) {
                            head = head->left;
                        } else {
                            head = head->right;
                        }
                    }
                } else if (x < head->value) {
                    remove_traverse(head->left, x);
                } else {
                    remove_traverse(head->right, x);
                }
            }
        }

    public: 
        void add(int x) {
            add_traverse(head, x);
        }

        void dfs() {
            dfs_traverse(head);
            cout << "\n";
        }

        node * &find(int x) {
            return traverse(head, x);
        }

        void remove(int x) {
            remove_traverse(head, x);
        }

        int getLength() const {return length;}
};

int main() {
    Tree A;
    /* 
        1 - Add new x number;
        2 - Find the x number;
        3 - Delete the x number;
        4 - DFS traversing
        5 - Length

        0 - Break;
    */


    cin.tie(0);
    ios_base::sync_with_stdio(0);

    while (1) {
        int o; cin >> o;
        if (o == 0) break;

        if (o == 4) {
            A.dfs();
            continue;
        } else if (o == 5) {
            cout << A.getLength() << "\n";
            continue;
        }


        int x; cin >> x;
        switch (o) {
            case 1: {
                A.add(x);
                break;
            } 
            case 2: {
                auto f = A.find(x);
                if (f!=nullptr) {
                    cout << "Found\n";
                } else {
                    cout << "Not Found\n";
                }
                break;
            }
            case 3: {
                A.remove(x);
                break;
            }
            
        };
    }
    
    // ignore the last message
    cin.get();
    cout << endl;
    return 0;
}