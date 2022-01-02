#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

void print(Node *head) {
    /*
    TC: O(n)
    */
    Node *current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}

Node *insert_at_begin(Node *head, int d) {
    /*
    TC: O(1)
    */
    Node *new_node = new Node(d);
    new_node->next = head; 
    head = new_node;

    return head;
}

Node *insert_at_end(Node *head, int d) {
    /*
    TC: O(n)
    */
    if (head == NULL) {
        return insert_at_begin(head, d);
    }

    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    Node *new_node = new Node(d);
    current->next = new_node;
    return head;
}

Node *insert_at_pos(Node *head, int d, int pos) {
    /*
    TC: O(min(pos, n))
    */
    if (head == NULL or pos == 0) {
        return insert_at_begin(head, d);
    }

    Node *current = head;
    while (pos != 1 and current->next != NULL) {
        current = current->next;
        pos--;
    }

    Node *new_node = new Node(d);
    new_node->next = current->next;
    current->next = new_node;
    
    return head;
}

Node *delete_from_begin(Node *head) {
    /*
    TC: O(1)
    */
    if (head == NULL) {
        return NULL;
    }
    return head->next;
}

Node *delete_from_end(Node *head) {
    /*
    TC: O(n)
    */
    if (head == NULL or head->next == NULL) {
        return NULL;
    }

    Node *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    current->next = NULL;

    return head;
}

Node *delete_from_pos(Node *head, int pos) {
    /*
    TC: O(min(pos, n))
    */
    if (pos == 0) {
        return delete_from_begin(head);
    }

    Node *current = head;
    while (pos != 1 and current != NULL) {
        current = current->next;
        pos--;
    }

    if (current == NULL or current->next == NULL) {
        return head;
    }
    current->next = current->next->next;
    return head;
}

int main() {

    // ---------------------------------------------
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    print(head);
    
    // ---------------------------------------------

    head = insert_at_begin(head, 4);

    print(head);

    // ---------------------------------------------

    head = insert_at_end(head, 5);

    print(head);

    // ---------------------------------------------

    head = new Node(1);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 3);
    head = insert_at_end(head, 4);

    head = insert_at_pos(head, 5, 0);
    print(head);

    head = insert_at_pos(head, 6, 3);
    print(head);

    head = insert_at_pos(head, 7, 100);
    print(head);

    // ---------------------------------------------

    head = new Node(1);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 3);

    head = delete_from_begin(head);
    print(head);

    // ---------------------------------------------

    head = new Node(1);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 3);

    head = delete_from_end(head);
    print(head);

    // ---------------------------------------------

    head = new Node(1);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 3);
    head = insert_at_end(head, 4);
    head = insert_at_end(head, 5);

    head = delete_from_pos(head, 2);
    print(head);

    head = delete_from_pos(head, 4);
    print(head);

    head = delete_from_pos(head, 100);
    print(head);

    // ---------------------------------------------
}