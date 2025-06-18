#include <bits/stdc++.h>
#define LIM 1e9
using namespace std;
/*
    (C) shinsouhitoshi1203

    Add, Remove, Find ✅
    Count, Get Index, Upperbound, Lowerbound ✅

    Range Query List [L, R] ✅
    Tree Depth calculation ✅
    Visualize Tree ✅
*/
class Tree {
protected:
    struct node {
        int data = 0;
        node * left = nullptr;
        node * right = nullptr;
        node * parent = nullptr;

        /* Only for counting left bound and right bound */
        int count_left = 0;
        int count_right= 0;

        // Node's depth
        int depth = 0;
    };
    int count = 0;
    node * head = nullptr;
    node * create_node(int x, node * old, int depth) {
        node * new_node = new node();
        new_node->data = x;
        new_node->depth = depth;
        new_node->parent = old;
        return new_node;
    }
    void add_node(node * &curr, int x, node * prev = nullptr, int depth = 0) {
        if (curr == nullptr) {
            curr = create_node(x, prev, depth);
            count++;
        } else {
            if (curr->data == x) return;
            if (x < curr->data) {
                // Count left_bound
                curr->count_left++;
                // Add node
                add_node(curr->left, x, curr, curr->depth+1);
            } else {
                // Count right_bound
                curr->count_right++;
                // Add node
                add_node(curr->right, x, curr, curr->depth+1);
            }
        }
    }
    void print_recur(node * curr) {
        // Node- Left- Right
        if (curr != nullptr) {
            cout << curr->data << " ";
            print_recur(curr->left);
            print_recur(curr->right);
        }
    }
    
    node * find_node(node * curr, int x) const{
        if (curr==nullptr) {
            return nullptr;
        } else {
            if (curr->data == x) return curr;
            if (x < curr->data) return find_node(curr->left, x);
            return find_node(curr->right, x);
        }
    }
    int find_pos_recur(int x) const{
        int l_bound = 0;
        node * ite = head;
        while (ite!=nullptr) {
            if (x == ite->data) {
                return l_bound + ite->count_left;
            } else if (x > ite->data) {
                l_bound += (1 + ite->count_left);
                ite = ite->right;
            } else {
                ite = ite->left;
            }
        }
        return -1;
    }
    
    int find_val(int x) const {
        int l_bound = 0;
        node * ite = head;
        while (ite!=nullptr) {
            if (x == l_bound+ite->count_left) {
                return ite->data;
            } else if (x > l_bound+ite->count_left) {
                l_bound += (1 + ite->count_left);
                ite = ite->right;
            } else {
                ite = ite->left;
            }
        }
        return LIM;
    }
    int find_val_lower (int x) const {
        node * ite = head;
        int saved = LIM;
        while (ite!=nullptr) {
            if (x >= ite->data) {
                saved = ite->data;
                ite = ite->right;
            } else {
                ite = ite->left;
            }
        }
        return saved;
    }
    int find_val_upper (int x) const {
        node * ite = head;
        int saved = LIM;
        while (ite!=nullptr) {
            if (x < ite->data) {
                saved = ite->data;
                ite = ite->left;
            } else {
                ite = ite->right;
            }
        }
        return saved;
    }

    void clear_recur(node * &head) {
        if (head!=nullptr) {
            if (head->left != nullptr) clear_recur(head->left);
            if (head->right != nullptr) clear_recur(head->right);
            delete head;
            head = nullptr;
        }
    }
    void kill_force(node * &og, node * &ite) {
        if (ite->right != nullptr) {
            ite->count_right--;
            kill_force(og, ite->right);
        } else {
            og->data = ite->data;
            if (ite->left==nullptr && ite->right==nullptr) {
                ite = nullptr;
            } else if (ite->left!=nullptr || ite->right!=nullptr) {
                if (ite->left != nullptr) {
                    ite = ite->left;
                } else {
                    ite = ite->right;
                }
            }
        }
    }
    void kill_recur(node * &curr, int x) {
        if (curr!=nullptr) {
            if (x == curr->data) {
                // delete node here...
                count--;
                if (curr->left==nullptr && curr->right==nullptr) {
                    // Delete the node that is the leaf node
                    curr = nullptr;
                } else if (curr->left!=nullptr && curr->right!=nullptr) {
                    // Delete the node that has two children
                    curr->count_left--;
                    kill_force(curr, curr->left);
                } else {
                    // Delete the node that has one single child
                    if (curr->left != nullptr) {
                        curr = curr->left;
                    } else {
                        curr = curr->right;
                    }
                }
            } else if (x < curr->data) {
                curr->count_left--;
                kill_recur(curr->left, x);
            } else {
                curr->count_right--;
                kill_recur(curr->right, x);
            }
        }
    }

    void list_range_recur(node * curr, int s, int e)  {
        if (curr!=nullptr) {
            if (curr->data >= s && curr->data <= e) {
                cout << curr->data << " ";
                list_range_recur(curr->left, s, e);
                list_range_recur(curr->right, s, e);
            } else if (curr->data < s) {
                list_range_recur(curr->right, s, e);
            } else {
                list_range_recur(curr->left, s, e);
            }
        }
    }
    int count_range(node * curr, int s, int e) {
        int count = 0;
        if (find(s)) count++;
        if (find(e)) count++;

        int upper_s = upper_bound(s); int i = find_pos(upper_s);
        if (upper_s == LIM) i = this->count; 
        int lower_e = lower_bound(e); int j = find_pos(lower_e);
        if (lower_e == e) j--;

        if (i > -1 && j > -1) {
            int del = j-i+1;
            if (del > 0) count += (j-i+1);
        } 
        return count;
    }
    void print_space() {for (int j = 0; j<4; ++j) cout << " ";}
    void print_tree_recur(node * curr, unordered_set<int> &visited, vector<node *>stack = {}) {
        unordered_map<string, string> Item = {
            {"stick"     , "│      "},
            {"hook_up"   , "┌─────→"},
            {"hook_down" , "└─────→"},
            {"hook"      , "├──────"},
            {"block"     , "       "}
        };
        // node - left - right
        if (curr!=nullptr) {
            stack.push_back(curr);
            print_tree_recur(curr->left, visited, stack);

            for (int i = 0; i<stack.size() - 1; ++i) {
                auto curr_node = stack.at(i);
                int f = curr_node->data;
                if (curr_node->left == curr || curr_node->right == curr) {
                    // is direct child of the curr_node;
                    if (curr_node->left == curr) {
                        if (visited.find(curr->data)==visited.end()) {
                            cout << Item["hook_up"];// ┌────
                        } else {
                            cout << Item["stick"];  // |    
                        }
                    } else {
                        if (visited.find(curr->data)==visited.end()) {
                            cout << Item["hook_down"];  // └────
                        } else {
                            cout << Item["block"];
                        }
                    }
                } else {
                    if (curr_node->left != nullptr && curr_node->right != nullptr) {
                        int L = curr_node->left->data;
                        int R = curr_node->right->data;

                        if (visited.find(L) != visited.end()) {
                            if (visited.find(R) != visited.end()) {
                                cout << Item["block"];
                            } else {
                                cout << Item["stick"]; // |   
                            }
                        } else {
                            cout << Item["block"];
                        }
                        
                    } else if (curr_node->left != nullptr || curr_node->right != nullptr) {
                        if (curr_node->left !=nullptr) {
                            if (visited.find(curr_node->left->data) != visited.end()) {
                                cout << Item["stick"]; // |   
                            } else {
                                cout << Item["block"];
                            }
                        } else {
                            if (visited.find(curr_node->right->data) != visited.end()) {
                                cout << Item["block"];
                            } else {
                                cout << Item["stick"]; // |   
                            }
                        }
                    } else {
                        cout << Item["block"];
                    }
                    
                }
            }
            cout << curr->data;
            cout << "\n";
            visited.insert(curr->data);
            
            print_tree_recur(curr->right, visited, stack);
            stack.pop_back();
        }
    } 

public:
    ~Tree() {clear_recur(head);};
    void print() {print_recur(head);}
    bool find(int x) {return (find_node(head, x)!=nullptr);}

    void add(int x) {
        if (find(x)) return;
        add_node(head, x);
    }
    void kill(int x) {
        if (!find(x)) return;
        kill_recur(head, x);
    }
    void clear_all() {clear_recur(head);};

    int count_node () const {return count;}
    int find_pos(int x) const {return find_pos_recur(x);}
    int operator [] (int x) const {return find_val(x);}
    int upper_bound (int x) const {return find_val_upper(x);};
    int lower_bound (int x) const {return find_val_lower(x);};

    void list_range(int s, int e) {list_range_recur(head, s, e);}
    int count_range(int s, int e) {return count_range(head, s, e);}

    int depth(int x) const {
        node * r = find_node(head, x);
        if (r != nullptr) return r->depth;
        return -1;
    }

    void print_tree() {
        unordered_set<int> visited;
        print_tree_recur(head, visited);
    }
};

int main()
{
    Tree T1;
    /* Insert code here */
    return 0;
}
