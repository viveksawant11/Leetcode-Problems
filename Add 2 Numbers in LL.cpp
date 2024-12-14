#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1) {
        data = data1;
        next = NULL;
    }
};

Node* createList(vector<int>& arr) {
    if (arr.empty()) return NULL;

    Node* head = new Node(arr[0]);
    Node* current = head;

    for (int i = 1; i < arr.size(); i++) {
        current->next = new Node(arr[i]);
        current = current->next; 
    }
    return head;
}

void print(Node* head) {
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* addTwoNo(Node* head1, Node* head2) {
    Node* dummyHead = new Node(-1);
    Node* current = dummyHead;
    Node* temp1 = head1;
    Node* temp2 = head2;
    int carry = 0;

    while (temp1 != NULL || temp2 != NULL) {
        int sum = carry;
        
        if (temp1) 
            sum += temp1->data;
        if (temp2)
            sum += temp2->data;

        Node* newNode = new Node(sum % 10);
        carry = sum / 10;

        current->next = newNode;
        current = current->next;

        if (temp1)
            temp1 = temp1->next;
        if (temp2)
            temp2 = temp2->next;
    }

    if (carry) {
        Node* newNode = new Node(carry);
        current->next = newNode;
    }

    return dummyHead->next;                         // Head
}

int main()
{
    vector<int> arr1 = {4, 5, 9, 9};                //  9945
    vector<int> arr2 = {3, 5};                      //    53

    Node* head1 = createList(arr1);
    Node* head2 = createList(arr2);
    Node* sumResult = addTwoNo(head1, head2);

    print(sumResult);
    
    return 0;
}

// T = O(max(n1,n2))
// S = O(max(n1,n2)) - for storing the result , technically not using anything to solve the question