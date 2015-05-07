#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Node {
    char c;
    int  v;
    vector<Node*> children;
    int parents;
    bool processed;
    
    // Constructor
    Node (char ch) {
        c = ch;
        v = (int) c;
        parents = 0;
        processed = false;
    }
    
    // A node is "free" is all of its parents have been processed
    bool isFree() {
        return (parents == 0);
    }
    
    // Adds a new child to the node
    void addChild (Node *child) {
        if (find(children.begin(), children.end(), child) == children.end()) {
            child->parents++;
            children.push_back(child);
        }
    }
    
    // Processes the nodes and alerts its kids that it has been processed
    void process() {
        processed = true;
        for (int i = 0; i < children.size(); i++) {
            children[i]->parents--;
        }
    }
};

struct Queue {
    // queue of nodes to be processed
    vector<Node*> nodes;
    
    // inserts a new node in alphabetical order into queue
    void insert (Node* n) {
        for (int i = 0; i < nodes.size(); i++) {
            if (n->v < nodes[i]->v) {
                nodes.emplace(nodes.begin() + i, n);
                return;
            }
        }
        nodes.push_back(n);
    }
    
    // returns true if queue is empty
    bool isEmpty() {
        return (nodes.size() == 0);
    }
    
    // removes first element from nodes queue and processes it
    // if any of its children are freeds due to it becoming processed,
    // adds freed children to queue as well
    // returns char value of first element
    char process() {
        Node* n = nodes[0];
        nodes.erase(nodes.begin());
        n->process();
        for (int i = 0; i < n->children.size(); i++) {
            Node *child = n->children[i];
            if (child->isFree()) {
                insert(child);
            }
        }
        return n->c;
    }
};

unordered_map<char, Node*> charNode;
Queue queue;

// Given a character, finds the node representing that character
// If the node doesn't exist, creates a new node to represent it
Node* getNode (char c) {
    if (charNode.find(c) == charNode.end()) {
        charNode[c] = new Node(c);
    }
    return charNode[c];
}

// Given two characters, creates the parent/child relation
void addRelation (char p, char c) {
    Node* parent = getNode(p);
    Node* child = getNode(c);
    parent->addChild(child);
}

// Processes a line of input containing 3 characters
void processLine() {
    char c1, c2, c3;
    cin >> c1 >> c2 >> c3;
    addRelation(c1, c2);
    addRelation(c2, c3);
}

// Searches the entire map of nodes looking for the free ones
// All free nodes are added to the queue
void findFreeNodes() {
    for (auto it = charNode.begin(); it != charNode.end(); ++it) {
        Node *n = it->second;
        if (n->isFree()) {
            queue.insert(n);
        }
    }
}

// Return true if all nodes in the map are free
bool allFree() {
    for (auto it = charNode.begin(); it != charNode.end(); ++it) {
        Node *n = it->second;
        if (!(n->isFree())) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        processLine();
    }
    findFreeNodes();
    
    string password = "";
    while (!(queue.isEmpty())) {
        password += queue.process();
    }
    
    if (allFree()) {
        cout << password;
    }
    else {
        cout << "SMTH WRONG";
    }
    
    return 0;
}
