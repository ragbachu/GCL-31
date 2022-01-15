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


void get_kth_level_helper(Node *root, int k, vector<int> &result) {

    if (root == NULL) {
        return;
    }

    if (k == 0) {
        result.push_back(root->data);
        return;
    }
    get_kth_level_helper(root->left, k - 1, result);
    get_kth_level_helper(root->right, k - 1, result);    
}

vector<int> get_kth_level(Node *root, int k) {

    vector<int> result;
    get_kth_level_helper(root, k, result);

    return result;
}

void level_order_brute(Node *root) {
    
    // TC: O(height * n) = O(n^2)

    int k = 0;
    while (true) {

        vector<int> current_level = get_kth_level(root, k);
        if (current_level.size() == 0) {
            break;
        }

        for (int i : current_level) {
            cout << i << " ";
        }
        k++;
    }
    cout << endl;
}

void level_order(Node *root) {

    // TC: O(n)

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {

        Node *current = q.front();
        q.pop();

        cout << current->data << " ";

        // Push the non-NULL child nodes of the current node in the queue.
        if (current->left != NULL) {
            q.push(current->left);
        }
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
    cout << endl;
}

unordered_map<Node*, int> heights_memo;

// TC: O(n)
int height(Node *root) {

    if (root == NULL) {
        return 0;
    }
    if (heights_memo.find(root) != heights_memo.end()) { // If height of 'root' has already been calculated.
        return heights_memo[root];
    }

    int left_subtree_height = height(root->left);
    int right_subtree_height = height(root->right);

    heights_memo[root] = max(left_subtree_height, right_subtree_height) + 1;
    return heights_memo[root];
}


// TC : O(n^2)
// TC : O(n) with memo approach
int diameter_brute(Node *root) {

    if (root == NULL) {
        return 0;
    }

    int left_subtree_diam = diameter_brute(root->left);
    int right_subtree_diam = diameter_brute(root->right);

    int max_subtree_diam = max(left_subtree_diam, right_subtree_diam);

    int left_subtree_height = height(root->left);
    int right_subtree_height = height(root->right);
    int current_diam = left_subtree_height + right_subtree_height + 1;

    return max(max_subtree_diam, current_diam);
}


// TC : O(n)
int diameter_helper(Node *root, int &result) {

    if (root == NULL) {
        return 0;
    }

    int left_subtree_height = diameter_helper(root->left, result);
    int right_subtree_height = diameter_helper(root->right, result);

    result = max(result, left_subtree_height + right_subtree_height + 1);

    return max(left_subtree_height, right_subtree_height) + 1;
}

int diameter(Node *root) {

    int result = 0;
    diameter_helper(root, result);

    return result;
}

int main() {

    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    preorder(root);
    cout << endl;

    postorder(root);
    cout << endl;

    inorder(root);
    cout << endl;

    level_order_brute(root);

    level_order(root);

    cout << height(root) << endl;

    cout << diameter_brute(root) << endl;

    cout << diameter(root) << endl;
}