#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(NULL) {}
};

void josephus(int n, int m) {
    Node* head = new Node(1);
    Node* prev = head;
    for (int i = 2; i <= n; ++i) {
        prev->next = new Node(i);
        prev = prev->next;
    }
    prev->next = head; 
    Node* ptr1 = head;
    Node* ptr2 = head;

    while (ptr1->next != ptr1) {
        int count = 1;
        while (count != m) {
            ptr2 = ptr1;
            ptr1 = ptr1->next;
            count++;
        }
        ptr2->next = ptr1->next; 
        ptr1 = ptr2->next; 
    }

    cout << "The leader is candidate number " << ptr1->data << endl;
}

int main() {
    int n, m;
    cout << "Enter the number of candidates: ";
    cin >> n;
    cout << "Enter the kill factor : ";
    cin >> m;

    josephus(n, m);

    return 0;
}

