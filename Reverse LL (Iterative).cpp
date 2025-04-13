#include<bits/stdc++.h>
using namespace std;

class Node {                                        // T = O(n)
public:                                             // S = O(1)
    int data;
    Node* next;

    Node(int data1) {
        data = data1;
        next = NULL;
    }
};

void print(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* convertArr2LL(vector<int>& arr) {
    if (arr.empty()) return NULL;

    Node* head = new Node(arr[0]);
    Node* current = head;

    for (int i = 1; i < arr.size(); i++) {
        current->next = new Node(arr[i]);
        current = current->next; 
    }
    return head;
}

Node* reverseLL(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    
    while (curr) {
        Node* front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    return prev;
}

int main() {
    vector<int> arr = {2, 5, 8, 9};
    Node* head = convertArr2LL(arr);

    head = reverseLL(head);
    print(head);
}