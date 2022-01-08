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

Node *reverse(Node *head) {
    /*
    TC: O(n)
    */
    Node *prev = NULL;
    Node *current = head;

    while (current != NULL) {
        Node *temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }

    return prev;
}

Node* get_middle(Node *head) {

    if (head == NULL) {
        return NULL;
    }
    
    Node *slow = head;
    Node *fast = head;

    while (fast->next != NULL and fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

bool is_palindrome(Node *head) {

    if (head == NULL or head->next == NULL) {
        return true;
    }

    Node *mid_node = get_middle(head);
    Node *head2 = mid_node->next;
    mid_node->next = NULL;

    head2 = reverse(head2);

    while (head != NULL and head2 != NULL) {
        if (head->data != head2->data) {
            return false;
        }
        head = head->next;
        head2 = head2->next;
    }

    return true;
}

Node* detect_and_remove_loop(Node *head) {

    if (head == NULL) {
        return head;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL and fast->next != NULL) {
        
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break;
        }
    }


    if (slow != fast) { // No loop detected.
        cout << "No loop detected" << endl;
        return head;
    }

    cout << "Loop detected" << endl;
    cout << "Intersection point of slow and fast:" << slow->data << endl;

    // Loop has been detected. Remove it.

    if (slow == head) { // The linked list is completely circular.

        while (fast->next != head) {
            fast = fast->next;
        }
        fast->next = NULL;
        return head;
    }

    fast = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    cout << "Loop starting point:" << slow->next->data << endl;
    slow->next = NULL;
    return head;
}

int main() {

    // ----------------------------------------

    Node *head = new Node(1);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 1);

    cout << is_palindrome(head) << endl;

    // ----------------------------------------

    head = new Node(1);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 3);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 1);

    cout << is_palindrome(head) << endl;

    // ----------------------------------------

    head = new Node(1);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 3);
    head = insert_at_end(head, 4);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 1);

    cout << is_palindrome(head) << endl;

    // ----------------------------------------

    head = new Node(1);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 3);
    head = insert_at_end(head, 4);
    head = insert_at_end(head, 5);
    head = insert_at_end(head, 6);
    head = insert_at_end(head, 7);

    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    tail->next = head->next->next;

    head = detect_and_remove_loop(head);
    print(head);

    // ----------------------------------------

    head = new Node(1);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 3);
    head = insert_at_end(head, 4);
    head = insert_at_end(head, 5);
    head = insert_at_end(head, 6);

    tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    tail->next = head;
    
    head = detect_and_remove_loop(head);
    print(head);

}