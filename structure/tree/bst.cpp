#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node * left = nullptr;
    node * right = nullptr;
};

typedef node * tree;

node * create_node (int x) {
    node * new_node = new node();
    new_node->data = x;
    return new_node;
}

bool bst(tree A, int x) {
    if (A!=nullptr) {
        if (A->data==x) {
            return true;
        } else if (x < A->data) {
            return bst(A->left, x);
        } else {
            return bst(A->right, x);
        }
    }   
    return false;
}

void add_new(tree &A, int x) {
    if (A!=nullptr) {
        if (x < A->data) {
            add_new(A->left, x);
        } else if (x > A->data) {
            add_new(A->right, x);
        }
    } else {
        node * new_node = create_node(x);
        A = new_node;
    }
}

node * find_max_DUMB (tree A) {
    // Be careful, this one is still ok but with O(N)
    if (A==nullptr) return nullptr;
    if (A->left!=nullptr || A->right !=nullptr) {
        node * max = A;
        // if (A->data)
        node * left = find_max_DUMB(A->left);
        node * right = find_max_DUMB(A->right);
        if (left!=nullptr) {
            if (left->data > A->data) max = left;
        }
        if (right!=nullptr) {
            if (right->data > A->data) max = right;
        }
        return max;
    } else {
        return A;
    }
}

node * find_max (tree A) {
    if (A==nullptr) return nullptr;
    if (A->right!=nullptr) {
        return find_max(A->right);
    }   
    return A;
}
node * find_min (tree A) {
    if (A==nullptr) return nullptr;
    if (A->left!=nullptr) {
        return find_min(A->left);
    }   
    return A;
}
void dfs(tree A) {
    if (A!=nullptr) {
        cout << A->data << " ";
        dfs(A->left);
        dfs(A->right);
    }
}

int main() {
    tree a = nullptr;
    int n;
    int * arr;
    cin >> n;
    arr = new int[n];
    for (int i = 0; i<n;++i) {
        cin >> arr[i];
        add_new(a, arr[i]);
    }
    // dfs(a);
    cout << endl << find_max(a)->data;
    // ignore the last message
    cin.get();
    cout << endl;
    return 0;
}