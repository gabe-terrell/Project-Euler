#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

struct Node {
    int value;
    int max_sum;
    Node *left;
    Node *right;
    
    Node (int m) {
        value = m;
        max_sum = 0;
        left = NULL;
        right = NULL;
    }
};

Node* makePath(int depth) {
    Node* root;
    int num;
    vector<Node*> parents;
    
    // Create the path in a tree node format, one level at a time
    for (int level = 0; level <= depth; level++) {
        // root level
        if (level == 0) {
            cin >> num;
            root = new Node(num);
            parents.push_back(root);
        }
        // create nodes for this level and assign pointers for parents
        else {
            for (int i = 0; i <= level; i++) {               
                cin >> num;
                Node *new_node = new Node(num);
                
                if (i == 0) {
                    parents[i]->left = new_node;
                }
                else if (i == level) {
                    parents[i - 1]->right = new_node;
                }
                else {
                    parents[i]->left = new_node;
                    parents[i - 1]->right = new_node;
                }
                
                // pushes to end of parent node -- shouldn't be touched with for loop
                parents.push_back(new_node);
            }
            
            // erase old parents so that remaining nodes are the ones from this level
            parents.erase(parents.begin(), parents.begin() + level);
        }
    }
    
    return root;
}

// Initializes max_sum of current node if not already set, then returns max_sum
int setMaxSum (Node* node) {
    if (node == NULL) {
        return 0;
    }
    if (node->max_sum > 0) {
        return node->max_sum;
    }
    else {
        int left_sum = setMaxSum(node->left);
        int right_sum = setMaxSum(node->right);
        
        if (left_sum > right_sum) {
            node->max_sum = node->value + left_sum;
        }
        else {
            node->max_sum = node->value + right_sum;
        }
        
        return node->max_sum;
    }
}

// Test code to ensure node structure was made correctly
// Depth-First Search Print
void depthPrint (Node* root) {
    vector<Node*> queue;
    queue.push_back(root);
    
    while (!queue.empty()) {
        // Take node from front of queue
        Node *node = queue.front();
        queue.erase(queue.begin());
        
        // Print its value and children
        cout << "\nNode: " << node->value << endl;
        if (node->left != NULL) {
            cout << "\t--> Left: " << node->left->value << endl;
        }
        if (node->right != NULL) {
            cout << "\t--> Right: " << node->right->value << endl;
        }
            
        
        // Add its children to the queue if not NULL
        if (node->left != NULL) {
            queue.push_back(node->left);
        }
        if (node->right != NULL) {
            queue.push_back(node->right);
        }
    }
}


int main() {
    int p;
    cin >> p;
    Node *paths[p];
    
    for (int i = 0; i < p; i++) {
        int d;
        cin >> d;
        paths[i] = makePath(d - 1);
    }
    
    for (int i = 0; i < p; i++) {
        cout << setMaxSum(paths[i]) << endl;
    }
    
    return 0;
}
