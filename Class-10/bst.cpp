#include<bits/stdc++.h>
using namespace std;

class Node {

public:
    int data;
    Node *left;
    Node *right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void preorder(Node *root) {

    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// TC : O(height)
bool search(Node *root, int search_value) {

    if (root == NULL) {
        return false;
    }

    if (root->data == search_value) {
        return true;
    }

    if (root->data > search_value) {
        return search(root->left, search_value);
    }
    return search(root->right, search_value);
}


// TC : O(height)
// insert a new node in the BST and return the root node.
Node *insert(Node *root, int insert_value) {

    if (root == NULL) {
        return new Node(insert_value);
    }
    if (root->data == insert_value) { // To avoid duplicate entries.
        return root;
    }

    if (root->data > insert_value) { // Insert in the left subtree.
        root->left = insert(root->left, insert_value);
    }
    else { // Insert in the right subtree.
        root->right = insert(root->right, insert_value);
    }

    return root;
}

int get_min_value(Node *root) {

    while (root->left != NULL) {
        root = root->left;
    }

    return root->data;
}

// Delete the given value node and return the updated root.
Node *delete_node(Node *root, int delete_value) {

    if (root == NULL) {
        return NULL;
    }

    if (root->data == delete_value) {

        // Case-1: If the node has no child nodes.
        if (root->left == NULL and root->right == NULL) {
            return NULL;
        }

        // Case-2: If the node has one child node.
        if (root->left == NULL and root->right != NULL) {
            return root->right;
        }
        if (root->left != NULL and root->right == NULL) {
            return root->left;
        }

        // Case-3: If the node has two child nodes.
        // Replace the node with its inorder sucessor.

        int new_value = get_min_value(root->right);
        root->data = new_value;

        root->right = delete_node(root->right, new_value);
    }

    else if (root->data > delete_value) {
        root->left = delete_node(root->left, delete_value);
    }
    else {
        root->right = delete_node(root->right, delete_value);
    }

    return root;
}

bool is_BST_helper(Node *root, int low, int high) {

    if (root == NULL) {
        return true;
    }

    if (root->data < low or root->data > high) { // If the current node does not lie in the desired range
        return false;
    }

    // Check if both the left and right subtrees are BSTs.
    return is_BST_helper(root->left, low, root->data - 1) and
           is_BST_helper(root->right, root->data + 1, high);
}

bool is_BST(Node *root) {

    return is_BST_helper(root, -10000, 10000);
}

int main() {

    Node *root = NULL;
    root = insert(root, 11);
    root = insert(root, 2);
    root = insert(root, 9);
    root = insert(root, 13);
    root = insert(root, 1);

    preorder(root);
    cout << endl;

    cout << search(root, 11) << endl;
    cout << search(root, 2) << endl;
    cout << search(root, 9) << endl;
    cout << search(root, 13) << endl;
    cout << search(root, 1) << endl;
    
    cout << search(root, 20) << endl;
    cout << search(root, 0) << endl;
    
    cout << search(root, 2) << endl;
    root = delete_node(root, 2);
    cout << search(root, 2) << endl;
    
    cout << is_BST(root) << endl;

    root->right->right = new Node(7);
    cout << is_BST(root) << endl;
}