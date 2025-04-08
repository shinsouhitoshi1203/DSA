#include <bits/stdc++.h>
using namespace std;


struct node {
    int data;
    node * next;
};

node * create_node(int data) {
    node * new_node = new node();
    (*new_node).data = data;
    (*new_node).next = nullptr;
    return new_node;
}

int count (node * head) {
    int n = 0;
    while (head) {
        n++;
        head = head->next;
    };
    return n;
}

void push_front(node * &head, int data) {
    node * new_node = create_node(data);
    (*new_node).next = head;
    head = new_node;
}

void push_back(node * &head, int data) {
    node * new_node = create_node(data);
    if (head==nullptr) {
        head = new_node;
        return;
    }
    node * ite = head;
    while ((*ite).next!=nullptr) {
        ite = (*ite).next;
    }
    (*ite).next = new_node;
}

void pop(node * &head) {
    node * ite = head;
    if (head==nullptr) return;
    if (head->next==nullptr) {
        head = nullptr; delete ite;
        return;
    }
    while (((*ite).next)->next!=nullptr) {
        ite = (*ite).next;
    };
    node * target = (*ite).next;
    delete target;
    (*ite).next = nullptr;
}

void shift (node * &head) {
    if (head==nullptr) return;
    node * ite = head;
    head = (*head).next;
    delete ite;
}

void splice(node * &head, int data, int pos) {
    int n = count (head);
    node * ite = head;
    if (pos<0 || pos >n) return;
    if (pos==0) {
        push_front(head, data);
        return;
    }
    node * new_node = create_node(data);
    for (int i=0;i<pos-1;++i) {
        ite = (*ite).next;
    }
    new_node->next = ite->next;
    ite->next = new_node;
}

void kill (node * &head, int pos) {
    if (head==nullptr || pos < 0 || pos > count (head)) return;
    if (pos==0) {
        shift(head);
        return;
    }
    node * ite = head;
    for (int i=0;i<pos-1;++i) {
        ite = (*ite).next;
    }
    node * target = (*ite).next;
    (*ite).next = (*target).next;
    delete target;
} 

void print(node * head) {
    while (head!=nullptr) {
        cout << (*head).data << " ";
        head = (*head).next;
    }
}

void alter(node * &head, int data, int pos) {
    if (head==nullptr || pos < 0 || pos > count (head)) return;
    node * ite = head;
    for (int i=0;i<pos;++i) {
        ite = (*ite).next;
    }
    node * &target = ite;
    target->data = data;
}

int main() {
    int n; int tmp;
    node * head = nullptr;
    cin >> n;
    for (int i = 0;i<n;++i) {
        cin >> tmp;
        push_back(head,tmp);
    }
    print(head);
    cout << endl;
    alter(head, 10000, 0);
    // kill(head, 2);
    print(head);
    cout << endl;
    return 0;
}
// 1 3 9 0
// 1 3 100 9 0
// 999 1 3 100 0