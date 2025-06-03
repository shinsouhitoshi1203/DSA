#include <bits/stdc++.h>
using namespace std;
 
struct node {
    string x;
    node * left = nullptr;
    node * right = nullptr;
};

node * create_node (string x) {
    node * new_node = new node();
    new_node->x = x;
    return new_node;
}

void setup(node * tree) {
    tree->left = create_node("*");
    tree->right = create_node("10");

    tree->left->left = create_node("11");
    tree->left->right = create_node("28");
    /* 
            +
           /  \
          *   10
         /  \
        11  28
    */
}

void dfs(node * tree) {
    if (tree!=nullptr) {
        dfs(tree->left);
        cout << tree->x << " ";
        dfs(tree->right);
    }
}

int calc(node * tree) {
    if (tree!= nullptr) {
        if (tree->x =="+") {
            return calc(tree->left) + calc(tree->right);
        } else if (tree->x == "*") {
            return calc(tree->left) * calc(tree->right);
        } else if (tree->x == "-") {
            return calc(tree->left) - calc(tree->right);
        } else if (tree->x == "/") {
            return calc(tree->left) / calc(tree->right);
        } else {
            return stoi(tree->x);
        }
    }
    return 0;
}

int main() {
    node * tree = create_node("+");
    setup(tree);
    dfs(tree);
    cout << " = " << calc(tree);
    // ignore the last message
    cin.get();
    cout << endl;
    return 0;
}