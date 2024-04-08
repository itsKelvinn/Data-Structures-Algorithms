
#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;
};

Node* root = nullptr;

Node* createNode(int value){
    Node* node = new Node;
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    return node; 
}

Node* insertNode(Node* node , Node* traversal){
    if(traversal == nullptr){
        return node;
    }
    else if(traversal->value > node->value){
        traversal->left = insertNode(node,traversal->left);
    }
    else if(traversal->value < node->value){
        traversal->right = insertNode(node,traversal->right);
    }
}

void insert(int value){
    
    Node* node = createNode(value);
    root = insertNode(node,root);

}

Node* remove_node(int value, Node* traversal) {
    if (traversal == nullptr) {
        // Base case: Node not found
        return nullptr;
    }

    if (value < traversal->value) {
        // If value is smaller than current node, search in the left subtree
        traversal->left = remove_node(value, traversal->left);
    } 
    else if (value > traversal->value) {
        // If value is greater than current node, search in the right subtree
        traversal->right = remove_node(value, traversal->right);
    } 
    else {

        // Node to be deleted found

        // Case 1: Node has no children (leaf node)
        if (traversal->left == nullptr && traversal->right == nullptr) {
            delete traversal;
            return nullptr; 
        }
        // Case 2: Node has one child
        else if (traversal->left == nullptr) {
            Node* temp = traversal->right;
            delete traversal;
            return temp; 
        } 
        else if (traversal->right == nullptr) {
            Node* temp = traversal->left;
            delete traversal;
            return temp;
        }
        // Case 3: Node has two children
        else {
            Node* successor = traversal->right;
            while (successor->left != nullptr) {
                successor = successor->left;
            }
            traversal->value = successor->value;
            traversal->right = remove_node(successor->value, traversal->right);
        }
    }

    return traversal;
}

void remove(int value, Node*& root) {
    root = remove_node(value, root);
}

// display binary search tree

void inOrder(Node* node){
    if(node != nullptr){
        inOrder(node->left);
        cout << node->value << endl;
        inOrder(node->right);
    }
}

void preOrder(Node* node){
    if(node != nullptr){
        cout << node->value << endl;
        preOrder(node->left);
        preOrder(node->right);
    }
}

void postOrder(Node* node){
    if(node != nullptr){
        postOrder(node->left);
        postOrder(node->right);
        cout << node->value << endl;
    }    
}


int main(){

    insert(10);
    insert(5);
    insert(12);
    insert(6);
    insert(3);
    insert(2);
    insert(4);

    
    
    postOrder(root);

    return 0;
}