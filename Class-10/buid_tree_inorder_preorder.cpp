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

void postorder(Node *root) {

    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void inorder(Node *root) {

    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


// TC: O(n * n)
Node* build_tree_helper(vector<int> &in, vector<int> &pre, int in_start, int in_end, int &pre_index) {

    if (in_start > in_end) {
        return NULL;
    }

    Node *root = new Node(pre[pre_index]);
    pre_index++;


    // Finding the index with value = root->data in the inorder array.
    int in_index = in_start;
    for (int i = in_start + 1; i <= in_end; i++) {
        if (in[i] == root->data) {
            in_index = i;
            break;
        }
    }

    root->left = build_tree_helper(in, pre, in_start, in_index - 1, pre_index);
    root->right = build_tree_helper(in, pre, in_index + 1, in_end, pre_index);

    return root;
}

Node* build_tree_inorder_preorder(vector<int> in, vector<int> pre) {

    int pre_index = 0;
    return build_tree_helper(in, pre, 0, in.size() - 1, pre_index);
}

void push_left(Node *root, stack<Node*> &s) {

    while (root != NULL) {
        s.push(root);
        root = root->left;
    }
}

vector<int> iterative_inorder(Node *root) {

    vector<int> result;

    stack<Node*> s;
    push_left(root, s);

    while (!s.empty()) {

        Node *current = s.top();
        s.pop();

        result.push_back(current->data);
        push_left(current->right, s);
    }

    return result;
}

int main() {

    Node *root = build_tree_inorder_preorder({3, 1, 4, 0, 5, 2}, {0, 1, 3, 4, 2, 5});

    cout << "inorder: ";
    inorder(root);
    cout << endl;

    cout << "preorder: ";
    preorder(root);
    cout << endl;

    vector<int> in = iterative_inorder(root);
    for (int i : in) {
        cout << i << " ";
    }
    cout << endl;
}