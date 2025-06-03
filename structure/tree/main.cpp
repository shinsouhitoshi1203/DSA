#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node * left = nullptr;
    node * right = nullptr;
};

node * create_node (int x) {
    node * new_node = new node();
    new_node->data = x;
    return new_node;
}


void setup(node * tree) {
    tree->left = create_node(7);
    tree->right = create_node(15);

    tree->left->left = create_node(5);
    tree->left->right = create_node(9);
    /* 
            10
           /  \
          7   15
         /  \
        5    9
    */
}

void dfs_pre(node * tree) {
    if (tree!=nullptr) {
        cout << tree->data << " ";
        dfs_pre(tree->left);
        dfs_pre(tree->right);
    }
}

void dfs_in(node * tree) {
    if (tree!=nullptr) {
        dfs_in(tree->left);
        cout << tree->data << " ";
        dfs_in(tree->right);
    }
}

void dfs_post(node * tree) {
    if (tree!=nullptr) {
        dfs_post(tree->left);
        dfs_post(tree->right);
        cout << tree->data << " ";
    }
}

// BST


int main() {
    node * tree = create_node(10);

    // set up tree
    setup(tree);

    dfs_pre(tree);
    cout << endl;
    dfs_in(tree);
    cout << endl;
    dfs_post(tree);
    cout << endl;



    delete tree;
    // ignore the last message
    cin.get();
    cout << endl;
    return 0;
}