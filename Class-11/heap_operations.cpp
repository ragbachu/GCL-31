#include <bits/stdc++.h>
using namespace std;

void bottom_up_heapify(vector<int> &heap, int index) {

    int parent_index = (index - 1) / 2;
    if (parent_index >= 0) {

        if (heap[index] > heap[parent_index]) {
            swap(heap[index], heap[parent_index]);
            bottom_up_heapify(heap, parent_index);
        }
    }
}

void insert_node(vector<int> &heap, int key) {

    heap.push_back(key);
    int index = heap.size() - 1;

    bottom_up_heapify(heap, index);
}

void top_down_heapify(vector<int> &heap, int index) {

    int left_child_index = index*2 + 1;
    int right_child_index = index*2 + 2;

    int n = heap.size();

    // `largest_value_index` will come be the index having the largest value among
    // (index, left_child_index, right_child_index).
    int largest_value_index = index;
    if (left_child_index < n and heap[left_child_index] > heap[largest_value_index]) {
        largest_value_index = left_child_index;
    }
    if (right_child_index < n and heap[right_child_index] > heap[largest_value_index]) {
        largest_value_index = right_child_index;
    }

    // If the the current node is having a greater value in any of its child nodes, we will
    // swap the current node with its maximum child node and will recursively heapify the maximum
    // child node.
    if (largest_value_index != index) {
        swap(heap[index], heap[largest_value_index]);
        // int temp = heap[index];
        // heap[index] = heap[largest_value_index];
        // heap[largest_value_index] = temp;
        top_down_heapify(heap, largest_value_index);
    }
}

void delete_max_node(vector<int> &heap) {

    int n = heap.size();
    if (n == 0) {
        return;
    }

    heap[0] = heap[n - 1]; // Replace the root with the last element.

    heap.pop_back(); // Scrapping-off the last element.

    top_down_heapify(heap, 0);
}

int main() {

    vector<int> heap = {10, 5, 3, 2, 4};
    insert_node(heap, 15);
    insert_node(heap, 11);

    for (int i : heap) {
        cout << i << " ";
    }

    cout << endl;

    delete_max_node(heap);

    for (int i : heap) {
        cout << i << " ";
    }

    cout << endl;
}
