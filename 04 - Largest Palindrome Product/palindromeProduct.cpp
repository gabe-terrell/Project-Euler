#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int value;
    Node *left;
    Node *right;
    
    Node (int v) {
        value = v;
        left = NULL;
        right = NULL;
    }
};

Node* paltree = NULL;

// Inserts the Node in BST Format. 
// Anything to the right is greater, left is lesser
void insert (Node *n, int v) {
    if (n == NULL) {
        paltree = new Node(v);
        return;
    }
    if (v < n->value) {
        if (n->left == NULL) {
            n->left = new Node(v);
        }
        else {
            insert(n->left, v);
        }
    }
    else if (v > n->value) {
        if (n->right == NULL) {
            n->right = new Node(v);
        }
        else {
            insert(n->right, v);
        }
    }
}

// Checks if the integer is a palindrome
bool isPal (int i) {
    string s = to_string(i);
    int len = s.length();
    
    for (int i = 0, h = len / 2; i < h; i++) {
        if (s[i] != s[len-i-1]) {
            return false;
        }
    }
    
    return true;
}

// Checks all possible 3-digit x 3-digit products
// If a product is a palindrome, add it to the palindrome BST
void createPalTree() {
    for (int i = 100; i < 1000; i++) {
        for (int j = 100; j < 1000; j++) {
            int n = i * j;
            if (isPal(n)) {
                insert(paltree, n);
            }
        }
    }
}

// Searches the BST for the largest value less than v.
int findLargest (Node *n, int v) {
    if (n == NULL) {
        return 0;
    }
    
    if (n->value > v) {
        if (n->left == NULL) {
            return 0;
        }
        return findLargest(n->left, v);
    }
    
    if (n->value < v) {
        int result = findLargest(n->right, v);
        if (result) {
            return result;
        }
    }
    
    return n->value;
}

int main() {
    createPalTree();
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout << findLargest(paltree, n) << endl;
    }
    
    return 0;
}
