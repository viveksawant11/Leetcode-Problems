#include <bits/stdc++.h>

template <typename T>
class Node {
    public:
    T data;
    Node* next;

    Node(T data) {
        next = NULL;
        this->data = data;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second) {
    Node<int>* dummyNode = new Node<int>(-1);
    Node<int>* current = dummyNode;

    while (first != NULL && second != NULL) {
        if (first->data <= second->data) {
            current->next = first;
            first = first->next;
        }
        else {
            current->next = second;
            second = second->next;
        }
        current = current->next;
    }

    if (first != NULL) 
        current->next = first;
    else 
        current->next = second;

    return dummyNode->next;
}

void printList(Node<int>* head) {
    while (head != NULL) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    Node<int>* first = new Node<int>(1);
    first->next = new Node<int>(3);
    first->next->next = new Node<int>(5);

    Node<int>* second = new Node<int>(2);
    second->next = new Node<int>(4);
    second->next->next = new Node<int>(6);

    Node<int>* mergedList = sortTwoLists(first, second);

    printList(mergedList);

    return 0;
}
